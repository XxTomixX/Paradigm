#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "Osoba.h"
#include "Konto.h"
#include "Blad.h"

class Administrator : Osoba {

private:
	string haslo;
	string email;
	int id;

public:
	void zaloguj(int id, string haslo);

	void wyloguj();

	Konto pobierz_dane_kont();

	void zaktualizuj_dane_konta(Konto k);

	void zamroz_konto(Konto k);

	void wyswietl_historie_dzialan(Konto k);

	void modyfikuj_stan_dzialania(Konto k);

	Blad pobierz_liste_bledow();

	void sprawdz_stan_bledu(Blad b);

	Blad zaktualizuj_liste_bledow();

	Konto znajdz_konto(int id);

	void zmien_status_bledu();

	void monitoruj_lokaty();

	void monitoruj_kredyty();

	void monituruj_przelewy();

	void rejestracja(string id_od_banku, string haslo);

	void odczytaj_dane_administrator();

	void sprawdz_poprawnosc_danych();

	void wyswietl_blad();
};

#endif
