#ifndef PRZELEW_H
#define PRZELEW_H

class Przelew {

private:
	Konto odbiorca;
	double kwota;
	Date data_nadania;
	int id_przelewu;

public:
	void wyslij_kod_potwierdzajacy();

	boolean zweryfikuj_dane();

	void stworz_przelew(Konto odbiorca, int kwota_double);

	bool wyslij_przelew();

	void anuluj_przelew();

	bool potwierdz_wykonanie_przelewu(bool przelac);

	bool podaj_kod_weryfikacji(int kod);

	void zapisz_przelew_w_bazie();

	bool potwierdz_przelew();
};

#endif
