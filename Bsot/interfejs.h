#ifndef interfejs_h
#define interfejs_h

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

class Interfejs
{
	friend class Pociag;
private:
	std::string wybrane_miasto;
public:
	void nazwa();
	int menu();
	int sprawdz();
	int koniec();
	std::string get_miasto();
};

#endif