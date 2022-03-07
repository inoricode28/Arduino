const int analogInPin = A0; //Analogico
const int analogOutPin = 3; // " ~ " PWM Modulacion de ancho de pulso
int potValor =0;//Potenciomentro
int OutputValor=0;

void setup() {
Serial.begin(9600);  

}

void loop() {
  potValor=analogRead(analogInPin);
  OutputValor=map(potValor, /*analog*/ 0, 1023, /*digital*/ 0, 255);
  analogWrite(analogOutPin, OutputValor);

  //analogico --> 2 a la 10 = 0 - 1023 (10bits)
  //digital --> 2 a la 8 = 0 - 255 (8bits)
  Serial.print("Potenciometroi = ");
  Serial.print(potValor);
  Serial.print("\t PWM = ");
  Serial.println(OutputValor);
  delay(100);

}