#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


class FiGeo {
public:
	float x, y;

	FiGeo(): x(0), y(0) {

	}
	FiGeo(FiGeo &o) {
		this->x = o.x;
		this->y = o.y;
	}

	FiGeo(float x,float y) {
		this->x = x;
		this->y = y;
	}
	
};


class Trapez: public FiGeo
{
	float a;	//dolna podstawa
	float b;	//gorna podstawa
	float h;	//wysokosc
	Trapez *nast;
	friend class blejtram;
	friend class Kolo;
public:
	double static pole;

	Trapez():FiGeo(),a(1),b(1),h(1),nast(NULL) {
		
		pole = pole + (((a + b)*h) / 2.0);
		printf("Pole T %f \n", pole);
	}
	Trapez(float, float, float, float, float);
	Trapez(Trapez &trapez);
	Trapez(Kolo &Kolo);
	~Trapez() {
		printf("Destruktor klasy Trapez obiektu A:%f B:%f H:%f  \n", a, b, h);
		pole = pole - ((a + b)*h) / 2.0;
		printf("Pomniejszone Pole T %f\n", pole);
		delete nast;
	}
	void opisz_trap(float a, float b, float h, float x, float y);
	void wypisz();
	void symetria(float n);

};



class Kolo: public FiGeo
{
	float r;//promien
	Kolo *nast;
	friend class blejtram;
	friend class Trapez;
public:
	double static pole;

	Kolo():FiGeo(0,0),r(1),nast(NULL) {
		pole = pole + (3.14*(r*r));
		printf("Pole K %f\n", pole);
	}
	Kolo(float, float, float);
	Kolo(Kolo &kolo);
	Kolo(Trapez &trapez);
	~Kolo() {
		pole = pole - (3.14*(r*r));
		printf("Destruktor klasy Kolo obiektu R:%f  \n", r);
		printf("Pomniejszone Pole K %f\n", pole);
		
		delete nast;
	}
	void opisz_kolo(float r, float x, float y);
	void wypisz();
	void symetria(float n);
	void skalowanie(float x);
};

class blejtram
{
	Trapez* htrap;
	Kolo* hkolo;
public:
	~blejtram() {
		delete htrap;
		delete hkolo;
		printf("USUNIETO LISTY!\n");
	}
	blejtram();
	Trapez* Dodaj_trapez(Trapez* t);
	Kolo* Dodaj_kolo(Kolo* t);
	void symetria_osiowa(double n);
	void wypisz();

};
//----------------------------------------------------------------
blejtram::blejtram() {
	htrap = NULL;
	hkolo = NULL;
}
Kolo* blejtram::Dodaj_kolo(Kolo*nowy) {
	Kolo* glowa = hkolo;
	if (hkolo == NULL) {
		hkolo = nowy;
	}
	else {
		while (hkolo->nast != NULL) {
			hkolo = hkolo->nast;
		}
		hkolo->nast = nowy;
		hkolo = glowa;
	}
	return hkolo;
}
Trapez* blejtram::Dodaj_trapez(Trapez*nowy) {
	Trapez* glowa = htrap;
	if (htrap == NULL) {
		htrap = nowy;
	}
	else {
		while (htrap->nast != NULL) {
			htrap = htrap->nast;
		}
		htrap->nast = nowy;
		htrap = glowa;
	}
	return htrap;
}

void blejtram::wypisz() {
	Kolo*head3 = hkolo;
	if (hkolo == NULL) {
		printf("lista kol pusta!\n");
	}
	while (hkolo != NULL) {
		hkolo->wypisz();
		hkolo = hkolo->nast;
	}
	hkolo = head3;
	Trapez*head2 = htrap;
	if (htrap == NULL) {
		printf("lista trapezow pusta!\n");
	}
	while (htrap != NULL) {
		htrap->wypisz();
		htrap = htrap->nast;
	}
	htrap = head2;
}
void blejtram::symetria_osiowa(double n) {
	Kolo*head3 = hkolo;
	if (hkolo == NULL) {
		printf("lista kol pusta!\n");
	}
	while (hkolo != NULL) {
		hkolo->symetria(n);
		hkolo = hkolo->nast;
	}
	hkolo = head3;
	Trapez*head2 = htrap;
	if (htrap == NULL) {
		printf("lista trapezow pusta!\n");
	}
	while (htrap != NULL) {
		htrap->symetria(n);
		htrap = htrap->nast;
	}
	htrap = head2;


}
//--------------------------------------------------------------------
Trapez::Trapez(float ta, float tb, float th, float tx, float ty):FiGeo(tx,ty),nast(NULL) {

	


	if (ta > 0) {
		a = ta;
	}
	else {
		printf("dlugosc mniejsza od 0!(ustawiam wartosc domyslna)\n");
		a = 1;
	}
	if (tb > 0) {
		b = tb;
	}
	else {
		printf("dlugosc mniejsza od 0!(ustawiam wartosc domyslna)\n");
		b = 1;
	}
	if (th > 0) {
		h = th;
	}
	else {
		printf("dlugosc mniejsza od 0!(ustawiam wartosc domyslna)\n");
		h = 1;
	}

	pole = pole + ((a + b)*h) / 2.0;
}

Trapez::Trapez(Trapez &trapez):FiGeo(trapez.x,trapez.y),a(trapez.a),b(trapez.b),h(trapez.h),nast(NULL) {
	pole = pole + ((a + b)*h) / 2.0;

}
Trapez::Trapez(Kolo &kolo):FiGeo(kolo.x,kolo.y),a(1),b(1),h(1){
	pole = pole + ((a + b)*h) / 2.0;

}
//------------------------------------------------------------
Kolo::Kolo(float kx, float ky, float kr):FiGeo(kx,ky),nast(NULL) {
	
	if (kr > 0) {
		r = kr;
	}
	else {
		printf("dlugosc mniejsza od 0!(ustawiam wartosc domyslna)\n");
		r = 1;
	}
	pole = pole + (3.14*(r*r));
}
Kolo::Kolo(Kolo &kolo): FiGeo(kolo.x,kolo.y),nast(NULL),r(kolo.r) {
	pole = pole + (3.14*(r*r));
}
Kolo::Kolo(Trapez &trapez):FiGeo(trapez.x,trapez.y),r(1) {
	pole = pole + (3.14*(r*r));
}
void Kolo::opisz_kolo(float rx, float nx, float ny) {
	if (rx > 0)
		r = rx;
	else
		r = 2;
	x = nx;
	y = ny;
}

void Kolo::wypisz()
{
	printf("pola figury(kolo): R:%f X:%f Y:%f", r, x, y);
	float er = pow(r, 2);
	float pi = 3.14;
	float pole = er*pi;
	printf("Pole kola wynosi:%f\n", pole);

}

void Kolo::symetria(float n)
{
	if (n < x)
		x -= 2 * (x - n);
	else if (n > x)
		x += 2 * (n - x);
	else
		;
}

void Kolo::skalowanie(float x)
{
	if (x > 0) {
		r = r*x;
	}
	else {
		printf("wspolczynnik ma byc dodatni!\n");
	}
}
//-----------------------------------------------------------------------------
void Trapez::opisz_trap(float na, float nb, float nh, float nx, float ny)
{
	if (na > 0)
		a = na;
	else
		a = 2;
	if (nb > 0)
		b = nb;
	else
		b = 1;
	if (nh > 0)
		h = nh;
	else
		h = 1;
	x = nx;
	y = ny;
}

void Trapez::wypisz()
{
	printf("pola figury(klasy):\na: %f\nb: %f\nh: %f\nx: %f  y: %f\n", a, b, h, x, y);

	printf("Lewy dolny rog: x: %f y:%f\n", (x - (a / 2)), (y - (h / 2)));
	printf("Prawy dolny rog: x: %f y:%f\n", (x + (a / 2)), (y - (h / 2)));
	printf("Prawy gorny rog: x: %f y:%f\n", (x + (b / 2)), (y + (h / 2)));
	printf("Lewy gorny rog: x: %f y:%f\n", (x - (b / 2)), (y + (h / 2)));
}

void Trapez::symetria(float n)
{
	if (n < x)
		x -= 2 * (x - n);
	else if (n > x)
		x += 2 * (n - x);
	else
		;
}

double Kolo::pole = 0;
double Trapez::pole = 0;

int main()
{

	blejtram *lista = new blejtram();

	Trapez *t1 = new Trapez(4, 2, 2, 1, 1);
	Trapez *t2 = new Trapez;
	Trapez *t3 = new Trapez(*t1);

	Kolo *k1 = new Kolo(2, 2, 2);
	Kolo *k2 = new Kolo;
	Kolo *k3 = new Kolo(*k1);

	lista->Dodaj_trapez(t1);
	lista->Dodaj_trapez(t2);
	lista->Dodaj_trapez(t3);

	lista->Dodaj_kolo(k1);
	lista->Dodaj_kolo(k2);
	lista->Dodaj_kolo(k3);

	lista->wypisz();

	putchar('\n');

	delete lista;

	/*
	for (int i = 0; i < 3; i++){
	float a=2+i;	//dolna podstawa
	float b=1+i;	//gorna podstawa
	float h=1+i;	//wysokosc
	float x=2+i;
	float y=1+i;
	float r=2+i;
	figura[i].opisz_trap(a, b, h, x, y);
	figura2[i].opisz_kolo(r, x, y);
	}

	do{
	int wyb;
	printf("Chcesz modyfikowac trapez czy kolo?\n Kolo, wcisnij 1\n Trapez wcisnij 2\n Wyjscie wcisnij 0\n");
	scanf("%d", &wyb);
	if (wyb != 1 && wyb != 2){
	printf("Wybrales wyjscie z programu\n");
	break;
	}
	switch (wyb){

	case 1:
	int a;
	int b;
	int c;
	printf("Wybrales modyfikacje Kola, sa 3 kola wbierz kola 0,1,2  \n");
	scanf("%d", &a);
	printf("Wybrales modyfikacje Kola %d co chcesz z nim zrobic?\n 1 Zmodyfikowac\n 2 odbic symetrycznie\n 3 zeskalowac \n",a);
	scanf("%d", &b);
	if (b == 1){
	float x1;
	float y1;
	float r1;
	figura2[a].wypisz();
	printf("jak chcesz zmienic Kolo?(r,x,y):");
	scanf("%f %f %f",&r1,&x1,&y1);
	figura2[a].opisz_kolo(r1, x1, y1);
	figura2[a].wypisz();
	}
	else if (b == 2){
	figura2[a].wypisz();
	printf("wzgledem czego odbic?:");
	scanf("%d", &c);
	figura2[a].symetria(c);
	figura2[a].wypisz();
	}
	else if (b == 3){
	float d;
	figura2[a].wypisz();
	printf("jak zeskalowac?:");
	scanf("%f", &d);
	figura2[a].skalowanie(d);
	figura2[a].wypisz();
	}
	break;
	case 2:
	int a2;
	int b1;
	int c1;
	printf("wybrales modyfikacje Trapezu,sa 3 trapezy wubierz trapez 0,1,2  \n");
	scanf("%d", &a2);
	printf("Wybrales modyfikacje Kola %d co chcesz z nim zrobic?\n 1 Zmodyfikowac\n 2 odbic symetrycznie \n", a2);
	scanf("%d", &b1);
	if (b1 == 1){
	float a1;
	float b2;
	float h1;
	float x2;
	float y2;
	figura[a2].wypisz();
	printf("jak chcesz zmienic Trapez?(a,b,h,x,y):");
	scanf("%f %f %f %f %f", &a1, &b2, &h1,&x2,&y2);
	figura[a2].opisz_trap(a1, b2, h1, x2, y2);
	figura[a2].wypisz();
	}
	else if (b1 == 2){
	figura[a2].wypisz();
	printf("wzgledem czego odbic?:");
	scanf("%d", &c1);
	figura[a2].symetria(c1);
	figura[a2].wypisz();
	}
	break;
	}






	} while (1);
	*/
	return 0;
}