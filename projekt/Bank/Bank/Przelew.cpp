#include "Przelew.h"
#include "Baza.h"
using namespace std;


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
		Blik* nowy = NULL;
		Przelew::blik_menu(nowy);
		//blik
	}

}

void Przelew::blik_menu(Blik*& nowy)
{
	nowy = new Blik();
	nowy->generuj_i_zweryfikuj_kod_blik();
}

bool Przelew::wyslij_przelew() {
	cout << "Przelew zosta? wykonany" << endl;
	return true;
}

bool Przelew::potwierdz_wykonanie_przelewu(bool przelac) {
	wyslij_przelew();
	string typ_przelewu = "k";
	Przelew::zapisz_przelew_w_bazie(id_odbiorca, typ_przelewu);
	cout << "Przelew zostal wykonany" << endl;
	return true;
}

void Przelew::kod_weryfikacji() {
	srand(time(NULL));
	int tab_kod_potwierdz[4];
	int x;
	cout << "Kod potwierdzajacy" << endl;
	for (int i = 0; i < 4; i++)
	{
		x = (rand() % 9) + 1;

		tab_kod_potwierdz[i] = x;

		cout << tab_kod_potwierdz[i] << " ";
	}
	int x1;
	int ii = 0;
	for (int i = 0; i < 4; i++)
	{
		cout << "Podaj kod: (kazda liczbe zakoncz enterem)" << endl;
		cin >> x1;
		if (x1 == tab_kod_potwierdz[i])
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

void Przelew::zapisz_przelew_w_bazie(unsigned long int id_odbiorca, string typ_przelewu) {
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
		cout << "Przelew zosta? anulowany" << endl;
		system("pause");
	}
	else if (a == 2)
	{
		cout << "Przelew nie zosta? anulowany";
		Przelew::potwierdz_przelew();
	}
	else
	{
		cout << "zly znak";
	}

}