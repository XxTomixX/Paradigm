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
	long long int ID;

public:
	void generuj_i_zweryfikuj_kod_blik();

	string wyswietl_blad();

	void terminal_request();

	void zapisz_przelew_w_bazie(unsigned long int id_odbiorca, string typ_przelewu, long long int ID);

	void stworz_przelew();

	void anuluj_przelew();

	Blik(unsigned long int id_o = 0, double kwo = 0, unsigned long int id_p = 0, string t_p = "", long long int ID = 0) : id_odbiorca(id_o), kwota(kwo), id_przelewu(id_p), typ_przelewu(t_p), ID(ID)
	{

	}
};

#endif