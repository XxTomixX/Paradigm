#include "Blik.h"
#include "Baza.h"

void Blik::generuj_i_zweryfikuj_kod_blik() {
	srand(time(NULL));
	int tab_blik[6];
	int x;
	cout << "Kod blik" << endl;
	for (int i = 0; i < 6; i++)
	{
		x = (rand() % 10)+1;

		tab_blik[i] = x;

		cout << tab_blik[i] << " ";
	}
	int x1;
	int ii = 0;
	for (int i = 0; i < 6; i++)
	{
		cout << "Podaj kod: (kazda liczbe zakoncz enterem)" << endl;
		cin >> x1;
		if (x1 == tab_blik[i])
		{
			cout << "Sprawdzanie..." << endl;
			ii++;
		}
		else
		{
			Blik::wyswietl_blad();
			break;

		}
		if (ii == 6) {
			cout << "Kod prawidlowy" << endl;
			Blik::terminal_request();
		}

	}
}

string Blik::wyswietl_blad() {
	cout << "Wystapil blad. Skonczyl sie czas lub kod blik sie nie pokrywa"<<endl;
	return 0;
}

void Blik::terminal_request() {
	int p;
	cout << "Czy na pewno chcesz wykonac przelew?" << endl << "1-Tak" << endl << "2-Nie" << endl;;
	cin >> p;
	if (p == 1)
	{
		Blik::stworz_przelew();
		Blik::zapisz_przelew_w_bazie(id_odbiorca, typ_przelewu);
	}
	else if (p == 2)
	{
		Blik::anuluj_przelew();
	}
}
/*
bool Blik::zweryfikuj_kod() {
	// TODO - implement Blik::zweryfikuj_kod
	throw "Not yet implemented";
}
*/
void Blik::stworz_przelew() {
	// TODO - implement Blik::stworz_przelew
	throw "Not yet implemented";
}

void Blik::zapisz_przelew_w_bazie(unsigned long int id_odbiorca, string typ_przelewu) {
	string kwota;
	cout << "Dla dodatkowej weryfikacji podaj jeszcze raz kwotę przelewu kodem blik" << endl;
	cin >> kwota;
	string sql = "INSERT INTO Przelewy (ID,PrzelewID,Typ,Kwota) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + to_string(id_odbiorca) + "','" + typ_przelewu + "','" + string(kwota);
	Baza::wykonaj("przelewy_blik.db", sql);
}

void Blik::anuluj_przelew() {
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
		Blik::terminal_request();
	}
	else
	{
		cout << "zly znak";
	}
}
