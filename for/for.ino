int tiempo = 50;
void setup(){
for (int i = 6; i <=13 ; i++)
{
    pinMode(i, OUTPUT);
}   

}

void loop(){
    int j;
    for (int i = 6, j = 13; i <= 13, j >= 6; i++, j--)
    {
        digitalWrite(i, 1);
        delay(tiempo);
        digitalWrite(i, 0);

        digitalWrite(j, 1);
        delay(tiempo);
        digitalWrite(j, 0);
}

}
