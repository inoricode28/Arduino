int Contador = 0;
String Cadena;
int ValInt = 0;
float ValFloat = 0.00; char floatbuf[32]; //Suficientemente grande para que quepa la cadena

void setup() {Serial.begin(9600);}

void loop()
{
  if (Serial.available())
  {
    Cadena = Serial.readString();                     //Lee lo que se halla en el puerto
    Serial.print("He recibido: ");
    Serial.println(Cadena);
    
    ValInt = Cadena.toInt();                          //Convertir a entero
    if (ValInt)  Serial.println(ValInt * 2);    
    
    Cadena.toCharArray(floatbuf, sizeof(floatbuf));  //Convertir primero a char
    ValFloat = atof(floatbuf);                       //Convertir ahora a float
    if (!ValFloat == 0) Serial.println(ValFloat * 2);
  }
  Cadena.toUpperCase();
  if (Cadena == "0") {Serial.println("Recibi­ un cero");}
  if (Cadena == "ABRIR") {Serial.println("Comando ABRIR aceptado");} 
  if (Cadena == "CERRAR") {Serial.println("Comando CERRAR aceptado");} 
  Cadena = "";    
  //delay(1000);
  //Serial.print("Contando: ");
  //Serial.println(Contador, DEC);
  //Contador++;
}

