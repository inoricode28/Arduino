int amarillo=13, verde=12, azul=11;
char dato;
void setup(){
  Serial.begin(9600);
  pinMode(amarillo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(azul,OUTPUT);
}
void loop(){
 
 
  if(Serial.available()>0){
     dato = Serial.read();
    if(dato== 'a'){digitalWrite(amarillo,HIGH);}
    if(dato== 'b'){digitalWrite(verde,HIGH);}
    if(dato== 'c'){digitalWrite(azul,HIGH);}
    if(dato== 'd'){
      digitalWrite(amarillo,0);
      digitalWrite(verde,0);
      digitalWrite(azul,0);
            
      }
 Serial.print(dato);
    }
  
}
