int led=13;
void setup() {
 //Comunicacion con el Arduino
 Serial.begin(9600);
 pinMode(led,OUTPUT);
}

void loop() {
	char teclado = Serial.read();
	if (teclado=='a'){digitalWrite(led,1);}
	if (teclado=='d'){digitalWrite(led,0);}
  

}
