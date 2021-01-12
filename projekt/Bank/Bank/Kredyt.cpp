#include "Kredyt.h"
#include "Baza.h"

#include <iostream>

using namespace std;

void Kredyt::przewalutowanie_kredytu(string waluta) {
	// TODO - implement Kredyt::przewalutowanie_kredytu
	throw "Not yet implemented";
}

bool Kredyt::sprawdz_zdolnosc_kredytowa() {
	//Sprawdzenie klienta w krajowych rejestrach (zewnêtrzy system)
	return true;
}

bool Kredyt::sprawdzanie_poprawnosci_danych_kredytowych() {
	// TODO - implement Kredyt::sprawdzanie_poprawnosci_danych_kredytowych
	throw "Not yet implemented";
}

void Kredyt::zaakceptuj_kredyt() {
	// TODO - implement Kredyt::zaakceptuj_kredyt
	throw "Not yet implemented";
}

void Kredyt::lista_kredytow() {
	// TODO - implement Kredyt::zaakceptuj_kredyt
	throw "Not yet implemented";
}

void Kredyt::zapisz_kredyt_w_bazie(unsigned long int id) {
	string sql = "INSERT INTO Kredyty (ID,KlientID,Typ,Kwota,Waluta,Oprocentowanie,Zaciagniecie,Splata) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + to_string(id) + "','" + typ_kredytu + "','"
		+ to_string(kwota) + "','" + waluta_kredytu + "','" + to_string(oprocentowanie) + "',date('now'),date('now','+6 month')); ";
	Baza::wykonaj("kredyty.db", sql);
}
