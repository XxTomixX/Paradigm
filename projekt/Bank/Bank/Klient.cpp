#include "Klient.h"
#include "Baza.h"
#include "sql/sqlite3.h"
#include <vector>

//Logowanie pozwala na dostęp do operacji na koncie
void Klient::zaloguj(string id, string haslo) {
	
	string sql = "SELECT Email,Tel,ID,Saldo,Zamrozone FROM Klienci WHERE ID = '" + id + "' AND Haslo = '" + haslo + "';";

	konta.clear();
	konta = Baza::daneklientazbazy("klienci.db", sql);

	if (konta.empty())
	{
		wyswietl_blad("Błędne haslo lub ID");
	}
	else
	{
		if (!konta[0]->get_zamrozone())
		{
			konta[0]->operacje_na_koncie();
		}
		else
		{
			wyswietl_blad("Twoje konto zostało zamrożone");
		}
		wyloguj();
	}
	
}

//Usunięcie obiektu konto
void Klient::wyloguj() {
	while (!konta.empty())
	{
		delete konta.back();
		konta.pop_back();
	}
	konta.clear();
}

//Zapisanie klienta (konto do bazy)
bool Klient::zarejestruj(string haslo, string email, string tel) {
	
	bool poprawnedane = sprawdz_poprawnosc_danych(haslo,email,tel);
	
	if (poprawnedane == true)
	{
		bool klientistnieje = czy_klient_istnieje();

		if (klientistnieje)
		{
			wyswietl_blad("Taki klient istnieje");
			return false;
		}
		else
		{
			wprowadz_konto_do_bazy(haslo, email, tel);
			return true;
		}

	}
	else
	{
		wyswietl_blad("Niepoprawne dane");
		return false;
	}
}


//Sprawdza popdawność niktórych wprowadzanych danych
bool Klient::sprawdz_poprawnosc_danych(string haslo, string email, string tel) {
	int dlugoschasla = haslo.length();
	int dlugostel = tel.length();
	if (haslo == "")
	{
		wyswietl_blad("Wprowadzono puste haslo");
		return false;
	}
	else if (dlugoschasla < 9)
	{
		wyswietl_blad("Kr�tkie has�o");
		return false;
	}
	else
	{
		bool liczba = false;
		bool malelitery = false;
		bool duzelitery = false;

		for (int i = dlugoschasla - 1; i >= 0; i--)
		{
			
			if (haslo[i] >= 48 && haslo[i] <= 57)
			{
				liczba = true;
			}

			if (haslo[i] >= 97 && haslo[i] <= 122)
			{
				malelitery = true;
			}

			if (haslo[i] >= 65 && haslo[i] <= 90)
			{
				duzelitery = true;
			}


		}

		for (int i = dlugostel - 1; i >= 0; i--)
		{
			if (tel[i] < 48 || tel[i] > 57)
			{
				wyswietl_blad("Wykryto inne znaki ni�cyfry");
				return false;
			}
		}

		if (dlugostel < 9)
		{
			wyswietl_blad("Za kr�tki numer telefonu");
			return false;
		}

		if (dlugostel > 9)
		{
			wyswietl_blad("Za d��gi numer telefonu");
			return false;
		}

		if (liczba == false)
		{
			wyswietl_blad("Brak liczby w ha�le");
			return false;
		}

		if (malelitery == false)
		{
			wyswietl_blad("Brak ma�ych liter w ha�le");
			return false;
		}

		if (duzelitery == false)
		{
			wyswietl_blad("Brak du�ych liter w ha�le");
			return false;
		}
	}

	return true;
}

//Wyświetla błąd
string Klient::wyswietl_blad(string blad) {
	
	cout << blad << endl;
	return blad;
}


//Sprawdza czy istnieje już taki klient w bazie
bool Klient::czy_klient_istnieje() {
	
	string sql = "SELECT ID FROM Klienci WHERE Imie = '" + imie + "' AND Nazwisko = '" + nazwisko + "' AND Pesel = '" + pesel + "';";
	return Baza::czyistnieje("klienci.db", sql);
}

//Zwraca id konta o danym haśle
void Klient::podajidkont(string haslo) {

	string sql = "SELECT ID FROM Klienci WHERE Haslo = '" + haslo + "';";
	Baza::idkont("klienci.db", sql);
}


//Wprowadzenie konta do bazy
bool Klient::wprowadz_konto_do_bazy(string haslo, string email, string tel) {
	
	string sql = "INSERT INTO Klienci (ID,Imie,Nazwisko,Pesel,Nip,Haslo,Email,Tel,Saldo,Zamrozone,LogDwa) "
		"VALUES ( ABS(random() % (9999999999 - 1000000000) + 1000000000),'" + imie + "','" + nazwisko + "','" 
		+ pesel + "','" + nip + "','" + haslo + "','" + email + "'," + tel + ",0,0,0 ); ";

	Baza::wykonaj("klienci.db", sql);

	return false;
}

