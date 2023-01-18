#include <iostream>
#include <array>
#include <iomanip>
using namespace std;
const int TAM = 7;
typedef array <int, TAM> Fila;
typedef array <Fila, TAM> Matriz;

void inicializar(Matriz& m){
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			m[f][c] = 0;
		}
	}
	int f1 = 0;
	for(int c = 0; c < int(m[f1].size()); c++){
		m[f1][c] = 1;
	}
	int c1 = 0;
	for(int f = 0; f < int(m.size()); f++){
		m[f][c1] = 1;
	}
}

bool derecha_diagonal(int f, int c){
	return (TAM - f - 1 < c);
}

void construir(Matriz& m){
	for(int f = 1; f < int(m.size()); f++){
		for(int c = 1; c < int(m[f].size()); c++){
			if(!derecha_diagonal(f, c)){
				m[f][c] = (m[f-1][c] + m[f][c-1]);
			}
		}
	}
}

void mostrar(const Matriz& m){
	cout << "Resultado: " << endl;
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			if(m[f][c] != 0){
				cout << setw(3) << m[f][c] << " ";
			}else{
				cout << " ";
			}
		}
		cout << endl;
	}
}

int main(){
	Matriz m;
	inicializar(m);
	construir(m);
	mostrar(m);
}