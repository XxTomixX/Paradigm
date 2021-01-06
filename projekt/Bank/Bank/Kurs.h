#ifndef KURS_H
#define KURS_H

#include <iostream>

using namespace std;

class Kurs {

private:
	double kwota;
	string waluta;

public:
	double sprawdz_kurs(int kwota);
};

#endif
