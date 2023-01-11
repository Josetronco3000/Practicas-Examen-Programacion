#include <iostream>
#include <array>
using namespace std;
const int NFILAS = 3;
const int NCOLUMNAS = 3;
typedef array <int, NCOLUMNAS> Fila;
typedef array <Fila, NFILAS> Matriz;

void leer(Matriz& m){
	cout << "Introduce los numeros enteros para una matriz cuadrada de 3x3: " << endl;
	for(int f = 0; f < NFILAS; f++){
		for(int c = 0; c < NCOLUMNAS; c++){
			cin >> m[f][c];
		}
	}
}

void mostrar_resultado(const Matriz& m){
	cout << "La matriz introducida es: ";
	for(int f = 0; f < NFILAS; f++){
		for(int c = 0; c < NCOLUMNAS; c++){
			cout << m[f][c] << " ";
		}
	}
}

bool comprobar_matriz(const Matriz& m){
	bool escotástica = false;
	//Primera condicion:
	bool elementos_positivos = false;
	if(comprobar_elementos_positivos(m)){
		elementos_positivos = true;
	}
	//Segunda condicion:
	bool suma_cien_fila = false;
	for(int f = 0; f < NFILAS; f++){
		if(Fila[f] == 100){
			suma_cien_fila = true;
		}
	}
	//Tercera condicion: 
	bool suma_cien_columna = false;
}

int main(){
	Matriz m;
	leer(m);
	bool escotástica = comprobar_matriz(m);
	mostrar_resultado(m);
}