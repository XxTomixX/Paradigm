#ifndef PRZELEW_H
#define PRZELEW_H

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

public:
	//int wyslij_kod_potwierdzajacy();

	//bool zweryfikuj_dane();

	void stworz_przelew(unsigned long int id_odbiorca, double kwota);

	bool wyslij_przelew();

	void anuluj_przelew();

	bool potwierdz_wykonanie_przelewu(bool przelac);

	//bool podaj_kod_weryfikacji(int tab_kod_potwierdz[4]);
	void kod_weryfikacji();

	void zapisz_przelew_w_bazie(unsigned long int id_odbiorca);

	void potwierdz_przelew();

	Przelew(unsigned long int id_o = 0, double kwo = 0, unsigned long int id_p = 0, string t_p = "") : id_odbiorca(id_o), kwota(kwo), id_przelewu(id_p), typ_przelewu(t_p)
	{

	}

};

#endif

