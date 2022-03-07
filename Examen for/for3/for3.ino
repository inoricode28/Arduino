void setup()
{
	for(int i=2; i<=13; i++){
	    pinMode(i, OUTPUT);
	}
}

void loop()
{
	int pin,i;
	for( pin=2,i=13; pin<=7, i>=8; pin++, i--){
	    digitalWrite(pin, HIGH);
	    digitalWrite(i, HIGH);
	    delay(100);
	    digitalWrite(pin, LOW);
	    digitalWrite(i, LOW);
	}
	for( pin=7,i=8; pin>=2, i<=13; pin--, i++){
	    digitalWrite(pin, HIGH);
	    digitalWrite(i, HIGH);
	    delay(100);
	    digitalWrite(pin, LOW);
	    digitalWrite(i, LOW);
	}
}