#include <iostream>
#include <array>
#include <iomanip>
#include <string>
using namespace std;

int divnum(int num){
	int cnt = 0;
	for(int i = 1; i <= num;  i++){
		if(num % i == 0){
			cnt++;
		}
	}
	return cnt;
}

bool primo(int num){
	bool es_primo = false;
	int divisores = divnum(num);
	if(divisores == 2){
		es_primo = true;
	}
	if(num <= 1){
		es_primo = false;
	}
	return es_primo;
}

int buscar_mayor_primo(int& act){
	cout << "Introduzca una secuencia de enteros positivos acabada en 0: ";
	cin >> act;
	int mayor_primo = 0;
	while(act != 0){
		if(primo(act)){
			if(act > mayor_primo){
				mayor_primo = act;
			}
		}
		cin >> act;
	}
	return mayor_primo;
}

void mostrar_resultado(int resultado){
	if(resultado == 0){
		cout << endl;
		cout << "No hay ningun primo en la secuencia" << endl;
	}else{
		cout << endl;
		cout << "El mayor primo de la secuencia es: " << resultado << endl;
	}
}

int main(){
	int act;
	int resultado = buscar_mayor_primo(act);
	mostrar_resultado(resultado);
}