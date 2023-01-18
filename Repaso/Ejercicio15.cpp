#include <iostream>
#include <array>
#include <string>
using namespace std;
const int MAX_PAL_DIST = 15;
const string FIN = "FIN";
typedef array <string, MAX_PAL_DIST> TArray;
struct TDatos{
	TArray palabras;
	int nelms;
};

void inicializar(TDatos& salida){
	salida.nelms = 0;
}

bool esta(const string& palabra, const TDatos& salida){
	int i = 0;
	while(i < int(salida.palabras.size()) && salida.palabras[i] != palabra){
		i++;
	}
	return (i < salida.palabras.size());
}

bool caracteresOrdenados(const string& palabra){
	int i = 0;
	while(i < int(palabra.size())-1 && palabra[i] <= palabra[i+1]){
		i++;
	}
	return i >= int(palabra.size())-1;
}

void escribir(const TDatos& salida){
	cout << "Las palabras cuyos caracteres estan ordenados son: " << endl;
	for(int i = 0; i < salida.nelms; i++){
		cout << salida.palabras[i] << " ";
	}
}

int main(){
	string palabra;
	TDatos salida;
	inicializar(salida);
	cout << "Introduzca el texto (FIN para terminar): " << endl;
	cin >> palabra;
	while(palabra != FIN){
		if(!esta(palabra, salida) && caracteresOrdenados(palabra)){
			salida.palabras[salida.nelms] = palabra;
			salida.nelms++;
		}
		cin >> palabra;
	}
	escribir(salida);
}