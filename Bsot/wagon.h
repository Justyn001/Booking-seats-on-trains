#pragma once
#include "interfejs.h"


class Wagon : public Pociag
{
private:
	std::map<std::string, int> maile;
public:
	void odczyt_maili();
	int wyswietl_bilety();
	void zapisz_maila(std::string);
	void zapisz_maila_dp();
};