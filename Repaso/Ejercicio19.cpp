#include <iostream>
#include <array>
#include <string>
using namespace std;
const string FIN = "FIN";
const int MAX = 10;
struct Persona{
	string nombre;
	int resultado;
	int dinero;
};
typedef array <Persona, MAX> TArray;
struct TDatos{
	int nelms;
	TArray elm;
};

void inicializar(TDatos& datos){
	datos.nelms = 0;
}

bool esta(const string& nombre, const TDatos& dt){
	int i = 0;
	while((i < int(dt.elm.size())) && (dt.elm[i].nombre != nombre)){
		i++;
	}
	return i < dt.elm.size();
}

int buscar(const string& nombre, const TDatos& dt){
	int i = 0;
	while(i < int(dt.elm.size()) && dt.elm[i].nombre != nombre){
		i++;
	}
	return i;
}

void leer_persona(TDatos& dt, string nombre){
	dt.nelms++;
	cout << "Nombre: ";
	cin >> nombre;
	if(nombre != FIN){
		dt.elm[dt.nelms].nombre = nombre;
		cout << "Resultado (0 1 2): ";
		cin >> dt.elm[dt.nelms].resultado;
		cout << "Cantidad (> 0): ";
		cin >> dt.elm[dt.nelms].dinero;	
	}
}

void leer(TDatos& dt, string nombre_){
	cout << "Introduzca nombres, resultados y cantidades apostadas (FIN para terminar): " << endl;
	cout << "Nombre: ";
	cin >> nombre_;
	if(nombre_ != FIN){
		dt.elm[dt.nelms].nombre = nombre_;
		cout << "Resultado (0 1 2): ";
		cin >> dt.elm[dt.nelms].resultado;
		cout << "Cantidad (> 0): ";
		cin >> dt.elm[dt.nelms].dinero;
		while(nombre_ != FIN){
			if(!esta(dt.elm[dt.nelms].nombre, dt)){
				leer_persona(dt, nombre_);
			}else if(esta(dt.elm[dt.nelms].nombre, dt)){
				int pos;
				pos = buscar(dt.elm[dt.nelms].nombre, dt);
				dt.elm[dt.nelms].dinero += dt.elm[pos].dinero;
				dt.nelms--;
			}
			leer_persona(dt, nombre_);
		}
	}
}

void mostrar(const TDatos& dt){
	for(int i = 0; i < int(dt.elm.size()); i++){
		cout << dt.elm[i].nombre << " " << dt.elm[i].resultado << " " << dt.elm[i].dinero << endl;
	}
	cout << endl << endl;
}

int suma_cantidades_apostadas(const TDatos& dt){
	int suma = 0;
	for(int i = 0; i < int(dt.elm.size()); i++){
		suma += dt.elm[i].dinero;
	}
	return suma;
}

int suma_cantidades_acertadas(const TDatos& dt, int resultado){
	int suma = 0;
	for(int i = 0; i < int(dt.elm.size()); i++){
		if(dt.elm[i].resultado == resultado){
			suma += dt.elm[i].dinero;
		}
	}
	return suma;
}

inline int ratio_total(int t1, int t2){
	return t1/t2;
}

void reintegro(const TDatos& dt, int resultado, int ratio){
	for(int i = 0; i < dt.elm.size(); i++){
		if(dt.elm[i].resultado != resultado){
			cout << dt.elm[i].nombre << " " << dt.elm[i].resultado << " " << dt.elm[i].dinero << " -> " << "0" << endl;
		}else{
			cout << dt.elm[i].nombre << " " << dt.elm[i].resultado << " " << dt.elm[i].dinero << " -> " << (dt.elm[i].dinero*ratio) << endl;
		}
	}
}

void reparto(const TDatos& dt, int resultado){
	int t1 = 0;
	int t2 = 0;
	int ratio = 0;
	t1 = suma_cantidades_apostadas(dt);
	t2 = suma_cantidades_acertadas(dt, resultado);
	ratio = ratio_total(t1, t2);
	cout << "Total apostado: " << t1 << endl;
	cout << "Total ganador: " << t2 << endl;
	cout << "Ratio: " << ratio << endl;
	cout << endl << endl;
	reintegro(dt, resultado, ratio);
}

int main(){
	TDatos dt;
	inicializar(dt);
	string nombre_;
	leer(dt, nombre_);
	int resultado = 0;
	cout << "Introduzca el resultado final de la apuesta (0 1 2): ";
	cin >> resultado;
	mostrar(dt);
	reparto(dt, resultado);
}