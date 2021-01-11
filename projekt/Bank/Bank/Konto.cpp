#include "Konto.h"
#include "Baza.h"
#include <vector>

Kurs Konto::podaj_kurs(double i, string waluta) {
	// TODO - implement Konto::podaj_kurs
	throw "Not yet implemented";
}

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

string Konto::wyswietl_komunikat(int numer_komunikatu) {
	// TODO - implement Konto::wyswietl_komunikat
	throw "Not yet implemented";
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

	cout << "Witaj. Konto na którym wykonywane s¹ operacje to: " << id<<endl;
	cout << "Stan konta wynosi: " << saldo_konta << " z³" << endl;

	int kwota = 0;
    string waluta = "";
	int opreacja = 0;
	while (opreacja != 7)
	{
		cout << "1: Przelew" << endl;
		cout << "2: Kredyt" << endl;
		cout << "3: Lokata" << endl;
		cout << "4: SprawdŸ kurs" << endl;
		cout << "5: Usuñ konto" << endl;
		cout << "6: ZamroŸ konto" << endl;
		cout << "7: Wyloguj" << endl;
		cin >> opreacja;
		switch (opreacja)
		{
		case 1:

			break;

		case 2:
			
			break;

		case 3:

			break;

		case 4:
			kwota = 0;
			cout << "Podaj kwote";
			cin >> kwota;

			waluta = "";
			cout << "Podaj walute (USD lub EUR)";
			cin >> waluta;

			Kurs::sprawdz_kurs(kwota, waluta);

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
