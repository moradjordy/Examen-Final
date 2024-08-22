#include <iostream>  //Aqui encontraremos la bibliotecas para trabajar en C++.
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);


//Variables globales: variables globales que podremos utilizar en todo el programa. 
const int MAXVIAJEROS = 100;
string idviajero[MAXVIAJEROS];
string nombreviajero[MAXVIAJEROS];
string apellidoviajero[MAXVIAJEROS];
string direccion[MAXVIAJEROS];
int todoslosviajeros = 0;
int viajes[MAXVIAJEROS] = {0};
int viajestotal = 0;
int ingresostotal = 0;
int salidastotal = 0;

// lista de void que iremos necesitando en el programa, ordenados acorde estan a lo largo del programa con el fin de tener un indice claro en caso de que el programa requiera una modificacion. 
//Primeros dos void son con el fin de dar estetica al programa.
void gotoxy();
void cuadro();
void ingresarviajeros();
void mostrarviajeros();
void ingreso();
void salida();
void reporte();
void salir();
void menu();


void gotoxy(int x, int y) {			// Void con el fin de dar margenes al programa. 
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void cuadro(int x1, int y1, int x2, int y2){		//void para agregar un cuadro que brinda estetica al programa. 
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}
	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}

void ingresarviajeros(){    //void para ingresar los datos de viajero. 
	
	char respagregar;
	
	do{
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
	cuadro(20, 5, 100, 19);
	gotoxy(30,9);cout << "Ingresar pasaporte del viajero" << endl;
	gotoxy(80,9);cin >> idviajero[todoslosviajeros];
	gotoxy(30,10);cout << "Ingresar nombre sin apellidos del viajero" << endl;
	gotoxy(80,10);cin >> nombreviajero[todoslosviajeros];
	gotoxy(30,11);cout << "Ingresar apellido del viajero" << endl;
	gotoxy(80,11);cin >> apellidoviajero[todoslosviajeros];
	gotoxy(30,12);cout << "Ingresar pais origen" << endl;
	gotoxy(80,12);cin >> direccion[todoslosviajeros];
	todoslosviajeros++;

	gotoxy(30,15);cout << "Viajero agregado." << endl;
	
	gotoxy(30,17);cout<< "Desea agregar otro viajero?  (S/N)" << endl;
	gotoxy(70,17);cin >> respagregar; 
	
	
	} while(respagregar == 's'|| respagregar == 'S');

	menu();
}

void mostrarviajeros(){		// void para ver la lista detalla de los pasajeros que se agregaron en el void ingresarviajeros
	char respmostrar;
	int posy = 6;
	
	do{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
		cuadro(5, 3, 115, 26);
		gotoxy(45,5);cout << "Viajeros disponibles:" << endl;
    	for (int i = 0; i < todoslosviajeros; ++i) {
    	gotoxy(8,posy); cout << "Numero de viajero: " << i+1 << " Pasaporte del viajero: " << idviajero[i]<< " Nombre: " << nombreviajero[i] << " Apellido: " << apellidoviajero[i] << " Pais: " << direccion[i] << endl;
    	posy++;
	}
	gotoxy(30,25);cout << "Desea regresar al menu?  (S/N)";
	gotoxy(65,25);respmostrar = tolower(getchar());
	
	} while (respmostrar != 's');

	menu();    
    
}

void ingreso(){				//void para contar e ingresar las entradas del pais por numero de viajero. 
	
	char respagregar;
    int numeroviajero;
    int posy = 11;
    
    do{

    system("cls");
    SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
	cuadro(20, 5, 100, 19);
    
    gotoxy(37,8); cout << "Ingrese el numero de viajero ";
    cin >> numeroviajero;
	viajestotal++;
	ingresostotal++;
    if (numeroviajero >= 1 && numeroviajero <= todoslosviajeros) {
        viajes[numeroviajero - 1]++;
		gotoxy(30,posy);cout << "Ha regitrado un ingreso para " << nombreviajero[numeroviajero - 1] << " " << apellidoviajero[numeroviajero - 1] << " de origen " << direccion[numeroviajero - 1] << "!" << endl;
		
    } 
	else {
        cout << "ID de viajero inválido. Vuelva a intentarlo." << endl;
    }
    gotoxy(30,17);cout<< "Desea registrar otro ingreso?  (S/N)" << endl;
	gotoxy(70,17);cin >> respagregar; 
    }while(respagregar == 's'|| respagregar == 'S');
    menu(); 	
		
}

void salida(){				//void para contar e ingresar las salidas del pais por numero de viajero. 
	
	char respagregar;
    int numeroviajero;
    int posy = 11;
    
    do{
    
    system("cls");
    SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
	cuadro(20, 5, 100, 19);
    
    gotoxy(37,8); cout << "Ingrese el numero de viajero ";
    cin >> numeroviajero;
	viajestotal++;
	salidastotal++;
    if (numeroviajero >= 1 && numeroviajero <= todoslosviajeros) {
        viajes[numeroviajero - 1]++;
		gotoxy(30,posy);cout << "Ha regitrado una salida para " << nombreviajero[numeroviajero - 1] << " " << apellidoviajero[numeroviajero - 1] << " de origen " << direccion[numeroviajero - 1] << "!" << endl;
		
    } 
	else {
        cout << "ID de viajero inválido. Vuelva a intentarlo." << endl;
    }
    gotoxy(30,17);cout<< "Desea registrar otra salida?   (S/N)" << endl;
	gotoxy(70,17);cin >> respagregar; 
    }while(respagregar == 's'|| respagregar == 'S');
    menu(); 
    	
}

void reporte(){				//void para llevar un reporte de los movieminetos dentro del programa. 
	char respreporte;
	int posy = 11;
	
	do{
	
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
	cuadro(20, 3, 100, 26);
	gotoxy(50,5); cout << "Reporte" << endl;
	gotoxy(38,7); cout << "Cantidad total de viajeros en sistema:  "<< todoslosviajeros << endl;
	gotoxy(38,8); cout << "Cantidad total de viajes:  " << viajestotal << endl;
	gotoxy(38,9); cout << "Cantidad total de ingresos al pais:  " << ingresostotal << endl;
	gotoxy(38,10); cout << "Cantidad total de salidas del pais:  " << salidastotal << endl;
	
	
    gotoxy(30,25);cout << "Desea regresar al menu?  (S/N)";
	gotoxy(65,25);respreporte = tolower(getchar());
    
	} while (respreporte != 's');
    
   menu();  

}

void salir(){				//void para salir del programa//
	
	gotoxy(45, 28);cout << "Saliendo del programa..." << std::endl;
    exit(0);
	
}

void menu(){ 				// void que sera la pantalla pricipal del programa, sera lo primero que se muestre y desde donde seleccionaremos las diferentes fucniones del programa. 
	
	int respmenu;

	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
	cuadro(20, 5, 100, 24);
	gotoxy(43,7);cout << "Bienvenido sistema de Migracion."<< endl;
	gotoxy(55,9);cout << "Costa Rica." << endl;
	gotoxy(30,11);cout << "1 - Ingresar viajeros." << endl;
	gotoxy(30,12);cout << "2 - Mostrar viajeros." << endl;
	gotoxy(30,13);cout << "3 - Ingresar entrada de viajeros." << endl;
	gotoxy(30,14);cout << "4 - Ingresar salida de viajeros." << endl;
	gotoxy(30,16);cout << "Antes de registrar una entrada o salida favor tener claro " << endl;
	gotoxy(30,17);cout << "el numero de viajero.(Favor consultar en submenu 2)." << endl;
	gotoxy(30,19);cout << "5 - Reporte." << endl;
	gotoxy(30,20);cout << "6 - Salir." << endl;
	gotoxy(30,22);cout << "Digite una opcion" << endl;
	gotoxy(50,22);cin >> respmenu;
	
	switch (respmenu){
		
		case 1:
		ingresarviajeros();
		break;
		case 2:
		mostrarviajeros();
		break;
		case 3:
 		ingreso();
		break;
		case 4:
		salida();
		break;
		case 5:
		reporte();
		break;
		case 6:
		salir();
		break;
		default:
		cout << "Opcion no valida" << endl;
		break;

	}
}

int main(){
	menu();
return 0;
}


