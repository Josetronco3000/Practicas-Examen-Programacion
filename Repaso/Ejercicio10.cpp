#include <iostream>
#include <array>
using namespace std;
const int NFILAS = 2;
const int NCOLUMNAS = 3;
const int NFILAS2 = 2*NFILAS;
typedef array <int, NCOLUMNAS> Fila;
typedef array <Fila, NFILAS> Matriz;
typedef array <int, NCOLUMNAS> Fila2;
typedef array <Fila2, NFILAS2> Matriz2;

void leer(Matriz& m){
	cout << "Introduzca la matriz M (2x3): " << endl;
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			cin >> m[f][c];
		}
	}
}

void inicializar(Matriz2& m){
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			m[f][c] = 0;
		}
	}
}

int media_entera(const Matriz& m){
	int suma = 0;
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			suma += m[f][c];
		}
	}
	return suma/(NFILAS*NCOLUMNAS);
}

void organizar_nueva_matriz(const Matriz& m, Matriz2& m2){
	for(int c = 0; c < int(m[0].size()); c++){
		m2[0][c] = m[0][c];
	}
	for(int f = 1; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			m2[f*2][c] = m[f][c];
		}
	}
}

bool es_valido(const Matriz2& m, int f, int c, int ff, int cc){
	return (0 <= f+ff && f+ff < int(m.size())) && (0 <= c+cc && c+cc < int(m[f+ff].size()));
}

int media_vecinos(const Matriz2& m, int f, int c, int media){
	int nvec = 0;
	int suma = 0;
	for(int ff = -1; ff <= +1; ff++){
		for(int cc = -1; cc <= +1; cc++){
			if(es_valido(m, ff, cc, f, c)){
				if(m[f+ff][c+cc] == 0){
					suma += media;
				}else{
					suma += m[ff+f][cc+c];
				}
				nvec++;
			}
		} 
	}
	suma -= media;
	nvec--;
	return suma/nvec;
}

void rellenar_filas_impares(Matriz2& m, int media){
	for(int f = 1; f < NFILAS2; f = f+2){
		for(int c = 0; c < NCOLUMNAS; c++){
			m[f][c] = media_vecinos(m, f, c, media);
		}
	}
}

void mostrar(const Matriz2& m){
	cout << "La matriz T (4x3) es la siguiente: " << endl;
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			cout << m[f][c] << " ";
		}
		cout << endl;
	}
}

int main(){
	Matriz m;
	Matriz2 m2;
	leer(m);
	inicializar(m2);
	int media = media_entera(m);
	organizar_nueva_matriz(m, m2);
	rellenar_filas_impares(m2, media);
	mostrar(m2);
	return 0;
}