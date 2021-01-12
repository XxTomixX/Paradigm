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
	static bool klientoperacjanabazie(string nazwabazy, string sql);
	static bool admindanedobazy(string nazwabazy, string sql);
	static vector<Konto*> daneklientazbazy(string nazwabazy, string sql);
	static bool czyistnieje(string nazwabazy, string sql);
	static void idkont(string nazwabazy, string sql);
	static vector<Kredyt*> danezbazykredyt(string nazwabazy, string sql);
	static bool kredytoperacjanabazie(string nazwabazy, string sql);
  
  static void stworzBazeBledow();
	static bool dodaj_blad_do_bazy(string nazwabazy, string sql);
	static vector<Blad*> daneBlad(string nazwabazy, string sql);

	static void stworzBazeAdmin();
	static bool dodaj_admina_do_bazy(string nazwabazy, string sql);
	static bool wykonaj(string nazwa, string sql);
  
};


