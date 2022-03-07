#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int ledverde=4,ledamarillo=5,ledrojo=6, led, valorOld =0;

const int trigger=2;
const int Echo=3;
long duracion, distancia;

void setup() {
Serial.begin(9600);
lcd.init();
lcd.backlight();
lcd.print("Arduino Peru");
lcd.setCursor(0,1);
lcd.print("Distancia cm: ");

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
//////////////////LCD////////////////////////////////
      if(d!=valorOld){
      lcd.setCursor(13,1);
      lcd.print("    ");
      lcd.setCursor(13,1);
      lcd.print(d);
      delay(500);
      valorOld = d;  
      }
      
      
}
