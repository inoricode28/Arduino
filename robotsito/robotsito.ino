const int sensor1 = 2;
const int boton1 = 7;
int sensor1State = 0;
const int pwm1 = 10;
const int pwm2 = 11;
const int motor1A = 3;
const int motor1B = 4;
const int motor2A = 5;
const int motor2B = 6;
int boton1Val = HIGH;
int botonEstado = HIGH;

void derecho(){
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);  
  }
void giroIzquierda(){
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);  
  }
void giroDerecha(){
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);  
  }
void setup() {

  pinMode(sensor1, INPUT);
  pinMode(boton1, INPUT_PULLUP);

  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  
}

void loop() {
    
  boton1Val = digitalRead(boton1);
  if(boton1Val == LOW)
  {
    botonEstado = LOW;
    delay(300);
  }
  else
    {
    botonEstado = HIGH;
    }

  while(botonEstado == LOW)
  {
  
  sensor1State = digitalRead(sensor1);
  if(sensor1State == HIGH)
  {
    analogWrite(pwm1, 125);
    analogWrite(pwm2, 125);
    derecho();
  }
  else
  {
    analogWrite(pwm1, 125);
    analogWrite(pwm2, 125);
   giroIzquierda();
  }
   boton1Val = digitalRead(boton1);
  
  if(boton1Val == LOW)
  {
    botonEstado = HIGH;
    delay(300);
  }
  
  }
 

  
}
