#include <iostream>
#include "SerialClass.h"

using namespace std;
int menu();
void amarillo();
void verde();
void azul();
void apagar();
//Nomenclatura para crear conexcion con los puertos COM1 - COM9
Serial* Arduino = new Serial("COM4");
/*Nomenclatura para crear con los puertos COM10 en adelante
Serial* Arduino =new Serial("\\\\.\\COM10")*/
int main(){
// Título de la ventana
SetConsoleTitle("Control Led Arduino - Dev C++");
	int op;
	while(op !=5){
		op = menu();
		switch(op){
			case 1: amarillo();
			break;
			case 2: verde();
			break;
			case 3: azul();
			break;
			case 4: apagar();
			break;
			case 5: cout<<"Hasta Pronto"<<endl;
			break;
		}
	}
}
int menu(){
	int op;
	string opciones[]{
	"Encender led amarillo",
	"Encender led verde",
	"Encender led Azul",
	"Apagar leds",
	"Salir del programa"};
	cout<<"---------------------MENU---------------------"<<endl;
	cout<<"--    1.- " + opciones[0]<<endl;
	cout<<"--    2.- " + opciones[1]<<endl;
	cout<<"--    3.- " + opciones[2]<<endl;
	cout<<"--    4.- " + opciones[3]<<endl;
	cout<<"--    5.- " + opciones[4]<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"--    Elije una Opcion >>> ";cin>>op;
	cout<<"\n\tUd. ha elejido ";
	cout<<" '" + opciones[op-1] + "' "<<"\n" <<endl;	
	//cout<<"----------------------------------------------";
	
	return op;
}

void amarillo(){

	if(Arduino -> IsConnected()){
		Arduino->WriteData("a", sizeof("a") - 1);
	}					
}
void verde(){
		if(Arduino -> IsConnected()){
			Arduino -> WriteData("b", sizeof("b")-1);
		}
				
}
void azul(){
		if(Arduino -> IsConnected()){
			Arduino -> WriteData("c", sizeof("c")-1);
		}
				
}
void apagar(){
		if(Arduino -> IsConnected()){
				Arduino -> WriteData("d", sizeof("d")-1);
		}
			
}
