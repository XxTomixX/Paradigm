#ifndef KONTO_H
#define KONTO_H

#include "Kurs.h"
#include "Kredyt.h"
#include "Przelew.h"
#include "Lokata.h"
#include <vector>

using namespace std;

class Konto {

private:
	string email;
	string nr_telefonu;
	long long int id;
	double saldo_konta;
	bool czy_zamrozone;
	vector<Przelew*> przelewy;
	vector<Kredyt*> kredyty;
	vector<Lokata*> lokaty;


public:
	Kurs podaj_kurs(double i, string waluta);

	void zglos_blad(string tytul, string tresc);

	bool modyfikuj_stan_konta(string operacja, int kwota);

	double stan_konta();

	string wyswietl_komunikat(int numer_komunikatu);

	void zamroz_srodki();

	void zaaktualizuj_dane_konta();

	void operacje_na_koncie();

	long long int get_id();

	void usun_konto();
	
	void zamroz_konto();
	
	bool get_zamrozone();

	Konto(string em = "",string nr = "",long long int i = 0,double sal = 0,bool czy = false):email(em),nr_telefonu(nr),id(i),saldo_konta(sal),czy_zamrozone(czy)
	{
	
	}

};

#endif
