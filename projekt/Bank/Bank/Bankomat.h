#ifndef BANKOMAT_H
#define BANKOMAT_H

#include "Konto.h"

using namespace std;

class Bankomat {

private:
	double gotowka;

public:
	//Funkcje obs³uguj¹ce wp³acanie i wyp³acanie gotówki
	bool wplac_pieniadze(Konto* konto);
	bool wyplac_pieniadze(Konto* konto);
	//Funkcje sprawdzaj¹ca czy wprowadzono odpowiedni¹ iloœæ gotówki (system zewnêtrzny)
	bool czy_poprawna_ilosc_gotowki_w_maszynie();
	Bankomat(double ilosc_wpl = 0) :gotowka(ilosc_wpl){}

};

#endif
