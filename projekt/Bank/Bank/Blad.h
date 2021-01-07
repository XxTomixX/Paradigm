#ifndef BLAD_H
#define BLAD_H
#include "Data.h"


class Blad {

private:
	string tytul;
	string tresc;
	int id_bledu;
	bool czy_naprawiony;
	Data data;

public:
	void utworz_blad(string tytul, string tresc);
};

#endif
