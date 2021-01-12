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

	void zglos_blad(string tytul, string tresc);

	bool modyfikuj_stan_konta(string operacja, int kwota);

	double stan_konta();

	void wyswietl_komunikat(string komunikat);

	void zamroz_srodki();

	void zaaktualizuj_dane_konta();

	void operacje_na_koncie();

	void przelew_menu(int& opreacja_przelew, Przelew*& nowy);

	void kredyt_menu(int &opreacja_kredyt, Kredyt * &nowy);

	double przewalutowanie(int &kwota, std::string &waluta);

	long long int get_id();

	void usun_konto();
	
	void zamroz_konto();
	
	bool get_zamrozone();

	Konto(string em = "",string nr = "",long long int i = 0,double sal = 0,bool czy = false):email(em),nr_telefonu(nr),id(i),saldo_konta(sal),czy_zamrozone(czy)
	{
	
	}

};

#endif
