#include "Konto.h"
#include "Baza.h"
#include <vector>

void Konto::zglos_blad(string tytul, string tresc) {
	// TODO - implement Konto::zglos_blad
	throw "Not yet implemented";
}

bool Konto::modyfikuj_stan_konta(string operacja, int kwota) {
	// TODO - implement Konto::modyfikuj_stan_konta
	throw "Not yet implemented";
}

double Konto::stan_konta() {
	// TODO - implement Konto::stan_konta
	throw "Not yet implemented";
}

void Konto::wyswietl_komunikat(string komunikat) {
	cout << komunikat << endl;
}

long long int Konto::get_id() {
	return id;
}
void Konto::zamroz_srodki() {
	// TODO - implement Konto::zamroz_srodki
	throw "Not yet implemented";
}

void Konto::zaaktualizuj_dane_konta() {
	// TODO - implement Konto::zaaktualizuj_dane_konta
	throw "Not yet implemented";
}

void Konto::usun_konto() {

	string sql = "DELETE FROM Klienci WHERE Id='"+to_string(id)+"';";
	Baza::klientoperacjanabazie("klienci.db", sql);
}

void Konto::zamroz_konto() {
	string sql = "UPDATE Klienci SET Zamrozone = '"+to_string(1)+"' WHERE ID = '"+ to_string(id) +"';";
	Baza::klientoperacjanabazie("klienci.db", sql);
}

bool Konto::get_zamrozone()
{
	return czy_zamrozone;
}

void Konto::operacje_na_koncie() {

	cout << "Witaj. Konto na kt�rym wykonywane s� operacje to: " << id<<endl;
	cout << "Stan konta wynosi: " << saldo_konta << " z�" << endl;

	int kwota = 0;
    string waluta = "";

	int opreacja = 0;
	int opreacja_kredyt = 0;

	Kredyt* nowy = NULL;
	string id = "";
	string haslo = "";

	while (opreacja != 7)
	{
		cout << "1: Przelew" << endl;
		cout << "2: Kredyt" << endl;
		cout << "3: Lokata" << endl;
		cout << "4: Sprawd� kurs" << endl;
		cout << "5: Usu� konto" << endl;
		cout << "6: Zamro� konto" << endl;
		cout << "7: Wyloguj" << endl;
		cin >> opreacja;
		switch (opreacja)
		{
		case 1:

			break;

		case 2:
			
			kredyt_menu(opreacja_kredyt, nowy);

			break;

		case 3:

			break;

		case 4:
			przewalutowanie(kwota, waluta);

			break;

		case 5:
			usun_konto();
			opreacja = 7;
			break;

		case 6:
			zamroz_konto();
			opreacja = 7;
			break;


		default:

			break;
		}
	}

}

void Konto::kredyt_menu(int &opreacja_kredyt, Kredyt * &nowy)
{
	string typ = "";
	double kwota = 0;
	string waluta = "";
	double oprocentowanie = 0;
	string data_zaciagniecia = "";
	string termin_splaty = "";
	unsigned long int id_kredytu = 0;

	while (opreacja_kredyt != 3)
	{
		cout << "1: We� kredyt" << endl;
		cout << "2: Lista kredyt�w" << endl;
		cout << "3: Opcje konta" << endl;
		cin >> opreacja_kredyt;
		switch (opreacja_kredyt)
		{
		case 1:

			cout <<"Podaj typ kredytu: ";
			cin >> typ;
			cout << "Podaj kwote kredytu: ";
			cin >> kwota;
			nowy = new Kredyt(typ,kwota,waluta,oprocentowanie,data_zaciagniecia,termin_splaty);

			if (nowy->sprawdz_zdolnosc_kredytowa())
			{
				cout << "aaaaaaaaaaaaaaaaaaaaass";
				nowy->zapisz_kredyt_w_bazie(id);
			}
			else
			{
				wyswietl_komunikat("Brak zdolno�ci kredytowej");
				delete nowy;
			}

			break;

		case 2:

			break;

		default:

			break;
		}
	}
}

double Konto::przewalutowanie(int &kwota,string &waluta)
{
	kwota = 0;
	cout << "Podaj kwote (z�): ";
	cin >> kwota;

	waluta = "";
	cout << "Podaj walute (USD lub EUR): ";
	cin >> waluta;

	return Kurs::sprawdz_kurs(kwota, waluta);
}
