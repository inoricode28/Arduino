#include<SoftwareSerial.h>

// se define al Pin2 como RX, Pin3 como TX
SoftwareSerial mySerial(2,3);

void setup()
{

//inicializa la comunicacion serial
Serial.begin(9600);
mySerial.begin(9600);

//se configura los pines de entrada y salida
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);

pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);

// inicializa el estdo de los LEDs
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
digitalWrite(9,LOW);
}

void loop()
{

char c=mySerial.read();
if(c=='1') digitalWrite(4,HIGH);
if(c=='2') digitalWrite(5,HIGH);
if(c=='3') digitalWrite(6,HIGH);
if(c=='a') digitalWrite(4,LOW);
if(c=='b') digitalWrite(5,LOW);
if(c=='c') digitalWrite(6,LOW);

if(c=='q') Adelante();
if(c=='w') Atras();
if(c=='e') Derecha();
if(c=='r') Izquierda();
if(c=='t') Detener();
if(c=='y') Girar();

}
//*************************************
//***********************************
//*** FUNCIONES****

void Adelante()
{
  
 digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  
  }
void Atras()
{
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  }
void Derecha(){

 digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);

  
  }
void Izquierda(){

 digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
   
  }void Detener(){

 digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  
  }

  void Girar(){
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW); 
    
    
    
    }

 
