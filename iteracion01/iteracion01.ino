void setup()
{
	for(int i=2; i<=13; i++){
	pinMode(i, OUTPUT);	
	    
	}
}
 void loop()
 {
 	int g;

 	for(int i=2, g=13; i<=13, g>=2; i++, g--){//METODO CRUZADO
 		digitalWrite(i, HIGH);
 		digitalWrite(g, HIGH);
 		delay(100);
 		digitalWrite(i, LOW);
 		digitalWrite(g, LOW); 	    
 	}

 }
