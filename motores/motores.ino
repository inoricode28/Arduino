int ENA= 10;
int motorA1=9;
int motorA2=8;

int ENB= 5;
int motorB1= 7;
int motorB2= 6;

void adelante()
{
	digitalWrite(ENA, 255);
	digitalWrite(motorA1, HIGH);
	digitalWrite(motorA2, LOW);

	digitalWrite(ENB, 255);
	digitalWrite(motorB1, LOW);
	digitalWrite(motorB2, HIGH);
}
 void atras()
 {
 	digitalWrite(ENA, 255);
 	digitalWrite(motorA1, LOW);
 	digitalWrite(motorA2, HIGH);

 	digitalWrite(ENB, 255);
 	digitalWrite(motorB1, HIGH);
 	digitalWrite(motorB2, LOW);
 }
 void detener()
 {
 	digitalWrite(ENA, 0);
 	digitalWrite(motorA1, LOW);
 	digitalWrite(motorA2, LOW);

 	digitalWrite(ENB, 0);
 	digitalWrite(motorB1, LOW);
 	digitalWrite(motorB2, LOW);
 }
 void setup()
 {
 	Serial.begin(9600);
 	pinMode(motorA1, OUTPUT);
 	pinMode(motorA2, OUTPUT);
 	pinMode(motorB1, OUTPUT);
 	pinMode(motorB2, OUTPUT);
 }
 void loop()
 {
 	char teclado= Serial.read();
 	if(teclado=='a'){adelante();}
 	if(teclado=='s'){atras();}
 	if(teclado=='d'){detener();}
 }
