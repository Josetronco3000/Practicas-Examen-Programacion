#include <iostream>
#include <array>
#include <string>
using namespace std;
const string FIN = "FIN";
const int MAX_PAL_DIST = 20;
typedef array <string, MAX_PAL_DIST> TArray;
struct TPalabras{
	TArray palabras;
	int nelms;
};

void inicializar(TPalabras& salida){
	salida.nelms = 0;
}

void abrirHueco(TPalabras& pal, int pos){
	for(int i = pal.nelms; i > pos; i--){
		pal.palabras[i] = pal.palabras[i-1];
	}
}

void posicion(const TPalabras& pal, const string &palabra){
	int pos = 0;
	while(pos < pal.nelms && pal.palabras[pos].length() <= palabra.length()){
		pos++;
	}
	return pos;
}

void insertarOrdenado(TPalabras& pal, const string& palabra){
	int pos;
	if(pal.nelms != MAX_PAL_DIST){
		pos = posicion(pal, palabra)
		abrirHueco(pal, pos);
		pal.palabras[pos] = palabra;
		pal.nelms++;
	}
}S

void bucle(string& palabra, TDatos& salida){
	while(palabra!= FIN){
		if(!esta(salida, palabra)){
			insertarOrdenado(salida, palabra);
		}
		cin >> palabra;
	}
}

int main(){
	string palabra;
	TPalabras salida;
	inicializar(salida);
	cout << "Introduzca un texto (FIN para terminar): ";
	cin >> palabra;
	bucle(palabra, salida);
}