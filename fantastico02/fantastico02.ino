/* El coche fantástico2*/
 
int pinArray[] = {2, 3, 4, 5, 6, 7, 8, 9,10,11,12};
int count = 0;
int timer = 15;
//timer marca como queremos que vaya de rápido la ráfaga de encendido-apagado de los LEDS
 
void setup(){
for (count=0;count<11;count++) {
pinMode(pinArray[count], OUTPUT);
}
}
 
void loop() {
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

