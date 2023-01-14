#include <iostream>
#include <array>
#include <string>
using namespace std;
const int NFILAS = 4;
const int NCOLUMNAS = 3;
typedef array <int, NCOLUMNAS> Fila;
typedef array <Fila, NFILAS> Matriz;

void leer(Matriz& m){
	cout << "Introduzca la matriz para suavizarla: " << endl;
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			cin >> m[f][c];
		}
	}
}

bool es_valido(const Matriz& m, int f, int c, int ff, int cc){
	return (0 <= f+ff && f+ff < int(m.size())) && (0 <= c+cc && c+cc < int(m[f+ff].size()));
}

double media(const Matriz& m, int f, int c){
	int nvec = 0;
	int suma = 0;
	for(int ff = -1; ff <= +1; ff++){
		for(int cc = -1; c <= +1; c++){
			if(es_valido(m, f, c, ff, cc)){
				suma += m[f+ff][c+cc];
				nvec++;
			}
		}
	}
	return double(suma) / double(nvec);
}

void suavizado(Matriz& m){
	Matriz aux = m;
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			m[f][c] = media(aux, f, c);
		}
	}
}

void mostrar(const Matriz& m){
	cout << "Resultado: " << endl;
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			cout << m[f][c] << " ";
		}
		cout << endl;
	}
}

int main(){
	Matriz m;
	leer(m);
	suavizado(m);
	mostrar(m);
}