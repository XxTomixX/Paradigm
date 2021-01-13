#include "Kurs.h"

//Przelicza z³otówki na USD lub EUR
double Kurs::sprawdz_kurs(double kwota, string waluta) {
	if (waluta == "EUR")
	{
		cout << "Twoje oszczêdnoœci w EURO: ";
		cout << kwota / (4.5136) <<"  €"<< endl;
		return kwota / (4.5136);
	}
	else if (waluta == "USD")
	{
		cout << "Twoje oszczêdnoœci w USD: ";
		cout << kwota / (3.7097) << "  $" << endl;
		return kwota / (3.7097);
	}
	else
	{
		cout << "Waluta nie obs³ugiwana" << endl;
		return 0;
	}

	
}
