#include <iostream>
#include <array>
#include <string>
using namespace std;
const int MAX = 20;
typedef array <int, MAX> TArray;
struct TMazo{
	TArray cartas_monton;
	int nmontones;
};

void inicializar(TMazo& mazo){
	mazo.nmontones = 0;
}

void leer(TMazo& mazo){
	cout << "Introduzca el numero de montones: ";
	cin >> mazo.nmontones;
	cout << "Introduzca el numero de cartas de cada monton: ";
	for(int i = 0; i < mazo.nmontones; i++){
		cin >> mazo.cartas_monton[i];
	}
}

void anyadir(TMazo& mazo, int cnt){
	mazo.nmontones++;
	mazo.cartas_monton[mazo.nmontones] = cnt;
}

void escribir(TMazo& mazo){
	for(int i = 0; i < mazo.nmontones; i++){
		cout << mazo.cartas_monton[i] << " ";
	}
	cout << endl;
}

void separar(TMazo& mazo){
	int cnt = 0;
	for(int i = 0; i < mazo.nmontones; i++){
		if(mazo.cartas_monton[i] != 0 && mazo.cartas_monton[i] > 0){
			mazo.cartas_monton[i]--;
			cnt++;
		}
	}
	anyadir(mazo, cnt);
}

void reorganizar(TMazo& mazo){
	while(mazo.nmontones <= MAX){
		separar(mazo);
		escribir(mazo);
	}
}

int main(){
	TMazo mazo;
	inicializar(mazo);
	leer(mazo);
	cout << "Resultado: " << endl;
	reorganizar(mazo);
}