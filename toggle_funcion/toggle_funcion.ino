int ledPin=8, ledPin2=9, ledPin3=10,ledPin4=11, ledPin5=12,ledPin6=13;

boolean ledOn=false;
void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
pinMode(ledPin5, OUTPUT);
pinMode(ledPin6, OUTPUT);


}

void loop() {
char teclado = Serial.read();
if(teclado=='a')toggleLED(ledPin);
if(teclado=='s')toggleLED(ledPin2);
if(teclado=='d')toggleLED(ledPin3);
if(teclado=='f')toggleLED(ledPin4);
if(teclado=='g')toggleLED(ledPin5);
if(teclado=='h')toggleLED(ledPin6);
}
void toggleLED(int Led){
  ledOn=!ledOn;
  digitalWrite(Led, ledOn);
}
