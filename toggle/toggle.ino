int ledPin=12;
boolean ledOn=true;//Condicional Booleana

void toggleLED(int Led){//funcion
  ledOn=!ledOn;//Diferencial
  digitalWrite(Led, ledOn);
}

void setup() {
Serial.begin(9600);//Puerto Serial
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin,1);
}

void loop() {
char teclado = Serial.read();//Lectura digital
if(teclado=='a')toggleLED(ledPin);//Anidado
}
