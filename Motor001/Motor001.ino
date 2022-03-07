void setup() {
 Serial.begin(9600); 
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);

}
void izquierda()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void derecha()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}


void detener()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void derecha01()
{
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void izquierda01()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void ADELANTE()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void ATRAS()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void loop() {
  char teclado = Serial.read();
  if(teclado=='a'){derecha();}
  if(teclado=='s'){izquierda();}
  if(teclado=='z'){detener();}
  if(teclado=='d'){derecha01();}
  if(teclado=='f'){izquierda01();}
  if(teclado=='g'){ADELANTE();}
  if(teclado=='h'){ATRAS();}

}
