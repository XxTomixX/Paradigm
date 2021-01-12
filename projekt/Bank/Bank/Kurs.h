#ifndef KURS_H
#define KURS_H

#include <iostream>

using namespace std;

class Kurs {

private:
	double kwota;
	string waluta;

public:
	static double sprawdz_kurs(double kwota,string waluta);
};

#endif
