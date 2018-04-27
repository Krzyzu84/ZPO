#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES



class Kolo
{
private:
	friend class Trapez;
	float r;
	float x, y;
public:
	friend class Trapez;
	void opisz_kolo(float r, float x, float y);
	void wypisz();
	void symetria(float n);
	void skaluj(float n);
};

class Trapez
{
	friend class Kolo;
	float a;	//dolna podstawa
	float b;	//gorna podstawa
	float h;	//wysokosc
	float x, y;	//wspolrzedne srodka

public:
	friend class Kolo;
	void opisz_trap(float a, float b, float h, float x, float y);
	void wypisz();
	void symetria(float n);
	//Trapez(const Kolo &k){
	//	a = 999;
	//	b = 999;
	//	h = 999;
	//	x = k.x;
	//	y = k.y;
	//}

	

	Trapez() {

	}

};





void Kolo::opisz_kolo(float ar, float ax, float ay)
{
	if (ar > 0)
		r = ar;
	else
		r = 2;
	x = ax;
	y = ay;
}

void Kolo::wypisz() {
	printf("Pola figury: \nPromien= %f \nx= %f \ny= %f\n", r, x, y);
	float pole = (3.14)*(r*r);
	printf("Pole kola wynosi: %f\n", pole);
}

void Kolo::symetria(float n)
{
	if (n < x)
		x -= 2 * (x - n);
	else if (n > x)
		x += 2 * (n - x);
}
void Kolo::skaluj(float n)
{
	if (n > 0)
		r = r*n;
	else
		printf("Wspolczynnik ma byc dodatki!\n");
}


class Prostokat {
	float a;
	float b;
	float x;
	float y;

public:
	void opisz_prostokat(float a, float b, float x,float y);
	void wypisz();
	void symetria(float n);
	void skaluj(float n);


};

void Prostokat::opisz_prostokat(float aa, float bb, float xx, float yy)
{
	if (aa > 0)
		a = aa;
	else
		a = 2;
	if (bb > 0)
		b = bb;
	x = xx;
	y = yy;
}

void Prostokat::wypisz()
{
	printf("A: %f\nB:%f\nX:%f\nY:%f\n", a, b, x, y);
	printf("Pole: %f\n", a*b);
}

void Prostokat::symetria(float n)
{
	if (n < x)
		x -= 2 * (x - n);
	else if (n > x)
		x += 2 * (n - x);
}

void Prostokat::skaluj(float n)
{
	if (n > 0) {
		a = a*n;
		b = b*n;
	}
	else
		printf("Liczba musi byc wieksza od zera\n");
}



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

}


int main()
{
	Trapez figura;

	float a;	
	float b;	
	float h;	
	float x, y;
	float r;


	Trapez t[3];
	Kolo k[3];
	Prostokat p[3];





	for (int i = 0; i < 3; i++)
	{
		a = i + 1;
		b = i + 2;
		h = i + 3;
		x = i + 4;
		y = i + 5;
		r = i + 6;

		t[i].opisz_trap(a, b, h, x, y);
		k[i].opisz_kolo(r, x, y);
		p[i].opisz_prostokat(a, b, x, y);
	}

	




	//for (int i = 0; i < 3; i++)
	//{

	//	printf("\nFigura nr %d\n", i + 1);
	//	t[i].wypisz();
	//	k[i].wypisz();
	//	p[i].wypisz();
	//}






	//int wybor;
	//int index;

	//printf("Wybierz opcje:\n1)Kolo\n2)Trapez\n3)Prostokat\n4)Wyjdz\n");
	//scanf("%d", &wybor);

	//while (wybor != 4)
	//{
	//	if (wybor == 1) //////KOLO////////
	//	{
	//		printf("Wybierz nr kola: \n");
	//		scanf("%d", &index);
	//		int wybor2;
	//		printf("Co chcesz zrobic? \n1)opisz,\n2)symertria,\n3)skaluj: ");
	//		scanf("%d", &wybor2);
	//		if (wybor2 == 1)
	//		{
	//			k[index].wypisz();
	//			printf("Jak chcesz opisac kolo? (r,x,y)\n");
	//			scanf("%f %f %f", &r, &x, &y);
	//			k[index].opisz_kolo(r, x, y);
	//			k[index].wypisz();
	//		}
	//		else if (wybor2 ==2)
	//		{
	//			k[index].wypisz();
	//			printf("Podaj pkt symetrii\n");
	//			scanf("%f", &x);
	//			k[index].symetria(x);
	//			k[index].wypisz();
	//		}
	//		if (wybor2 == 3)
	//		{
	//			k[index].wypisz();
	//			printf("O ile chcesz zeskalowac?\n");
	//			scanf("%f", &x);
	//			k[index].skaluj(x);
	//			k[index].wypisz();
	//		}

	//	}
	//	if (wybor == 2) //////Trapez////////
	//	{
	//		printf("Wybierz nr Trapezu: \n");
	//		scanf("%d", &index);
	//		int wybor2;
	//		printf("Co chcesz zrobic? \n1)opisz,\n2)symertria\n: ");
	//		scanf("%d", &wybor2);
	//		if (wybor2 == 1)
	//		{
	//			t[index].wypisz();
	//			printf("Jak chcesz opisac trapez? (a,b,h,x,y)\n");
	//			scanf("%f %f %f %f %F", &a, &b, &h,&x,&y);
	//			t[index].opisz_trap(a,b,h,x,y);
	//			t[index].wypisz();
	//		}
	//		else if (wybor2 == 2)
	//		{
	//			t[index].wypisz();
	//			printf("Podaj pkt symetrii\n");
	//			scanf("%f", &x);
	//			t[index].symetria(x);
	//			t[index].wypisz();
	//		}


	//	}

	//	if (wybor == 3) //////Prostokat////////
	//	{
	//		printf("Wybierz nr Prostokata: \n");
	//		scanf("%d", &index);
	//		int wybor2;
	//		printf("Co chcesz zrobic? \n1)opisz,\n2)symertria,\n3)skaluj: ");
	//		scanf("%d", &wybor2);
	//		if (wybor2 == 1)
	//		{
	//			p[index].wypisz();
	//			printf("Jak chcesz opisac Prostokat? (a,b,x,y)\n");
	//			scanf("%f %f %f %f", &a, &b, &x,&y);
	//			p[index].opisz_prostokat(a,b,x,y);
	//			p[index].wypisz();
	//		}
	//		else if (wybor2 == 2)
	//		{
	//			p[index].wypisz();
	//			printf("Podaj pkt symetrii\n");
	//			scanf("%f", &x);
	//			p[index].symetria(x);
	//			p[index].wypisz();
	//		}
	//		if (wybor2 == 3)
	//		{
	//			p[index].wypisz();
	//			printf("O ile chcesz zeskalowac?\n");
	//			scanf("%f", &x);
	//			p[index].skaluj(x);
	//			p[index].wypisz();
	//		}

	//	}

	//	printf("Wybierz opcje: \n1)Kolo\n2)Trapez \n3)Prostokat\n4)Wyjdz\n");
	//	scanf("%d", &wybor);
	//}




	printf("Koniec Programu!\n");





















	/*printf("Podaj dane trapezu: (a,b,h,x,y):\n");
	scanf("%f %f %f %f %f", &a, &b, &h, &x, &y);

	figura.opisz_trap(a, b, h, x, y);


	figura.wypisz();


	float n;
	printf("Podaj argument dla metody symetrii osiowej\n");
	scanf("%f", &n);
	figura.symetria(n);

	figura.wypisz();
	figura.symetria(n);
	figura.wypisz();*/

	return 0;
}