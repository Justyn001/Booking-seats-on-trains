#pragma once
#include "interfejs.h"

class Pociag
{
private:
	std::string miasto;
	std::map<std::pair<double, double>, std::pair<int, int>> mapa;
	double godzina_o, godzina_p;
	int miejsca;
	int wolne_miejsca;
public:
	void odczyt(std::string plik);
	int wypisz();
	void zapisz(int);
	std::string potwierdzenie();
	void zapisz_dane_dp(std::string);
};