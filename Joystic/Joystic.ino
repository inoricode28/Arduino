#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);
//variables

long tiempo=0;
long distancia=0;
int xPin =A1;
int yPin=A0;
int buttonPin =6;
int xPosition =0;
int yPosition =0;
int buttonState=0;
int xPin1 = A2;
int yPin1 = A3;
int buttonPin1 =5;
int xPosition1 =0;
int yPosition1 =0;
int buttonState1=0;

void setup() {
  Serial.begin(9600);
  inicioLCD();

  
  pinMode(9,OUTPUT);
  pinMode(8,INPUT); 
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(xPin1,INPUT);
  pinMode(yPin1,INPUT);
  pinMode(buttonPin1,INPUT_PULLUP);


}


void loop() {
 
fdistancia();
yoistick();
yoistick1();

lcd.clear();
lcd.setCursor(12,1),
lcd.print(distancia);

if(xPosition>800){  
  lcd.setCursor(0,0);
  lcd.print(" arriba");  
  }
  if(xPosition<250){
    lcd.setCursor(0,0);
    lcd.print("  abajo");
    }

    if(yPosition>800){  
  lcd.setCursor(0,0);
  lcd.print(" derecha");  
  }
  if(yPosition<250){
    lcd.setCursor(0,0);
    lcd.print("  izquierda");
    }




if(xPosition1>800){  
  lcd.setCursor(0,1);
  lcd.print(" arriba");  
  }
  if(xPosition1<250){
    lcd.setCursor(0,1);
    lcd.print("  abajo");
    }

    if(yPosition1>800){  
  lcd.setCursor(0,1);
  lcd.print(" derecha");  
  }
  if(yPosition1<250){
    lcd.setCursor(0,1);
    lcd.print("  izquierda");
    }
    
}



void inicioLCD(){  
lcd.begin(16,2);
lcd.setBacklightPin(3,POSITIVE);
lcd.setBacklight(HIGH);
delay(1000);
lcd.home();
lcd.print("HOME ELECTRONICS");
lcd.setCursor(0,1);
lcd.print("CURSO DE ARDUINO");
delay(3000);

 
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Miguel Alfonzo");
lcd.setCursor(2,1);
lcd.print("Chavez Ramos");
delay(3000);
  
  }
  
void fdistancia(){
 digitalWrite(9,LOW);
 delayMicroseconds(5);
 digitalWrite(9,HIGH);
 delayMicroseconds(10);
 tiempo=pulseIn(8,HIGH);
 distancia=int(0.017*tiempo);
 Serial.print("  Distancia  ");
 Serial.print(distancia);
 Serial.println("cm");
 delay(100);
 lcd.home();
  
}
  
void yoistick(){
  xPosition = analogRead(xPin);
  yPosition= analogRead(yPin);
  buttonState=digitalRead(buttonPin);
  Serial.print("x:  ");
  Serial.print(xPosition);
  Serial.print("|y:  ");
  Serial.print(yPosition);
  Serial.print("| Button:  ");
  Serial.print(buttonState);
  delay(100);
}
 void yoistick1(){
  xPosition1 = analogRead(xPin1);
  yPosition1= analogRead(yPin1);
  buttonState1=digitalRead(buttonPin1);
  Serial.print("x:  ");
  Serial.print(xPosition1);
  Serial.print("|y:  ");
  Serial.print(yPosition1);
  Serial.print("| Button  :");
  Serial.print(buttonState1);
  delay(100);
 }
    
  


