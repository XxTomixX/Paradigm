#ifndef PRZELEW_H
#define PRZELEW_H

using namespace std;

class Przelew {

private:
	
	unsigned long int id_odbiorca;
	double kwota;
	unsigned long int id_przelewu;

public:
	void wyslij_kod_potwierdzajacy();

	bool zweryfikuj_dane();

	void stworz_przelew(unsigned long int id_odbiorca, int kwota_double);

	bool wyslij_przelew();

	void anuluj_przelew();

	bool potwierdz_wykonanie_przelewu(bool przelac);

	bool podaj_kod_weryfikacji(int kod);

	void zapisz_przelew_w_bazie();

	bool potwierdz_przelew();

	Przelew(unsigned long int id_o=0, double kwo = 0, unsigned long int id_p = 0):id_odbiorca(id_o),kwota(kwo),id_przelewu(id_p)
	{
	
	}

};

#endif
