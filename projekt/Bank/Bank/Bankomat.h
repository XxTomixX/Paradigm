#ifndef BANKOMAT_H
#define BANKOMAT_H

#include "Konto.h"

using namespace std;

class Bankomat {

private:
	double gotowka;

public:
	bool wplac_pieniadze(Konto* konto);

	bool wyplac_pieniadze(Konto* konto);

	bool czy_poprawna_ilosc_gotowki_w_maszynie();

	Bankomat(double ilosc_wpl = 0) :gotowka(ilosc_wpl)
	{

	}

};

#endif
