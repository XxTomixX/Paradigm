#include "Konto.h"
#include "Baza.h"
#include "Bankomat.h"
#include <vector>
#include <iomanip>

void Konto::zglos_blad(string tytul, string tresc) {
	// TODO - implement Konto::zglos_blad
	throw "Not yet implemented";
}

double Konto::stan_konta() {
	
	string sql = "SELECT Email,Tel,ID,Saldo,Zamrozone FROM Klienci WHERE ID = '" + to_string(id)+"';";
	saldo_konta = Baza::daneklientazbazy("klienci.db", sql)[0]->saldo_konta;

	cout << "Saldo wynosi: " <<setprecision(2)<<fixed<< saldo_konta <<" z³s"<<endl;
	
	return saldo_konta;
}

void Konto::wyswietl_komunikat(string komunikat) {
	cout << komunikat << endl;
}

long long int Konto::get_id() {
	return id;
}

void Konto::usun_konto() {

	string sql = "DELETE FROM Klienci WHERE Id='"+to_string(id)+"';";
	Baza::wykonaj("klienci.db", sql);
}

void Konto::zamroz_konto() {
	string sql = "UPDATE Klienci SET Zamrozone = '"+to_string(1)+"' WHERE ID = '"+ to_string(id) +"';";
	Baza::wykonaj("klienci.db", sql);
}

bool Konto::get_zamrozone()
{
	return czy_zamrozone;
}

long double Konto::get_saldo()
{
	return saldo_konta;
}

void Konto::operacje_na_koncie() {

	cout << "Witaj. Konto na którym wykonywane s¹ operacje to: " << id<<endl;
	cout << "Stan konta wynosi: " <<setprecision(2)<<fixed << saldo_konta << " z³" << endl;

	
	int opreacja = 0;
	
	Bankomat* maszyna;
	
	string id = "";
	string haslo = "";

	int ilosc_gotowki = 0;

	while (opreacja != 10)
	{
		cout << "1: Przelew" << endl;
		cout << "2: Kredyt" << endl;
		cout << "3: Lokata" << endl;
		cout << "4: SprawdŸ kurs" << endl;
		cout << "5: Usuñ konto" << endl;
		cout << "6: ZamroŸ konto" << endl;
		cout << "7: Stan Konta" << endl;
		cout << "8: Wp³aæ gotówke" << endl;
		cout << "9: Wyp³aæ gotówke" << endl;
		cout << "10: Wyloguj" << endl;
		cin >> opreacja;
		switch (opreacja)
		{
		case 1:

			break;

		case 2:
			
			kredyt_menu();

			break;

		case 3:
			lokata_menu();
			break;

		case 4:
			przewalutowanie();

			break;

		case 5:
			usun_konto();
			opreacja = 7;
			break;

		case 6:
			zamroz_konto();
			opreacja = 7;
			break;

		case 7:
			stan_konta();
			break;

		case 8:
			
			cout << "Podaj ile gotówki wp³aciæ " << endl;
			cin >> ilosc_gotowki;
			maszyna = new Bankomat(ilosc_gotowki);
			maszyna->wplac_pieniadze(this);
			delete maszyna;
			stan_konta();
			break;

		case 9:

			cout << "Podaj ile gotówki wyplacic " << endl;
			cin >> ilosc_gotowki;
			maszyna = new Bankomat(ilosc_gotowki);
			maszyna->wyplac_pieniadze(this);
			stan_konta();
			delete maszyna;

			break;

		default:

			break;
		}
	}

}

void Konto::kredyt_menu()
{
	int opreacja_kredyt = 0;
	Kredyt* nowy = NULL;

	string typ = "";
	double kwota = 0;
	string waluta = "";
	double oprocentowanie = 0;
	string data_zaciagniecia = "";
	string termin_splaty = "";
	unsigned long int id_kredytu = 0;

	string sql;

	while (opreacja_kredyt != 4)
	{
		cout << "1: WeŸ kredyt" << endl;
		cout << "2: Lista kredytów" << endl;
		cout << "3: Przewalutowanie kredytu" << endl;
		cout << "4: Opcje konta" << endl;
		cin >> opreacja_kredyt;
		switch (opreacja_kredyt)
		{
		case 1:

			cout <<"Podaj typ kredytu: ";
			cin >> typ;
			cout << "Podaj kwote kredytu: ";
			cin >> kwota;
			nowy = new Kredyt(typ,kwota,waluta,oprocentowanie,data_zaciagniecia,termin_splaty);
			nowy->zapisz_kredyt_w_bazie(id);



			delete nowy;
		
			break;

		case 2:
	
			lista_kredytow();

			break;

		case 3:
			lista_kredytow();

			if (kredyty.size() < 0)
			{
				cout << "Brak kredytów" << endl;
			}
			else
			{
				int przewalutowany_kredyt = 0;
				cout << "Wybierz kredyt: " << endl;
				cin >> przewalutowany_kredyt;
				kredyty[przewalutowany_kredyt]->przewalutowanie_kredytu();
			}
			//sql = "SELECT * FROM Kredyty WHERE KlientID = '" + to_string(id) + "';";
			//kredyty = Baza::danezbazykredyt("kredyty.db", sql);

			

			break;

		default:

			break;
		}
	}
}

void Konto::lokata_menu()
{
	

	int operacja_lokaty = 0;
	while (operacja_lokaty != 4)
	{
		cout << "1: Stwórz lokate" << endl;
		cout << "2: Lista lokat" << endl;
		cout << "3: Anuluj lokate" << endl;
		cout << "4: Opcje konta" << endl;
		cin >> operacja_lokaty;
		switch (operacja_lokaty)
		{
		case 1:
			tworzenie_lokaty();
			break;

		case 2:
			lista_lokat();
			break;

		case 3:
			anuluj_lokate();
			break;

		default:

			break;
		}
	}
}

void Konto::anuluj_lokate()
{
	lista_lokat();
	if (lokaty.size() < 0)
	{
		cout << "Brak lokat" << endl;
	}
	else
	{
		int anulowanie = 0;
		cout << "Wybierz lokate: " << endl;
		cin >> anulowanie;
		lokaty[anulowanie]->anuluj_lokate(id);
	}
}

void Konto::tworzenie_lokaty()
{
	string typ = "";
	double kwota = 0;
	Lokata* nowa = NULL;
	cout << "Podaj typ lokaty: ";
	cin >> typ;
	cout << "Podaj wielkoœæ lokaty: ";
	cin >> kwota;
	nowa = new Lokata(typ, kwota, 0, 0);
	if (kwota > saldo_konta)
	{
		cout << "Brak œrodków do utworzenia lokaty" << endl;
	}
	else
	{
		nowa->zapisz_lokate_do_bazy(id);
	}


	delete nowa;
}

void Konto::lista_lokat()
{
	string sql = "SELECT * FROM Lokaty WHERE KlientID = '" + to_string(id) + "';";
	lokaty = Baza::danezbazylokat("lokaty.db", sql);

	for (auto &lokata : lokaty) // access by reference to avoid copying
	{
		lokata->get_informacje();
	}
}

void Konto::lista_kredytow()
{
	string sql = "SELECT * FROM Kredyty WHERE KlientID = '" + to_string(id) + "';";
	kredyty = Baza::danezbazykredyt("kredyty.db", sql);

	for (auto &kredyt : kredyty) // access by reference to avoid copying
	{
		kredyt->get_informacje();
	}
}

double Konto::przewalutowanie()
{
	int kwota = 0;
	string waluta = "";

	cout << "Podaj kwote (z³): ";
	cin >> kwota;

	cout << "Podaj walute (USD lub EUR): ";
	cin >> waluta;

	return Kurs::sprawdz_kurs(kwota, waluta);
}
