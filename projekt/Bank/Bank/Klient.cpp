#include "Klient.h"
#include "sql/sqlite3.h" 

void Klient::zaloguj(int id, string haslo) {
	// TODO - implement Klient::zaloguj
	throw "Not yet implemented";
}

void Klient::wyloguj() {
	// TODO - implement Klient::wyloguj
	throw "Not yet implemented";
}

void Klient::zarejestruj(string haslo) {
	
	if (haslo == "")
	{
		wyswietl_blad("Wprowadzono nieprawid³owe dane");
	}
	else if (haslo.length() < 9)
	{
		wyswietl_blad("Krótkie has³o");
	}

	
	/*
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	string sql;

	
	rc = sqlite3_open("klienci.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}

	
	sql = "CREATE TABLE Klienci(" 
		"ID INT PRIMARY KEY," 
		"Imie           TEXT    NOT NULL," 
		"Nazwisko       TEXT    NOT NULL,"
		"Pesel          INT     NOT NULL," 
		"Pin          INT     NOT NULL);";


	rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
	*/

	
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	string sql;


	rc = sqlite3_open("Klienci.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}


	sql = "INSERT INTO Klienci (Imie,Nazwisko,Pesel,Pin) "
		"VALUES ('Paul', 'G',10202020233, 2137 ); ";
		

	
	rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);
	
}

void Klient::usun_konto() {
	// TODO - implement Klient::usun_konto
	throw "Not yet implemented";
}

void Klient::zamroz_konto() {
	// TODO - implement Klient::zamroz_konto
	throw "Not yet implemented";
}

bool Klient::sprawdz_poprawnosc_danych(int id, string haslo, int string_imie, int string_nazwisko) {
	// TODO - implement Klient::sprawdz_poprawnosc_danych //sprawdza poprawnoœæ danych
	throw "Not yet implemented";
}

string Klient::odczytaj_dane_klienta(int id, string haslo) {
	// TODO - implement Klient::odczytaj_dane_klienta
	throw "Not yet implemented";
}

string Klient::wyswietl_blad(string blad) {
	
	cout << blad << endl;
	return blad;
}

bool Klient::czy_klient_istnieje(int id) {
	// TODO - implement Klient::czy_klient_istnieje
	throw "Not yet implemented";
}

bool Klient::wprowadz_konto_do_bazy(int id, string haslo, int string_imie, int string_nazwisko, int int_pesel) {
	// TODO - implement Klient::wprowadz_konto_do_bazy
	throw "Not yet implemented";
}

bool Klient::usun_konto_z_bazy(int id, string haslo, int string_imie, int string_nazwisko, int int_pesel) {
	// TODO - implement Klient::usun_konto_z_bazy
	throw "Not yet implemented";
}

void Klient::wyslij_kod(int id, int nrT) {
	// TODO - implement Klient::wyslij_kod
	throw "Not yet implemented";
}

int Klient::wybierz_metode() {
	// TODO - implement Klient::wybierz_metode
	throw "Not yet implemented";
}

bool Klient::sprawdz_kod(int code) {
	// TODO - implement Klient::sprawdz_kod
	throw "Not yet implemented";
}
