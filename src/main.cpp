#include <iostream>
#include <vector>
#include "GoldbachAdmin.h"



using namespace std;

int main(void) {
	cout << "Cargando" << endl << "El proceso puede llevar unos segundos" << endl;

	//si da un problema con los ficheros porque no existen, no pasa nada, los crea de 0
	//si el problema lo da porque eno hay suficientes primos, lo soluciona automáticamente el GoldbachAdmin
	GoldbachAdmin ga("../resources/goldbach.txt", "../resources/primes.txt");
	size_t number;

	ga.print(true); //activa un bit que indica 

	cout << "Indica cuantos numeros pares nuevos quieres comprobar:" << endl;
	
	cin >> number;
	if (cin.bad()) {
		cerr << "Numero no valido" << endl;
		system("pause");
		ga.close();
		return 1;
	}
		
	for (int i = 0; i < number; i++)
		ga.new_goldbach();

	system("pause");
	ga.close();
	return 0;
}

