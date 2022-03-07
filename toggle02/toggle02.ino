int led01=2 , led02=3, led03=4 , led04=5 , led05=6 , led06=7 , led07=8 , led08=9 , led09=10 , led10=11 , led11=12 , led12=13;
boolean ledOn01=false, ledOn02=false, ledOn03=false , ledOn04=false ,ledOn05=false , ledOn06=false , ledOn07=false , ledOn08=false , ledOn09=false , ledOn10=false , ledOn11=false , ledOn12=false;
void toggle01(int Led)
{ 
	ledOn01 =! ledOn01;
	digitalWrite(Led, ledOn01);
}
void toggle02(int Led)
{
	ledOn02 =! ledOn02;
	digitalWrite(Led, ledOn02);
}
void toggle03(int Led)
{ 
	ledOn03 =! ledOn03;
	digitalWrite(Led, ledOn03);
}
void toggle04(int Led)
{ 
	ledOn04 =! ledOn04;
	digitalWrite(Led, ledOn04);
}
void toggle05(int Led)
{ 
	ledOn05 =! ledOn05;
	digitalWrite(Led, ledOn05);
}
void toggle06(int Led)
{ 
	ledOn06 =! ledOn06;
	digitalWrite(Led, ledOn06);
}
void toggle07(int Led)
{ 
	ledOn07 =! ledOn07;
	digitalWrite(Led, ledOn07);
}
void toggle08(int Led)
{ 
	ledOn08 =! ledOn08;
	digitalWrite(Led, ledOn08);
}
void toggle09(int Led)
{ 
	ledOn09 =! ledOn09;
	digitalWrite(Led, ledOn09);
}
void toggle10(int Led)
{ 
	ledOn10 =! ledOn10;
	digitalWrite(Led, ledOn10);
}
void toggle11(int Led)
{ 
	ledOn11 =! ledOn11;
	digitalWrite(Led, ledOn11);
}
void toggle12(int Led)
{ 
	ledOn12 =! ledOn12;
	digitalWrite(Led, ledOn12);
}
void setup()
{
	Serial.begin(9600);
	pinMode(led01, OUTPUT);
	pinMode(led02, OUTPUT);
	pinMode(led03, OUTPUT);
	pinMode(led04, OUTPUT);
	pinMode(led05, OUTPUT);
	pinMode(led06, OUTPUT);
	pinMode(led07, OUTPUT);
	pinMode(led08, OUTPUT);
	pinMode(led09, OUTPUT);
	pinMode(led10, OUTPUT);
	pinMode(led11, OUTPUT);
	pinMode(led12, OUTPUT);
}
void loop()
{
	char teclado = Serial.read();
	if(teclado=='a'){toggle01(led01);}
	if(teclado=='s'){toggle02(led02);}
	if(teclado=='d'){toggle03(led03);}
	if(teclado=='f'){toggle04(led04);}
	if(teclado=='g'){toggle05(led05);}
	if(teclado=='h'){toggle06(led06);}
	if(teclado=='j'){toggle07(led07);}
	if(teclado=='k'){toggle08(led08);}
	if(teclado=='l'){toggle09(led09);}
	if(teclado=='z'){toggle10(led10);}
	if(teclado=='x'){toggle11(led11);}
	if(teclado=='c'){toggle12(led12);}
}