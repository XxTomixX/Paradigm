#ifndef BLIK_H
#define BLIK_H

#include <iostream>

using namespace std;

class Blik {


public:
	int generuj_kod_blik();

	string wyswietl_blad();

	int terminal_request();

	bool zweryfikuj_kod();

	void stworz_przelew();

	void anuluj_przelew();
};

#endif
