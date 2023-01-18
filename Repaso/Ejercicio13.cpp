#include <iostream>
#include <string>
#include <array>
using namespace std;
const int MAX_PAL_DIST = 10;
const string FIN = "FIN";
typedef array <string, MAX_PAL_DIST> TArray;
struct TPalabras{
	TArray palabras;
	int nelms;
};

void inicializar(TPalabras& salida){
	salida.nelms = 0;
}

int buscar(char c, const string& pal){
	int ind = 0;
	while((ind < int(pal.size())) && (pal[ind] != c)){
		ind++;
	}
	return ind;
}

bool caracteresComun(const string& palabra, const string& patron, int x){
	int cnt = 0;
	int ind = 0;
	int pos = 0;
	string palabra_auxiliar;
	palabra_auxiliar = palabra;
	while((cnt < x) && (ind < int(patron.size()))){
		pos = buscar(patron[ind], palabra_auxiliar);
		if(pos < int(palabra_auxiliar.size())){
			palabra_auxiliar[pos] = ' ';
			cnt++;
		}
		ind++;
	}

	return cnt >= x;
}

bool esta(const string& palabra, const TPalabras& salida){
	int i = 0;
	while(i < int(salida.palabras.size()) && salida.palabras[i] != palabra){
		i++;
	}
	return (i < salida.palabras.size()); 
}

void mostrar_resultado(const TPalabras& salida){
	cout << "Resultado: " << endl;
	for(int i = 0; i < salida.nelms; i++){
		cout << salida.palabras[i] << " ";
	}
}

int main(){
	string palabra, patron;
	TPalabras salida;
	inicializar(salida);
	cout << "Introduzca el patron: ";
	cin >> patron;
	if(patron != FIN){
		int x = 0;
		cout << "Introduzca el valor de x: ";
		cin >> x;
		cout << "Introduzca el texto (FIN para terminar): " << endl;
		cin >> palabra;
		while(palabra != FIN){
			if(!esta(palabra, salida) && caracteresComun(palabra, patron, x)){
				salida.palabras[salida.nelms] = palabra;
				salida.nelms++;
			}
			cin >> palabra;
		}
	}
	mostrar_resultado(salida);
}