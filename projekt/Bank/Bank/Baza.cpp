#include "Baza.h"
#include "Konto.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> 
#include <sstream>
#include "sql/sqlite3.h" 

using namespace std;


//Metoda ³¹czy z baz¹ danych o podanej nazwie
sqlite3* Baza::polaczdobazy(string nazwabazy) {

	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	string sql;

	rc = sqlite3_open(nazwabazy.c_str(), &db);

	
	if (rc) {
		//fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return NULL;
	}
	else {
		//fprintf(stdout, "Opened database successfully\n");
		return db;
	}
	
	
}

//Zapisywanie danych do bazy
bool Baza::klientdanedobazy(string nazwabazy, string sql) {
	
	sqlite3 *db = polaczdobazy("Klienci.db");

	int rc;
	char *zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		//fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else {
		//fprintf(stdout, "Ok \n");
		sqlite3_close(db);
		return true;
	}
	

	
}
bool Baza::admindanedobazy(string nazwabazy, string sql) {
	// TODO - implement Klient::wyloguj
	throw "Not yet implemented";
}

//Czy klient istnieje zwraca bool
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
		//fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		
	}
	else {
		//fprintf(stdout, "Istnieje \n");
		sqlite3_close(db);
		
	}

	return istnieje;
}

//Zwraca listê obiektów kont klienta o podanym haœle
vector<Konto*> danezbazy;
int back_danezbazy(void *NotUsed, int argc, char **argv, char **azColName) {

	cout << "===================" << endl;
	for (int i = 0; i < argc; i++)
	{
		cout<<i<<" "<< argv[i] << endl;
	}
	
	string id = (string)argv[2];
	Konto* kontozbazy = new Konto((string)argv[0], (string)argv[1], stoll(id), atof(argv[3]), stoi(argv[4]));
	danezbazy.push_back(kontozbazy);
	cout<<"sss"<<danezbazy[0]->get_id();
	cout << endl;
	return 0;
}

vector<Konto*> Baza::daneklientazbazy(string nazwabazy, string sql) {

	sqlite3 *db = polaczdobazy(nazwabazy);

	int rc;
	char *zErrMsg = 0;
	rc = sqlite3_exec(db, sql.c_str(), back_danezbazy, NULL, &zErrMsg);

	if (rc != SQLITE_OK) {
		//fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Wypisano \n");
	}
	sqlite3_close(db);


	return danezbazy;
}

//Funkcja pomocnicza sqlite3 i metoda zwracaj¹ca id konta

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
		//fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		//fprintf(stdout, "Wypisano \n");
	}
	sqlite3_close(db);
}


