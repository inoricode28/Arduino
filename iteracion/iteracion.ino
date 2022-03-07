void setup()
{
	for(int i=2; i<=13; i++){
		pinMode(i, OUTPUT);//Modo Salida	    
	}
}

void loop()
{
	for(int i=2; i<=13; i++){//Va a iterar de uno en uno
		digitalWrite(i, HIGH);//Encendido
		delay(100);//tiempo de espera
		digitalWrite(i, LOW); //apagado
	    
	}
}

