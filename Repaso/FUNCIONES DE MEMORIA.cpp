#include <iostream>
#include <string>
#include <array>

//FUNCION QUE COMPRUEBA SI UN ELEMENTO ESTA EN UN ARRAY
bool esta(const string& palabra, const TPalabras& salida){
	int i = 0;
	while(i < int(salida.palabras.size()) && salida.palabras[i] != palabra){
		i++;
	}
	return (i < salida.palabras.size()); 
}

//FUNCION QUE ENCUENTRA LA POSICION DE UN ELEMENTO EN UN ARRAY
int buscar(char c, const string& pal){
	int ind = 0;
	while((ind < int(pal.size())) && (pal[ind] != c)){
		ind++;
	}
	return ind;
}

//FUNCION QUE CUENTA LAS LETRAS EN COMUN EN DOS STRINGS
int caracteresComun(const string& palabra, const string& patron){
	int cnt = 0;
	int ind = 0;
	int pos = 0;
	string palabra_auxiliar;
	palabra_auxiliar = palabra;
	while(ind < int(patron.size())){
		pos = buscar(patron[ind], palabra_auxiliar);
		if(pos < int(palabra_auxiliar.size())){
			palabra_auxiliar[pos] = ' ';
			cnt++;
		}
		ind++;
	}
	return cnt;
}

//FUNCION QUE DEVUELVE LA MEDIA DE UN ELEMENTO DE UNA MATRIZ CON SUS VECINOS

bool es_valido(const Matriz& m, int f, int c, int ff, int cc){
	return (0 <= f+ff && f+ff < int(m.size())) && (0 <= c+cc && c+cc < int(m[f+ff].size()));
}

double media(const Matriz& m, int f, int c){
	int nvec = 0;
	int suma = 0;
	for(int ff = -1; ff <= +1; ff++){
		for(int cc = -1; c <= +1; c++){
			if(es_valido(m, f, c, ff, cc)){
				suma += m[f+ff][c+cc];
				nvec++;
			}
		}
	}
	return double(suma) / double(nvec);
}

