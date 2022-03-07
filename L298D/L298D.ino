

// Motor A
int ENA = 10;
int motorA1 = 9;
int motorA2 = 8;

// Motor B
int ENB = 5;
int motorB1 = 7;
int motorB2 = 6;

void adelante()
{
	//MotorA
	//PWM 8bits 0-255(0%-100%)
	digitalWrite(ENA, 255);
	digitalWrite(motorA1, HIGH);
	digitalWrite(motorA2, LOW);

	//MotorB
	digitalWrite(ENB, 255);
	digitalWrite(motorB1, LOW);
	digitalWrite(motorB2, HIGH);
}

void atras()
{
	//MotorA
	//PWM 8bits 0-255(0%-100%)
	digitalWrite(ENA, 255);
	digitalWrite(motorA1, LOW);
	digitalWrite(motorA2, HIGH);

	//MotorB
	digitalWrite(ENB, 255);
	digitalWrite(motorB1, HIGH);
	digitalWrite(motorB2, LOW);
}

void detener()
{
	//MotorA
	//PWM 8bits 0-255(0%-100%)
	digitalWrite(ENA, 0);
	digitalWrite(motorA1, LOW);
	digitalWrite(motorA2, LOW);

	//MotorB
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
	
char teclado =Serial.read();
if(teclado=='a'){adelante();}
if(teclado=='s'){atras();}
if(teclado=='d'){detener();}

}

