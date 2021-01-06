#ifndef KREDYT_H
#define KREDYT_H

#include "Data.h"

using namespace std;

class Kredyt {

private:
	string typ_kredytu;
	double kwota;
	string waluta_kredytu;
	double oprocentowanie;
	Data data_zaciagniecia;
	Data termin_splaty;
	int id_kredytu;

public:
	void przewalutowanie_kredytu(string waluta);

	bool sprawdz_zdolnosc_kredytowa();

	void utworz_kredyt(string typ_kredytu, double kwota, string waluta_kredytu, double oprocentowanie);

	bool sprawdzanie_poprawnosci_danych_kredytowych();

	void zaakceptuj_kredyt();

	void zapisz_kredyt_w_bazie();
};

#endif
