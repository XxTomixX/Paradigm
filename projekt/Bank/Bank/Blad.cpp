#include "Blad.h"
#include "Baza.h"
#include "sql/sqlite3.h"

// Wpisuje blad do bazy
void Blad::utworz_blad(string tytul, string tresc) {

	// Baza::stworzBazeBledow();
	czy_naprawiony = 0;	// status bledu
	time_t now = time(0);
	char* dt = ctime(&now);
	data = dt;	// czas zgloszenia

	string sql;
	sql = "INSERT INTO Blad (ID,Tytul,Tresc,Status,Data) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + tytul + "','" + tresc + "','" + to_string(czy_naprawiony) + "','" + data + "'); ";
	Baza::wykonaj("blad.db", sql);
	
}
