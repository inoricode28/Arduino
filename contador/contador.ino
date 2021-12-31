int LED = 13;
int Boton = 7;
int valor = 0;
int contador = 0;
int estadoanteriorboton = 0;
 
void setup()
{
Serial.begin(9600); // Configura velocidad de transmisión a 9600
pinMode(LED, OUTPUT); // inicializa como salida digital el pin 13
pinMode(Boton, INPUT); // inicializa como entrada digital el 7
}
 
void loop()
{
valor = digitalRead(Boton); // lee el valor de la entrad digital pin 7
digitalWrite(LED, valor);
if(valor!= estadoanteriorboton){
 
if(valor == HIGH){
contador++;
Serial.println(contador);
if (contador == 10) {
contador = 0;
  }
 }
}
estadoanteriorboton = valor;
}