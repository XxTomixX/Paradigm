#ifndef BANKOMAT_H
#define BANKOMAT_H

using namespace std;

class Bankomat {

private:
	double ilosc_gotowki_w_bankomacie;
	int id_bankomatu;

public:
	bool wplac_pieniadze(double kwota);

	bool wyplac_pieniadze(double kwota);

	bool czy_poprawna_ilosc_gotowki_w_maszynie(int kwota);
};

#endif
