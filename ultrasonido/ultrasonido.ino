int ledverde=4,ledamarillo=5,ledrojo=6, led; 
const int trigger=2;
const int Echo=3;
long duracion, distancia;

void setup() {
  Serial.begin(9600);
  pinMode(ledverde, OUTPUT);
  pinMode(ledamarillo, OUTPUT);
  pinMode(ledrojo, OUTPUT);  
  pinMode(trigger, OUTPUT);// el tiro esta configurado en salida
  pinMode(Echo, INPUT);// el echo esta configurado en entrada
  digitalWrite(trigger, LOW);//se inicializa el tiro en modo apagado


}

void loop() {
////////////////////////////////////////////////////////////////////
long t, d;
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

t =pulseIn(Echo, HIGH);
d = t/59;
Serial.print("Distancia: "); Serial.print(d);Serial.println("cm\n");
delay(100);
////////////////////////////////////////////////////////////////////

  if (d>20){
    led=1;
    digitalWrite(ledamarillo,LOW);
    digitalWrite(ledrojo,LOW);
  }

  if (d<=20&&d>10){
    led=2;
    digitalWrite(ledverde,LOW);
    digitalWrite(ledrojo,LOW);
  }
  if (d<=10){
    led=3;
    digitalWrite(ledverde,LOW);
    digitalWrite(ledamarillo,LOW);
  }
  switch(led){
    case 1:
    digitalWrite(ledverde,HIGH);
    break;
    case 2:
    digitalWrite(ledamarillo,HIGH);
    break;
    case 3:
    digitalWrite(ledrojo,HIGH);
    break;
  }
}
