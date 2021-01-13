#include "Blik.h"
#include "Baza.h"

void Blik::generuj_i_zweryfikuj_kod_blik() {
	srand(time(NULL));
	int tab_blik[6];
	int x;
	cout << "Kod blik" << endl;
	for (int i = 0; i < 6; i++)  //generowanie kodu blik
	{
		x = (rand() % 9) + 1;

		tab_blik[i] = x;

		cout << tab_blik[i] << " ";
	}
	int x1;
	int ii = 0;
	for (int i = 0; i < 6; i++)
	{
		cout << "Podaj kod: (kazda liczbe zakoncz enterem)" << endl; //sprawdzanie poprawno?ci kodu blik
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
	cout << "Wystapil blad. Skonczyl sie czas lub kod blik sie nie pokrywa" << endl;  //b??d w podawanie kodu
	return 0;
}

void Blik::terminal_request() {
	int p;
	cout << "Czy na pewno chcesz wykonac przelew?" << endl << "1-Tak" << endl << "2-Nie" << endl; //potwierdzenie przelewu
	cin >> p;
	if (p == 1)
	{
		Blik::stworz_przelew();
	}
	else if (p == 2)
	{
		Blik::anuluj_przelew();
	}
}

void Blik::stworz_przelew() {
	cout << "Przelew Blik zosta? wykonany" << endl;
	string typ_przelewu = "b";
	cout << "Dla dodatkowego bezpiecze?stwa podaj:" << endl;
	cout << "Twoje ID" << endl;
	cin >> Blik::ID;
	zapisz_przelew_w_bazie(id_odbiorca,typ_przelewu,ID);
	                                                                                                                              //przesy? pieniedzy
	string sql_konto_nadawcy = "UPDATE Klienci SET Saldo = Saldo -" + to_string(kwota) + " WHERE ID =" + to_string(ID) + ";";
	Baza::wykonaj("klienci.db", sql_konto_nadawcy);
	string sql_konto_odbiorcy = "UPDATE Klienci SET Saldo = Saldo +" + to_string(kwota) + " WHERE ID =" + to_string(id_odbiorca) + ";";
	Baza::wykonaj("klienci.db", sql_konto_odbiorcy);
}

void Blik::zapisz_przelew_w_bazie(unsigned long int id_odbiorca, string typ_przelewu,long long int ID) {  //zapis w bazie z przelewami

	string sql = "INSERT INTO Przelewy (IDPrzelew,ID,IDN,Typ,Kwota) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + to_string(id_odbiorca) + "','" + to_string(ID) + "','" + typ_przelewu + "','" + to_string(kwota) + "');";
	Baza::wykonaj("przelewy.db", sql);
}

void Blik::anuluj_przelew() {
	int a;
	cout << "Czy na pewno chcesz anulowac przelew?" << endl << "1-Tak" << endl << "2-Nie" << endl;  // anulowanie przelewu blik
	cin >> a;
	if (a == 1)
	{
		cout << "Przelew zosta? anulowany" << endl;
		system("pause");
	}
	else if (a == 2)
	{
		cout << "Przelew nie zosta? anulowany";
		Blik::terminal_request();
	}
	else
	{
		cout << "zly znak";
	}
}
