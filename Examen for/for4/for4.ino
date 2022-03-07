void setup()
{
	for(int i=2; i<13; i++){
	    pinMode(i, OUTPUT);
	}
}

void loop()
{
	int pin,i;
	for( i=2,pin=13; i<=13,pin>=2; i++,i--){
	    digitalWrite(i, HIGH);
	    digitalWrite(pin, HIGH);
	    delay(100);
	    digitalWrite(i, LOW);
	    digitalWrite(pin, LOW);
	}
}