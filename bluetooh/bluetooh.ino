#include<SofwareSerial.h>
SofwareSerial BTSerial(10,11); //RX :: TX
void setup() {
pinMode(9, OUTPUT);  
digitalWrite(9, HIGH);
Serial.begin(9600);
Serial.println("Enter AT Commands: ");
BTSerial.begin(38400);
}

void loop() {
 if (BTSerial.available()) 
 Serial.write(BTSerial.read());
 
 if (Serial.available())
 BTSerial.write(Serial.read());

}
