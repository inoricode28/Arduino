#include "SoftwareSerial.h"
SoftwareSerial BT(7,8); //7 es RX, 8 es TX
int ledPin1=13, ledPin2=12, ledPin3=11, ledPin4=10 , ledPin5=9 , /*ledPin6=8 , ledPin7=7 ,*/ ledPin8=6 , ledPin9=5 , ledPin10=4 , ledPin11=3 ,ledPin12=2;
boolean ledOn01=false, ledOn02=false, ledOn03=false, ledOn04=false , ledOn05=false , /*ledOn06=false , ledOn07=false ,*/ ledOn08=false , ledOn09=false , ledOn10=false , ledOn11=false , ledOn12=false;

void led01(int Led)
{
  ledOn01=!ledOn01;
  digitalWrite(Led, ledOn01);  
}

void led02(int Led)
{
  ledOn02=!ledOn02;
  digitalWrite(Led, ledOn02);  
}

void led03(int Led)
{
  ledOn03=!ledOn03;
  digitalWrite(Led, ledOn03);  
}

void led04(int Led)
{
  ledOn04=!ledOn04;
  digitalWrite(Led, ledOn04);  
}
void led05(int Led)
{
  ledOn05=!ledOn05;
  digitalWrite(Led, ledOn05);
}
/*
void led06(int Led)
{
  ledOn06=!ledOn06;
  digitalWrite(Led, ledOn06);
}
void led07(int Led)
{
  ledOn07=!ledOn07;
  digitalWrite(Led, ledOn07);
}
*/
void led08(int Led)
{
  ledOn08=!ledOn08;
  digitalWrite(Led, ledOn08);
}
void led09(int Led)
{
  ledOn09=!ledOn09;
  digitalWrite(Led, ledOn09);
}
void led10(int Led)
{
  ledOn10=!ledOn10;
  digitalWrite(Led, ledOn10);
}
void led11(int Led)
{
  ledOn11=!ledOn11;
  digitalWrite(Led, ledOn11);
}
void led12(int Led)
{
  ledOn12=!ledOn12;
  digitalWrite(Led, ledOn12);
}
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  /*
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  */
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10,OUTPUT);
  pinMode(ledPin11,OUTPUT);
  pinMode(ledPin12,OUTPUT);
  BT.begin(9600);
  Serial.begin(9600);

}

void loop() {
  if (BT.available() > 0) {
      char bluetooh = BT.read();
      if(bluetooh=='a'){led01(ledPin1);}
      if(bluetooh=='s'){led02(ledPin2);}
      if(bluetooh=='d'){led03(ledPin3);}
      if(bluetooh=='f'){led04(ledPin4);}  
      if(bluetooh=='g'){led05(ledPin5);}
      /*
      if(bluetooh=='h'){led06(ledPin6);}
      if(bluetooh=='j'){led07(ledPin7);}
      */
      if(bluetooh=='k'){led08(ledPin8);}
      if(bluetooh=='l'){led09(ledPin9);}
      if(bluetooh=='z'){led10(ledPin10);}
      if(bluetooh=='x'){led11(ledPin11);}
      if(bluetooh=='c'){led12(ledPin12);}
      if(bluetooh=='v'){
        led01(ledPin1);
        led02(ledPin2);
        led03(ledPin3);
        led04(ledPin4);
        led05(ledPin5);
        led08(ledPin8);
        led09(ledPin9);
        led10(ledPin10);
        led11(ledPin11);
        led12(ledPin12);}
      }

  if (Serial.available() > 0) {
      char teclado = Serial.read();
      if(teclado=='a'){led01(ledPin1);}
      if(teclado=='s'){led02(ledPin2);}
      if(teclado=='d'){led03(ledPin3);}
      if(teclado=='f'){led04(ledPin4);} 
      if(teclado=='g'){led05(ledPin5);}
      /*
      if(teclado=='h'){led06(ledPin6);}
      if(teclado=='j'){led07(ledPin7);}
      */
      if(teclado=='k'){led08(ledPin8);}
      if(teclado=='l'){led09(ledPin9);}
      if(teclado=='z'){led10(ledPin10);}
      if(teclado=='x'){led11(ledPin11);}
      if(teclado=='c'){led12(ledPin12);}
      if(teclado=='v'){led01(ledPin1);
        led02(ledPin2);
        led03(ledPin3);
        led04(ledPin4);
        led05(ledPin5);
        led08(ledPin8);
        led09(ledPin9);
        led10(ledPin10);
        led11(ledPin11);
        led12(ledPin12);}
  }
}
