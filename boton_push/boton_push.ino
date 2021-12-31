const int pulsadorPin = 2;
const int ledPin = 13;
 
int valorPulsador = 0;
 
void setup() {
    // Activamos los pines de entrada y salida
    pinMode(pulsadorPin, INPUT);
    pinMode(ledPin, OUTPUT);
}
 
void loop() {
    // Leemos el valor del pin
    valorPulsador = digitalRead(pulsadorPin);
 
  // Encendemos o apagamos el pin del LED según convenga
  if (valorPulsador == HIGH) {
      digitalWrite(ledPin, HIGH);
  }
  else {
      digitalWrite(ledPin, LOW);
  }
}
