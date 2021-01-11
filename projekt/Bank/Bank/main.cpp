
#include "Osoba.h"
#include "Klient.h"

#include "Konto.h"
#include "Przelew.h"
#include "Kredyt.h"
#include "Lokata.h"


#include "Administrator.h"
#include "Blik.h"
#include "Data.h"
#include "Kurs.h"

#include "Blad.h"
#include "Bankomat.h"
#include "main.h"

#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

void rejestracja();

int main()
{
	 setlocale(LC_CTYPE, "Polish");
	//Klient k("BBBBB", "xsss", 123123, 12332);
	//k.zarejestruj("1xxxxQxxx","asdad@gmail.com","121123123");

	int operacja = 0;
	
	while (operacja != 3)
	{
		cout << "Witaj w Banku" << endl;
		cout << "1: Zaloguj" << endl;
		cout << "2: Zarejestruj siê" << endl;
		cout << "3: WyjdŸ" << endl;
	
		cin >> operacja;
		switch (operacja)
		{
		case 1:
			//system("cls");
			menu_logowanie(operacja);
			break;

		case 2:
			rejestracja();
			break;

		default:
	
			break;
		}
	}

	system("Pause");
}

void menu_logowanie(int operacja)
{
	
	
	int log = 0;

	while (log != 3)
	{
		Klient* logowany = new Klient();
		string id ="";
		string haslo="";
		cout << "1: Klient" << endl;
		cout << "2: Administrator" << endl;
		cout << "3: Menu" << endl;
		cin >> log;
		switch (log)
		{
		case 1:

			cout << "Podaj id konta" << endl;
			cin >> id;
			cout << "Podaj haslo konta" << endl;
			cin >> haslo;

			cout << id << " " << haslo << endl;
			logowany->zaloguj(id, haslo);
			delete logowany;
			break;

		case 2:
			cout << "A";
			break;

		default:

			break;
		}
	}

}

void rejestracja()
{
	

	bool udanarejestracja = false;

	while (!udanarejestracja)
	{
		string imie = "";
		string nazwisko = "";
		string pesel = "";
		string nip = "";
		string haslo = "";
		string email = "";
		string tel = "";
		int wyjscie = 0;

		cout << "Menu 1 konntynuj rejestracje 0" << endl;
		cin >> wyjscie;
		if (wyjscie == 1)
		{
			system("cls");
			break;
		}

		cout << "Podaj imie" << endl;
		cin >> imie;
		cout << "Podaj nazwisko" << endl;
		cin >> nazwisko;
		cout << "Podaj pesel" << endl;
		cin >> pesel;
		cout << "Podaj nip" << endl;
		cin >> nip;
		cout << "Podaj email" << endl;
		cin >> email;
		cout << "Podaj numer telefonu" << endl;
		cin >> tel;
		cout << "Podaj haslo" << endl;
		cin >> haslo;


		Klient* k = new Klient(imie, nazwisko, pesel, nip);
		udanarejestracja = k->zarejestruj(haslo, email,tel);
		if (!udanarejestracja) { delete k; }
		else
		{
			k->podajidkont(haslo);
			delete k;
		}

	}

	
	
	

}