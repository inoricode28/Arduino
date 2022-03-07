#include <Ping.h>
#define Trig 12
#define Eco 13
const int zumbador = 6;
const int led = 8;
int distancia;
int pausa;

void setup() {
pinMode(Trig, OUTPUT);
pinMode(Eco, INPUT);
pinMode(zumbador, OUTPUT);
pinMode(led, OUTPUT);
}

void loop() {
long duracion;

/* Hacer el disparo*/

digitalWrite(Trig, LOW);
delayMicroseconds(2);
digitalWrite(Trig, HIGH);
delayMicroseconds(10);
digitalWrite(Trig, LOW);

/* Recepcion del Eco Respuesta*/
 duracion = pulseIn(Eco, HIGH);
 distancia = (duracion / 2) / 29;

if (distancia < 100){
  pausa = distancia * 10;
  digitalWrite(zumbador, HIGH);
  digitalWrite(led, HIGH);
  delay(pausa);  
  }

digitalWrite(zumbador, LOW);
digitalWrite(led, LOW);
delay(pausa);
}
