#include <NewPing.h>
#include <Servo.h>

// --- Control por Serial + Ultrasonido (NewPing) + Brazo Robótico (4 servos) ---
// --- Driver L298N (Jumpers ENA y ENB colocados) ---

// --- Motores de tracción ---
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

// --- Sensor Evita-Obstáculos (Ultrasonido) ---
#define TRIG A2
#define ECHO A3
#define MAX_DISTANCE 100
NewPing sonar(TRIG, ECHO, MAX_DISTANCE);

int distance;
bool modoAutomatico = false;

// --- Servos del Brazo Robótico ---
Servo base;     // Rotación base
Servo hombro;   // Movimiento vertical
Servo codo;     // Articulación intermedia
Servo garra;    // Pinza o muñeca

int basePin   = 9;
int hombroPin = 10;
int codoPin   = 11;
int garraPin  = 12;

// Posiciones iniciales de los servos
int posBase   = 90;
int posHombro = 90;
int posCodo   = 90;
int posGarra  = 90;

void setup() {
  Serial.begin(9600);

  // Pines motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Servos
  base.attach(basePin);
  hombro.attach(hombroPin);
  codo.attach(codoPin);
  garra.attach(garraPin);

  base.write(posBase);
  hombro.write(posHombro);
  codo.write(posCodo);
  garra.write(posGarra);

  Serial.println("=== CONTROL DE MOTORES + SENSOR ULTRASONIDO + BRAZO ROBOTICO (4 SERVOS) ===");
  Serial.println("Comandos:");
  Serial.println("W = Avanzar | S = Retroceder | A = Izquierda | D = Derecha | X = Detener");
  Serial.println("M = Activar/Desactivar modo automático");
  Serial.println("B/b = Rotar base derecha/izquierda");
  Serial.println("H/h = Subir/Bajar hombro");
  Serial.println("C/c = Subir/Bajar codo");
  Serial.println("G/g = Abrir/Cerrar garra");
  Serial.println("---------------------------------------------------------------");
}

void loop() {
  // Mostrar distancia cada 500 ms
  static unsigned long tiempoAnterior = 0;
  if (millis() - tiempoAnterior >= 500) {
    tiempoAnterior = millis();
    medirDistancia();
  }

  // --- Control manual ---
  if (Serial.available()) {
    char comando = Serial.read();

    switch (comando) {
      case 'W': case 'w': moveForward(); break;
      case 'S': case 's': moveBackward(); break;
      case 'A': case 'a': turnLeft(); break;
      case 'D': case 'd': turnRight(); break;
      case 'X': case 'x': Stop(); break;
      case 'M': case 'm':
        modoAutomatico = !modoAutomatico;
        if (modoAutomatico) Serial.println("Modo automático ACTIVADO");
        else { Serial.println("Modo automático DESACTIVADO"); Stop(); }
        break;

      // --- Control de servos manual ---
      case 'B': moverBase(10); break;   // rotar base a la derecha
      case 'b': moverBase(-10); break;  // rotar base a la izquierda
      case 'H': moverHombro(10); break; // subir hombro
      case 'h': moverHombro(-10); break;// bajar hombro
      case 'C': moverCodo(10); break;   // subir codo
      case 'c': moverCodo(-10); break;  // bajar codo
      case 'G': moverGarra(10); break;  // abrir garra
      case 'g': moverGarra(-10); break; // cerrar garra
    }
  }

  // --- Modo Automático (Evasión + Brazo) ---
  if (modoAutomatico) {
    medirDistancia();

    if (distance <= 10 && distance > 0) {
      Stop();
      Serial.println("⚠️ Obstáculo MUY CERCANO: activando brazo...");
      accionarBrazo();
      delay(500);
      moveBackward();
      delay(700);
      Stop();
      turnRight();
      delay(600);
      Stop();
    }
    else if (distance <= 15 && distance > 0) {
      Stop();
      Serial.println("⚠️ Obstáculo detectado, retrocediendo...");
      moveBackward();
      delay(700);
      Stop();
      turnRight();
      delay(600);
      Stop();
    } 
    else {
      moveForward();
    }
  }
}

// --- Medir distancia con NewPing ---
void medirDistancia() {
  unsigned int cm = sonar.ping_cm();
  distance = cm;
  if (cm == 0) {
    Serial.println("Sin lectura de ultrasonido");
    return;
  }
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(" cm");
}

// --- Funciones de movimiento del brazo ---
void moverBase(int cambio) {
  posBase = constrain(posBase + cambio, 0, 180);
  base.write(posBase);
  Serial.print("Base: "); Serial.println(posBase);
}

void moverHombro(int cambio) {
  posHombro = constrain(posHombro + cambio, 0, 180);
  hombro.write(posHombro);
  Serial.print("Hombro: "); Serial.println(posHombro);
}

void moverCodo(int cambio) {
  posCodo = constrain(posCodo + cambio, 0, 180);
  codo.write(posCodo);
  Serial.print("Codo: "); Serial.println(posCodo);
}

void moverGarra(int cambio) {
  posGarra = constrain(posGarra + cambio, 60, 130);
  garra.write(posGarra);
  Serial.print("Garra: "); Serial.println(posGarra);
}

void accionarBrazo() {
  // Movimiento automático simulado de los 4 servos
  moverBase(20);
  delay(300);
  moverHombro(15);
  delay(300);
  moverCodo(-15);
  delay(300);
  moverGarra(-20);
  delay(400);
  moverGarra(20);
  delay(400);
  moverCodo(15);
  moverHombro(-15);
  moverBase(-20);
  Serial.println("✅ Brazo accionado automáticamente");
}

// --- Funciones de movimiento del chasis ---
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Avanzando");
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Retrocediendo");
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Girando Izquierda");
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Girando Derecha");
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Detenido");
}
