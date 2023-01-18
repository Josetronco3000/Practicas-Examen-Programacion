
#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

const int MAX = 4;

typedef array <int, MAX> Fila;
typedef array <Fila, MAX> TMatriz;
typedef array <Fila, MAX> TMatriz2;

void inicializar(TMatriz2& m){
	for(int f = 0; f < MAX; f++){
		for(int c = 0; c < MAX; c++){
			m[f][c] = 0;
		}
	}
}

void girarFilas(TMatriz& m, TMatriz2& m2){
	inicializar(m2);
	int i = 1;
	int tamano = int(m.size());
	for(int f = 0; f < MAX; f++){
		for(int c = 0; c < MAX; c++){
			if(i <= 4){
				m2[c][tamano-i] = m[f][c];
			}
		}
		i++;
	}

}

void rotar(TMatriz& m, int n){
	TMatriz m2;
	for(int i = 0; i < n; i++){
		girarFilas(m, m2);
		for(int f = 0; f < MAX; f++){
			for(int c = 0; c < MAX; c++){
				m[f][c] = m2[f][c];
			}
		}
	}
}

void leer(TMatriz& m) {

	for (int fi = 0; fi < MAX; fi++) {
		for (int co = 0; co < MAX; co++) {
			cin >> m[fi][co];
		}
	}
}

void escribir(const TMatriz& m) {

	for (int fi = 0; fi < MAX; fi++) {
		for (int co = 0; co < MAX; co++) {
			cout << setw(3) << m[fi][co] << " ";
		}
		cout << endl;
	}
}


int main() {
	TMatriz mat;
	int n;

	cout << "Introduzca los elementos de la matriz ("
                << MAX << " x " << MAX << ") fila a fila:" << endl;
	leer(mat);

	cout << "\nIntroduzca el numero de rotaciones a realizar: ";
	cin >> n;

	rotar(mat, n);

	cout << "\nLa matriz resultado tras las rotaciones es:\n";
	escribir(mat);

	return 0;
}


