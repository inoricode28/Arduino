#include <Servo.h>
char dato;

Servo Cintura, Hombro1, Codo, Pinzas;
int pcintura, phombro1, pcodo, ppinzas, contador=0;
int j_cintura, j_hombro1, j_codo, j_pinza;

void setup() 
{
  
 Cintura.attach(3);
 Hombro1.attach(4);
 Codo.attach(6);
 Pinzas.attach(9);
 
 Serial.begin(9600);
}
void loop() 
{
  //----------INICIO DE LECTURA DEL JOYSTICK------------------
        j_cintura = analogRead(0); 
	j_cintura = map(j_cintura, 0, 1023, 10, 90); 
	      j_hombro1 = analogRead(1);
	j_hombro1 = map(j_hombro1, 0, 1023, 10, 90);
        j_codo    = analogRead(2);
	j_codo    = map(j_codo, 0, 1023, 10, 90);
        j_pinza   = analogRead(3);
	j_pinza   = map(j_pinza, 0, 1023, 10, 90);

configurar();
  
  //----------FIN    DE LECTURA DEL JOYSTICK------------------
  
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

}

void configurar(){
  
  
//--- INICIO CINTURA---------------------  
  if(j_cintura <= 20){
          if(pcintura>=175)
              pcintura=175;
          if(pcintura<=180 && pcintura>=0)
          {           
            pcintura++;
            Cintura.write(pcintura);
            delay(15);
          }

	}
//---------------------------------------
  if(j_cintura >= 80){
        if(pcintura<=5)
              pcintura=5; 
         if(pcintura<=180 && pcintura>=0)
          {
            pcintura--;
            Cintura.write(pcintura);
            delay(15);
          }
			
	}
//--- FIN CINTURA------------------------  

//--- INICIO HOMBRO1 Y 2---------------------  
  if(j_hombro1 <= 20){  //arriba hombro
  
         if(phombro1>=175)
              phombro1=175;
          if(phombro1<=180 && phombro1>=0)
         {
            
            phombro1++;
            Hombro1.write(phombro1);
            //Hombro2.write(phombro1);
          
            delay(15);
          }
   
	}
  if(j_hombro1 >= 80){  //bajar hombro
  
    if(phombro1<=5)
              phombro1=5;  
         if(phombro1<=180 && phombro1>=0)
          {
            phombro1--;
            Hombro1.write(phombro1);
           // Hombro2.write(phombro1);
            delay(15);
          }
  
  			
	}
//---  FIN HOMBRO1 Y 2------------------------  


//--- INICIO CODO --------------------  
  if(j_codo <= 20){   // arriba codo
    if(pcodo>=175)
              pcodo=175;
          if(pcodo<=180 && pcodo>=0)
          {
            
            pcodo++;
            Codo.write(pcodo);
            delay(15);
          }
  
  
   
	}
  if(j_codo >= 80){  // abajo codo
   if(pcodo<=5)
              pcodo=5; 
         if(pcodo<=180 && pcodo>=0)
          {
            pcodo--;
            Codo.write(pcodo);
            delay(15);
          }
  
  	
	}
//---  FIN CODO ------------------------  

//--- INICIO PINZA --------------------  
  if(j_pinza <= 20){  //abrir pinza
  
    if(ppinzas>=175)
              ppinzas=175;
          if(ppinzas<=180 && ppinzas>=0)
          {
            
            ppinzas++;
            Pinzas.write(ppinzas);
            delay(15);
          }
    
   
	}
  if(j_pinza >= 80){  // cerrar pinza
  
   if(ppinzas<=5)
              ppinzas=5; 
         if(ppinzas<=180 && ppinzas>=0)
          {
            ppinzas--;
            Pinzas.write(ppinzas);
            delay(15);
          }
  
  	
	}
//---  FIN  PINZA ------------------------  

  
}

