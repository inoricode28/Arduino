#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int potenciometro=A0;
int valorPotenciometroOld =0, OutputValor=0;
const int analogOutPin = 5; // " ~ " PWM Modulacion de ancho de pulso

void setup() {
Serial.begin(9600);
lcd.init();
lcd.backlight();
lcd.print("Arduino Peru");
lcd.setCursor(0,1);
lcd.print("Val. Lido: ");

}

void loop() {
  int valorPotenciometro = analogRead(potenciometro);
  OutputValor=map(valorPotenciometro, /*analog*/ 0, 1023, /*digital*/ 0, 255);
  analogWrite(analogOutPin, OutputValor);

  if(valorPotenciometro!=valorPotenciometroOld){
      lcd.setCursor(12,1);
      lcd.print("    ");
      lcd.setCursor(12,1);
      lcd.print(valorPotenciometro);
      delay(500);
      valorPotenciometroOld = valorPotenciometro;

  }

}
