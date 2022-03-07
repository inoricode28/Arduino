void setup()
{
	for(int i=2; i<=7; i++){
	pinMode(i,OUTPUT);    
	}
}
void loop()
{
	for(int i=2; i<=7; i++){
	    digitalWrite(i,HIGH);
	    delay(100);
	    digitalWrite(i,LOW);
	}
	for(int d=7; d>=2; d--){
		digitalWrite(d,HIGH);
		delay(100);
		digitalWrite(d,LOW);
	    
	}
}