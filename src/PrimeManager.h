#pragma once

#include <iostream>
#include <fstream>
#include <vector>

typedef unsigned long ulong;

class PrimeManager {
	friend class GoldbachAdmin;
	std::vector<ulong> primeList;
	std::fstream fprime;

	void open(const char* name);
//public:


	PrimeManager(const char* name);
	void close(void);

	ulong operator [](size_t index);
	ulong at(size_t index) { return (*this)[index]; }
	std::vector<ulong>* primes(void) { return &primeList; }
	size_t size(void) { return primeList.size(); }

	ulong new_prime(void);
	bool is_prime(ulong number);



};