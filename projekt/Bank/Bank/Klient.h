#include "Osoba.h"
#include "Konto.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Klient : Osoba {

private:
	string pesel;
	string nip;
	// wektor do przechowania konta klienta z bazy danych
	vector<Konto*> konta;	

public:

	void zaloguj(string id, string haslo);
	void wyloguj();
	bool zarejestruj(string haslo, string email, string tel);
	bool sprawdz_poprawnosc_danych(string haslo, string email, string tel);
	string wyswietl_blad(string blad);
	bool czy_klient_istnieje();
	bool wprowadz_konto_do_bazy(string haslo, string email, string tel);
	void podajidkont(string haslo);

	Klient(string im = "",string na = "",string pe = "", string ni = ""):Osoba(im, na),pesel(pe),nip(ni){}

};


