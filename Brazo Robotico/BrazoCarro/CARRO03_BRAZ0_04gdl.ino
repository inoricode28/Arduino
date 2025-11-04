 
 #include <Servo.h>
 
char dato;
Servo Cintura, Hombro1, Codo, Pinzas;
int pcintura, phombro1, pcodo, ppinzas, contador=0;


#define Pecho A1
#define Ptrig A0

long duracion, distancia;   


int Izq2 = 11;
int Izq1 = 10;
int Der2 = 9;
int Der1 = 8;

void setup()
{       

Cintura.attach(2);
Hombro1.attach(3);
Codo.attach(4);
Pinzas.attach(5);
 
   
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  
  pinMode(Izq2, OUTPUT);     
  pinMode(Izq1, OUTPUT);   
  pinMode(Der2, OUTPUT);     
  pinMode(Der1, OUTPUT);   
   
  digitalWrite(Izq2, LOW);
  digitalWrite(Izq1, LOW);
  digitalWrite(Der2, LOW);
  digitalWrite(Der1, LOW);
}
  
void loop()
{
  
  if(contador==0)
 { 
  //Leer posicion inicial de cada servo para evitar movimientos bruscos 
  pcintura=Cintura.read();
  phombro1=Hombro1.read();
  pcodo=Codo.read();
  ppinzas=Pinzas.read();  
  //Escribir la posicion en cada servo
  Cintura.write(pcintura);
  Hombro1.write(phombro1);
  Codo.write(pcodo);
  Pinzas.write(ppinzas);
  
  contador++;
 } 
 
 leer_distancis();
 leer_celular();
// Serial.println("leer celular"); 
 }   
    



void leer_distancis(){
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
  Serial.println(distancia);           // envia el valor de la distancia por el puerto serial
 // Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
  
}
void retroceder(){
    // Serial.println("retroceso");       
         digitalWrite(Izq2, HIGH);
         digitalWrite(Izq1, LOW);
         digitalWrite(Der2, HIGH);
         digitalWrite(Der1, LOW);          
}

void izquierda(){
    // Serial.println("izquierda");       
         digitalWrite(Izq2, HIGH);
         digitalWrite(Izq1, LOW);
         digitalWrite(Der2, LOW);
         digitalWrite(Der1, HIGH);          
}
void derecha(){
     //Serial.println("derecha");       
         digitalWrite(Izq2, LOW);
         digitalWrite(Izq1, HIGH);
         digitalWrite(Der2, HIGH);
         digitalWrite(Der1, LOW);         
}

void adelante(){
     // Serial.println("adelante");       
         digitalWrite(Izq2, LOW);
         digitalWrite(Izq1, HIGH);
         digitalWrite(Der2, LOW);
         digitalWrite(Der1, HIGH);          
}
void detener(){
      //Serial.println("detener");       
         digitalWrite(Izq2, LOW);
         digitalWrite(Izq1, LOW);
         digitalWrite(Der2, LOW);
         digitalWrite(Der1, LOW);         
  
}

void leer_celular(){
dato='s'; 
 dato = Serial.read();
 switch(dato)
 {
   
   //------------seccion inicio carrito-----------
   case 'A': //--carrito adelatne
    {
     while(Serial.read()!='s')
      {
      leer_distancis();
    // distancia=25;
       if (distancia >= 20 )       {
            //  Serial.print(distancia);           
            //  Serial.println("cm");             
              adelante();                   
            }
           if (distancia < 20 )     {
              //Serial.print(distancia);          
             // Serial.println("cm"); 
              Serial.println("detener");  
                 digitalWrite(Izq2, LOW);
                 digitalWrite(Izq1, LOW);
                 digitalWrite(Der2, LOW);
                 digitalWrite(Der1, LOW);             
                detener();                    
            }
      }   
    detener();  
    break;  
    }
    
     case 'a': //--carrito retroceder
    {
     while(Serial.read()!='s')   {
      retroceder();  
      }   
      detener();  
    break;  
    }
    
       case 'I': //--carrito adelatne
    {
     while(Serial.read()!='s')  {
      izquierda();  
      }      
      detener();  
    break;  
    }
    
    case 'D': //--carrito adelatne
    {
      while(Serial.read()!='s')
      {
      derecha();  
      }  
      detener();  
    break;  
    
    }
     
   //-----------seccion fin de carrito------------
    //----------seccion inicio brazo-------------
   
    //control pinza
    case 'P': //abrir pinza
    {
       while(Serial.read()!='s')
       {
          if(ppinzas>=175)
              ppinzas=175;
          if(ppinzas<=180 && ppinzas>=0)
          {
            
            ppinzas++;
            Pinzas.write(ppinzas);
            delay(15);
          }
       }
      break;  
    }
    
    case 'p': //cerrar pinza
    {
       while(Serial.read()!='s')
       {
         if(ppinzas<=5)
              ppinzas=5; 
         if(ppinzas<=180 && ppinzas>=0)
          {
            ppinzas--;
            Pinzas.write(ppinzas);
            delay(15);
          }
      }
      break;  
    }
    
    case 'b': //arriba brazo
    {
       while(Serial.read()!='s')
       {
          if(pcodo>=175)
              pcodo=175;
          if(pcodo<=180 && pcodo>=0)
          {
            
            pcodo++;
            Codo.write(pcodo);
            delay(15);
          }
       }
      break;  
    }
    
    case 'B': //abajo brazo
    {
       while(Serial.read()!='s')
       {
         if(pcodo<=5)
              pcodo=5; 
         if(pcodo<=180 && pcodo>=0)
          {
            pcodo--;
            Codo.write(pcodo);
            delay(15);
          }
      }
      break;  
    }
    
    //control hombro1
    case 'H': //arriba hombro
    {
       while(Serial.read()!='s')
       {
          if(phombro1>=175)
              phombro1=175;
          if(phombro1<=180 && phombro1>=0)  {          
            phombro1++;           
            Hombro1.write(phombro1);
          
            delay(15);
          }
       }
      break;  
    }
    
    case 'h': //abajo hombro
    {
       while(Serial.read()!='s')
       {
         if(phombro1<=5)
              phombro1=5;  
         if(phombro1<=180 && phombro1>=0)
          {
            phombro1--;
            
            Hombro1.write(phombro1);
            delay(15);
          }
      }
      break;  
    }
    
    //control cintura
    case 'C': //derecha cintura
    {
       while(Serial.read()!='s')
       {
          if(pcintura>=175)
              pcintura=175;
          if(pcintura<=180 && pcintura>=0)
          {
            
            pcintura++;
            Cintura.write(pcintura);
            delay(15);
          }
       }
      break;  
    }
    
    case 'c': //izquierda cintura
    {
       while(Serial.read()!='s')
       {
         if(pcintura<=5)
              pcintura=5; 
         if(pcintura<=180 && pcintura>=0)
          {
            pcintura--;
            Cintura.write(pcintura);
            delay(15);
          }
      }
      break;  
    }
    
        //----------seccion fin brazo-------------
}
 }
