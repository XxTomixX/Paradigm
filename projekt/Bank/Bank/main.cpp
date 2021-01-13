
#include "Osoba.h"
#include "Klient.h"

#include "Konto.h"
#include "Bankomat.h"
#include "Przelew.h"
#include "Kredyt.h"
#include "Lokata.h"

#include "Administrator.h"
#include "Blik.h"
#include "Kurs.h"

#include "Blad.h"
#include "main.h"

#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

void rejestracja();

int main()
{
	setlocale(LC_CTYPE, "Polish");
	
	int operacja = 0;
	
	while (operacja != 3)
	{
		cout << "Witaj w Banku" << endl;
		cout << "1: Zaloguj" << endl;
		cout << "2: Zarejestruj się" << endl;
		cout << "3: Wyjdź" << endl;
	
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
		cout << "1: Klient" << endl;
		cout << "2: Administrator" << endl;
		cout << "3: Menu" << endl;
		cin >> log;
		switch (log)
		{
		case 1:
			log_Klient();
			break;

		case 2:
			log_Admin();
			break;

		default:

			break;
		}
	}
}

void log_Admin()
{
	Administrator* Admin_Logowany = new Administrator();
	int id_a;
	string haslo_a = "";
	cout << "Administracja - Panel logowania" << endl;
	cout << "Podaj id konta" << endl;
	cin >> id_a;
	cout << "Podaj haslo konta" << endl;
	cin >> haslo_a;
	Admin_Logowany->zaloguj(id_a, haslo_a);
	delete Admin_Logowany;
}

void log_Klient()
{
	Klient* logowany = new Klient();
	string id = "";
	string haslo = "";
	cout << "Podaj id konta" << endl;
	cin >> id;
	cout << "Podaj haslo konta" << endl;
	cin >> haslo;

	cout << id << " " << haslo << endl;
	logowany->zaloguj(id, haslo);
	delete logowany;
}

void rejestracja()
{
	int wybor;
	bool udanarejestracja = false;

	cout << "\nREJESTRACJA KLIENTA - WYBIERZ [0]\nREJESTRACJA ADMIN - WYBIERZ [1]\n";
	cin >> wybor;
	if (wybor == 0) {
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

			cout << "[0] KONTYNUUJ\n[1] POWRÓT DO MENU\n" << endl;
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
			udanarejestracja = k->zarejestruj(haslo, email, tel);
			if (!udanarejestracja) { delete k; }
			else
			{
				k->podajidkont(haslo);
				delete k;
			}

		}

	}
	else if (wybor == 1) {

		while (!udanarejestracja)
		{
			int id_a;
			string imie_a = "";
			string nazwisko_a = "";
			string haslo_a = "";
			string email_a = "";
			int wyjscie = 0;

			cout << "[0] KONTYNUUJ\n[1] POWRÓT DO MENU\n" << endl;
			cin >> wyjscie;
			if (wyjscie == 1)
			{
				system("cls");
				break;
			}
			cout << "Podaj okreslone ID" << endl;
			cin >> id_a;
			cout << "Podaj imie" << endl;
			cin >> imie_a;
			cout << "Podaj nazwisko" << endl;
			cin >> nazwisko_a;
			cout << "Podaj email" << endl;
			cin >> email_a;
			cout << "Podaj haslo" << endl;
			cin >> haslo_a;


			Administrator* a = new Administrator(id_a,imie_a,nazwisko_a,haslo_a,email_a);
			udanarejestracja = a->rejestracja(id_a, haslo_a, email_a);
			if (!udanarejestracja) { delete a; }

		}
	}
}

	
	
	

