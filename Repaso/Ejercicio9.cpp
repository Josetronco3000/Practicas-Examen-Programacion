#include <iostream>
#include <array>
#include <string>
using namespace std;
const int MAX_PAL_DIST = 15;
const string FIN = "FIN";
typedef array <string, MAX_PAL_DIST> TArray;
struct TPalabra{
	TArray palabras;
	int num_pal;
};

void inicializar(TPalabra& salida){
	salida.num_pal = 0;
}

void mostrar(const TPalabra& salida){
	cout << "Las palabras cuyos caracteres estan ordenados son: " << endl;
	for(int i = 0; i < salida.num_pal; i++){
		cout << salida.palabras[i] << " ";
	}
}

bool esta(const TPalabra& pal, const string& palabra){
	int i = 0;
	while(i < pal.num_pal && pal.palabras[i] != palabra){
		i++;
	}
	return (i < pal.num_pal);
}

bool caracteresOrdenados(const string& palabra){
	int i = 0;
	while(i < int(palabra.size())-1 && palabra[i] <= palabra[i+1]){
		i++;
	}
	return i >= int(palabra.size())-1;
}

int main(){
	string palabra;
	TPalabra salida;
	inicializar(salida);
	cout << "Introduzca el texto (FIN para terminar): " << endl;
	cin >> palabra;
	while(palabra != FIN){
		if(!esta(salida, palabra) && caracteresOrdenados(palabra)){
			salida.palabras[salida.num_pal] = palabra;
			salida.num_pal++;
		}
		cin >> palabra;
	}
	mostrar(salida);
}