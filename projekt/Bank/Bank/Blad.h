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
	int id_bledu;
	bool czy_naprawiony;
	string data;
	

public:
	Blad() {};
	void utworz_blad(string tytul, string tresc);
};

#endif
