#ifndef KONTO_H
#define KONTO_H

#include "Kurs.h"

class Konto {

private:
	string email;
	string nr_telefonu;
	long long int id;
	double saldo_konta;
	bool czy_zamrozone;

public:
	Kurs podaj_kurs(double i, string waluta);

	void zglos_blad(string tytul, string tresc);

	bool modyfikuj_stan_konta(string operacja, int kwota);

	double stan_konta();

	string wyswietl_komunikat(int numer_komunikatu);

	Konto dostep_do_konta();

	void zamroz_srodki();

	void zaaktualizuj_dane_konta();

	long long int get_id();

	Konto(string em,string nr,long long int i,double sal,bool czy)
	{
		 email = em;
		 nr_telefonu =nr;
		 id=i;
		 saldo_konta=sal;
		 czy_zamrozone=czy;
	}

};

#endif
