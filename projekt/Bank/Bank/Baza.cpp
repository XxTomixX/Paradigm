
#include "Baza.h"
#include "Konto.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> 
#include <sstream>
#include "sql/sqlite3.h" 

using namespace std;

// Nawiązanie połączenia z bazą
sqlite3* Baza::polaczdobazy(string nazwabazy) {

	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	string sql;

	rc = sqlite3_open(nazwabazy.c_str(), &db);
	if (rc) {
		return NULL;
	}
	else {
		return db;
	}
}

// Czy klient istnieje, zwraca bool
bool istnieje = false;
int back_istnieje(void *NotUsed, int argc, char **argv, char **azColName) {

	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	cout << endl;
	istnieje = true;

	return 0;
}

bool Baza::czyistnieje(string nazwabazy, string sql) {

	istnieje = false;

	sqlite3 *db = polaczdobazy(nazwabazy);
	int rc;
	char *zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), back_istnieje, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		
	}
	else {
		fprintf(stdout, "Konto istnieje.\n");
		sqlite3_close(db);
		
	}
	return istnieje;
}

// Zwraca konto klienta o podanym haœle
vector<Konto*> danezbazy;
int back_danezbazyklienta(void *NotUsed, int argc, char **argv, char **azColName) {

	danezbazy.clear();
	string id = (string)argv[2];
	Konto* kontozbazy = new Konto((string)argv[0], (string)argv[1], stoll(id), stold(argv[3]), stoi(argv[4]));
	danezbazy.push_back(kontozbazy);
	return 0;
}

vector<Konto*> Baza::daneklientazbazy(string nazwabazy, string sql) {

	sqlite3 *db = polaczdobazy(nazwabazy);
	int rc;
	char *zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), back_danezbazyklienta, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Wypisano dane.\n");
	}
	sqlite3_close(db);
	return danezbazy;
}

// Funkcja pomocnicza sqlite3 i metoda zwracajaca id konta
int back_idkonta(void *NotUsed, int argc, char **argv, char **azColName) {

	cout << "ID twojego konta to: " << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	return 0;
}

void Baza::idkont(string nazwabazy, string sql) {

	sqlite3 *db = polaczdobazy(nazwabazy);
	int rc;
	char *zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), back_idkonta, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
}

// Zwraca Kredyty klienta o ID
vector<Kredyt*> danekredytowe;
int back_danezbazykredyty(void *NotUsed, int argc, char **argv, char **azColName) {

	string id_kredyt = (string)argv[0];
	Kredyt* kredyt = new Kredyt((string)argv[2], atof(argv[3]), (string)argv[4], atof(argv[5]), (string)argv[6], (string)argv[7], stoll(id_kredyt));
	danekredytowe.push_back(kredyt);
	return 0;
}

vector<Kredyt*> Baza::danezbazykredyt(string nazwabazy, string sql) {
	
	danekredytowe.clear();
	sqlite3 *db = polaczdobazy(nazwabazy);
	int rc;
	char *zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), back_danezbazykredyty, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		// fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Wypisano dane.\n");
	}
	sqlite3_close(db);
	return danekredytowe;
}

// Zwraca Lokaty klienta o ID
vector<Lokata*> danelokat;
int back_danezbazylokaty(void *NotUsed, int argc, char **argv, char **azColName) {

	string id_lokat = (string)argv[0];
	Lokata* lokata = new Lokata((string)argv[2], atof(argv[3]), (int)argv[4], stoll(id_lokat));
	danelokat.push_back(lokata);
	cout << endl;
	return 0;
}

vector<Lokata*> Baza::danezbazylokat(string nazwabazy, string sql) {
	
	danelokat.clear();
	sqlite3 *db = polaczdobazy(nazwabazy);
	int rc;
	char *zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), back_danezbazylokaty, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Wypisano \n");
	}
	sqlite3_close(db);
	return danelokat;
}

vector<Przelew*> daneprzelewow;
int back_danezbazyprzelewow(void* NotUsed, int argc, char** argv, char** azColName) {

	string id_przelew = (string)argv[0];
	Przelew* przelew = new Przelew ( stoll(argv[1]), atof(argv[4]), stoll(id_przelew), (string)argv[3], stoll(argv[2]) );
	daneprzelewow.push_back(przelew);
	cout << endl;
	return 0;
}

vector<Przelew*> Baza::danezbazyprzelew(string nazwabazy, string sql) {

	sqlite3* db = polaczdobazy(nazwabazy);
	daneprzelewow.clear();
	int rc;
	char* zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), back_danezbazyprzelewow, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		// fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Wypisano \n");
	}
	sqlite3_close(db);
	return daneprzelewow;
}

// BLAD
// Tworzenie bazy bledow
void Baza::stworzBazeBledow() {

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

// ADMIN
// Tworzenie bazy administratorow
void Baza::stworzBazeAdmin() {
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

// Przelewy
// Tworzenie bazy przelewow
void Baza::stworzBazePrzelewow() {

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	string sql;
	rc = sqlite3_open("przelewy.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}

	sql = "CREATE TABLE Przelewy("
		"IDPrzelew INT PRIMARY KEY,"
		"ID           INT    NOT NULL,"
		"Typ       INT    NOT NULL,"
		"Kwota       DOUBLE    NOT NULL"
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
// Blik
// Tworzenie bazy przelewow blik
void Baza::stworzBazePrzelewowBlik() {
	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	string sql;


	rc = sqlite3_open("przelewy_blik.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}

	sql = "CREATE TABLE PrzelewyBlik("
		"IDPrzelew INT PRIMARY KEY,"
		"ID           INT    NOT NULL,"
		"IDN           INT    NOT NULL,"
		"Typ       INT    NOT NULL,"
		"Kwota       DOUBLE    NOT NULL"
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

//Wykonuje polecenia SQL na bazie
bool Baza::wykonaj(string nazwa, string sql) {

	sqlite3* db = polaczdobazy(nazwa);
	int rc;
	char* zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else {
		sqlite3_close(db);
		return true;
	}
}

//Zwraca błędy z bazy 
vector<Blad*> wektor_bledow;
int back_daneBlad(void* NotUsed, int argc, char** argv, char** azColName) {

	cout << "===================" << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << i << " " << argv[i] << endl;
	}

	string id = (string)argv[2];
	Blad* bladzBazy = new Blad((string)argv[0], (string)argv[1], stoll(id), stoi(argv[3]), string(argv[4]));
	wektor_bledow.push_back(bladzBazy);
	return 0;
}

vector<Blad*> Baza::daneBlad(string nazwabazy, string sql) {
	wektor_bledow.clear();
	sqlite3* db = polaczdobazy(nazwabazy);

	int rc;
	char* zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), back_daneBlad, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		//fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Wypisano dane bledow.\n");
	}
	sqlite3_close(db);
	return wektor_bledow;
}

//Zwraca konto admina o podanym hasle
vector<Administrator*> Admin_danezbazy;
int back_danezbazyadmin(void* NotUsed, int argc, char** argv, char** azColName) {

	cout << "===================" << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << i << " " << argv[i] << endl;
	}

	danezbazy.clear();
	string id = (string)argv[0];
	Administrator* Admin_kontozbazy = new Administrator(stoll(id), (string)argv[1], (string)argv[2], (string)argv[3], (string)argv[4]);
	Admin_danezbazy.push_back(Admin_kontozbazy);
	return 0;
}

vector<Administrator*> Baza::daneadminazbazy(string nazwabazy, string sql) {
	Admin_danezbazy.clear();
	sqlite3* db = polaczdobazy(nazwabazy);
	int rc;
	char* zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), back_danezbazyadmin, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		//fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Wypisano dane.\n");
	}
	sqlite3_close(db);
	return Admin_danezbazy;
}
