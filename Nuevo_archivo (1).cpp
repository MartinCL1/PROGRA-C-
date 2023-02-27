// CREANDO EL BUSCAMINAS

#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class Personaje{
	private:
		int posX;
		int posY;
	public:
		Personaje(){
			
		}
		
		Personaje(int posX, int posY){
			this->posX = posX;
			this->posY = posY;
		}
		
		int getPosX(){
			return this->posX;
		}
		
		int getPosY(){
			return this->posY;
		}
		
		void setPosX(int posX){
			this->posX = posX;
		}
		
		void setPosY(int posY){
			this->posY = posY;
		}
};

class Matriz{
	private:
		char matriz[5][5];
		char tabla[5][5];
	
	public:
		
		Matriz(){
		}
		
		void modificacion(){
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 5; j++){
					this->tabla[i][j] = '0'; 
				}
			}	
		}
		
		void mostrarTabla(){
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 5; j++){
					cout<<this->tabla[i][j]<<" "; 
				}
				cout<<endl;
			}	
		}
		
		void inicializar(){
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 5; j++){
					this->matriz[i][j] = '0'; 
				}
			}
			modificacion();
		}
		
		void generar(){
			srand(time(NULL));
			for(int i = 0; i < 10 ; i++){
				int columna = 0 + rand() % 5;
				int fila = 0 + rand() % 5;
				this->matriz[fila][columna] = '*';
			}
		}
		
		void mostrar(){
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 5; j++){
					cout<<this->matriz[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
		bool colocarPunto(int x, int y){
			if(this->matriz[y][x] == '*'){
				return true;	
			}else{
				this->tabla[y][x] = ' ';
			}
		}
};

void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
void menu();
void pantallaCarga();
void iniciarJuego();
Personaje personaje;
Matriz tabla;
bool GAME_OVER;

int main(){	
	tabla = Matriz();
	tabla.inicializar();
	tabla.generar();
	
	pantallaCarga();
	menu();
	
	getch();
	return 0;
}

void menu(){
	int opcion;
	system("cls");
	while(opcion != 0){
		GAME_OVER = false;
		tabla.inicializar();
		tabla.generar();
		
		cout<<"1- INICIAR."<<endl;
		cout<<"0- SALIR."<<endl;
		cout<<"Ingrese su opcion: ";
		cin>>opcion;
		system("cls");
		switch(opcion){
			case 1:
				iniciarJuego();
				break;
			case 2:
				exit(0);
			default:
				cout<<"\nOpcion incorrecta.";
		}
		getch();
	}
	
	iniciarJuego();
}

void pantallaCarga(){
	char b = ' ';
	
	gotoxy(10, 10);
	for(int i = 0; i< 10;i++){
		cout<<char(219);
		Sleep(100);
	}
	
	system("cls");
	gotoxy(10, 10);
	
	for(int i = 0; i< 10;i++){
		switch(i){
			case 0:
				b = 'B';
				system("color 0b");
				break;
			case 1:
				b = 'I';
				system("color 0c");
				break;
			case 2:
				b = 'E';
				system("color 0e");
				break;
			case 3:
				b = 'N';
				system("color 0c");
				break;
			case 4:
				b = 'V';
				system("color 0e");
				break;
			case 5:
				b = 'E';
				system("color 0a");
				break;
			case 6:
				b = 'N';
				system("color 0e");
				break;
			case 7:
				b = 'I';
				system("color 0c");
				break;
			case 8:
				b = 'D';
				system("color 0e");
				break;
			case 9:
				b = 'O';
				system("color 0a");
				break;
		}
		cout<<b<<" ";
		Sleep(300);
	}
	cout<<endl;
	system("pause");
}

void iniciarJuego(){
	int tecla;
	int fila = 0, columna = 0;
	
	personaje = Personaje(fila, columna);  // definiendo el punto de partida.
	
	fflush(stdin);
		
	while((columna <= 5 || columna > 0 || (fila < 5 || fila > 0)) && GAME_OVER != true){
		tabla.mostrarTabla();
		
		cout<<"Indique su posicion inicial."<<endl;
		cout<<"Fila: "; cin>>fila;
		cout<<"Columna: "; cin>>columna;
			
		personaje.setPosX(columna);
		personaje.setPosY(fila);
			
		GAME_OVER = tabla.colocarPunto(personaje.getPosX(), personaje.getPosY());
		system("cls");
	}
	
	
	cout<<"HAS PERDIDO EL JUEGO"<<endl;
	getch();
	system("cls");
}
