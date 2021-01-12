#include "Przelew.h"
#include "Baza.h"
using namespace std;

int Przelew::wyslij_kod_potwierdzajacy() {
	srand(time(NULL));
	int tab_kod_potwierdz[4];
	int x;
	cout << "Kod potwierdzajacy" << endl;
	for (int i = 0; i < 4; i++)
	{
		x = (rand() % 10);

		tab_kod_potwierdz[i] = x;

		cout << tab_kod_potwierdz[i] << " ";
		return tab_kod_potwierdz[i];
	}
}

bool Przelew::zweryfikuj_dane() {
	// TODO - implement Przelew::zweryfikuj_dane
	throw "Not yet implemented";
}

void Przelew::stworz_przelew(unsigned long int id_odbiorca, int kwota_double) {
	int m;
	cout << "Rodzaje przelewu:" << endl;
	cout << "1-Przelew klasyczny" << endl;
	cout << "2-Blik" << endl;
	cin >> m;

}

bool Przelew::wyslij_przelew() {
	// TODO - implement Przelew::wyslij_przelew
	throw "Not yet implemented";
}

bool Przelew::potwierdz_wykonanie_przelewu(bool przelac) {
	cout << "Przelew zostal wykonany";
	return true;
}

bool Przelew::podaj_kod_weryfikacji(int tab_kod_potwierdz[4]) {
	int tab_kod[4];
	int x;
	for (int i = 0; i < 4; i++)
	{
		cout << "Podaj kod: (kazda liczbe zakoncz enterem)" << endl;
		x = tab_kod[i];
		if (x = tab_kod_potwierdz[i])
		{
			cout << "Sprawdzanie..." << endl;
		}
		else
		{
			cout << "Kod jest bledny" << endl;
			return 0;
		}
	}
	return true;
}

void Przelew::zapisz_przelew_w_bazie(unsigned long int id) {
	string sql = "INSERT INTO Przelewy (ID,PrzelewID,Typ,Kwota) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + to_string(id) + "','" + typ_przelewu + "','" + to_string(kwota);
	Baza::wykonaj("przelewy.db", sql);
}

void Przelew::potwierdz_przelew() {
	int p;
	cout << "Czy na pewno chcesz wykonac przelew?" << endl << "1-Tak" << endl << "2-Nie" << endl;;
	cin >> p;
	bool przelac;
	if (p == 1)
	{
		przelac = true;
		Przelew::potwierdz_wykonanie_przelewu(przelac);
	}
	else if (p == 2)
	{
		Przelew::anuluj_przelew();
	}
}

void Przelew::anuluj_przelew() {
	int a;
	cout << "Czy na pewno chcesz anulowac przelew?" << endl << "1-Tak" << endl << "2-Nie" << endl;;
	cin >> a;
	if (a == 1)
	{
		cout << "Przelew został anulowany";
		//Konto::operacje_na_koncie();
	}
	else if (a == 2)
	{
		cout << "Przelew nie został anulowany";
		Przelew::potwierdz_przelew();
	}
	else
	{
		cout << "zly znak";
	}

}