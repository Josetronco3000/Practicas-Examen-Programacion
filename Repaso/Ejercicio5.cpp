#include <iostream>
#include <array>
#include <string>
using namespace std;
const int TAM = 10;
typedef array <int, TAM> Numeros;

void leer(Numeros& numero){
	cout << "Introduzca 10 numeros enteros: ";
	for(int i = 0; i < int(numero.size()); i++){
		cin >> numero[i];
	}
}

int mayorLongitud(const Numeros& sucesion){
	int cnt = 1;
	int mayor = 0;
	for(int i = 0; i < int(sucesion.size()); i++){
		if(sucesion[i+1] >= sucesion[i]){
			cnt++;
		}else if(sucesion[i+1] < sucesion[i]){
			if(mayor < cnt){
				mayor = cnt;
			}
			cnt = 1;
		}
	}
	if(cnt > mayor){
		mayor = cnt;
	}
	return mayor;
}

void mostrar(int longitud){
	cout << "La longitud de la mayor sub-sucesion es: " << longitud << endl;
}

int main(){
	Numeros sucesion;
	leer(sucesion);
	int longitud = mayorLongitud(sucesion);
	mostrar(longitud);
}