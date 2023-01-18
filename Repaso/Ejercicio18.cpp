#include <iostream>
#include <string>
#include <array>
using namespace std;
const string FIN = "FIN";
const int MAX_PAL_DIST = 20;
typedef array <string, MAX_PAL_DIST> TArray;
struct TPalabras{
	TArray palabras;
	int nelms;
};

bool esta(const string& palabra, const TPalabras& salida){
	int i = 0;
	while((i < int(salida.palabras.size())) && (salida.palabras[i] != palabra)){
		i++;
	}
	return i < salida.palabras.size();
}

void abrirHueco(TPalabras& salida, int pos){
	for(int i = salida.nelms; i > pos; i--){
		salida.palabras[i] = salida.palabras[i-1];
	}
}

int posicion(const TPalabras& salida, const string& palabra){
	int pos = 0;
	while(pos < salida.nelms && salida.palabras[pos].length() <= palabra.length()){
		pos++;
	}
	return pos;
}

void insertarOrdenado(const string& palabra, TPalabras& salida){
	int pos = 0;
	if(salida.nelms != MAX_PAL_DIST){
		pos = posicion(salida, palabra);
		abrirHueco(salida, pos);
		salida.palabras[pos] = palabra;
		salida.nelms++;
	}
}

void mostrar(const TPalabras& salida){
	cout << "Las palabras ordenadas de mayor a menor longitud son: " << endl;
	for(int i = 0; i < salida.nelms; i++){
		cout << salida.palabras[i] << " ";
	}
}

int main(){
	string palabra;
	TPalabras salida;
	cout << "Introduzca un texto (FIN para terminar): ";
	cin >> palabra;
	while(palabra != FIN){
		if(!esta(palabra, salida)){
			insertarOrdenado(palabra, salida);
		}
		cin >> palabra;
	}
	mostrar(salida);
}