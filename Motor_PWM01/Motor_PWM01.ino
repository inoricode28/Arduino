 
int pin2=9;   //Entrada 2 del L293D
int pin7=10; 
int pin3=5;
int pin4=6; //Entrada 7 del L293D
int pote=A0;
int pote1=A1; 
  //Potenciómetro
 
int valorpote;
int valorpote1;     //Variable que recoge el valor del potenciómetro
int pwm1;          //Variable del PWM 1
int pwm2;          //Variable del PWM 2
int pwm3;          //Variable del PWM 1
int pwm4; 
void setup()
{
 
  pinMode(pin2,OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}
 
void loop()
{
 
  
  valorpote=analogRead(pote);
  valorpote1=analogRead(pote1);
 
  pwm1 = map(valorpote, 0, 1023, 0, 255);
  pwm2 = map(valorpote, 0, 1023, 255, 0);
  pwm3 = map(valorpote1, 0, 1023, 0, 255);
  pwm4 = map(valorpote1, 0, 1023, 255, 0);
  
  analogWrite(pin2,pwm1);
  analogWrite(pin7,pwm2);
  analogWrite(pin3,pwm3);
  analogWrite(pin4,pwm4);
}
