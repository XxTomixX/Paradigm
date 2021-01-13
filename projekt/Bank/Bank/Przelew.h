#ifndef PRZELEW_H
#define PRZELEW_H

#include"Blik.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Przelew {

private:
	unsigned long int id_odbiorca;
	double kwota;
	unsigned long int id_przelewu;
	string typ_przelewu;
	long long int ID;

public:


	void stworz_przelew(unsigned long int id_odbiorca, double kwota);

	void blik_menu(Blik*& nowy, double k, unsigned long int id_od);

	bool wyslij_przelew();

	void anuluj_przelew();

	bool potwierdz_wykonanie_przelewu(bool przelac);

	void kod_weryfikacji();

	void zapisz_przelew_w_bazie(unsigned long int id_odbiorca, string typ_przelewu);

	void potwierdz_przelew();

	Przelew(unsigned long int id_o = 0, double kwo = 0, unsigned long int id_p = 0, string t_p = "", long long int ID = 0) : id_odbiorca(id_o), kwota(kwo), id_przelewu(id_p), typ_przelewu(t_p), ID(ID)
	{

	}

};

#endif