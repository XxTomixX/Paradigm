#include "Kredyt.h"
#include "Baza.h"

#include <iostream>

using namespace std;

void Kredyt::przewalutowanie_kredytu() {

		if (waluta_kredytu == "ZL")
		{
			int przewalutowanie = 0;
			cout << "Przewalutowanie kredytu na 1: (USD) 2:(EUR)" << endl;
			cin >> przewalutowanie;
			if (przewalutowanie == 1)
			{
				string przewalutowanie1 = "UPDATE Kredyty SET Kwota = Kwota / 3.71, Waluta = 'USD' WHERE ID ='" + to_string(id_kredytu) + "';";
				Baza::wykonaj("kredyty.db", przewalutowanie1);
			}
			else if (przewalutowanie == 2)
			{
				string przewalutowanie2 = "UPDATE Kredyty SET Kwota = Kwota / 4.52, Waluta = 'EUR' WHERE ID ='" + to_string(id_kredytu) + "';";
				Baza::wykonaj("kredyty.db", przewalutowanie2);
			
			}
			else
			{
				cout << "Nie ma takiej opcji" << endl;
			}

		}
		else
		{
			cout << "Kredyt ju¿ przewalutowano" << endl;
		}
}

bool Kredyt::sprawdz_zdolnosc_kredytowa() {
	//Sprawdzenie klienta w krajowych rejestrach (zewnêtrzy system)
	return true;
}

bool Kredyt::sprawdzanie_poprawnosci_danych_kredytowych() {
	
	if (typ_kredytu.length() > 20)
	{
		cout << "Niepoprawny format danych"<<endl;
		return false;
	}
	return true;
}

bool Kredyt::zaakceptuj_kredyt() {
	int akceptacja_kredytu = 0;
	cout << "Czy akceptujesz kredyt ? (1 tak 0 nie): ";
	cin >> akceptacja_kredytu;
	cout << endl;

	return (bool)akceptacja_kredytu;
}

void Kredyt::zapisz_kredyt_w_bazie(long long int id) {

	//Dodanie kredytu do bazy
	string sql_kredyt = "INSERT INTO Kredyty (ID,KlientID,Typ,Kwota,Waluta,Oprocentowanie,Zaciagniecie,Splata) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + to_string(id) + "','" + typ_kredytu + "','"
		+ to_string(kwota) + "','ZL', 5 ,date('now'),date('now','+6 month')); ";

	//Zwiêkszenie salda o kredyt
	string sql_konto = "UPDATE Klienci SET Saldo = Saldo +" + to_string(kwota) + " WHERE ID =" + to_string(id) + ";";

	if (sprawdzanie_poprawnosci_danych_kredytowych() && sprawdz_zdolnosc_kredytowa() && zaakceptuj_kredyt())
	{
		Baza::wykonaj("kredyty.db", sql_kredyt);
		Baza::wykonaj("klienci.db", sql_konto);
	}
	else
	{
		cout << "Anulowanio wziêcie kredytu" << endl;
	}

}

void Kredyt::get_informacje()
{

	cout << "Id Kredytu: " << id_kredytu <<endl;
	cout << "Kwota: " << kwota << endl;
	cout << "Oprocentowanie: " << oprocentowanie << endl;
	cout <<"Waluta: " << waluta_kredytu << endl;
	cout <<"Data zaci¹gniêcia: " << data_zaciagniecia << endl;
	cout <<"Termin sp³aty: " << termin_splaty << endl <<endl;
}
