#include <iostream>
#include <array>
#include <string>
#include <cassert>
using namespace std;
const int MAX_DIST = 10;
struct Persona{
	string nombre = "";
	double gastos = 0.0;
};
typedef array <Persona, MAX_DIST> APersonas;
struct Datos{
	int nelms = 0;
	APersonas elm;
};

double vabs(double x){
	if(x < 0){
		x = -x;
	}
	return x;
}

double menor(double a, double b){
	double x = a;
	if(b < x){
		x = b;
	}
	return x;
}

void inicializar(Datos& dt){
	dt.nelms = 0;
}

bool es_cero(double x){
	return vabs(x) < 1e-3;
}

int buscar(const Datos& dt, const string& x){
	int i = 0;
	while((i < dt.nelms) && (x != dt.elm[i].nombre)){
		i++;
	}
	if(i == dt.nelms){
		i = -1;
	}
	return i;
}

void anyadir(Datos& dt, const Persona& p){
	int pos = buscar(dt, p.nombre);
	if(0 <= pos && pos < dt.nelms){
		dt.elm[pos].gastos += p.gastos;
	}else if(dt.nelms < int(dt.elm.size())){
		dt.elm[dt.nelms] = p;
		dt.nelms++;
	}
}

void leer(Persona& p){
	cout << "Nombre: ";
	cin >> p.nombre;
	if(p.nombre != "FIN"){
		cout << "Gastos: ";
		cin >> p.gastos;
	}
}

void leer(Datos& dt){
	Persona p;
	inicializar(dt);
	cout << "Introduzca nombres y gastos (FIN para terminar)" << endl;
	leer(p);
	while(p.nombre != "FIN"){
		anyadir(dt, p);
		leer(p);
	}
}

void mostrar(const Datos& dt){
	cout << endl;
	for(int i = 0; i < dt.nelms; i++){
		cout << dt.elm[i].nombre << " ha gastado en comun " << dt.elm[i].gastos << endl; 
	}
}

double media(const Datos& dt){
	double suma = 0;
	if(dt.nelms > 0){
		for(int i = 0; i < dt.nelms; i++){
			suma += dt.elm[i].gastos;
		}
		suma = suma / dt.nelms;
	}
	return suma;
}

void diferencias(const Datos& dt, Datos& dif, double med){
	dif = dt;
	for(int i = 0; i < dif.nelms; i++){
		dif.elm[i].gastos -= med;
	}
}

void mostrar_diferencias(const Datos& dif){
	cout << endl;
	for(int i = 0; i < dif.nelms; i++){
		if(es_cero(dif.elm[i].gastos)){
			cout << dif.elm[i].nombre << " esta a la par " << endl;
		}else if(dif.elm[i].gastos > 0){
			cout << dif.elm[i].nombre << " debe recibir " << vabs(dif.elm[i].gastos) << endl;
		}else{
			cout << dif.elm[i].nombre << " debe pagar " << vabs(dif.elm[i].gastos) << endl;
		}
	}
}

void mayor_menor(const Datos& dt, int& imayor, int& imenor){
	imayor = 0;
	imenor = 0;
	for(int i = 1; i < dt.nelms; i++){
		if(dt.elm[i].gastos > dt.elm[imayor].gastos){
			imayor = i;
		}else if(dt.elm[i].gastos < dt.elm[imenor].gastos){
			imenor = i;
		}
	}
}

bool todos_cero(const Datos& dt){
	int i = 0;
	while((i < dt.nelms) && (es_cero(dt.elm[i].gastos))){
		i++;
	}
	return (i = dt.nelms);
}

void movimientos(Datos& mov){
	cout << endl;
	while (!todos_cero(mov)){
		int imayor, imenor;
		mayor_menor(mov, imayor, imenor);
		double dd = menor(vabs(mov.elm[imayor].gastos), vabs(mov.elm[imenor].gastos));
		cout << mov.elm[imenor].nombre << " paga " << dd << " a " << mov.elm[imayor].nombre << endl;
		mov.elm[imayor].gastos -= dd;
		mov.elm[imenor].gastos += dd;
	}
}

void ajustar_cuentas(const Datos& dt){
	double med = media(dt);
	cout << endl << "La media de gastos en comun es " << med << endl;
	Datos dif;
	diferencias(dt, dif, med);
	mostrar_diferencias(dif);
	Datos mov = dif;
	movimientos(mov);
}

int main(){
	Datos dt;
	leer(dt);
	cout << endl;
	mostrar(dt);
	ajustar_cuentas(dt);
}