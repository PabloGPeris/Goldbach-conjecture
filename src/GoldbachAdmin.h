#pragma once

#include "GoldbachManager.h"
#include "PrimeManager.h"

class GoldbachAdmin {
	GoldbachManager *gm;
	PrimeManager *pm;



public:
	GoldbachAdmin(const char * gname, const char * pname); //nombre de fichero de números de Goldbach y nombre de fichero de primos

	ulong new_goldbach(void);
	void close(void);
	void print(bool b) { gm->print(b); }
};