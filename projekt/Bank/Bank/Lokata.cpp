#include "Lokata.h"
#include "Konto.h"
#include "Baza.h"

void Lokata::anuluj_lokate(long long int id) {
	//Dodanie do salda konta wielko�ci usuwanej lokaty
	string sql_konto = "UPDATE Klienci SET Saldo = Saldo +" + to_string(kwota) + " WHERE ID =" + to_string(id) + ";";
	Baza::wykonaj("klienci.db", sql_konto);

	string sql_lokaty = "DELETE FROM Lokaty WHERE ID = "+to_string(id_lokaty)+";";
	Baza::wykonaj("lokaty.db", sql_lokaty);
}

void Lokata::get_informacje() {

	cout << "Id Lokaty: " << id_lokaty << endl;
	cout << "Typ: " << typ_lokaty << endl;
	cout << "Kwota: " << kwota << endl;
	cout << "Oprocentowanie: " << oprocentowanie << endl<<endl;
}

void Lokata::zapisz_lokate_do_bazy(long long int id) {
	
	//Zapisanie lokaty wa bazie
	string sql_lokaty = "INSERT INTO Lokaty (ID,KlientID,Typ,Kwota,Oprocentowanie,Utworzenie) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + to_string(id) + "','" + typ_lokaty + "','"
		+ to_string(kwota) + "','" + to_string(oprocentowanie) + "',date('now')); ";
	Baza::wykonaj("lokaty.db", sql_lokaty);

	//Odj�cie od salda konta wielko�ci lokaty
	string sql_konto = "UPDATE Klienci SET Saldo = Saldo -" + to_string(kwota) + " WHERE ID =" + to_string(id) + ";";
	Baza::wykonaj("klienci.db", sql_konto);

}
