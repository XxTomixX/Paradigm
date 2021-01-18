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
	// wektory do przechowywania danych z odpowiednich baz
	vector<Przelew*> przelewy;
	vector<Kredyt*> kredyty;
	vector<Lokata*> lokaty;


public:

	double stan_konta();

	// panel obslugi przelewow
	void przelew_menu(int& opreacja_przelew, Przelew*& nowy);	
	
	// panel obslugi lokat
	void lokata_menu();	
	void anuluj_lokate();
	void tworzenie_lokaty();
	void lista_lokat();

	// panel obslugi kredytow
	void kredyt_menu();	
	void przewalutowanie_kredytu();
	void tworzenie_kredytu();
	void lista_kredytow();

	// zwracane informacje o koncie
	long long int get_id();
	void zamroz_konto();
	bool get_zamrozone();
	long double get_saldo();
	void get_informacje();

	// panel operacji na koncie
	void operacje_na_koncie();	
	void zglos_blad();
	void wyplac_gotowke();
	void wplac_gotowke();
	double zmiananakurs();
	void usun_konto();
	void wyswietl_komunikat(string komunikat);

	Konto(string em = "",string nr = "",long long int i = 0,long double sal = 0,bool czy = false):email(em),nr_telefonu(nr),id(i),saldo_konta(sal),czy_zamrozone(czy){}

};

#endif
