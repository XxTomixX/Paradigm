#include "Bankomat.h"
#include "Konto.h"
#include "Baza.h"

using namespace std;

// pozwala wp³aciæ gotówkê na konta
bool Bankomat::wplac_pieniadze(Konto* konto) {
	
	if (czy_poprawna_ilosc_gotowki_w_maszynie())
	{
		string wplac = "UPDATE Klienci SET Saldo = Saldo +" + to_string(gotowka) + " WHERE ID ='" + to_string(konto->get_id()) + "';";
		Baza::wykonaj("klienci.db", wplac);
		return true;
	}
	else
	{
		cout << "Niepoprawna iloœæ" << endl;
		return false;
	}
	
}

// pozwala wyp³aciæ gotówkê z konta
bool Bankomat::wyplac_pieniadze(Konto* konto) {
	
	if (konto->get_saldo() > gotowka)
	{
		string wplac = "UPDATE Klienci SET Saldo = Saldo -" + to_string(gotowka) + " WHERE ID ='" + to_string(konto->get_id()) + "';";
		Baza::wykonaj("klienci.db", wplac);
		return true;
	}
	else
	{
		cout << "Za ma³o œrodków na koncie" << endl;
		return false;
	}

}

bool Bankomat::czy_poprawna_ilosc_gotowki_w_maszynie() {
	// Polaczenie z bankomatem
	return true;
}
