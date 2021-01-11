#include "Administrator.h"
#include "Konto.h"
#include "Osoba.h"
#include "Blad.h"
#include "sql/sqlite3.h" 

void stworzBaze() {
	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	string sql;


	rc = sqlite3_open("admin.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}


	sql = "CREATE TABLE Admin("
		"ID INT PRIMARY KEY,"
		"Imie           TEXT    NOT NULL,"
		"Nazwisko       TEXT    NOT NULL,"
		"Haslo       TEXT    NOT NULL,"
		"Email       TEXT    NOT NULL"
		");";


	rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);

}

void Administrator::zaloguj(int id, string haslo) {
	// TODO - implement Administrator::zaloguj
	throw "Not yet implemented";
}

void Administrator::wyloguj() {
	// TODO - implement Administrator::wyloguj
	throw "Not yet implemented";
}

Konto Administrator::pobierz_dane_kont() {
	// TODO - implement Administrator::pobierz_dane_kont
	throw "Not yet implemented";
}

void Administrator::zaktualizuj_dane_konta(Konto k) {
	// TODO - implement Administrator::zaktualizuj_dane_konta
	throw "Not yet implemented";
}

void Administrator::zamroz_konto(Konto k) {
	// TODO - implement Administrator::zamroz_konto
	throw "Not yet implemented";
}

void Administrator::wyswietl_historie_dzialan(Konto k) {
	// TODO - implement Administrator::wyswietl_historie_dzialan
	throw "Not yet implemented";
}

void Administrator::modyfikuj_stan_dzialania(Konto k) {
	// TODO - implement Administrator::modyfikuj_stan_dzialania
	throw "Not yet implemented";
}

Blad Administrator::pobierz_liste_bledow() {
	// TODO - implement Administrator::pobierz_liste_bledow
	throw "Not yet implemented";
}

void Administrator::sprawdz_stan_bledu(Blad b) {
	// TODO - implement Administrator::sprawdz_stan_bledu
	throw "Not yet implemented";
}

Blad Administrator::zaktualizuj_liste_bledow() {
	// TODO - implement Administrator::zaktualizuj_liste_bledow
	throw "Not yet implemented";
}

Konto Administrator::znajdz_konto(int id) {
	// TODO - implement Administrator::znajdz_konto
	throw "Not yet implemented";
}

void Administrator::zmien_status_bledu() {
	// TODO - implement Administrator::zmien_status_bledu
	throw "Not yet implemented";
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
	bool poprawnedane = sprawdz_poprawnosc_danych(haslo);

	if (poprawnedane == true)
	{
			wprowadz_konto_do_bazy(id_od_banku, haslo, email);
	}
	else wyswietl_blad("Niepoprawne dane");

	//stworzBaze();
	
}

bool Administrator::sprawdz_poprawnosc_danych(string haslo) {
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

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	string sql;


	rc = sqlite3_open("admin.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}


	sql = "INSERT INTO Admin (ID,Imie,Nazwisko, Haslo,Email) "
		"VALUES ( '"+to_string(id)+"','" + imie + "','" + nazwisko + "','" + haslo + "','" + email + "'); ";



	rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);


	return false;

}
