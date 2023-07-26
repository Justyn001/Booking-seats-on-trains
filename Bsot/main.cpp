#include <iostream>﻿
#include "interfejs.h"
#include "pociag.h"
#include "wagon.h"


int main()
{
	int zmienna;
	Interfejs poczatek;
	Pociag x;
	Wagon w;
	while (true)
	{
		poczatek.nazwa();
		zmienna = poczatek.menu();
		if (zmienna == 1)
		{
			zmienna = poczatek.sprawdz();
			if ((zmienna > 0) and (zmienna < 9))
			{
				x.odczyt(poczatek.get_miasto());
				zmienna = x.wypisz();
				if ((zmienna > 0) and (zmienna < 6))
				{
					w.odczyt_maili();
					x.zapisz(zmienna);
					w.zapisz_maila(x.potwierdzenie());
					w.zapisz_maila_dp();
					x.zapisz_dane_dp(poczatek.get_miasto());
				}
			}

		}
		else if (zmienna == 2)
		{
			w.odczyt_maili();
			zmienna = w.wyswietl_bilety();
			if (zmienna == 2)
			{
				return 0;
			}
		}
		else if (zmienna == 3)
		{
			return 0;
		}
		std::string znak;
		std::cout << std::endl << "Czy chcesz zrobic cos jeszcze?(T/N): ";
		std::cin >> znak;
		if ((znak == "N") or (znak == "n"))
			break;
		system("cls");
	}
}