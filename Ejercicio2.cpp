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

void mostrar_resultado(const Matriz& m, bool escotástica){
	cout << "La matriz introducida es: " << endl;
	for(int f = 0; f < NFILAS; f++){
		for(int c = 0; c < NCOLUMNAS; c++){
			cout << m[f][c] << " ";
		}
		cout << endl;
	}
	cout << endl;
	if(escotástica){
		cout << "La matriz introducida SI es doblemente estocastica normalizada";
	}else{
		cout << "La matriz introducida NO es doblemente escotastica normalizada";
	}
}

int sumar_fila(const Fila& fil){
	int suma = 0;
	for(int c = 0; c < int(fil.size()); c++){
		suma += fil[c];
	}
	return suma;
}

int sumar_columna(const Matriz&m, int c){
	int suma = 0;
	for(int f = 0; f < int(m.size()); f++){
		suma += m[f][c];
	}
	return suma;
}

bool comprobar_elementos_positivos(const Matriz& m){
	bool resultado = true;
	for(int f = 0; f < int(m.size()); f++){
		for(int c = 0; c < int(m[f].size()); c++){
			if(m[f][c] < 0 || m[f][c] > 100){
				resultado = false;
			}
		}
	}
	return resultado;
}

bool comprobar_matriz(const Matriz& m){
	bool escotástica = false;
	//Primera condicion:
	bool elementos_positivos = false;
	if(comprobar_elementos_positivos(m)){
		elementos_positivos = true;
	}
	//Segunda condicion:
	bool suma_cien_fila = true;
	for(int f = 0; f < int(m.size()); f++){
		if(sumar_fila(m[f]) != 100){
			suma_cien_fila = false;
		}
	}
	//Tercera condicion: 
	bool suma_cien_columna = true;
	for(int c = 0; c < int(m[0].size()); c++){
		if(sumar_columna(m, c) != 100){
			suma_cien_columna = false;
		}
	}
	if(elementos_positivos && suma_cien_fila && suma_cien_columna){
		escotástica = true;
	}
	return escotástica;
}

int main(){
	Matriz m;
	leer(m);
	bool escotástica = comprobar_matriz(m);
	mostrar_resultado(m, escotástica);
}