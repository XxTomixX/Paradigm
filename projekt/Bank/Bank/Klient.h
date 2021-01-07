#ifndef KLIENT_H
#define KLIENT_H

#include "Osoba.h"
#include <iostream>
#include <string>

using namespace std;

class Klient : Osoba {

private:
	int pesel;
	int nip;

public:
	void zaloguj(int id, string haslo);

	void wyloguj();

	void zarejestruj(string haslo);

	void usun_konto();

	void zamroz_konto();

	bool sprawdz_poprawnosc_danych(int id, string haslo, int string_imie, int string_nazwisko);

	string odczytaj_dane_klienta(int id, string haslo);

	string wyswietl_blad(string blad);

	bool czy_klient_istnieje(int id);

	bool wprowadz_konto_do_bazy(int id, string haslo, int string_imie, int string_nazwisko, int int_pesel);

	bool usun_konto_z_bazy(int id, string haslo, int string_imie, int string_nazwisko, int int_pesel);

	void wyslij_kod(int id, int nrT);

	int wybierz_metode();

	bool sprawdz_kod(int code);

	Klient(string im,string na,int pe, int ni):Osoba(im,na)
	{
		pesel = pe;
		nip = ni;
	}
};

#endif
