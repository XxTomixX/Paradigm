#ifndef PRZELEW_H
#define PRZELEW_H

#include "Konto.h"
#include "Data.h"

class Przelew {

private:
	Konto odbiorca;
	double kwota;
	Data data_nadania;
	int id_przelewu;

public:
	void wyslij_kod_potwierdzajacy();

	bool zweryfikuj_dane();

	void stworz_przelew(Konto odbiorca, int kwota_double);

	bool wyslij_przelew();

	void anuluj_przelew();

	bool potwierdz_wykonanie_przelewu(bool przelac);

	bool podaj_kod_weryfikacji(int kod);

	void zapisz_przelew_w_bazie();

	bool potwierdz_przelew();
};

#endif
