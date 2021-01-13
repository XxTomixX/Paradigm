#include "Konto.h"
#include "Baza.h"
#include "Bankomat.h"
#include <vector>
#include <iomanip>

//Wypisujê stan konta
double Konto::stan_konta() {
	
	string sql = "SELECT Email,Tel,ID,Saldo,Zamrozone FROM Klienci WHERE ID = '" + to_string(id)+"';";
	saldo_konta = Baza::daneklientazbazy("klienci.db", sql)[0]->saldo_konta;

	cout << "Saldo wynosi: " <<setprecision(2)<<fixed<< saldo_konta <<" z³s"<<endl;
	
	return saldo_konta;
}

void Konto::zglos_blad(string tytul, string tresc) {
	// TODO - implement Konto::zglos_blad
	throw "Not yet implemented";
}

void Konto::wyswietl_komunikat(string komunikat) {
	cout << komunikat << endl;
}

//usuwa konto z bazy
void Konto::usun_konto() {

	string sql = "DELETE FROM Klienci WHERE Id='"+to_string(id)+"';";
	Baza::wykonaj("klienci.db", sql);
}

//zamrozenie konta 
void Konto::zamroz_konto() {
	string sql = "UPDATE Klienci SET Zamrozone = '"+to_string(1)+"' WHERE ID = '"+ to_string(id) +"';";
	Baza::wykonaj("klienci.db", sql);
}

long long int Konto::get_id() {
	return id;
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
	int operacja_przelew = 0;
	
	
	string id = "";
	string haslo = "";

	

	while (opreacja != 10)
	{
		
		Przelew* now = new Przelew;
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
		cin.ignore();
		switch (opreacja)
		{
		case 1:
			operacja_przelew = 1;
			przelew_menu(operacja_przelew, now);
			break;

		case 2:
			kredyt_menu();
			break;

		case 3:
			lokata_menu();
			break;

		case 4:
			zmiananakurs();
			break;

		case 5:
			usun_konto();
			opreacja = 10;
			break;

		case 6:
			zamroz_konto();
			opreacja =10;
			break;

		case 7:
			stan_konta();
			break;

		case 8:
			wplac_gotowke();
			break;

		case 9:
			wyplac_gotowke();
			break;

		default:
			break;
		}
		delete now;
		
	}
	
}

//odejmowanie gotówki z konta
void Konto::wyplac_gotowke()
{
	Bankomat* maszyna = new Bankomat;
	double ilosc_gotowki = 0.0;
	cout << "Podaj ile gotówki wyplacic " << endl;
	cin >> ilosc_gotowki;
	maszyna = new Bankomat(ilosc_gotowki);
	maszyna->wyplac_pieniadze(this);
	stan_konta();
	delete maszyna;
}

//dodawanie gotówki do konta
void Konto::wplac_gotowke()
{
	Bankomat* maszyna = new Bankomat;
	double ilosc_gotowki = 0.0;
	cout << "Podaj ile gotówki wp³aciæ " << endl;
	cin >> ilosc_gotowki;
	maszyna = new Bankomat(ilosc_gotowki);
	maszyna->wplac_pieniadze(this);
	stan_konta();
	delete maszyna;
}

//obsluga menu przelewu
void Konto::przelew_menu(int& opreacja_przelew, Przelew*& now)
{
	unsigned long int id_odbiorca = 0;
	double kwota = 0.0;
	unsigned long int id_przelewu = 0;
	string typ_przelewu = "";

	while (opreacja_przelew == 1)
	{
		cout << "Czy chcesz wykonac przelew?" << endl << "1-Tak" << endl << "2-Nie" << endl;
		cin >> opreacja_przelew;
		switch (opreacja_przelew)
		{
		case 1:

			cout << "Podaj id odbiorcy ";
			cin >> id_odbiorca;
			cout << "Podaj kwote przelewu: ";
			cin >> kwota;
			if (kwota > saldo_konta) {
				cout << "Za ma?o ?rodków na koncie" << endl;
			}
			else 
			{
				now = new Przelew(id_odbiorca, kwota, id_przelewu, typ_przelewu, id);
				now->stworz_przelew(id_odbiorca, kwota);
			}
			break;

		case 2:

			break;

		default:

			break;
		}
	}
}

//obsluga menu kredytu
void Konto::kredyt_menu()
{
	int opreacja_kredyt = 0;

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
			tworzenie_kredytu();
			break;

		case 2:
	
			lista_kredytow();
			break;

		case 3:
			przewalutowanie_kredytu();
			break;
		default:
			break;
		}
	}
}

//przewalutowanie kredytu
void Konto::przewalutowanie_kredytu()
{
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
}


//tworzy i zapisujê kredyt w bazie
void Konto::tworzenie_kredytu()
{
	Kredyt* nowy = NULL;
	string typ = "";
	double kwota = 0.0;
	string waluta = "";
	double oprocentowanie = 0.0;
	string data_zaciagniecia = "";
	string termin_splaty = "";
	cout << "Podaj typ kredytu: ";
	cin >> typ;
	cout << "Podaj kwote kredytu: ";
	cin >> kwota;
	nowy = new Kredyt(typ, kwota, waluta, oprocentowanie, data_zaciagniecia, termin_splaty);
	nowy->zapisz_kredyt_w_bazie(id);
	delete nowy;
}

//obsluga menu lokaty
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

//usuwa lokate z bazy i przypisujê kwotê do konta
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

//tworzy lokate w bazie
void Konto::tworzenie_lokaty()
{
	string typ = "";
	double kwota = 0.0;
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

//wyœwietla listê lokat
void Konto::lista_lokat()
{
	string sql = "SELECT * FROM Lokaty WHERE KlientID = '" + to_string(id) + "';";
	lokaty = Baza::danezbazylokat("lokaty.db", sql);

	for (auto &lokata : lokaty) // access by reference to avoid copying
	{
		lokata->get_informacje();
	}
}

//wyœwietla listê kredytów
void Konto::lista_kredytow()
{
	string sql = "SELECT * FROM Kredyty WHERE KlientID = '" + to_string(id) + "';";
	kredyty = Baza::danezbazykredyt("kredyty.db", sql);

	for (auto &kredyt : kredyty) // access by reference to avoid copying
	{
		kredyt->get_informacje();
	}
}

//przelicza podan¹ iloœæ z³otówek na USD lib EUR
double Konto::zmiananakurs()
{
	double kwota = 0.0;
	string waluta = "";

	cout << "Podaj kwote (z³): ";
	cin >> kwota;

	cout << "Podaj walute (USD lub EUR): ";
	cin >> waluta;

	return Kurs::sprawdz_kurs(kwota, waluta);
}
