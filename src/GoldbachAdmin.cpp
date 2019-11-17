#include "GoldbachAdmin.h"

using namespace std;

GoldbachAdmin::GoldbachAdmin(const char * gname, const char * pname) {
	pm = new PrimeManager(pname);
	gm = new GoldbachManager(gname, pm->primes());
	while (gm->act() > pm->at(pm->size() - 1))
		pm->new_prime();
	gm->init_index();
}

ulong GoldbachAdmin::new_goldbach(void) {
	while (gm->act() > pm->at(pm->size() - 1))
		pm->new_prime();

	return gm->new_goldbach();
}

void GoldbachAdmin::close(void) {
	gm->save();
	gm->close();
	pm->close();
	if (gm != NULL)
		delete gm;
	if (pm != NULL)
		delete pm;
}