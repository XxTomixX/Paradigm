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
	long long int id_lokaty;

public:

	long long int get_id() { return id_lokaty; } // do testow
	void anuluj_lokate(long long int id);
	void zapisz_lokate_do_bazy(long long int id);
	void get_informacje();

	Lokata(string typ = "", double kwo = 0, int opr = 0, long long  int id_lo = 0) :typ_lokaty(typ), kwota(kwo), oprocentowanie(opr), id_lokaty(id_lo) {}

};

#endif
