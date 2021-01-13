#include <iostream>
#include <string>
#include "sql/sqlite3.h" 
#include "Konto.h" 
#include "Blad.h" 

#include <vector>

using namespace std;

class Baza {

public:

	static sqlite3* polaczdobazy(string nazwa);
	static vector<Konto*> daneklientazbazy(string nazwabazy, string sql);
	static bool czyistnieje(string nazwabazy, string sql);
	static void idkont(string nazwabazy, string sql);
	static vector<Kredyt*> danezbazykredyt(string nazwabazy, string sql);
	static vector<Lokata*> danezbazylokat(string nazwabazy, string sql);
  
	

	static void stworzBazeBledow();
	static vector<Blad*> daneBlad(string nazwabazy, string sql);

	static void stworzBazeAdmin();
	static bool wykonaj(string nazwa, string sql);
  
};


