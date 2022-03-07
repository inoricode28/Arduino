int tiempo = 50;
int pin;

void setup()
{
  for( pin = 2; pin <= 12; pin++)
  {
    
    pinMode(pin,OUTPUT);
    
  }
}

void loop()
{
 for( pin = 2; pin <= 12; pin++)
  {
    
    pinMode(pin,OUTPUT);
    digitalWrite(pin,HIGH);
    delay(tiempo);
    digitalWrite(pin,LOW);
  }
  
  for( pin = 12; pin >= 2; pin--)
  {
    
    pinMode(pin,OUTPUT);
    digitalWrite(pin,HIGH);
    delay(tiempo);
    digitalWrite(pin,LOW);
  }
  
}
