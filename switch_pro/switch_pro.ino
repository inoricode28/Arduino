void setup() {
 //Definimos la velocidad de transferencia a 9600 baudios
 //y el pin 13 como salida
 Serial.begin(9600);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
}

void loop() {
 //Mientras el puerto serie este accesible
 while (Serial.available())
 {
 //Guardamos en dato el valor leido del puerto serie
 byte dato = Serial.read();
 switch (dato){
 //Si es '1' encendemos el led
 case '1':
 digitalWrite(8,HIGH);
 digitalWrite(9,HIGH);
 
  break;
 //Si es '0' apagamos el led
 case '0':
 digitalWrite(8,LOW);
 digitalWrite(9,LOW);
  break;
  
  case '2':
 digitalWrite(10,HIGH);
 digitalWrite(11,HIGH); 
  break;
 //Si es '0' apagamos el led
  case '3':
 digitalWrite(10,LOW);
 digitalWrite(11,LOW);
  break;
 }
 }
}
