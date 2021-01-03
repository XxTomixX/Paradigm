#ifndef KONTO_H
#define KONTO_H

class Konto {

private:
	string haslo;
	string email;
	string nr_telefonu;
	int id;
	double saldo_konta;
	boolean czy_zamrozone;

public:
	Kurs podaj_kurs(double i, string waluta);

	void zglos_blad(string tytul, string tresc);

	bool modyfikuj_stan_konta(string operacja, int kwota);

	double stan_konta();

	string wyswietl_komunikat(int numer_komunikatu);

	Konto dostep_do_konta();

	void zamroz_srodki();

	void zaaktualizuj_dane_konta();
};

#endif
