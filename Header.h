#include <cstdio>
#include <fstream>	//pliki
#include <iostream>	//strumienie
#include <ctime>  //czas
using namespace std;

#ifndef wyklad13b_h
#define wyklad13b_h


const int a = 4;
template <typename T, int rozmiar>
class Tablica {
	T A[rozmiar];
public:
	T& operator[](int index);
};

template <typename T, int rozmiar>
T& Tablica<T, rozmiar>::operator[](int index)
{
	if (index >= rozmiar || index<0)
		return A[0];
	else
		return A[index];
}


struct Dane {
public:

	int ID;
	char nick[10];
	unsigned level;
	double pkt;


	Dane *next;

	Dane(); // konstruktor pusty

	Dane(int _ID, char nick[10], unsigned level, double pkt); //konstruktor

	friend ostream & operator<<(ostream &o,Dane &d); //operator wyjscia do pliku


	Dane operator>(Dane &d); //operator porownania, decyduje o najwiekszej wartosci z
							 //danych, oraz umieszcza najwieksza w operatorze wywolujacym
							 //najwieksza wartosc

};

void fun(Tablica<Dane, a> &t, string nazwa, int tryb);	//funkcja 






//class queue{
//	Dane *glowa;
//	Dane *ogon;
//
//
//	queue();
//	~queue();
//	void pop();
//	bool isempty();
//	Dane* front();
//	void put(Dane *d);
//	Dane get();
//
//	
//};


#endif
