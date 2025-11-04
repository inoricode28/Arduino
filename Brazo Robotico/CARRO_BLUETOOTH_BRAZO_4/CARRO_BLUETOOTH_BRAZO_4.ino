#include <Servo.h>
Servo Cintura,    Hombro1,     Hombro2,     Pinzas;
int pcintura=100, phombro1=90, phombro2=90, ppinzas=28;

#include <Ultrasonic.h>
Ultrasonic ultrasonic(A0, A1); //Trig= 2   Echo=  3
int distancia, contt, estado;
int motor1A = 12,   motor2A = 11,   motor1B = 10,   motor2B = 9;
int PWMA=6,         PWMB=5,         velo=150,       dato;
int led=8,leda=A3,bufer=A5,contat=0;
void setup(){
   Serial.begin (9600);
   pinMode(motor1A, OUTPUT); pinMode(motor2A, OUTPUT); pinMode(motor1B, OUTPUT); pinMode(motor2B, OUTPUT);  
   pinMode(led,OUTPUT);pinMode(leda,OUTPUT);  pinMode(bufer,OUTPUT); 
   Cintura.attach(2);
   Hombro1.attach(3);
   Hombro2.attach(4);
   Pinzas.attach(7);
   ////////////////////////////////////
   Cintura.write(pcintura);
   Hombro1.write(phombro1);
   Hombro2.write(phombro2);
   Pinzas.write(ppinzas); 
   }
void loop() 
   {   
      dato='a';
      sensorr();
      //ultrasonido();
      digitalWrite(led,0);digitalWrite(leda,0);
      if(Serial.available() > 0){
       dato = Serial.read();
       if(dato<10){velo = map(dato, 0, 9, 0, 255);}
       if (dato == 'b') {while(Serial.read()!='a'){  
                            //delante();
                            digitalWrite(led,1);
                            atras();
                            ultrasonido();
                            Serial.println();
                        }}
       if (dato == 'c') {while(Serial.read()!='a'){   
                            //atras();
                            delante();contat++;
                            delay(5);
                            Serial.println(contat);
                            if(contat==1){digitalWrite(bufer,1);digitalWrite(leda,1); }
                            if(contat==100){digitalWrite(bufer,0);digitalWrite(leda,0); }
                            if(contat==200){contat=0;}
                        }}
       if (dato == 'd') {while(Serial.read()!='a'){  
                            //izquierda();  
                            derecha();                       
                        }}

       if (dato == 'e') {while(Serial.read()!='a'){ 
                            //derecha();
                            izquierda();
                        }} 
       if (dato == 'f') /*abrir pinza*/{while(Serial.read()!='a'){
          if(ppinzas<=20) ppinzas=20; 
          if(ppinzas<=180 && ppinzas>=0){
            ppinzas--;
            Pinzas.write(ppinzas);
            Serial.println("abrir pinza");
            Serial.println(ppinzas);
            delay(15);       }} 
            
                              }
       if (dato == 'g')/*cerrar pinza*/{ while(Serial.read()!='a'){
          if(ppinzas>=110) ppinzas=110;
          if(ppinzas<=180 && ppinzas>=0){
            ppinzas++;
            Pinzas.write(ppinzas);
            Serial.println("cerrar pinza");
            Serial.println(ppinzas);
            delay(15);        }}
                              }  
       if (dato == 'h')/*abajo hombro1*/{while(Serial.read()!='a'){
         if(phombro1<=5)phombro1=5;  
         if(phombro1<=180 && phombro1>=0) {
            phombro1--;
            Hombro1.write(phombro1);
            Serial.println("abajo hombro");
            Serial.println(phombro1);
            delay(15);    }} 
                           }
       if (dato == 'i')/*arriba hombro1*/{while(Serial.read()!='a'){
          if(phombro1>=175)phombro1=175;
          if(phombro1<=180 && phombro1>=0) {
            phombro1++;
            Hombro1.write(phombro1);
            Serial.println("arriba hombro");
            Serial.println(phombro1);
            delay(15);     }}
                            }                           
      if (dato == 'j') /*arriba hombro2*/{while(Serial.read()!='a'){
          if(phombro2>=175)phombro2=175;
          if(phombro2<=180 && phombro2>=0){
             phombro2++;
             Hombro2.write(phombro2);
             Serial.println("abajo codo");
             Serial.println(phombro2);
             delay(15);      }} 
                             }
      if (dato == 'k') /*arriba hombro2*/{while(Serial.read()!='a'){
         if(phombro2<=5) phombro2=5; 
         if(phombro2<=180 && phombro2>=0){
            phombro2--;
            Hombro2.write(phombro2);
            Serial.println("arriba codo");
            Serial.println(phombro2);
            delay(15);      }}
                             }
    if (dato == 'l') /*izquierda cintura*/{while(Serial.read()!='a'){
          if(pcintura>=175) pcintura=175;
          if(pcintura<=180 && pcintura>=0) {
            pcintura++;
            Cintura.write(pcintura);
            Serial.println("derecha cintura");
            Serial.println(pcintura);
            delay(15);    }} 
                           }
    
    if (dato == 'm') /*derecha cintura*/{while(Serial.read()!='a'){
         if(pcintura<=5)pcintura=5; 
         if(pcintura<=180 && pcintura>=0){
            pcintura--;
            Cintura.write(pcintura);
            Serial.println("izquierda cintura");
            Serial.println(pcintura);
            delay(15);    }}
                           }   
     if (dato == 'n') /*derecha cintura*/{while(Serial.read()!='a'){
            digitalWrite(led,!digitalRead(led)); 
                          }}
                            
      }
     paro();   
     //atras();
     Serial.print(" VELO=");
     Serial.println(velo);
   }
  void delante(){
   digitalWrite(motor1A, HIGH);
   digitalWrite(motor2A, LOW);
   digitalWrite(motor1B, LOW);
   digitalWrite(motor2B, HIGH); 
   analogWrite(PWMA,velo);
   analogWrite(PWMB,velo);    
    }
   void atras(){
   digitalWrite(motor1A, LOW);
   digitalWrite(motor2A, HIGH);
   digitalWrite(motor1B, HIGH);
   digitalWrite(motor2B, LOW); 
   analogWrite(PWMA,velo);
   analogWrite(PWMB,velo);
    }
   void izquierda(){
   digitalWrite(motor1A, HIGH);
   digitalWrite(motor2A, LOW);
   digitalWrite(motor1B, HIGH);
   digitalWrite(motor2B, LOW); 
   analogWrite(PWMA,velo);
   analogWrite(PWMB,velo);
    }
    void derecha(){
   digitalWrite(motor1A, LOW);
   digitalWrite(motor2A, HIGH);
   digitalWrite(motor1B, LOW);
   digitalWrite(motor2B, HIGH);   
   analogWrite(PWMA,velo);
   analogWrite(PWMB,velo);
    }
    void paro(){
   digitalWrite(motor1A, LOW);
   digitalWrite(motor2A, LOW);
   digitalWrite(motor1B, LOW);
   digitalWrite(motor2B, LOW); 
   analogWrite(PWMA,0);
   analogWrite(PWMB,0);
      }
    
void ultrasonido() {      
  Serial.print(" Distance in CM: ");
  distancia=ultrasonic.distanceRead();
  Serial.print(distancia);
   if(distancia<=30){
      paro();
     /* delay(100); 
      atras();
      delante();
      delay(200);
      izquierda();*/
      delay(1000);    
                   }
}
void sensorr(){
  Serial.print(analogRead(A2));
  if(analogRead(A2)<=100){digitalWrite(bufer,1);delay(20);digitalWrite(bufer,0);delay(20);  }
  else{digitalWrite(bufer,0);}
}

