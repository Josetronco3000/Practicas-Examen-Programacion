#include <iostream>
#include <array>
#include <string>
using namespace std;
const int MAX_PAL_DIST = 15;
const string FIN = "FIN";
typedef array <string, MAX_PAL_DIST> Palabras;
struct Datos{
	int nelms = 0;
	Palabras elm;
};

int sumaASCII(string& palabra){
	int suma = 0;
	for(int i = 0; i < int(palabra.size()); i++){
		suma += int(palabra[i]);
	}
	return suma;
}

bool repetidas(const Datos& dt, string& palabra){
	int i = 0;
	while(i < int(dt.elm.size()) && dt.elm[i] != palabra){
		i++;
	}
	return (i < dt.elm.size());
}

void bucle(string& patron, string& texto, Datos& dt){
	cout << "Introduzca el patron: ";
	cin >> patron;
	cout << "Introduzca el texto (FIN para terminar): " << endl;
	cin >> texto;
	int i = 0;
	while(texto != FIN){
		if((sumaASCII(patron) == sumaASCII(texto)) && !repetidas(dt, texto)){
			dt.elm[i] = texto;
			dt.nelms++;
		}
		cin >> texto;
		i++;
	}
}

void mostrar(const Datos& dt){
	cout << "Las palabras que cumplen la condicion son: " << endl;
	for(int i = 0; i < int(dt.elm.size()); i++){
		cout << dt.elm[i] << " ";
	}
}

int main(){
	string patron;
	string texto;
	Datos dt;
	bucle(patron, texto, dt);
	mostrar(dt);
}