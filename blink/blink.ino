int led=13,tiempo=100;
void setup() {
  pinMode(led,OUTPUT);

}

void loop() {
  digitalWrite(led,1);
  delay(tiempo);
  digitalWrite(led,0);
  delay(tiempo);

}
