String mensaje;

void setup() {
Serial.begin(9600);
pinMode(8,OUTPUT);

}

void loop() {

 while(Serial.available()){
    delay(10);
     char c = Serial.read();
      mensaje += c;
}
if(mensaje.length()>0){
if(mensaje=="*prende led"){digitalWrite(8,HIGH);}
else if (mensaje=="*apaga led"){digitalWrite(8,LOW);}
}
mensaje="";
}
