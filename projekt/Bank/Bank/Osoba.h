#ifndef OSOBA_H
#define OSOBA_H
#include <iostream>
#include <string>

using namespace std;

class Osoba {
public:
	string imie;
	string nazwisko;
	Osoba() {};
	Osoba(string im, string na)
	{
		imie = im;
		nazwisko = na;
	}

};

#endif

