#include "Blik.h"


int Blik::generuj_kod_blik() {
	srand(time(NULL));
	int tab_blik[6];
	int x;
	cout << "Kod blik" << endl;
	for (int i = 0; i < 6; i++)
	{
		x = (rand() % 10);

		tab_blik[i] = x;

		cout << tab_blik[i] << " ";
		return tab_blik[i];
	}
	//return tab_blik[];
}

string Blik::wyswietl_blad() {
	cout << "Wystapil blad. Skonczyl sie czas lub kod blik sie nie pokrywa";
	return 0;
}

int Blik::terminal_request() {
	// TODO - implement Blik::terminal_request
	throw "Not yet implemented";
}

bool Blik::zweryfikuj_kod() {
	// TODO - implement Blik::zweryfikuj_kod
	throw "Not yet implemented";
}

void Blik::stworz_przelew() {
	// TODO - implement Blik::stworz_przelew
	throw "Not yet implemented";
}

void Blik::anuluj_przelew() {
	// TODO - implement Blik::anuluj_przelew
	throw "Not yet implemented";
}
