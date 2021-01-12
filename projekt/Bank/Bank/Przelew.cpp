#include "Przelew.h"
#include "Baza.h"
using namespace std;
/*
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
		if (i == 4) {
			Przelew::podaj_kod_weryfikacji(tab_kod_potwierdz[i]);
		}
		return tab_kod_potwierdz[i];
	}
	
}
*/
/*
bool Przelew::zweryfikuj_dane() {
	// TODO - implement Przelew::zweryfikuj_dane
	throw "Not yet implemented";
}
*/
void Przelew::stworz_przelew(unsigned long int id_odbiorca, double kwota) {
	int m;
	cout << "Rodzaje przelewu:" << endl;
	cout << "1-Przelew klasyczny" << endl;
	cout << "2-Blik" << endl;
	cin >> m;
	if (m == 1) 
	{
		Przelew::kod_weryfikacji();
		
	}
	else if (m == 2)
	{
		//blik
	}

}

bool Przelew::wyslij_przelew() {
	// TODO - implement Przelew::wyslij_przelew
	throw "Not yet implemented";
}

bool Przelew::potwierdz_wykonanie_przelewu(bool przelac) {
	wyslij_przelew();
	Przelew::zapisz_przelew_w_bazie(id_odbiorca);
	cout << "Przelew zostal wykonany";
	return true;
}

void Przelew::kod_weryfikacji() {
	srand(time(NULL));
	int tab_kod_potwierdz[4];
	int x;
	cout << "Kod potwierdzajacy" << endl;
	for (int i = 0; i < 4; i++)
	{
		x = (rand() % 10);

		tab_kod_potwierdz[i] = x;

		cout << tab_kod_potwierdz[i] << " ";
	}
	int x1;
	int ii=0;
	for (int i = 0; i < 4; i++)
	{
		cout << "Podaj kod: (kazda liczbe zakoncz enterem)" << endl;
		cin >> x1;
		if (x1 = tab_kod_potwierdz[i])
		{
			cout << "Sprawdzanie..." << endl;
			ii++;
		}
		else
		{
			cout << "Kod jest bledny" << endl;
			break;
			
		}
		if (ii == 4) {
			cout << "Kod prawidlowy" << endl;
			Przelew::potwierdz_przelew();
		}

	}
}

void Przelew::zapisz_przelew_w_bazie(unsigned long int id_odbiorca) {
	string sql = "INSERT INTO Przelewy (ID,PrzelewID,Typ,Kwota) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + to_string(id_odbiorca) + "','" + typ_przelewu + "','" + to_string(kwota);
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
		system("pause");
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