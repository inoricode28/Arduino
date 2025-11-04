#include <NewPing.h>

// --- Control por Serial + Ultrasonido (NewPing) + Modo Automático (Aviación) ---
// --- Driver L298N (Jumpers ENA y ENB colocados) ---

// --- Motores ---
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

// --- Sensor Evita-Obstáculos (Ultrasonido) ---
#define TRIG A2
#define ECHO A3
#define MAX_DISTANCE 100
NewPing sonar(TRIG, ECHO, MAX_DISTANCE);

int distance; // distancia medida en cm
bool modoAutomatico = false; // control del modo automático

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.println("=== CONTROL DE MOTORES + SENSOR ULTRASONIDO ===");
  Serial.println("Comandos:");
  Serial.println("W = Avanzar");
  Serial.println("S = Retroceder");
  Serial.println("A = Izquierda");
  Serial.println("D = Derecha");
  Serial.println("X = Detener");
  Serial.println("M = Activar/Desactivar modo automático (aviación)");
  Serial.println("-----------------------------------------------");
}

void loop() {
  // Mostrar distancia cada 500 ms
  static unsigned long tiempoAnterior = 0;
  if (millis() - tiempoAnterior >= 500) {
    tiempoAnterior = millis();
    medirDistancia();
  }

  // Control por Serial (manual)
  if (Serial.available()) {
    char comando = toupper(Serial.read());
    switch (comando) {
      case 'W': moveForward(); break;
      case 'S': moveBackward(); break;
      case 'A': turnLeft(); break;
      case 'D': turnRight(); break;
      case 'X': Stop(); break;
      case 'M':
        modoAutomatico = !modoAutomatico;
        if (modoAutomatico) {
          Serial.println("Modo automático ACTIVADO");
        } else {
          Serial.println("Modo automático DESACTIVADO");
          Stop();
        }
        break;
    }
  }

  // --- Modo Automático (Evita Obstáculos) ---
  if (modoAutomatico) {
    medirDistancia();

    if (distance <= 15 && distance > 0) {
      Stop();
      Serial.println("⚠️ Obstáculo detectado, retrocediendo...");
      moveBackward();
      delay(700);
      Stop();

      Serial.println("Girando para evitar obstáculo...");
      turnRight();
      delay(600);
      Stop();
    } else {
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

// --- Funciones de movimiento ---
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
