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
	string data_zaciagniecia;
	string termin_splaty;
	int id_kredytu;

public:
	void przewalutowanie_kredytu(string waluta);

	bool sprawdz_zdolnosc_kredytowa();

	Kredyt(string typ = "", double kwo = 0, string waluta = "", double opr = 0, string data_za = "", string term = "", long int id = 0) :typ_kredytu(typ), kwota(kwo), waluta_kredytu(waluta), oprocentowanie(opr), data_zaciagniecia(data_za), termin_splaty(term), id_kredytu(id)
	{

	}

	bool sprawdzanie_poprawnosci_danych_kredytowych();

	void zaakceptuj_kredyt();

	void zapisz_kredyt_w_bazie(unsigned long int id);

	void lista_kredytow();
};

#endif
