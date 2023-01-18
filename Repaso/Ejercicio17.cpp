#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;
const int NFILAS = 5;
const int NCOLUMNAS = 7;
typedef array <char, NCOLUMNAS> Fila;
typedef array <Fila, NFILAS> SalaCine;

void inicializar(SalaCine& sala){
	for(int f = 0; f < int(sala.size()); f++){
		for(int c = 0; c < int(sala[f].size()); c++){
			sala[f][c] = 'o';
		}
	}
}

void guiones(){
	for(int i = 0; i < 16; i++){
		cout << "-";
	}
	cout << endl;
}

void mostrar(const SalaCine& sala){
	cout << "El estado actual de la sala de cine es: " << endl;
	cout << "   ";
	for(int i = 0; i < 7; i++){
		cout << i << " ";
	}
	cout << endl;
	guiones();
	for(int f = 0; f < int(sala.size()); f++){
		cout << f << ": ";
		for(int c = 0; c < int(sala[f].size()); c++){
			cout << sala[f][c] << " ";
		}
		cout << endl;
	}
}

void comprar_ticket_consecutivo(SalaCine& sc, int fila_1, int fila_2, int n, bool& ok, int& fil_sel, int&col_sel){
	if((fila_1 <= fila_2) && n > 0){
		int cnt = 0;
		bool encontrados = false;
		for(int f = fila_1; f <= fila_2 && !encontrados; f++){
			for(int c = 0; c < int(sc[f].size()) && !encontrados; c++){
				if(sc[f][c] = 'o'){
					cnt++;
				}else{
					cnt = 0;
				}
				if(cnt == n){
					encontrados = true;
					ok = true;
					fil_sel = f;
					col_sel = c-n+1;
					for(int j = col_sel; j <= c; j++){
						sc[fil_sel][j] = 'x';
					}
				}
			}
		}
	}else{
		cout << "Filas o numero de asientos incorrecto" << endl;
		ok = false;
	}
}

void cancelar_ticket(SalaCine& sc, int fila, int columna, bool& ok){
	if((0 <= fila && fila <= int(sc.size())) && (0 <= columna && columna <= int(sc[fila].size())) && sc[fila][columna] == 'x'){
		ok = true;
		sc[fila][columna] = 'o';
	}else{
		ok = false;
		cout << "Error. Asiento incorrecto" << endl;
	}
}

void menu_comprar(SalaCine& sala){
	cout << "Ha accedido al menu para comprar tickets." << endl;
	cout << "Introduzca el rango de filas: " << endl;
	cout << "Fila1: ";
	int fila_1;
	cin >> fila_1;
	cout << "Fila2: ";
	int fila_2;
	cin >> fila_2;
	cout << "Introduzca el numero de asientos que quiera comprar: ";
	int n = 0;
	cin >> n;
	bool ok;
	int fil_sel;
	int col_sel;
	comprar_ticket_consecutivo(sala, fila_1, fila_2, n, ok, fil_sel, col_sel);
}

void menu_cancelar(SalaCine& sala){
	cout << "Ha accedido al menu para cancelar un asiento." << endl;
	cout << "Introduzca que asiento desea cancelar: " << endl;
	cout << "Fila: ";
	int fila, columna;
	cin >> fila;
	cout << "Columna: ";
	cin >> columna;
	bool ok;
	cancelar_ticket(sala, fila, columna, ok);
}

void menu(SalaCine& sala){
	cout << "Bienvenido al menu del cine, que le gustaria hacer?: " << endl;
	cout << "Comprar tickets (c)." << endl;
	cout << "Cancelar tickets (b)." << endl;
	cout << "Salir (e)." << endl;
	mostrar(sala);
	cout << "Escriba la opcion: ";
	char n;
	cin >> n;
	while(n != 'e'){
		switch(n){
			case 'c':	
				menu_comprar(sala);
				mostrar(sala);
			break;
			case 'b':
				menu_cancelar(sala);
				mostrar(sala);
			break;
			default: 
				cout << "Opcion incorrecta";
		}
		cout << "Escriba la opcion: ";
		cin >> n;
	}
}

int main(){
	SalaCine sala;
	inicializar(sala);
	menu(sala);
}