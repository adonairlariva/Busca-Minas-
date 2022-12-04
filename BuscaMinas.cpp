//Librerias
#include <iostream> //En uso
#include <stdlib.h>//En uso
#include<conio.h>
#include <cstdlib>//??
#include <windows.h>//En uso
#include <time.h> //En uso

/*

//Teclas
#define IZQUIERDA 75
#define DERECHA 77 
#define ARRIBA 1
#define ABAJO 0
#define ENTER 13

//SEGUNDO JUGADOR

#define ARRIBA2 "w"
#define ABAJO2 "s"
#define DERECHA2 "d"
#define IZQUIERDA2 "a"
//#define ESPACIO

*/

using namespace std;

//Matriz
int minas[15][15];
int detector[15][15];
int bandera[15][15];

//Variables
int x = 0, y = 0, alarma = 0, iniciador = 0, alterMinas = 0, minasA =0,dim=0, ini=0, fin=dim,opc=0;

//Declarar funciones
void Pantalla_De_Inicio();
void Elegir_Dificultad();
void GameOver();
void Game();
void Win();
void Borde_Decorativo();
void tablero();
void relleno();
int comprobar();
int comparar(int &x, int &y, int &alarma);
void marcarMinas(int x, int y, int bandera[15][15]);
void extenderA(int x, int y);
void extenderB(int x, int y);
void extenderC(int x, int y);
void extenderD(int x, int y);


//Funciones experimentales
void Reinicio();
/*

void Cantidad_De_Jugadores();
void Music();

*/


//Gotoxy.h
void gotoxy(int x,int y){
HANDLE hcon;
hcon = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X = x;
dwPos.Y = y;
SetConsoleCursorPosition(hcon,dwPos);
}


int main(){
	while(1){
	
	//==CONFIGURACIÓN ESTETICA==
	system("color 1F"); //Cambiar color del fondo y del texto
	
	
	//==TITULO SUPERIOR DE LA VENTANA==
	SetConsoleTitle("BUSCAMINAS"); 
	
	
	//==LLAMAR FUNCIONES==
    
    Pantalla_De_Inicio();
	Elegir_Dificultad();
}
	return 0;
}


void Borde_Decorativo(){
	
	//==MARCO==

	//Top-Bottom
	for(int i=0;i<79;i++){
	gotoxy(i,0); printf("%c",205);
	gotoxy(i,24); printf("%c",205);
}

	//Left-Right
	for(int i=1;i<24;i++){
	gotoxy(0,i); printf("%c",186);
	gotoxy(79,i); printf("%c",186);
}

	//Esquinas - Superior derecha
	gotoxy(79,0); printf("%c",187);
	
	//Esquinas - Superior izquierda
	gotoxy(0,0); printf("%c",201);

	//Esquinas - Inferio izquierda
	gotoxy(0,24); printf("%c",200);

	//Esquinas - Inferio Derecha
	gotoxy(79,24); printf("%c",188);
	
}


//Pantalla de Inicio	
void Pantalla_De_Inicio(){	
	
//Llamar a la función borde
Borde_Decorativo();

//==LOGO==
//Parte 1 (BUSCA)
int x1=1;
int x2=1;
int x3=1;
int x4=1;
int x5=1;

//Parte 2 (MINAS)
int x6=67;
int x7=67;
int x8=67;
int x9=67;
int x10=67;


while(1){ //Bucle infinito

//==CADENA DE APARICIÓN DE LAS LETRAS==

//Contadores Inicializadores
x1++;
x6--;


//Cadena de condicionales para establacer un orden de aumento de los contadores

/*
Nota: Cada contador controla la posición y el orden de aparición de cada una de las
letras.
*/

//Parte uno del titulo	
	if(x1>=11){
		x2++;
	}
	
	if(x2>=11){
		x3++;
	}
	
	if(x3>=10){
		x4++;
	}
	
	if(x4>=12){
		x5++;
	}

//Parte dos del titulo

	if(x6<=56){
		x7--;
	}
	
	if(x7<=56){
		x8--;
	}
	
	if(x8<=55){
		x9--;
	}
	
	if(x9<=56){
		x10--;
	}

//==GRAFICOS==

//Parte uno del titulo
if(x1==50){ //Condición para establace la posición limite de la letra.
	break;
}

else{
	//Letra A
	Sleep(10);
	gotoxy(x1,3); printf("   #######  ");
	gotoxy(x1,4); printf("  ######### "); 
	gotoxy(x1,5); printf("  ###   ### "); 
	gotoxy(x1,6); printf("  ######### "); 
	gotoxy(x1,7); printf("  ###   ### "); 
	gotoxy(x1,8); printf("  ###   ### ");
}


if(x2==40){ //Condición para establace la posición limite de la letra.
	break;
}

else if(x1>=10){ //Condición para dejar un espacio entre cada letra

	//Letra C
	Sleep(10);
	gotoxy(x2,3); printf(" ######### ");
	gotoxy(x2,4); printf(" ######### "); 
	gotoxy(x2,5); printf(" ####      "); 
	gotoxy(x2,6); printf(" ####      "); 
	gotoxy(x2,7); printf(" ######### "); 
	gotoxy(x2,8); printf(" ######### ");
}

if(x3==30){ //Condición para establace la posición limite de la letra.
	break;
}

else if(x2>=10){ //Condición para dejar un espacio entre cada letra
	
	//Letra S
	Sleep(10);
	gotoxy(x3,3); printf(" ######### ");
	gotoxy(x3,4); printf(" ####      "); 
	gotoxy(x3,5); printf(" ######### "); 
	gotoxy(x3,6); printf("       ### "); 
	gotoxy(x3,7); printf(" ######### "); 
	gotoxy(x3,8); printf(" ######### "); 
}

if(x4==20){ //Condición para establace la posición limite de la letra.
	break;
}

else if(x3>=10){ //Condición para dejar un espacio entre cada letra
	
	//Letra U
	Sleep(10);
	gotoxy(x4,3); printf(" ###  ### ");
	gotoxy(x4,4); printf(" ###  ### "); 
	gotoxy(x4,5); printf(" ###  ### "); 
	gotoxy(x4,6); printf(" ###  ### "); 
	gotoxy(x4,7); printf(" ######## "); 
	gotoxy(x4,8); printf(" ######## ");
	}
	
if(x5==10){ //Condición para establace la posición limite de la letra.
	break;
}

else if(x4>=12){ //Condición para dejar un espacio entre cada letra

	//Letra B
	Sleep(10);
	gotoxy(x5,3); printf(" ########  ");
	gotoxy(x5,4); printf(" ##     ## "); 
	gotoxy(x5,5); printf(" ########  "); 
	gotoxy(x5,6); printf(" ######### "); 
	gotoxy(x5,7); printf(" ##     ## "); 
	gotoxy(x5,8); printf(" ########  ");
}




//PARTE DOS DEL TITULO
//Cadena de aparición de las letras

if(x6==15){ //Condición para establace la posición limite de la letra.
	break;
}

else{

	//Letra M
	Sleep(10);
	gotoxy(x6,11); printf(" ###   ### ");
	gotoxy(x6,12); printf(" #### #### "); 
	gotoxy(x6,13); printf(" ######### "); 
	gotoxy(x6,14); printf(" ######### "); 
	gotoxy(x6,15); printf(" ### # ### "); 
	gotoxy(x6,16); printf(" ###   ### "); 
}

if(x7==25){ //Condición para establace la posición limite de la letra.
	break;
}

else if(x7<=66){ //Condición para dejar un espacio entre cada letra
	//Letra I
	Sleep(10);
	gotoxy(x7,11); printf(" ######### ");
	gotoxy(x7,12); printf(" ######### "); 
	gotoxy(x7,13); printf("    ###    "); 
	gotoxy(x7,14); printf("    ###    "); 
	gotoxy(x7,15); printf(" ######### "); 
	gotoxy(x7,16); printf(" ######### ");
}

if(x8==35){ //Condición para establace la posición limite de la letra.
	break;
}

else if(x8<=66){ //Condición para dejar un espacio entre cada letra
	
	//Letra N
	Sleep(10);
	gotoxy(x8,11); printf(" ####   ### ");
	gotoxy(x8,12); printf(" #####  ### "); 
	gotoxy(x8,13); printf(" ###### ### "); 
	gotoxy(x8,14); printf(" ### ###### "); 
	gotoxy(x8,15); printf(" ###  ##### "); 
	gotoxy(x8,16); printf(" ###   #### "); 
}

if(x9==45){ //Condición para establace la posición limite de la letra.
	break;
}

else if(x9<=66){ //Condición para dejar un espacio entre cada letra

	//Letra A
	Sleep(10);
	gotoxy(x9,11); printf("  #######  ");
	gotoxy(x9,12); printf(" ######### "); 
	gotoxy(x9,13); printf(" ###   ### "); 
	gotoxy(x9,14); printf(" ######### "); 
	gotoxy(x9,15); printf(" ###   ### "); 
	gotoxy(x9,16); printf(" ###   ### ");
}

if(x10==55){ //Condición para establace la posición limite de la letra.
	break;
}

else if(x10<=66){ //Condición para dejar un espacio entre cada letra
	//Letra S
	Sleep(10);
	gotoxy(x10,11); printf(" ######### ");
	gotoxy(x10,12); printf(" ####      "); 
	gotoxy(x10,13); printf(" ######### "); 
	gotoxy(x10,14); printf("       ### "); 
	gotoxy(x10,15); printf(" ######### "); 
	gotoxy(x10,16); printf(" ######### "); 
	}
}

//==EFECTO DE CARGA==

	for(int i=20;i<61;i++){
	
	gotoxy(i,20); printf("%c",205);
	gotoxy(i,22); printf("%c",205);
	}
	
	//Laterales
	gotoxy(20,21); printf("%c",186);
	gotoxy(60,21); printf("%c",186);
	
	//Esquinas - Superior derecha
	gotoxy(60,20); printf("%c",187);
	
	//Esquinas - Superior izquierda
	gotoxy(20,20); printf("%c",201);

	//Esquinas - Inferio izquierda
	gotoxy(20,22); printf("%c",200);

	//Esquinas - Inferio Derecha
	gotoxy(60,22); printf("%c",188);
	
	//Barra de carga
	for(int i=21;i<60;i++){
		Sleep(30);
		gotoxy(i,21); printf("%c",219); //Pintar los cuadros blancos
	}
	
	for(int i=21;i<60;i++){
	gotoxy(i,21); printf(" "); //Borrar los cuadros blancos
	}
	
	gotoxy(24,21); printf("PRESIONE UNA TECLA PARA CONTINUAR");
	getch();
}



void Elegir_Dificultad(){
	
//==SELECCIÓNAR DIFICULTAD==
	
	system("cls"); //Borrar pantalla

	Borde_Decorativo(); //Llamar al marco para decorar
	
	int dif=0; //Variable del menú	
	
	
	//Titulo
	Sleep(20);
	gotoxy(6,3); cout<<"--- Bienvenido a Buscaminas! - En que dificultad quiere jugar? ---";
	
	//Opciones
	Sleep(30);
	gotoxy(10,10); cout<<"[1] - Facil";
	gotoxy(32,10); cout<<"[2] - Normal";
	gotoxy(55,10); cout<<"[3] - Dificil";
	
	//Casilla para escribir
	gotoxy(36,20);	cout<<" [ ";
	gotoxy(38,20);	cout<<" ] ";
	//gotoxy(41,20); //Posicion de escritura
	
	
	gotoxy(38,20);cin>>dif;//Guardar dato
	
	
	
	while(1){ //Bucle infinito

	//Condición por si el usuario elije un numero diferente a las opciones del menú
	if(dif>3 || dif<1){
	gotoxy(36,20);	cout<<" [ ";
	gotoxy(38,20);	cout<<" ] ";
	gotoxy(38,20); printf(" ");
	gotoxy(38,20);cin>>dif;//Guardar dato
	}
	
	else{
		break;
		}
	}

	switch(dif){ //Selección de dificultad
		
	case 1:
	system("cls");
	dim=5;
	Game();
	break;
	
	case 2:
	system("cls");
	dim=10;
	Game();
	break;
		
	case 3:
	system("cls");
	dim=15;
	Game();
	break;

		}
	}


void GameOver(){
	//==PANTALLA DE PERDIDA==
	
	Reinicio();//Reiniciar tablero
	
	system("cls");//Borrar pantalla
	
	Borde_Decorativo(); //Llamar al marco para decorar
	
	int opc=0; //Variable del menú
	
	//Titulo
	Sleep(20);
	gotoxy(6,3); cout<<"---   Upsss... Lamentableente perdiste. Ahora que quieres hacer?   ---";
	
	//Opciones
	Sleep(30);
	gotoxy(3,10);  cout<<"[1] - Volver a jugar";
	gotoxy(27,10); cout<<"[2] - Cambiar dificultad";
	gotoxy(55,10); cout<<"[3] - Salir del juego";
	
	//Casilla para escribir
	gotoxy(36,20);	cout<<" [ ";
	gotoxy(38,20);	cout<<" ] ";
	//gotoxy(41,20); //Posicion de escritura
	
	
	gotoxy(38,20);cin>>opc;//Guardar dato
	
	while(1){

	if(opc>3 || opc<1){
	gotoxy(36,20);	cout<<" [ ";
	gotoxy(38,20);	cout<<" ] ";
	gotoxy(38,20); printf(" ");
	gotoxy(38,20);cin>>opc;//Guardar dato
	}
	
	else{
		break;
		}
	}

	switch(opc){
		
	case 1:
	//Llamar funcion para  jugar
	system("cls");
	Game();
	break;
	
	case 2:
	//Llamar funcion para cambiar la dificultad
	system("cls");
	Elegir_Dificultad();
	break;
	
	
	case 3:
	//Salir del juego
	gotoxy(20,20); exit(0);
	break;
	
	}
}

void Game(){
	
	//Borde_Decorativo(); //Llamar al marco para decorar
	
	gotoxy(10,10); relleno();
		
	while (1)
	{
		/*evitar posiciones adelantadas*/
		if (iniciador > 0)
		{
			comparar(x, y, alarma);
			if (alarma == 0)
			{
				for (int i = x; i >= 0; i--)
				{
					if (i > -1)
					{
						comparar(i, y, alarma);

						marcarMinas(i, y, bandera);
						extenderA(i, y);
				
					}
					if (minas[i - 1][y] == 2)
					{
						ini=i;
						break;
					}
				}
				for (int i = x; i <dim; i++)
				{
					comparar(i, y, alarma);
					marcarMinas(i, y, bandera);
					extenderA(i, y);
		

					if (minas[i + 1][y] == 2)
					{
						fin=i;
						break;
					}
				}

				for (int i = y; i >= 0; i--)
				{
					if (i > -1)
					{
						comparar(x, i, alarma);
						marcarMinas(x, i, bandera);
						extenderB(x, i);
					}
					if (minas[x][i - 1] == 2)
					{
						break;
					}
				}

				for (int i = y; i < dim; i++)
				{
					comparar(x, i, alarma);
					marcarMinas(x, i, bandera);
					extenderB(x, i);

					if (minas[x][i+1] == 2)
					{
						break;
					}
				}
			for(int i=ini;i<fin;i++){
					extenderC(i, y);
					extenderD(i, y);
				}
			}
			
		}
		
        comprobar();
        
		//==Construcción del tablero==
		
		tablero();

		/*funciones de búsqueda*/
		if (alarma == 0)
		{
			while (1)
			{
				cout << "\nSeleccione La Columna: ";
				cin >> y;

				cout << "\nSeleccione La Fila: ";
				cin >> x;

				cout << "\n";
			
				if (detector[x][y] == 0)
				{
					break;
				}
			}
			iniciador++;
		}
		
		if (alarma == 1)
		{
			Sleep(3000);
			Reinicio();
			GameOver();
			break;
		}
				if (alarma == 
