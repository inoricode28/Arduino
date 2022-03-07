/* Estrella Fugaz
 
*---------------
* Este programa es una variante del ejemplo del coche
* fantástico. Muestra mediante un loop una estrella
* fugaz que es dibujada en una linea de LED-s
* directamente conectados a la placa Arduino
*
* Puedes controlar la velocidad a la que la estrella
* se mueve gracias a una variable llamada "waitNextLed"
*
* También puedes controlar la longitud de la cola
* de la estrella a través de la variable "tail length"
*
* @author: Miguel Alfonzo Chavez Ramos
*
*/
// Declaracion de Variables
 
int pinArray [] = { 2,3,4,5,6,7,8,9,10,11,12 }; // Declaración de los PIN-es mediante un array
int controlLed = 13; // LED de control
int waitNextLed = 100; // Tiempo antes de encender el siguiente LED
int tailLength = 4; // Número de LED-s que permanecen encendidos antes de empezar a apagarlos para formar la cola
int lineSize = 11; // Número de LED-s conectados (que es también el tamaño del array)
 
void setup() // Configuración de los PIN-es como salida digital
{
  Serial.begin(9600);
int i;
pinMode (controlLed, OUTPUT);
for (i=0; i< lineSize; i++)
{
pinMode(pinArray[i], OUTPUT);
}

}
 
void loop()
{
  char datos = Serial.read();
  if(datos=='a'){fugas();}
  if(datos=='s'){fantastico();fantastico();fugas();}
  if(datos=='d'){fugas2();}
 
}

void fantastico(){
int count = 0;
int timer = 15;
  
for (count=0;count<10;count++) {
digitalWrite(pinArray[count], HIGH);
delay(timer);
digitalWrite(pinArray[count + 1], HIGH);
delay(timer);
digitalWrite(pinArray[count], LOW);
delay(timer*2);
}
for (count=10;count>0;count--) {
digitalWrite(pinArray[count], HIGH);
delay(timer);
digitalWrite(pinArray[count - 1], HIGH);
delay(timer);
digitalWrite(pinArray[count], LOW);
delay(timer*2);
}  
  }

  
void fugas(){
  
int i;
int tailCounter = tailLength; // Se establece la longitud de la cola en un contador
digitalWrite(controlLed, HIGH); // Se enciende el LED de control para indicar el inicio del loop
 
for (i=0; i<lineSize; i++)
{
digitalWrite(pinArray[i],HIGH); // Se encienden consecutivamente los LED
delay(waitNextLed); // Esta variable de tiempo controla la velocidad a la que se mueve la estrella
if (tailCounter == 0)
{
digitalWrite(pinArray[i-tailLength],LOW); // Se apagan los LED-s en función de la longitud de la cola.
}
else
if (tailCounter > 0)
tailCounter--;
}
 
for (i=(lineSize-tailLength); i<lineSize; i++)
{
digitalWrite(pinArray[i],LOW); // Se apagan los LED
delay(waitNextLed); // Esta variable de tiempo controla la velocidad a la que se mueve la estrella
}  
  }


void fugas2(){
  
int i;
int tailCounter = tailLength; // Se establece la longitud de la cola en un contador
digitalWrite(controlLed, HIGH); // Se enciende el LED de control para indicar el inicio del loop
 
for (i=0; i<lineSize; i++)
{
digitalWrite(pinArray[i],HIGH); // Se encienden consecutivamente los LED
delay(waitNextLed); // Esta variable de tiempo controla la velocidad a la que se mueve la estrella
if (tailCounter == 0)
{
digitalWrite(pinArray[i-tailLength],LOW); // Se apagan los LED-s en función de la longitud de la cola.
}
else
if (tailCounter > 0)
tailCounter--;
}
 
for (i=(lineSize-tailLength); lineSize>i; i++)
{
digitalWrite(pinArray[i],LOW); // Se apagan los LED
delay(waitNextLed); // Esta variable de tiempo controla la velocidad a la que se mueve la estrella
}  
  }

