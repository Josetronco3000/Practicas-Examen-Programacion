#include <iostream>
#include <array>
#include <string>
using namespace std;
const string FIN = "FIN";
const int MAX_PAL_DIST = 10;
typedef array <string, MAX_PAL_DIST> TArray;
struct TPalabras{
	TArray palabras;
	int num_pal;
};

int sumaASCII(const string& palabra){
	int suma = 0;
	for(int i = 0; i < int(palabra.size()); i++){
		suma += int(palabra[i]);
	}
	return suma;
}

bool esta(const TPalabras &pal, const string &palabra){
	int i = 0;
	while(i < pal.num_pal && pal.palabras[i] != palabra){
		i++;
	}
	return (i < pal.num_pal);
}

void abrirHueco(TPalabras &pal, int pos){
	for(int i = pal.num_pal; i > pos; i--){
		pal.palabras[i] = pal.palabras[i-1];
	}
}

int posicion(const TPalabras &pal, const string &palabra){
	int pos = 0;
	while((pos <pal.num_pal) && (pal.palabras[pos] <= palabra)){
		pos++;
	}
	return pos;
}

void insertarOrdenado(TPalabras &pal, const string &palabra){
	int pos;
	if(pal.num_pal != MAX_PAL_DIST){
		pos = posicion(pal, palabra);
		abrirHueco(pal, pos);
		pal.palabras[pos] = palabra;
		pal.num_pal++;
	}
}

void mostrar(const string &salida, const TPalabras &pal){
	cout << "Las palabras que son menores que " << salida << " son: " << endl;
	for(int i = 0; i < pal.num_pal; i++){
		cout << pal.palabras[i] << " ";
	}
}

int main(){
	string primera, palabra;
	TPalabras salida;
	int suma;
	salida.num_pal = 0;
	cout << "Introduzca secuencia de palabras terminada en FIN: ";
	cin >> primera;
	suma = sumaASCII(primera);
	if(primera != FIN){
		cin >> palabra;
		while(palabra != FIN){
			if(!esta(salida, palabra) && sumaASCII(palabra) < suma){
				insertarOrdenado(salida, palabra);
			}
			cin >> palabra;
		}
	}
	mostrar(primera, salida);
}