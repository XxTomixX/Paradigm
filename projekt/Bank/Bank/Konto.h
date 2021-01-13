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
	long double saldo_konta;
	bool czy_zamrozone;
	vector<Przelew*> przelewy;
	vector<Kredyt*> kredyty;
	vector<Lokata*> lokaty;


public:

	void zglos_blad(string tytul, string tresc);

	double stan_konta();

	void wyswietl_komunikat(string komunikat);

	void operacje_na_koncie();

	void przelew_menu(int& opreacja_przelew, Przelew*& nowy);

	void kredyt_menu();

	void lokata_menu();

	void anuluj_lokate();

	void tworzenie_lokaty();

	void lista_lokat();

	void lista_kredytow();

	double przewalutowanie();

	long long int get_id();

	void usun_konto();
	
	void zamroz_konto();
	
	bool get_zamrozone();

	long double get_saldo();

	Konto(string em = "",string nr = "",long long int i = 0,long double sal = 0,bool czy = false):email(em),nr_telefonu(nr),id(i),saldo_konta(sal),czy_zamrozone(czy)
	{
	
	}

};

#endif
