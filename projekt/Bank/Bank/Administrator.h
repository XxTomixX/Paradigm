#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "Osoba.h"
#include "Konto.h"
#include "Blad.h"

class Administrator : Osoba {

private:
	int id;
	string haslo;
	string email;
	

public:
	void zaloguj(int id, string haslo);
	void wyloguj();
	void rejestracja(int id_od_banku, string haslo, string email);
	bool sprawdz_poprawnosc_danych(string haslo);
	bool wprowadz_konto_do_bazy(int id, string haslo, string email);

	Konto pobierz_dane_kont();
	Konto znajdz_konto(int id);

	void zaktualizuj_dane_konta(Konto k);
	void zamroz_konto(Konto k);
	void wyswietl_historie_dzialan(Konto k);
	void modyfikuj_stan_dzialania(Konto k);

	Blad pobierz_liste_bledow();
	Blad zaktualizuj_liste_bledow();
	void sprawdz_stan_bledu(Blad b);
	void zmien_status_bledu();
	
	void monitoruj_lokaty();
	void monitoruj_kredyty();
	void monituruj_przelewy();

	void wyswietl_blad(string);

	Administrator(int id, string im, string na, string h, string e) :Osoba(im, na)
	{
		haslo = h;
		email = e;
	}
};

#endif
