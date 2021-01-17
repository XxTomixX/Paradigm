#include "Przelew.h"
#include "Baza.h"
using namespace std;

// Tworzenie przelewu
void Przelew::stworz_przelew(long long int id_odbiorca, double kwota) {

	int m;
	double k;
	k = kwota;
	long long int id_od = id_odbiorca;
	cout << "Rodzaje przelewu:" << endl;   //menu przelewów
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
		Przelew::blik_menu(nowy,k,id_od);
	}

}

// Obsluga BLIK
void Przelew::blik_menu(Blik*& nowy,double k, long long int id_od)
{
	nowy = new Blik(id_od,k);      //tworzenie przelewu blik
	nowy->generuj_i_zweryfikuj_kod_blik();
}

bool Przelew::wyslij_przelew() {  // przesy? pieni?dzy
	
	string sql_konto_nadawcy = "UPDATE Klienci SET Saldo = Saldo -" + to_string(kwota) + " WHERE ID =" + to_string(ID) + ";";
	Baza::wykonaj("klienci.db", sql_konto_nadawcy);
	string sql_konto_odbiorcy = "UPDATE Klienci SET Saldo = Saldo +" + to_string(kwota) + " WHERE ID =" + to_string(id_odbiorca) + ";";
	Baza::wykonaj("klienci.db", sql_konto_odbiorcy);
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
	for (int i = 0; i < 4; i++)  //generowanie kodu potwierdzaj?cego przelew klasyczny
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
		if (x1 == tab_kod_potwierdz[i])  //weryfikacja kodu potwierdzaj?cego przelew klasyczny 
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

void Przelew::zapisz_przelew_w_bazie(long long int id_odbiorca, string typ_przelewu) {  //tworzenie bazy danych

	string sql = "INSERT INTO Przelewy (IDPrzelew,ID,IDN,Typ,Kwota) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + to_string(id_odbiorca) + "','" + to_string(ID) + "','" + typ_przelewu + "','" + to_string(kwota) + "');";
	Baza::wykonaj("przelewy.db", sql);
}

void Przelew::potwierdz_przelew() {   //dodatkowe potwierdzenie przelewu

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
		Przelew::anuluj_przelew();  //anulowanie przelewu
	}
}

void Przelew::anuluj_przelew() {

	int a;
	cout << "Czy na pewno chcesz anulowac przelew?" << endl << "1-Tak" << endl << "2-Nie" << endl;;  //potwierdzenie anulowania przelewu
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

void Przelew::get_informacje() {

	cout << "ID odbiorcy:\t" << id_odbiorca<<endl;
	cout << "KWOTA:\t" << kwota << endl;
	cout << "ID przelewu:\t" << id_przelewu << endl;
	cout << "TYP:\t" << typ_przelewu << endl;
	cout << "ID nadawcy:\t" << ID << endl;
	cout << endl;
}