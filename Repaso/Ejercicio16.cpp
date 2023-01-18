#include <iostream>
#include <string>
#include <array>
using namespace std;
const string FIN = "fin";
const int MAX_LONG_DIST = 10;
struct TPalabras{
	int longitud;
	int cont;
};
typedef array <TPalabras, MAX_LONG_DIST> TArray;
struct TDatos{
	TArray elementos;
	int nelms;
};

void inicializar(TDatos& datos){
	datos.nelms = 0;
}

int buscarLongitud(const TDatos& datos, int lng){
	int i = 0;
	while((i < datos.nelms) && (lng != datos.elementos[i].longitud)){
		i++;
	}
	return i; //DEVUELVE LA POSICION DE LA LONGITUD EN CUESTION
}

void anyadirPalabra(TDatos& datos, const string& palabra){
	int longitud = palabra.size();
	int idx = buscarLongitud(datos, longitud);
	if(idx < datos.nelms){
		datos.elementos[idx].cont++; //AUMENTA EL CONTADOR EN LA POSICION DE LA LONGITUD
	}else{
		datos.elementos[datos.nelms].longitud = longitud;
		datos.elementos[datos.nelms].cont = 1;
		datos.nelms++;
	}
}

void leer(TDatos& datos){
	string palabra;
	cout << "Introduzca un texto (fin para terminar): " << endl;
	cin >> palabra;
	inicializar(datos);
	while(palabra != FIN){
		anyadirPalabra(datos, palabra);
		cin >> palabra;
	}
}

void mostrar(TDatos& datos){
	cout << "Longitudes Repeticiones \n";
	for(int i = 0; i < datos.nelms; i++){
		cout << datos.elementos[i].longitud << "          " << datos.elementos[i].cont << endl;
	}
}

int main(){
	TDatos datos;
	leer(datos);
	mostrar(datos);
}