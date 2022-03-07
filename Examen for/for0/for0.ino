void setup()
{
	for(int i=2; i<=7; i++){//Iteracion que permite un conteo desde el pin 2 al pin 7
	pinMode(i,OUTPUT);//permite la salida iterada del pin 2 al pin 7    
	}
}
void loop()
{
	for(int i=2; i<=7; i++){//Conteo de pin 2 hasta el pin 7
	    digitalWrite(i,1);//Encendera los led del pin 2 al pin 7 de uno en uno 
	    delay(50);// tiempo de espera
	    digitalWrite(i,0); //apagara los led del pin 2 al pin 7 de uno en uno
	}
}