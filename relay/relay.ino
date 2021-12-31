#include "SoftwareSerial.h"
SoftwareSerial sw(4,5);//4 es RX, 5 es TX
const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3; 
long duracion, distancia;
int ledPin1=12,ledPin2=11,ledPin3=10;
boolean ledOn1 = false, ledOn2 = false, ledOn3 = false;


void ultrasonido(){
  long t,d; //tiempo demora llegar el eco y tiempo en cm
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  Serial.print("Distancia: ");Serial.print(d);Serial.println("cm\n");
  delay(100);          //Hacemos una pausa de 100ms
  if (d<11){
    digitalWrite(ledPin1,HIGH);
  }else{
    digitalWrite(ledPin1,ledOn1);
  }
}

void foco1(int Led){
ledOn1=!ledOn1;
digitalWrite(Led, ledOn1);
}

void foco2(int Led){
ledOn2=!ledOn2;
digitalWrite(Led, ledOn2);
}

void foco3(int Led){
ledOn3=!ledOn3;
digitalWrite(Led, ledOn3);
} 

void setup(){

Serial.begin(9600);
sw.begin(9600);
pinMode(ledPin1,OUTPUT);
pinMode(ledPin2,OUTPUT);
pinMode(ledPin3,OUTPUT);
pinMode(Trigger, OUTPUT); pinMode(Echo, INPUT);
digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop(){
ultrasonido();

if (Serial.available()>0) {
  char teclado = Serial.read();
  if(teclado=='a'){foco1(ledPin1);
  Serial.write(teclado);
  Serial.println();
  delay(50);
}

if(teclado=='s'){foco2(ledPin2);
  Serial.write(teclado);
  Serial.println();
  delay(50);
}

  if(teclado=='d'){foco3(ledPin3);
  Serial.write(teclado);
  Serial.println();
  delay(50);
  }

 }

  if (sw.available() > 0) {
    char teclado = sw.read();
    if(teclado=='a'){foco1(ledPin1);
    Serial.write(teclado);
    Serial.println();
    delay(50);
  }

    if(teclado=='s'){foco2(ledPin2);
    Serial.write(teclado);
    Serial.println();
    delay(50);
  }

    if(teclado=='d'){foco3(ledPin3);
    Serial.write(teclado);
    Serial.println();
    delay(50);
  }
    
 }

}
