/* Coche fantático 1*/
 
int pinArray[] = {2, 3, 4, 5, 6, 7, 8, 9,10,11,12};
int count = 0;
int timer = 70;
 
void setup(){
for (count=0;count<11;count++) {
pinMode(pinArray[count], OUTPUT);
}
}
 
void loop() {
for (count=0;count<11;count++) {
digitalWrite(pinArray[count], HIGH);
delay(timer);
digitalWrite(pinArray[count], LOW);
delay(timer);
}
for (count=10;count>=0;count--) {
digitalWrite(pinArray[count], HIGH);
delay(timer);
digitalWrite(pinArray[count], LOW);
delay(timer);
}
}

