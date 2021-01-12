#ifndef LOKATA_H
#define LOKATA_H

#include <string>
#include <iostream>

using namespace std;

class Lokata {

private:
	string typ_lokaty;
	double kwota;
	int oprocentowanie;
	string data_otworzenia;
	int id_lokaty;

public:
	bool zweryfikuj_dane(int typ_lokaty_string, double kwota, int oprocentowanie, string data_otworzenia, int id_lokaty);

	void stworz_lokate(int typ_lokaty_string, double kwota, int oprocentowanie, string data_otworzenia, int id_lokaty);

	void anuluj_lokate();

	void zapisz_lokate_do_bazy(Lokata L);
};

#endif
