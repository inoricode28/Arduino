//int led01=2, led02=3, led03=4, led04=5, led05=6,led06=7, led07=8, led08=9, led09=10, led10=11, led11=12, led12=13;

void setup()
{
	for(int i=2; i<=13; i++){
	pinMode(i, OUTPUT);	
	 }    
    
}

void loop()
{
	int g;

 	for(int i=2, g=13; i<=13, g>=2; i++, g--)
 	{//METODO CRUZADO
 		digitalWrite(i, HIGH);
 		digitalWrite(g, HIGH);
 		delay(100);
 		digitalWrite(i, LOW);
 		digitalWrite(g, LOW); 	    
 	}

}