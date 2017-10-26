#include <cstdio>
#include "Header.h"
#include <string>
using namespace std;

int main() {
	



	Tablica<Dane, a> Tab;


	for (int i = 0; i < a; i++)
	{
		Tab[i].ID = i + i;
	}

	strcpy_s(Tab[0].nick, "Piasek");
	Tab[0].level = 7;
	Tab[0].pkt = 30.0343;

	strcpy_s(Tab[1].nick, "Piesek");
	Tab[1].level = 12;
	Tab[1].pkt = 100.9343;

	strcpy_s(Tab[2].nick, "Pasek");
	Tab[2].level = 15;
	Tab[2].pkt = 5432.1434;

	strcpy_s(Tab[3].nick, "Pisak");
	Tab[3].level = 2;
	Tab[3].pkt = 50.0343;

	string nazwa = "3.txt";

	int tryb = ios::out|ios::app;

	fun(Tab, nazwa, tryb);



	
	


	return 0;
}