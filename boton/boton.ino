int boton =2, PULLUP_boton=3, PULLDONW_boton=4,BTN1=5,BTN2=6,BTN3=7,BTN4=8;

void setup()
{
	pinMode(boton, INPUT_PULLUP);
	pinMode(PULLUP_boton, INPUT);
	pinMode(PULLDONW_boton, INPUT);
	pinMode(BTN1, OUTPUT);
	pinMode(BTN2, OUTPUT);
	pinMode(BTN3, OUTPUT);
	pinMode(BTN4, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	char teclado =Serial.read();

	if(teclado=='a'){
		digitalWrite(BTN1, HIGH);
		digitalWrite(BTN2, LOW);
	}
	if(teclado=='s'){
		digitalWrite(BTN2, HIGH);
		digitalWrite(BTN1, LOW);
	}
	if(teclado=='d'){
		digitalWrite(BTN2, LOW);
		digitalWrite(BTN1, LOW);
		digitalWrite(BTN3, LOW);	
		digitalWrite(BTN4, LOW);    
	}
    if(teclado=='f'){
    	digitalWrite(BTN3,HIGH);
    	digitalWrite(BTN4,LOW);
    } 
    if(teclado=='g'){
    	digitalWrite(BTN4,HIGH);
    	digitalWrite(BTN3,LOW);
    }

	//int x =!digitalRead(boton);
	//int y =!digitalRead(PULLUP_boton);
	//int z =!digitalRead(PULLDONW_boton);
	//Serial.println(x);
	//Serial.println(y);
	//Serial.println(z);
	//delay(100);
}

