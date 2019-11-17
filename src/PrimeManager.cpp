#include "PrimeManager.h"
#include <math.h>

using namespace std;

//constructor
PrimeManager::PrimeManager(const char * name) {
	open(name);
}

ulong PrimeManager::operator [](size_t index) {
	return primeList[index];
}

bool PrimeManager::is_prime(ulong number) { //comprueba si el n�mero es primo
	while (primeList.back() < sqrt(number)) { //hace falta n�meros primos hasta su ra�z cuadrada para comprobarlo
		new_prime();
	}
	for (int i = 0; primeList[i] <= sqrt(number); i++) {
		if (!(number % primeList[i])) //si es divisible por un primo anterior (no superior a su ra�z cuadrada), no es primo
			return false;
	}
	return true;
}

ulong PrimeManager::new_prime(void) { //crea un nuevo n�mero primo y lo a�ade al fichero
	ulong number = primeList.back() + 2;
	while (1) {
		if (is_prime(number)) { //comprueba si es primo
			primeList.push_back(number); //lo a�ade
			fprime << number << endl;
			return number;
		}
		else //si no lo es, suma 2 (se sobreentiende que es impar)
			number += 2;
	}
}

void PrimeManager::close(void) { 
	if (fprime.is_open()) //cierra el fichero si est� abierto
		fprime.close(); 
}

void PrimeManager::open(const char * name) {
	ulong number;
	close(); //cierra el fichero si est� abierto
	fprime.open(name, ios::in);

	if (fprime.fail()) {
		cerr << "[ERROR] Opening file" << endl;
	}
	else {
		while (1) { //carga los valores del fichero 
			fprime >> number;
			if (fprime.eof()) break; //si llega al final del fichero, rompe el bucle
			primeList.push_back(number); //a�ade el n�mero le�do
		}
	}
	close(); //cierra el fichero (en modo lectura)
	fprime.open(name, ios::app); //abre el fichero para no tener que abrirlo constantemente en modo APPEND (escribe al final)
	if (size() < 1) { //si hay menos de 2 datos (primos 2 y 3) los a�ade para empezar con ellos y los pone en el fichero
		primeList.push_back(2);
		primeList.push_back(3);
		fprime << 2 << endl;
		fprime << 3 << endl;
	}
	else if (size() < 2) {
		primeList.push_back(3);
		fprime << 3 << endl;
	}

}
