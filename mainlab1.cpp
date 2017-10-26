#include "Header.h"
using namespace std;


ostream & operator<<(ostream &o, Dane &d)
{
	//ID
	o << "|";
	o.width(6);
	o.fill('0');
	o << d.ID;
	o << "|";
	o.fill(' ');

	//nick

	o.setf(ios::left);
	o.width(10);
	o << d.nick;
	o << "|";

	//level
	o.width(7);
	o.setf(ios::right, ios::left);
	o << d.level;
	o << "|";

	//pkt
	o.precision(1);
	o.width(7);
	o.setf(ios::fixed);
	o << d.pkt;
	o << "|";
	o << endl;


	return o;


}



Dane::Dane()	//ustawia wszystko na 0
{
	this->ID = 0;
	this->level = 0;
	this->pkt = 0;
	strcpy_s(this->nick, "");
	this->next = NULL;
}

Dane::Dane(int _ID, char _nick[10], unsigned _level, double _pkt)	//przypisuje wart
{
	this->ID = _ID;
	strcpy_s(this->nick, nick);
	this->level = level;
	this->pkt = _pkt;
	this->next = NULL;
}


Dane Dane::operator>(Dane &d)		//porownuje typy i przypisuje te z najwieksza ilosc danych
{
	if (d.level > this->level && d.pkt > this->pkt)
	{
		this->level = d.level;
		this->pkt = d.pkt;
	}
	return *this;
}





void fun(Tablica<Dane, a> &t, string nazwa, int tryb)
{

	if (tryb == ios::in)
	{
		exit(0);
	}


	ofstream plik(nazwa, tryb);

	time_t rawtime;
	time(&rawtime);

	plik.width(35);

	plik << ctime(&rawtime) << endl << endl;

	plik << getenv("COMPUTERNAME") << endl;

	plik << "+------+----------+-------+------+ " << endl;
	plik << "| ID   | nick     | level |  pkt | " << endl;
	plik << "+------+----------+-------+------+ " << endl;


	for (int i = 0; i < a; i++)
	{
		plik << t[i];
	}



	plik << "+------+----------+-------+------+ " << endl;

	Dane najw;		//ELEMENT KTORY BEDZIE PRZECHOWYWAL NAJWIEKSZY ELEMENT

	for (int i = 0; i < a; i++)
	{
		najw > t[i]; // WYKORZYSTUJE PRZECIAZONY OPERATOR < KTORY TEZ PRZEPISUJE DANE
	}

	plik << najw;


	plik << "+------+----------+-------+------+ " << endl;

	
}



//queue::queue()
//{
//	glowa = ogon = NULL;
//}
//
//queue::~queue()
//{
//	while (glowa) pop();
//}
//
//
//Dane* queue::front()
//{
//	if (glowa)
//	{
//		Dane *p = glowa;
//		return p;
//	}
//	else
//		return 0;
//}
//
//void queue::put(Dane *d)
//{
//	Dane * p = new Dane;
//	p->ID = d->ID;
//	p->level = d->level;
//	strcmp(p->nick, d->nick);
//	p->pkt = d->pkt;
//	p->next = NULL;
//
//
//
//
//	if (ogon){
//		ogon = ogon->next;
//	}
//	else
//		glowa = p;
//	ogon = p;
//}
//
//void queue::pop()
//{
//	Dane *p = glowa;
//
//	glowa = glowa->next;
//
//	if (!glowa) ogon = NULL;
//
//	delete p;
//}