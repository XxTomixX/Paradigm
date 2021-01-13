#ifndef BLIK_H
#define BLIK_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Blik {
private:
	unsigned long int id_odbiorca;
	double kwota;
	unsigned long int id_przelewu;
	string typ_przelewu;

public:
	void generuj_i_zweryfikuj_kod_blik();

	string wyswietl_blad();

	void terminal_request();

	void zapisz_przelew_w_bazie(unsigned long int id_odbiorca, string typ_przelewu);

	void stworz_przelew();

	void anuluj_przelew();
};

#endif