#pragma once

#include <iostream>
#include <fstream>
#include <vector>

typedef unsigned long ulong;

class GoldbachManager
{
	friend class GoldbachAdmin;

	ulong actualEven;
	size_t bigIndex;
	size_t smallIndex;
	size_t indexReg;
	std::vector <ulong> * primeList;
	std::fstream fgold;
	const char * name;

	bool printBit;

	void open(const char* name);

//public:
	GoldbachManager(const char * name, std::vector <ulong> *pl);

	void init_index(void);
	void close(void);
	void save(void);
	void print(bool b) { printBit = b; }

	ulong act(void) { return actualEven; }
	size_t idx(void) { return indexReg; }

	ulong new_goldbach(void);
	bool is_goldbach(ulong number);
};

