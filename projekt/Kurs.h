#ifndef KURS_H
#define KURS_H

class Kurs {

private:
	double kwota;
	string waluta;

public:
	double sprawdz_kurs(int kwota);
};

#endif
