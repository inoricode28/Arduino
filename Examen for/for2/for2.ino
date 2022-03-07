void setup()
{
	for(int i=2; i<=13; i++){
	 	pinMode(i, OUTPUT);
	}
}

void loop()
{
	int pin,i;
	for(int pin=2, i=13; pin<=7, i>=8; pin++, i--){//error
	    digitalWrite(pin, HIGH);
	    digitalWrite(i, HIGH);
	    delay(100);
	    digitalWrite(pin, LOW);
	    digitalWrite(i, LOW);
	}
	for(int pin=7, i=8; pin>=2,i<=13; pin--,i++){//error
	    digitalWrite(pin, HIGH);
	    digitalWrite(i, HIGH);
	    delay(100);
	    digitalWrite(pin, LOW);
	    digitalWrite(i, LOW);	    
	}
}
