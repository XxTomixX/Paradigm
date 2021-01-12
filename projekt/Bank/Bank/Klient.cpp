#include "Klient.h"
#include "Baza.h"
#include "sql/sqlite3.h"
#include <vector>


void Klient::zaloguj(string id, string haslo) {
	/*
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	string sql;
	rc = sqlite3_open("kredyty.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}
	sql = "CREATE TABLE Kredyty("
		"ID INT PRIMARY KEY,"
		"KlientID INT NOT NULL,"
		"Typ           TEXT    NOT NULL,"
		"Kwota       DOUBLE    NOT NULL,"
		"Waluta          TEXT     NOT NULL,"
		"Opocentowanie   INT     NOT NULL,"
		"Zaciagniecie       Date    NOT NULL,"
		"Splata       Date    NOT NULL);";
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
	
	string sql = "SELECT Email,Tel,ID,Saldo,Zamrozone FROM Klienci WHERE ID = '" + id + "' AND Haslo = '" + haslo + "';";

	konta.clear();
	konta = Baza::daneklientazbazy("klienci.db", sql);

	if (konta.empty())
	{
		wyswietl_blad("Błędne haslo lub ID");
	}
	else
	{
		if (!konta[0]->get_zamrozone())
		{
			konta[0]->operacje_na_koncie();
		}
		else
		{
			wyswietl_blad("Twoje konto zostało zamrożone");
		}
		wyloguj();
	}
	
}

void Klient::wyloguj() {
	while (!konta.empty())
	{
		delete konta.back();
		konta.pop_back();
	}
	konta.clear();
}

bool Klient::zarejestruj(string haslo, string email, string tel) {
	
	bool poprawnedane = sprawdz_poprawnosc_danych(haslo,email,tel);
	
	if (poprawnedane == true)
	{
		bool klientistnieje = czy_klient_istnieje();

		if (klientistnieje)
		{
			wyswietl_blad("Taki klient istnieje");
			return false;
		}
		else
		{
			wprowadz_konto_do_bazy(haslo, email, tel);
			return true;
		}

	}
	else
	{
		wyswietl_blad("Niepoprawne dane");
		return false;
	}
}



bool Klient::sprawdz_poprawnosc_danych(string haslo, string email, string tel) {
	int dlugoschasla = haslo.length();
	int dlugostel = tel.length();
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

		for (int i = dlugostel - 1; i >= 0; i--)
		{
			if (tel[i] < 48 || tel[i] > 57)
			{
				wyswietl_blad("Wykryto inne znaki ni�cyfry");
				return false;
			}
		}

		if (dlugostel < 9)
		{
			wyswietl_blad("Za kr�tki numer telefonu");
			return false;
		}

		if (dlugostel > 9)
		{
			wyswietl_blad("Za d��gi numer telefonu");
			return false;
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

string Klient::wyswietl_blad(string blad) {
	
	cout << blad << endl;
	return blad;
}

bool Klient::czy_klient_istnieje() {
	
	string sql = "SELECT ID FROM Klienci WHERE Imie = '" + imie + "' AND Nazwisko = '" + nazwisko + "' AND Pesel = '" + pesel + "';";
	return Baza::czyistnieje("klienci.db", sql);
}

void Klient::podajidkont(string haslo) {

	string sql = "SELECT ID FROM Klienci WHERE Haslo = '" + haslo + "';";
	Baza::idkont("klienci.db", sql);
}

bool Klient::wprowadz_konto_do_bazy(string haslo, string email, string tel) {
	
	string sql = "INSERT INTO Klienci (ID,Imie,Nazwisko,Pesel,Nip,Haslo,Email,Tel,Saldo,Zamrozone,LogDwa) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + imie + "','" + nazwisko + "','" 
		+ pesel + "','" + nip + "','" + haslo + "','" + email + "'," + tel + ",0,0,0 ); ";

	Baza::wykonaj("klienci.db", sql);

	return false;
}

void Klient::wyslij_kod(int id, int nrT) {
	// TODO - implement Klient::wyslij_kod
	throw "Not yet implemented";
}


bool Klient::sprawdz_kod(int code) {
	// TODO - implement Klient::sprawdz_kod
	throw "Not yet implemented";
}
