//incoimpleto
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int analogInPin = A0; //Analogico
const int analogOutPin = 3; // " ~ " PWM Modulacion de ancho de pulso
int potValor =0;//Potenciomentro
int OutputValor=0;

void setup() {
  Serial.begin(9600);
  pinMode(ledverde, OUTPUT);
  pinMode(ledamarillo, OUTPUT);
  pinMode(ledrojo, OUTPUT);  
  pinMode(trigger, OUTPUT);// el tiro esta configurado en salida
  pinMode(Echo, INPUT);// el echo esta configurado en entrada
  digitalWrite(trigger, LOW);//se inicializa el tiro en modo apagado

  lcd.init();// Inicioaliza el LCD
 
  //Imprime Mensaje en el LCD
  lcd.backlight();//Luz de LCD
  lcd.setCursor(0,0);//Pocicion en el LCD
  lcd.print("   HAY ENTRO  ");//Mensaje en el LCD
  lcd.setCursor(0,1);//Pocicion en el LCD
  lcd.print("   CARAMELO  ");//Mensaje en el LCD
  delay(100000);//Tiempo de espera

  lcd.clear();//Limpiado de pantalla

}

void loop() {
  potValor=analogRead(analogInPin);
  OutputValor=map(potValor, /*analog*/ 0, 1023, /*digital*/ 0, 255);
  analogWrite(analogOutPin, OutputValor);

  //analogico --> 2 a la 10 = 0 - 1023 (10bits)
  //digital --> 2 a la 8 = 0 - 255 (8bits)
  Serial.print("Potenciometroi = ");
  Serial.print(potValor);
  lcd.setCursor(0,0);//Pocicion en el LCD
  lcd.print(potValor);//Mensaje en el LCD
  ///////////////////////////////////////////////////
  Serial.print("\t PWM = ");
  Serial.println(OutputValor);
  lcd.setCursor(0,1);//Pocicion en el LCD
  lcd.print(OutputValor);//Mensaje en el LCD
  delay(100);

}
