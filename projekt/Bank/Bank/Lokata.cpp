#include "Lokata.h"
#include "Konto.h"
#include "Baza.h"

//Usuniêcie lokaty z bazy
void Lokata::anuluj_lokate(long long int id) {
	//Dodanie do salda konta wielkoœci usuwanej lokaty
	string sql_konto = "UPDATE Klienci SET Saldo = Saldo +" + to_string(kwota) + " WHERE ID =" + to_string(id) + ";";
	Baza::wykonaj("klienci.db", sql_konto);

	//Usuniêcie lokaty
	string sql_lokaty = "DELETE FROM Lokaty WHERE ID = "+to_string(id_lokaty)+";";
	Baza::wykonaj("lokaty.db", sql_lokaty);
}

//Wypisujê informacjê o lokacie
void Lokata::get_informacje() {

	cout << "Id Lokaty: " << id_lokaty << endl;
	cout << "Typ: " << typ_lokaty << endl;
	cout << "Kwota: " << kwota << endl;
	cout << "Oprocentowanie: " << oprocentowanie << endl<<endl;
}

//Zapisanie lokaty do bazy
void Lokata::zapisz_lokate_do_bazy(long long int id) {
	
	//Zapisanie lokaty wa bazie
	string sql_lokaty = "INSERT INTO Lokaty (ID,KlientID,Typ,Kwota,Oprocentowanie,Utworzenie) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + to_string(id) + "','" + typ_lokaty + "','"
		+ to_string(kwota) + "','" + to_string(oprocentowanie) + "',date('now')); ";
	Baza::wykonaj("lokaty.db", sql_lokaty);

	//Odjêcie od salda konta wielkoœci lokaty
	string sql_konto = "UPDATE Klienci SET Saldo = Saldo -" + to_string(kwota) + " WHERE ID =" + to_string(id) + ";";
	Baza::wykonaj("klienci.db", sql_konto);

}
