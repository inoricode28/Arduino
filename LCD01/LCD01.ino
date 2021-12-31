#include <Ping.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR 0x27
LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);

/////////////////////////////////////////////////////////////
//VARIABLES

const int PinTrig = 7;
const int PinEcho = 6;
 
// Constante velocidad sonido en cm/s
const float VelSon = 34000.0;
 
// Número de muestras
const int numLecturas = 100;
 
const float distanciaVacio = 11.41;
// Distancia a los 100 ml y vacío
const float distancia100 = 2.15;
 
float lecturas[numLecturas]; // Array para almacenar lecturas
int lecturaActual = 0; // Lectura por la que vamos
float total = 0; // Total de las que llevamos
float media = 0; // Media de las medidas
bool primeraMedia = false; // Para saber que ya hemos calculado por lo menos una


/////////////////////////////////////////////////////////////


void setup() {
  Serial.begin(9600);
 // Ponemos el pin Trig en modo salida
  pinMode(PinTrig, OUTPUT);
  // Ponemos el pin Echo en modo entrada
  pinMode(PinEcho, INPUT);
 
  // Inicializamos el array
  for (int i = 0; i < numLecturas; i++)
  {
    lecturas[i] = 0;
  }
inicioLCD();

}


void loop() {
// Eliminamos la última medida
  total = total - lecturas[lecturaActual];
 
  iniciarTrigger();
 
  // La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso a HIGH
  unsigned long tiempo = pulseIn(PinEcho, HIGH);
 
  // Obtenemos la distancia en cm, hay que convertir el tiempo en segudos ya que está en microsegundos
  // por eso se multiplica por 0.000001
  float distancia = tiempo * 0.000001 * VelSon / 2.0;
 
  // Almacenamos la distancia en el array
  lecturas[lecturaActual] = distancia;
 
  // Añadimos la lectura al total
  total = total + lecturas[lecturaActual];
 
  // Avanzamos a la siguiente posición del array
  lecturaActual = lecturaActual + 1;
 
  // Comprobamos si hemos llegado al final del array
  if (lecturaActual >= numLecturas)
  {
    primeraMedia = true;
    lecturaActual = 0;
  }
 
  // Calculamos la media
  media = total / numLecturas;
 
  // Solo mostramos si hemos calculado por lo menos una media
  if (primeraMedia)
  {
    float distanciaLleno = distanciaVacio - media;
    float cantidadLiquido = distanciaLleno * 100 / distancia100;
    int porcentaje = (int) (distanciaLleno * 100 / distanciaVacio);
 
    // Mostramos en la pantalla LCD
    lcd.clear();
    // Cantidada de líquido
    lcd.setCursor(0, 0);
    lcd.print(String(cantidadLiquido) + " ml");
 
    // Porcentaje
    lcd.setCursor(0, 1);
    lcd.print(String(porcentaje) + " %");
 
    Serial.print(media);
    Serial.println(" cm");
 
    Serial.print(cantidadLiquido);
    Serial.println(" ml");
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Calculando: " + String(lecturaActual));
  }
 
  delay(500);
}
 
// Método que inicia la secuencia del Trigger para comenzar a medir
void iniciarTrigger()
{
  // Ponemos el Triiger en estado bajo y esperamos 2 ms
  digitalWrite(PinTrig, LOW);
  delayMicroseconds(2);
 
  // Ponemos el pin Trigger a estado alto y esperamos 10 ms
  digitalWrite(PinTrig, HIGH);
  delayMicroseconds(10);
 
  // Comenzamos poniendo el pin Trigger en estado bajo
  digitalWrite(PinTrig, LOW);
}

void inicioLCD(){
  
  lcd.begin(16,2);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  delay(1000);
  lcd.home();
  lcd.setCursor(3,0);
  lcd.print("CIENTIFICA");
  lcd.setCursor(0,1);
  lcd.print("DEL SUR");
  delay(3000);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("PEDRO");
  lcd.setCursor(6,1);
  lcd.print("ACOSTA");
  delay(3000);
  lcd.clear();
  
  }
 
