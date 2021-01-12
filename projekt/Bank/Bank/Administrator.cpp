#include "Administrator.h"
#include "Konto.h"
#include "Osoba.h"
#include "Blad.h"
#include "Baza.h"
#include "sql/sqlite3.h" 

vector<Administrator*> Admin_Log;

void Administrator::operacje_na_koncie() {
	int operacja;
	int id_k;
	unsigned long int id_d;
	unsigned long int id_b;
	int s;

	string tt;
	string tr;
	
	do
	{
		Blad* b = new Blad();
		cout << "PANEL ADMINISTRATORA ID:\t" << id << endl;
		cout << "1: Znajdz konto" << endl;
		cout << "2: Zaktualizuj dane konta" << endl;
		cout << "3: Zamroz konto" << endl;
		cout << "4: Wyswietl historie dzialan" << endl;
		cout << "5: Zmodyfikuj dzialanie" << endl;
		cout << "6: Monitoruj kredyty" << endl;
		cout << "7: Monitoruj przelewy" << endl;
		cout << "8: Monitoruj lokaty" << endl;
		cout << "9: Pobierz liste bledow" << endl;
		cout << "10: Sprawdz stan bledu" << endl;
		cout << "11: Zmien status bledu" << endl;
		cout << "12: Zaktualizuj liste bledow" << endl;
		cout << "13: Zglos blad" << endl;
		cout << "14: Wyloguj" << endl;
		cin >> operacja;
		cin.ignore();
		switch (operacja)
		{
		case 1:
			znajdz_konto();
			break;

		case 2:
			cout << "\nPODAJ ID KONTA:\n";
			cin >> id_k;
			zaktualizuj_dane_konta(id_k);
			break;
		case 3:
			cout << "\nPODAJ ID KONTA:\n";
			cin >> id_k;
			zamroz_konto(id_k);
			break;
		case 4:
			cout << "\nPODAJ ID KONTA:\n";
			cin >> id_k;
			wyswietl_historie_dzialan(id_k);
			break;
		case 5:
			cout << "\nPODAJ ID DZIALANIA:\n";
			cin >> id_d;
			modyfikuj_stan_dzialania(id_d);
			break;
		case 6:
			monitoruj_kredyty();
			break;
		case 7:
			monituruj_przelewy();
			break;
		case 8:
			monitoruj_lokaty();
			break;
		case 9:
			pobierz_liste_bledow();
			break;
		case 10:
			cout << "\nPODAJ ID BLEDU:\n";
			cin >> id_b;
			sprawdz_stan_bledu(id_b);
			break;
		case 11:
			cout << "\nPODAJ ID BLEDU:\n";
			cin >> id_b;
			cout << "\nPODAJ NOWY STATUS [ 0 -> NIENAPRAWIONY ; 1 -> NAPRAWIONY ]:\n";
			cin >> s;
			zmien_status_bledu(id_b,s);
			break;
		case 12:
			zaktualizuj_liste_bledow();
			break;
		case 13:
			cout << "PODAJ TYTUL BLEDU: ";
			getline(cin, tt);
			cout << "TWOJ TYTUL: " << tt << ".\n";
			cout << "PODAJ TRESC BLEDU: ";
			getline(cin, tr);
			cout << "TWOJA TRESC: " << tr << ".\n";
			b->utworz_blad(tt, tr);
			break;
		case 14:
			break;
		default:
			wyswietl_blad("Zly numer operacji.\n");
			break;
		}
		delete b;
	} while (operacja != 14);
	if (operacja == 14) wyloguj();
}


void Administrator::zaloguj(int id, string haslo) {
	string sql = "SELECT * FROM Admin WHERE ID = '"+ to_string(id) + "' AND Haslo = '" + haslo + "';";
	Admin_Log.clear();
	Admin_Log = Baza::daneadminazbazy("admin.db", sql);

	if (Admin_Log.empty())
	{
		wyswietl_blad("Błędne haslo lub ID");
	}
	else
	{
		Admin_Log[0]->operacje_na_koncie();
	}
}

void Administrator::wyloguj() {
	while (!Admin_Log.empty())
	{
		delete Admin_Log.back();
		Admin_Log.pop_back();
	}
	Admin_Log.clear();
}

bool Administrator::rejestracja(int id_od_banku, string haslo, string email) {

	// stworz baze przy pierwszej rejestracji

	// Baza::stworzBazeAdmin();

	bool poprawnedane = sprawdz_poprawnosc_danych(haslo);

	if (poprawnedane == true)
	{
		wprowadz_konto_do_bazy(id_od_banku, haslo, email);
		return true;
	}
	else
	{
		wyswietl_blad("Niepoprawne dane");
		return false;
	}

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

bool Administrator::wprowadz_konto_do_bazy(int id, string haslo, string email) {

	string sql;
	sql = "INSERT INTO Admin (ID,Imie,Nazwisko, Haslo,Email) "
		"VALUES ( '" + to_string(id) + "','" + imie + "','" + nazwisko + "','" + haslo + "','" + email + "'); ";
	Baza::wykonaj("admin.db", sql);
	return false;

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
			Baza::wykonaj("klienci.db", sql);
			cout << "ZAKTUALIZOWANO: IMIE\n";
			break;
		case 2:
			cout << "PODAJ NOWE NAZWISKO:\n";
			cin >> nz;
			sql = "UPDATE Klienci SET Nazwisko = '" + nz + "' WHERE ID = '" + to_string(id) + "';";
			Baza::wykonaj("klienci.db", sql);
			cout << "ZAKTUALIZOWANO: NAZWISKO\n";
			break;
		case 3:
			cout << "PODAJ NOWY NIP:\n";
			cin >> nip;
			sql = "UPDATE Klienci SET Nip = '" + nip + "' WHERE ID = '" + to_string(id) + "';";
			Baza::wykonaj("klienci.db", sql);
			cout << "ZAKTUALIZOWANO: NIP\n";
			break;
		case 4:
			cout << "PODAJ NOWY NR TELEFONU:\n";
			cin >> nr_tel;
			sql = "UPDATE Klienci SET Tel = '" + nr_tel + "' WHERE ID = '" + to_string(id) + "';";
			Baza::wykonaj("klienci.db", sql);
			cout << "ZAKTUALIZOWANO: NR TELEFONU\n";
			break;
		case 0: 
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

vector<Konto*> dane;
void Administrator::znajdz_konto() {
	int opcja;
	int id_f;
	string pesel_f;
	string sql;
	cout << "WYSZUKAJ PO:\n1.ID\n2.PESEL\n";
	cin >> opcja;
	if (opcja == 1) {
		cout << "\nPODAJ ID KLIENTA:\n";
		cin >> id_f;
		sql = "SELECT Email,Tel,ID,Saldo,Zamrozone FROM Klienci WHERE ID = '" + to_string(id_f) + "';";
		dane.clear();
		dane = Baza::daneklientazbazy("klienci.db", sql);
		if (dane.empty())
		{
			wyswietl_blad("Klient nie istnieje.");
		}
	}
	else if (opcja == 2) {
		cout << "\nPODAJ PESEL KLIENTA:\n";
		cin >> pesel_f;
		sql = "SELECT Email,Tel,ID,Saldo,Zamrozone FROM Klienci WHERE Pesel = '" + pesel_f + "';";
		dane.clear();
		dane = Baza::daneklientazbazy("klienci.db", sql);
		if (dane.empty())
		{
			wyswietl_blad("Klient nie istnieje.");
		}
	}
	else if (opcja < 0 || opcja >2) {
		wyswietl_blad("Bledny numer operacji.");
	}
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

void Administrator::wyswietl_blad(string blad) {
	cout << blad << endl;
}

void Administrator::pobierz_liste_bledow() {
	string sql;
	sql = "SELECT Tytul,Tresc,ID,Status,Data FROM Blad;";
	Baza::daneBlad("blad.db", sql);
}

void Administrator::sprawdz_stan_bledu(unsigned long int id) {
	string sql;
	sql = "SELECT Tytul,Tresc,ID,Status,Data FROM Blad WHERE ID = '" + to_string(id) + "';";
	Baza::daneBlad("blad.db", sql);
}

void Administrator::zaktualizuj_liste_bledow() { // skasuj bledy o status=1
	string sql;
	sql = "DELETE FROM Blad WHERE Status = 1;";
	Baza::wykonaj("blad.db", sql);
}

void Administrator::zmien_status_bledu(unsigned long int id, int status) { // zmien status na 0 albo na 1
	string sql;
	sql = "UPDATE Blad SET Status = '" + to_string(status) + "' WHERE ID = '" + to_string(id) + "';";
	Baza::wykonaj("blad.db", sql);
}

