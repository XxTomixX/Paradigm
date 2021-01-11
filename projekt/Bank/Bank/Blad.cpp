#include "Blad.h"
#include "sql/sqlite3.h"

void stworzBazeBledow() {
	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	string sql;


	rc = sqlite3_open("blad.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}


	sql = "CREATE TABLE Blad("
		"ID INT PRIMARY KEY,"
		"Tytul           TEXT    NOT NULL,"
		"Tresc       TEXT    NOT NULL,"
		"Status       INT    NOT NULL,"
		"Data       TEXT    NOT NULL"
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

void Blad::utworz_blad(string tytul, string tresc) {
	//stworzBazeBledow();
	czy_naprawiony = 0;	// status bledu
	time_t now = time(0);
	char* dt = ctime(&now);
	data = dt;	// czas zgloszenia

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	string sql;


	rc = sqlite3_open("blad.db", &db);

	// debug
	/*if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}*/


	sql = "INSERT INTO Blad (ID,Tytul,Tresc,Status,Data) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + tytul + "','" + tresc + "','" + to_string(czy_naprawiony) + "','" + data + "'); ";

	rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

	// debug
	/*if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records created successfully\n");
	}*/
	sqlite3_close(db);
	
}
