#include "GoldbachManager.h"

using namespace std;

GoldbachManager::GoldbachManager(const char * name, vector <ulong> *pl): printBit(0), name(name), primeList(pl) {
	open(name);
	if (primeList == NULL) {
		cerr << "[ERROR] PrimeManager link unsuccessful" << endl;
	}
	if (actualEven > primeList->back())
		cerr << "[ERROR] Not enough primes" << endl;
}

bool GoldbachManager::is_goldbach(ulong number) { //devuelve si el número es goldbach
	ulong sum;
	while(1) {
		sum = primeList->at(smallIndex) + primeList->at(bigIndex); //suma los primos de la posición smallIndex y bigIndex
		if (smallIndex > bigIndex) //tras mirar todos los primos menores al número , la conjetura de Goldbach es falsa
			return false;
		else if (sum == number) //cumple la conjetura de Goldbach
			return true;
		else if (sum < number)
			smallIndex++;
		else if (sum > number)
			bigIndex--;
	}
}

ulong GoldbachManager::new_goldbach(void) { //calcula otro número par y comprueba si cumple la conjetura
	actualEven += 2;
	if (primeList->at(indexReg + 1) < actualEven - 1)
		indexReg++;
	smallIndex = 1;
	bigIndex = indexReg;
	while (1) {
		if (is_goldbach(actualEven)) { //comprueba si es primo
			fgold << actualEven << " = " << primeList->at(smallIndex) << " + " << primeList->at(bigIndex) << endl;
			if (printBit)
				cout << actualEven << " = " << primeList->at(smallIndex) << " + " << primeList->at(bigIndex) << endl;
			return actualEven;
		}
		else { //si no lo es, suma 2 (se sobreentiende que es impar)
			fgold << actualEven << "NO CUMPLE LA CONJETURA DE GOLDBACH" << endl;
			cout << actualEven << "NO CUMPLE LA CONJETURA DE GOLDBACH" << endl;
			return 0;
		}
	}
}

void GoldbachManager::init_index(void) {
	indexReg = 0;
	while (primeList->at(indexReg + 1) < actualEven - 1) {
		indexReg++;
	}
}

void GoldbachManager::close(void) {
	if (fgold.is_open()) //cierra el fichero si está abierto
		fgold.close();
}

void GoldbachManager::open(const char * name) {
	close(); //cierra el fichero si está abierto
	fgold.open(name, ios::in);

	if (fgold.fail()) {
		cerr << "[ERROR] Opening file" << endl;
		actualEven = 4;
		fgold.close();
		fgold.open(name, ios::out);
		fgold << "4" << endl << "                             " << endl;
		fgold << "4 = 2 + 2" << endl;
	}
	else {
		fgold >> actualEven;
		if (!fgold.good()) {
			actualEven = 4;
			fgold.close();
			fgold.open(name, ios::out);
			fgold << "4" << endl;
			fgold << "4 = 2 + 2" << endl;
		}
	}
	close(); //cierra el fichero (en modo lectura)
	fgold.open(name, ios::app); //abre el fichero para no tener que abrirlo constantemente en modo APPEND (escribe al final)
}

void GoldbachManager::save(void) {
	close();
	fgold.open(name, ios::out | ios::in);
	fgold << actualEven << endl;
	close();
	fgold.open(name, ios::app);
}