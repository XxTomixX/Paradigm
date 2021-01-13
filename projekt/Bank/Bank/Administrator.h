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
	// proces logowania, rejestraci admina
	void zaloguj(int id, string haslo);
	void wyloguj();
	bool rejestracja(int id_od_banku, string haslo, string email);
	bool sprawdz_poprawnosc_danych(string haslo);
	bool wprowadz_konto_do_bazy(int id, string haslo, string email);
	void operacje_na_koncie();
	// operacje na koncie
	void znajdz_konto();
	void zaktualizuj_dane_konta(int id);
	void zamroz_konto(int id);
	void odmroz_konto(int id);
	void wyswietl_historie_dzialan(int id);
	// operacje na bledach
	void pobierz_liste_bledow();
	void zaktualizuj_liste_bledow();
	void sprawdz_stan_bledu(unsigned long int id);
	void zmien_status_bledu(unsigned long int id, int status);
	// operacje na czynnosciach
	void monitoruj_lokaty();
	void monitoruj_kredyty();
	void monituruj_przelewy();
	void modyfikuj_stan_dzialania(int id);
	// blad w dzialaniu
	void wyswietl_blad(string);
	// konstruktor
	Administrator() {};
	Administrator(string im, string na) :Osoba(im, na) {};
	Administrator(int i, string im, string na, string hs, string em) : id(i), haslo(hs), email(em), Osoba(im,na) {};
};

#endif
