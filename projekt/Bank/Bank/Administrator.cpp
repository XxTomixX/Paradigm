#include "Administrator.h"
#include "Konto.h"
#include "Osoba.h"
#include "Blad.h"
#include "Baza.h"
#include "sql/sqlite3.h" 

void Administrator::zaloguj(int id, string haslo) {
	string sql = "SELECT Email,ID,FROM Admin WHERE ID = '"+ to_string(id) + "' AND Haslo = '" + haslo + "';";
	// TODO - implement Administrator::zaloguj
	throw "Not yet implemented";
}

void Administrator::wyloguj() {
	// TODO - implement Administrator::wyloguj
	throw "Not yet implemented";
}
void Administrator::zaktualizuj_dane_konta(int id) {
	int c;
	string im, nz, nip, nr_tel;
	string sql;
	cout << "KLIENT ID " << id << endl;
	do {
		cout << "1 - IMIE 2 - NAZWISKO 3 - NIP 4 - NR TEL 0 - WYJDZ\n";
		cin >> c;
		switch (c) {
		case 1:
			cout << "PODAJ NOWE IMIE:\n";
			cin >> im;
			sql = "UPDATE Klienci SET Imie = '" + im + "' WHERE ID = '" + to_string(id) + "';";
			Baza::wykonaj("kilenci.db", sql);
			cout << "ZAKTUALIZOWANO: IMIE\n";
			break;
		case 2:
			cout << "PODAJ NOWE NAZWISKO:\n";
			cin >> nz;
			sql = "UPDATE Klienci SET Nazwisko = '" + nz + "' WHERE ID = '" + to_string(id) + "';";
			Baza::wykonaj("kilenci.db", sql);
			cout << "ZAKTUALIZOWANO: NAZWISKO\n";
			break;
		case 3:
			cout << "PODAJ NOWY NIP:\n";
			cin >> nip;
			sql = "UPDATE Klienci SET Nip = '" + nip + "' WHERE ID = '" + to_string(id) + "';";
			Baza::wykonaj("kilenci.db", sql);
			cout << "ZAKTUALIZOWANO: NIP\n";
			break;
		case 4:
			cout << "PODAJ NOWY NR TELEFONU:\n";
			cin >> nr_tel;
			sql = "UPDATE Klienci SET Tel = '" + nr_tel + "' WHERE ID = '" + to_string(id) + "';";
			Baza::wykonaj("kilenci.db", sql);
			cout << "ZAKTUALIZOWANO: NR TELEFONU\n";
			break;
		default: 
			wyswietl_blad("Zly numer polecenia\n."); 
			break;
		}
		cout << endl;
	} while (c != 0);
}

void Administrator::zamroz_konto(int id) {
	string sql;
	sql = "UPDATE Klienci SET Zamrozone = '" + to_string(1) + "' WHERE ID = '" + to_string(id) + "';";
	Baza::wykonaj("kilenci.db", sql);
}

void Administrator::wyswietl_historie_dzialan(int id) {
	cout << "ID KONTA: " << id << endl;
	cout << "\nPRZELEWY:\n";
	//
	cout << "LOKATY:\n";
	//
	cout << "\nKREDYTY:\n";
	//
	throw "Not yet implemented";
}

void Administrator::modyfikuj_stan_dzialania(int id) {
	// TODO - implement Administrator::modyfikuj_stan_dzialania
	throw "Not yet implemented";
}

void Administrator::pobierz_liste_bledow() {
	string sql;
	sql = "SELECT Tytul,Tresc,ID,Status,Data FROM Blad;";
	Baza::daneBlad("blad.db", sql);
}

void Administrator::sprawdz_stan_bledu(int id) {
	string sql;
	sql = "SELECT Tytul,Tresc,ID,Status,Data FROM Blad WHERE ID = '"+to_string(id)+"';";
	Baza::daneBlad("blad.db", sql);
}

void Administrator::zaktualizuj_liste_bledow() { // skasuj bledy o status=1
	string sql;
	sql = "DELETE FROM Blad WHERE Status = 1;";
	Baza::wykonaj("blad.db", sql);
}

void Administrator::znajdz_konto() {
	// TODO - implement Administrator::znajdz_konto
	throw "Not yet implemented";
}

void Administrator::zmien_status_bledu(int id,int status) { // zmien status na 0 albo na 1
	string sql;
	sql = "UPDATE Blad SET Status = '" + to_string(status) + "' WHERE ID = '" + to_string(id) + "';";
	Baza::wykonaj("blad.db", sql);
}

void Administrator::monitoruj_lokaty() {
	// TODO - implement Administrator::monitoruj_lokaty
	throw "Not yet implemented";
}

void Administrator::monitoruj_kredyty() {
	// TODO - implement Administrator::monitoruj_kredyty
	throw "Not yet implemented";
}

void Administrator::monituruj_przelewy() {
	// TODO - implement Administrator::monituruj_przelewy
	throw "Not yet implemented";
}


void Administrator::rejestracja(int id_od_banku, string haslo,string email) {

	// stworz baze przy pierwszej rejestracji

	//Baza::stworzBazeAdmin();

	bool poprawnedane = sprawdz_poprawnosc_danych(haslo);

	if (poprawnedane == true)
	{
			wprowadz_konto_do_bazy(id_od_banku, haslo, email);
	}
	else wyswietl_blad("Niepoprawne dane");

}

bool Administrator::sprawdz_poprawnosc_danych(string haslo) {

	// haslo >9 liter

	int dlugoschasla = haslo.length();
	if (haslo == "")
	{
		wyswietl_blad("Wprowadzono puste haslo");
		return false;
	}
	else if (dlugoschasla < 9)
	{
		wyswietl_blad("Kr�tkie has�o");
		return false;
	}
	else
	{
		bool liczba = false;
		bool malelitery = false;
		bool duzelitery = false;

		for (int i = dlugoschasla - 1; i >= 0; i--)
		{

			if (haslo[i] >= 48 && haslo[i] <= 57)
			{
				liczba = true;
			}

			if (haslo[i] >= 97 && haslo[i] <= 122)
			{
				malelitery = true;
			}

			if (haslo[i] >= 65 && haslo[i] <= 90)
			{
				duzelitery = true;
			}
		}

		if (liczba == false)
		{
			wyswietl_blad("Brak liczby w ha�le");
			return false;
		}

		if (malelitery == false)
		{
			wyswietl_blad("Brak ma�ych liter w ha�le");
			return false;
		}

		if (duzelitery == false)
		{
			wyswietl_blad("Brak du�ych liter w ha�le");
			return false;
		}
	}

	return true;
}

void Administrator::wyswietl_blad(string blad) {
	cout << blad << endl;
}

bool Administrator::wprowadz_konto_do_bazy(int id, string haslo, string email) {

	string sql;
	sql = "INSERT INTO Admin (ID,Imie,Nazwisko, Haslo,Email) "
		"VALUES ( '"+to_string(id)+"','" + imie + "','" + nazwisko + "','" + haslo + "','" + email + "'); ";
	Baza::dodaj_admina_do_bazy("admin.db", sql);
	return false;

}
