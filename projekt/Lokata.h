#ifndef LOKATA_H
#define LOKATA_H

class Lokata {

private:
	string typ_lokaty;
	double kwota;
	int oprocentowanie;
	Data data_otworzenia;
	int id_lokaty;

public:
	boolean zweryfikuj_dane(int typ_lokaty_string, double kwota, int oprocentowanie, Data data_otworzenia, int id_lokaty);

	void stworz_lokate(int typ_lokaty_string, double kwota, int oprocentowanie, Data data_otworzenia, int id_lokaty);

	void anuluj_lokate();

	void zapisz_lokate_do_bazy(Lokata L);
};

#endif
