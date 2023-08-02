#include "interfejs.h"
#include "pociag.h"
#include "wagon.h"

void Interfejs::nazwa()
{
	std::cout << "\t \t \t -----------------------------------------------------------" << std::endl
		<< "\t \t \t | Program zakupu biletow i rezerwacji miejsc w pociagach. |" << std::endl
		<< "\t \t \t -----------------------------------------------------------" << std::endl;
}


int Interfejs::menu()
{
	std::cout << std::endl << "1. Rezerwacja miejsca i zakup biletu." << std::endl << "2. Sprawdz swoje bilety."
		<< std::endl << "3. Wyjdz z programu." << std::endl;
	int _wybor;
	std::cout << std::endl << "Prosze wybrac numer: ";
	std::cin >> _wybor;
	if (_wybor > 3)
		do {
			std::cout << "Prosze wybrac numer od 1 do 3!" << std::endl;
			std::cout << "Prosze wybrac numer: ";
			std::cin >> _wybor;
		} while (_wybor > 3);
		switch (_wybor)
		{
		case 1: _wybor = 1; break;
		case 2: _wybor = 2; break;
		case 3: _wybor = 3;  break;
		}
		return _wybor;
}

int Interfejs::sprawdz()
{
	int _wybor;
	std::cout << "Dostepne miasta: " << std::endl << "1. Warszawa" << std::endl << "2. Gdansk" << std::endl << "3. Gliwice" << std::endl <<
		"4. Czestochowa" << std::endl << "5. Krakow" << std::endl << "6. Poznan " << std::endl << "7. Szczecin" << std::endl << "8. Wroclaw" << std::endl
		<< "9. Powrot" << std::endl;
	std::cout << "Prosze wybrac numer: ";
	std::cin >> _wybor;
	if ((_wybor > 9) or (_wybor < 1))
		do {
			std::cout << "Prosze wybrac numer z przedzialu 1 do 9! " << std::endl << "Prosze podac numer: ";
			std::cin >> _wybor;
		} while ((_wybor > 9) or (_wybor < 1));
		switch (_wybor)
		{
		case 1: wybrane_miasto = "warszawa.txt"; break;
		case 2: wybrane_miasto = "gdansk.txt"; break;
		case 3: wybrane_miasto = "gliwice.txt"; break;
		case 4: wybrane_miasto = "czestochowa.txt"; break;
		case 5: wybrane_miasto = "krakow.txt"; break;
		case 6: wybrane_miasto = "poznan.txt"; break;
		case 7: wybrane_miasto = "szczecin.txt"; break;
		case 8: wybrane_miasto = "wroclaw.txt"; break;
		case 9: break;
		}
		return _wybor;
}

std::string Interfejs::get_miasto()
{
	return wybrane_miasto;
}


int Interfejs::koniec()
{
	return 0;
}


void Pociag::odczyt(std::string _plik)
{

	std::ifstream plik(_plik);
	double _godzina_o, _godzina_p;
	int wolne_miejsca, miejsca;
	char znak;
	while (plik >> znak >> _godzina_o >> znak >> _godzina_p >> znak >> znak >> wolne_miejsca >> znak >> miejsca >> znak)
	{
		auto para1 = std::make_pair(_godzina_o, _godzina_p);
		auto para2 = std::make_pair(wolne_miejsca, miejsca);
		mapa[para1] = para2;
	}
}

int Pociag::wypisz()
{
	int i = 0;
	int _wybor;
	for (auto& x : mapa)
	{
		std::cout << i + 1 << ". Pociag odjezdza o godzinie: " << x.first.first << ". Na miejscu o: " << x.first.second << ". Liczba miejsc wolnych: "
			<< x.second.first << ". Liczba miejsc lacznie: " << x.second.second << std::endl;
		i++;
	}
	std::cout << "6. Powrot" << std::endl;
	std::cout << "Prosze wybrac numer: ";
	std::cin >> _wybor;
	return _wybor;
}

void Pociag::zapisz(int _liczba)
{
	int i = 0;
	double o, p;
	int w, m;
	for (auto& x : mapa)
	{
		o = x.first.first;
		p = x.first.second;
		w = x.second.first;
		m = x.second.second;
		i++;
		if (i == _liczba)
		{
			godzina_o = o;
			godzina_p = p;
			wolne_miejsca = w - 1;
			miejsca = m;
			auto para = std::make_pair(o, p);
			auto para1 = std::make_pair(wolne_miejsca, m);
			mapa[para] = para1;
		}
	}
}

std::string Pociag::potwierdzenie()
{
	std::cout << "Prosze podac maila aby dokonac zakupu: ";
	std::string mail;
	std::cin >> mail;
	wolne_miejsca--;
	std::cout << "Gotowe, bilet zostanie wyslany na wskazany email.";
	return mail;
}

void Wagon::zapisz_maila(std::string _mail)
{
	maile[_mail]++;
}

void Wagon::odczyt_maili()
{
	std::ifstream plik_z_mailami("maile.txt");
	std::string mail;
	int liczba_biletow;
	char znak;
	while (plik_z_mailami >> mail >> znak >> liczba_biletow >> znak)
		maile[mail] = liczba_biletow;
}

int Wagon::wyswietl_bilety()
{
	int flaga = 1;
	std::string podany_mail;
	std::cout << "Prosze podac maila: ";
	std::cin >> podany_mail;
	for (auto& x : maile)
	{
		if (x.first == podany_mail)
		{
			flaga = 0;
			if (x.second == 1)
				std::cout << "Posiadasz juz bilet na pociag.";
			else if ((x.second >= 2) and (x.second < 5))
				std::cout << "Posiadasz juz " << x.second << " bilety na pociag.";
			else if (x.second > 4)
				std::cout << "Posiadasz juz " << x.second << " biletow na pociag.";
		}
	}
	if (flaga)
		std::cout << "Nie posiadasz jeszcze biletow";
	int zmienna;
	std::cout << std::endl << "1. Powrot do menu." << std::endl << "2. Wyjdz z programu." << std::endl << "Wybierz numer: ";
	std::cin >> zmienna;
	return zmienna;
}

void Wagon::zapisz_maila_dp()
{
	std::ofstream plik("maile.txt");
	if (plik)
		for (auto& x : maile)
			plik << x.first << " - " << x.second << "," << std::endl;
}

void Pociag::zapisz_dane_dp(std::string _plik)
{
	std::ofstream plik(_plik);
	if (plik)
		for (auto& x : mapa)
			plik << "[" << x.first.first << " - " << x.first.second << "](" << x.second.first << "," << x.second.second << ")" << std::endl;
}