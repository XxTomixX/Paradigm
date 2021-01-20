#ifndef BLAD_H
#define BLAD_H
#include <string>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

class Blad {

private:
	string tytul;
	string tresc;
	long long int id_bledu;
	bool czy_naprawiony;
	string data;
public:
	unsigned long int get_id() { return id_bledu; } // do testow
	Blad() {};
	Blad(string tt, string tr, long long int i, bool cn, string d) : tytul(tt), tresc(tr), id_bledu(i), czy_naprawiony(cn), data(d) {};
	void utworz_blad(string tytul, string tresc);
};

#endif
