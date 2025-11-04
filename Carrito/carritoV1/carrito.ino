// --- Control por Serial: MOTORES (Versión sin ENA/ENB) ---
// --- Definiciones del Motor Driver L298N ---
// (Se asume que los jumpers ENA y ENB están colocados)

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.println("=== CONTROL DE MOTORES ===");
  Serial.println("Comandos:");
  Serial.println("W = Avanzar");
  Serial.println("S = Retroceder");
  Serial.println("A = Izquierda");
  Serial.println("D = Derecha");
  Serial.println("X = Detener");
}

void loop() {
  if (Serial.available()) {
    char comando = toupper(Serial.read());
    switch (comando) {
      case 'W': moveForward(); break;
      case 'S': moveBackward(); break;
      case 'A': turnLeft(); break;
      case 'D': turnRight(); break;
      case 'X': Stop(); break;
    }
  }
}

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
