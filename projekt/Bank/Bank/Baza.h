#include <iostream>
#include <string>
#include "sql/sqlite3.h" 
#include "Konto.h" 
#include "Blad.h" 
#include "Administrator.h"
#include <vector>

using namespace std;

class Baza {

public:

	// obs³uguje po³¹cznie z baz¹
	static sqlite3* polaczdobazy(string nazwa);

	// wykonaj na bazie zadana komende SQL
	static bool wykonaj(string nazwa, string sql);	
	static bool czyistnieje(string nazwabazy, string sql);
	static void idkont(string nazwabazy, string sql);

	// zapisanie danych z bazy do wektora
	static vector<Kredyt*> danezbazykredyt(string nazwabazy, string sql);
	static vector<Lokata*> danezbazylokat(string nazwabazy, string sql);
	static vector<Przelew*> danezbazyprzelew(string nazwabazy, string sql);
	static vector<Administrator*> daneadminazbazy(string nazwabazy, string sql);
	static vector<Konto*> daneklientazbazy(string nazwabazy, string sql);
	static vector<Blad*> daneBlad(string nazwabazy, string sql);

	// tworzenie bazy przy pierwszym wywolaniu
	static void stworzBazeBledow();
	static void stworzBazeAdmin();
	static void stworzBazePrzelewow();
	static void stworzBazePrzelewowBlik();
	
};


