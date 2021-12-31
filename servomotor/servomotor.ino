
#include <Servo.h>
//Definir los Servos a trabajar
Servo servo1, servo2;
//Definir los joystick en los pines analogicos
int joyX=0, joyY=1, joyVal, pin=11;
//int dato = 0;

void setup()
{
  pinMode(pin, OUTPUT);
 

  //pinMode(3, OUTPUT);
  servo1.attach(7);
  servo2.attach(8);  
}

void loop()
{
  int dato = map(dato = analogRead(0), 0, 1024, 0, 255);
  analogWrite(pin, dato);
  //digitalWrite(3, HIGH);
  joyVal = analogRead(joyX);
  joyVal = map(joyVal, 0, 1023, 0, 180);
  servo1.write(joyVal);  

  joyVal = analogRead(joyX);
  joyVal = map(joyVal, 0, 1023, 0, 180);
  servo2.write(joyVal);
  delay(15);

}
