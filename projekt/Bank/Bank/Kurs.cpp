#include "Kurs.h"

//Przelicza złotówki na USD lub EUR
double Kurs::sprawdz_kurs(double kwota, string waluta) {

	if (waluta == "EUR")
	{
		cout << "Twoje oszczędności w EURO: ";
		cout << kwota / (4.5136) <<"  €"<< endl;
		return kwota / (4.5136);
	}
	else if (waluta == "USD")
	{
		cout << "Twoje oszczędności w USD: ";
		cout << kwota / (3.7097) << "  $" << endl;
		return kwota / (3.7097);
	}
	else
	{
		cout << "Waluta nie obsługiwana" << endl;
		return 0;
	}
}
