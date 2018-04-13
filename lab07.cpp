#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define ILE 20
#define ILE_CZUJNIKOW 4


struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[ILE];
	double temp;
	struct pomiar *next;
	struct pomiar *prev;
};




void usun(pomiar *head) {
	pomiar *p;
	while (head) {
		p = head;
		head = head->next;
		free(p);
	}
}


struct pomiar *stworz(int a, int b, char  *c, double d)
{
	struct pomiar *wsk = (pomiar*)malloc(sizeof(struct pomiar));

	wsk->nr_pomiaru = a;
	wsk->nr_czujnika = b;
	strcpy(wsk->data_i_czas, c);
	wsk->temp = d;
	wsk->next = NULL;
	wsk->prev = NULL;

	return wsk;
}


void minMax(struct pomiar * glowa) {
	struct pomiar * min = (pomiar*)malloc(sizeof(struct pomiar));
	struct pomiar * max = (pomiar*)malloc(sizeof(struct pomiar));
	struct pomiar * wsk = glowa;
	if (wsk == NULL) {
		printf("Lista jest pusta!\n");
		exit(0);
	}
	min->temp = INT_MAX;
	max->temp = INT_MIN;

	while (wsk->next != NULL) {
		if (wsk->temp > max->temp) {
			max = wsk;
		}
		if (wsk->temp < min->temp) {
			min = wsk;

		}
		wsk = wsk->next;
	}
	printf("Minimalna temp: %d %d %s %.2lf\n", min->nr_pomiaru, min->nr_czujnika, min->data_i_czas, min->temp);
	printf("Maksymalna temp: %d %d %s %.2lf\n", max->nr_pomiaru, max->nr_czujnika, max->data_i_czas, max->temp);
	printf("odleglosc miedzy wartoscia min a wartoscia max wynosi:%d\n", min->nr_pomiaru - max->nr_pomiaru);

	printf("\n");
}


void pokaz(struct pomiar* head) {
	pomiar *p;
	p = head;
	while (p) {
		printf("%d\n", p->nr_pomiaru);
		p = p->next;
	}
}

struct pomiar * fun1(char *wejscie) {

	struct pomiar *head = NULL;
	struct pomiar *poprz = NULL;
	FILE *input;

	if ((input = fopen(wejscie, "r")) == NULL)
	{
		printf("Plik wejsciowy nie zostal otwarty\n");
		exit(0);
	}


	fgetc(input);

	if (feof(input)) {
		printf("Otwarto pusty plik\nKoniec programu.\n");
		return NULL;
	}
	else {
		rewind(input);
	}


	while (!feof(input)) {
		int pomiar = 0;
		int czujnik = 0;
		char data[ILE];
		double temp = 0;

		fscanf(input, "%d %d %s %lf", &pomiar, &czujnik, data, &temp);
		if (feof(input)) break;
		printf("Wczytuje: %d %d %s %.2f\n", pomiar, czujnik, data, temp);

		struct pomiar * nowy = stworz(pomiar, czujnik, data, temp);


		if (head == NULL) {
			head = nowy;
			head->prev = NULL;
			head->next = poprz;
			poprz = head;
		}
		else {
			poprz->next = nowy;
			nowy->prev = poprz;
			poprz = nowy;

		}
	}

	fclose(input);

	return head;
}

void fun2(struct pomiar *head) {
	struct pomiar * p = head;
	int i = 1;
	printf("Pierwszy element: %d %d %s %.2f\n", p->nr_pomiaru,p->nr_czujnika, p->data_i_czas, p->temp);
	while (p->next != NULL) {
		p = p->next;
		i++;
	}
	printf("Ostatni element: %d %d %s %.2f\n", p->nr_pomiaru, p->nr_czujnika, p->data_i_czas, p->temp);
	printf("Lista posiada %d elementow\n", i);
	
}

struct glowy {
	struct pomiar *h1;
	struct pomiar *h2;
	struct pomiar *h3;
	struct pomiar *h4;
};

struct glowy *fun33(struct pomiar *&glowa) {
	//Tworze 4 listy
	struct pomiar * glowaListyPomiarow = glowa;
	struct pomiar * czujnik1 = NULL, *czujnik1temp = NULL;
	struct pomiar * czujnik2 = NULL, *czujnik2temp = NULL;
	struct pomiar * czujnik3 = NULL, *czujnik3temp = NULL;
	struct pomiar * czujnik4 = NULL, *czujnik4temp = NULL;
	struct pomiar * tempPoprz1 = NULL;
	struct pomiar * tempPoprz2 = NULL;
	struct pomiar * tempPoprz3 = NULL;
	struct pomiar * tempPoprz4 = NULL;
	int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
	//Rodzielam je na 4 inne listy
	while (glowaListyPomiarow != NULL) {
		//czujnik1temp obecna glowa listy
		//Sprawdzam numer czujnika
		int nr_czujnika = glowaListyPomiarow->nr_czujnika;
		//Odlaczam pierwszy element z listy od gory
		struct pomiar * elementOderwany = glowaListyPomiarow;
		glowaListyPomiarow = glowaListyPomiarow->next;
		//Przyklejam wezel do odpowiedniej listy
		switch (nr_czujnika) {
		case 1:
			if (czujnik1 == NULL) {
				czujnik1temp = elementOderwany;
				czujnik1temp->next = NULL;
				czujnik1temp->prev = NULL;
				czujnik1 = czujnik1temp;
				i1++;
			}
			else {
				tempPoprz1 = czujnik1temp;
				czujnik1temp->next = elementOderwany;
				czujnik1temp = czujnik1temp->next;
				czujnik1temp->next = NULL;
				czujnik1temp->prev = tempPoprz1;
				i1++;
			}
			break;
		case 2:
			if (czujnik2 == NULL) {
				czujnik2temp = elementOderwany;
				czujnik2temp->next = NULL;
				czujnik2temp->prev = NULL;
				czujnik2 = czujnik2temp;
				i2++;
			}
			else {
				tempPoprz2 = czujnik2temp;
				czujnik2temp->next = elementOderwany;
				czujnik2temp = czujnik2temp->next;
				czujnik2temp->next = NULL;
				czujnik2temp->prev = tempPoprz2;
				i2++;
			}
			break;
		case 3:
			if (czujnik3 == NULL) {
				czujnik3temp = elementOderwany;
				czujnik3temp->next = NULL;
				czujnik3temp->prev = NULL;
				czujnik3 = czujnik3temp;
				i3++;
			}
			else {
				tempPoprz3 = czujnik3temp;
				czujnik3temp->next = elementOderwany;
				czujnik3temp = czujnik3temp->next;
				czujnik3temp->next = NULL;
				czujnik3temp->prev = tempPoprz3;
				i3++;
			}
			break;
		case 4:
			if (czujnik4 == NULL) {
				czujnik4temp = elementOderwany;
				czujnik4temp->next = NULL;
				czujnik4temp->prev = NULL;
				czujnik4 = czujnik4temp;
				i4++;
			}
			else {
				tempPoprz4 = czujnik4temp;
				czujnik4temp->next = elementOderwany;
				czujnik4temp = czujnik4temp->next;
				czujnik4temp->next = NULL;
				czujnik4temp->prev = tempPoprz4;
				i4++;
			}
			break;
		}
	}
	glowa = NULL;
	printf("pomiarow czujnikow jest 1:%d 2:%d 3:%d 4:%d\n", i1, i2, i3, i4);
	struct glowy * wynik = (glowy*)malloc(sizeof(struct glowy));
	wynik->h1 = czujnik1;
	wynik->h2= czujnik2;
	wynik->h3 = czujnik3;
	wynik->h4 = czujnik4;
	return wynik;
}


int main()
{
	char wejscie[ILE], bufor[ILE], wyjscie[ILE_CZUJNIKOW][ILE];
	strcpy(wejscie, "temp.txt");

	struct pomiar *head = fun1(wejscie);
	printf("Glowa\n");
	minMax(head);
	printf("\n");
	printf("\n");
	fun2(head);
	struct glowy *czteryGlowy = fun33(head);


	usun(head);

	printf("GLOWA!\n");
	pokaz(head);
	printf("GLOWA!\n");

	fun2(czteryGlowy->h1); minMax(czteryGlowy->h1);
	fun2(czteryGlowy->h2); minMax(czteryGlowy->h2);
	fun2(czteryGlowy->h3); minMax(czteryGlowy->h3);
	fun2(czteryGlowy->h4); minMax(czteryGlowy->h4);

	///////////////////////////////////////////////////////////////////////////////////

	//struct pomiar *head = NULL;
	//struct pomiar *poprz = NULL;


	//FILE *input;


	///////////////////// OTWARCIE WEJSCIA ///////////////////





	//if ((input = fopen(wejscie, "r")) == NULL)
	//{
	//	printf("Plik wejsciowy nie zostal otwarty\n");
	//	exit(0);
	//}


	//fgetc(input);

	//if (feof(input)) {
	//	printf("Otwarto pusty plik\nKoniec programu.\n");
	//	return NULL;
	//}
	//else {
	//	rewind(input);
	//}
	//

	//while (!feof(input)) {
	//	int pomiar = 0;
	//	int czujnik = 0;
	//	char data[ILE];
	//	double temp = 0;

	//	fscanf(input, "%d %d %s %lf", &pomiar, &czujnik, data, &temp);
	//	if (feof(input)) break;
	//	printf("Wczytuje: %d %d %s %.2f\n", pomiar, czujnik, data, temp);

	//	struct pomiar * nowy = stworz(pomiar, czujnik, data, temp);


	//	if (head == NULL) {
	//		head = nowy;
	//		head->prev = NULL;
	//		head->next = poprz;
	//		poprz = head;
	//	}
	//	else {
	//		poprz->next = nowy;
	//		nowy->prev = poprz;
	//		poprz = nowy;

	//	}
	//}

	//fclose(input);



	///////////// ROZDZIELENIE NA 4 LISTY /////////////////


	//struct pomiar * glowaListyPomiarow = head;
	//struct pomiar * czujnik1 = NULL, *czujnik1temp = NULL;
	//struct pomiar * czujnik2 = NULL, *czujnik2temp = NULL;
	//struct pomiar * czujnik3 = NULL, *czujnik3temp = NULL;
	//struct pomiar * czujnik4 = NULL, *czujnik4temp = NULL;
	//struct pomiar * tempPoprz1 = NULL;
	//struct pomiar * tempPoprz2 = NULL;
	//struct pomiar * tempPoprz3 = NULL;
	//struct pomiar * tempPoprz4 = NULL;
	//int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
	////Rodzielam je na 4 inne listy
	//while (glowaListyPomiarow != NULL) {
	//	//czujnik1temp obecna glowa listy
	//	//Sprawdzam numer czujnika
	//	int nr_czujnika = glowaListyPomiarow->nr_czujnika;
	//	//Odlaczam pierwszy element z listy od gory
	//	struct pomiar * elementOderwany = glowaListyPomiarow;
	//	glowaListyPomiarow = glowaListyPomiarow->next;
	//	//Przyklejam wezel do odpowiedniej listy
	//	switch (nr_czujnika) {
	//	case 1:
	//		if (czujnik1 == NULL) {
	//			czujnik1temp = elementOderwany;
	//			czujnik1temp->next = NULL;
	//			czujnik1temp->prev = NULL;
	//			czujnik1 = czujnik1temp;
	//			i1++;
	//		}
	//		else {
	//			tempPoprz1 = czujnik1temp;
	//			czujnik1temp->next = elementOderwany;
	//			czujnik1temp = czujnik1temp->next;
	//			czujnik1temp->next = NULL;
	//			czujnik1temp->prev = tempPoprz1;
	//			i1++;
	//		}
	//		break;
	//	case 2:
	//		if (czujnik2 == NULL) {
	//			czujnik2temp = elementOderwany;
	//			czujnik2temp->next = NULL;
	//			czujnik2temp->prev = NULL;
	//			czujnik2 = czujnik2temp;
	//			i2++;
	//		}
	//		else {
	//			tempPoprz2 = czujnik2temp;
	//			czujnik2temp->next = elementOderwany;
	//			czujnik2temp = czujnik2temp->next;
	//			czujnik2temp->next = NULL;
	//			czujnik2temp->prev = tempPoprz2;
	//			i2++;
	//		}
	//		break;
	//	case 3:
	//		if (czujnik3 == NULL) {
	//			czujnik3temp = elementOderwany;
	//			czujnik3temp->next = NULL;
	//			czujnik3temp->prev = NULL;
	//			czujnik3 = czujnik3temp;
	//			i3++;
	//		}
	//		else {
	//			tempPoprz3 = czujnik3temp;
	//			czujnik3temp->next = elementOderwany;
	//			czujnik3temp = czujnik3temp->next;
	//			czujnik3temp->next = NULL;
	//			czujnik3temp->prev = tempPoprz3;
	//			i3++;
	//		}
	//		break;
	//	case 4:
	//		if (czujnik4 == NULL) {
	//			czujnik4temp = elementOderwany;
	//			czujnik4temp->next = NULL;
	//			czujnik4temp->prev = NULL;
	//			czujnik4 = czujnik4temp;
	//			i4++;
	//		}
	//		else {
	//			tempPoprz4 = czujnik4temp;
	//			czujnik4temp->next = elementOderwany;
	//			czujnik4temp = czujnik4temp->next;
	//			czujnik4temp->next = NULL;
	//			czujnik4temp->prev = tempPoprz4;
	//			i4++;
	//		}
	//		break;
	//	}
	//}

	//head = NULL;
	//printf("pomiarow czujnikow jest 1:%d 2:%d 3:%d 4:%d\n", i1, i2, i3, i4);


	//usun(head);

	//minMax(czujnik1); printf("\n");
	//minMax(czujnik2); printf("\n");
	//minMax(czujnik3); printf("\n");
	//minMax(czujnik4); printf("\n");






	////printf("\nPodaj nazwe pliku: ");
	////scanf("%s", &bufor);

	//strcpy(bufor, "NR");
	//printf("Bufor: %s\n", bufor);

	//strcpy(wyjscie[0], bufor);
	//strcpy(wyjscie[1], bufor);
	//strcpy(wyjscie[2], bufor);
	//strcpy(wyjscie[3], bufor);

	//char jeden[ILE] = "1.txt";
	//char dwa[ILE] = "2.txt";
	//char trzy[ILE] = "3.txt";
	//char cztery[ILE] = "4.txt";

	//strcat(wyjscie[0], jeden);
	//strcat(wyjscie[1], dwa);
	//strcat(wyjscie[2], trzy);
	//strcat(wyjscie[3], cztery);


	//FILE *output;

	///////////////////// WYJSCIE NR 1 ///////////////////
	//if ((output = fopen(wyjscie[0], "w")) == NULL)
	//{
	//	printf("Plik wyjsciowy nie zostal otwarty\n");
	//	exit(0);
	//}

	//while (czujnik1 != NULL)
	//{
	//	fprintf(output, "%d %d %s %.2f\n", czujnik1->nr_pomiaru, czujnik1->nr_czujnika, czujnik1->data_i_czas, czujnik1->temp);
	//	czujnik1 = czujnik1->next;
	//}
	//fclose(output);




	///////////////////// WYJSCIE NR 2 ///////////////////
	//if ((output = fopen(wyjscie[1], "w")) == NULL)
	//{
	//	printf("Plik wyjsciowy nie zostal otwarty\n");
	//	exit(0);
	//}

	//while (czujnik2 != NULL)
	//{
	//	fprintf(output, "%d %d %s %.2f\n", czujnik2->nr_pomiaru, czujnik2->nr_czujnika, czujnik2->data_i_czas, czujnik2->temp);
	//	czujnik2 = czujnik2->next;
	//}
	//fclose(output);



	///////////////////// WYJSCIE NR 3 ///////////////////
	//if ((output = fopen(wyjscie[2], "w")) == NULL)
	//{
	//	printf("Plik wyjsciowy nie zostal otwarty\n");
	//	exit(0);
	//}

	//while (czujnik3 != NULL)
	//{
	//	fprintf(output, "%d %d %s %.2f\n", czujnik3->nr_pomiaru, czujnik3->nr_czujnika, czujnik3->data_i_czas, czujnik3->temp);
	//	czujnik3 = czujnik3->next;
	//}
	//fclose(output);



	///////////////////// WYJSCIE NR 4 ///////////////////
	//if ((output = fopen(wyjscie[3], "w")) == NULL)
	//{
	//	printf("Plik wyjsciowy nie zostal otwarty\n");
	//	exit(0);
	//}
	//while (czujnik4 != NULL)
	//{
	//	fprintf(output, "%d %d %s %.2f\n", czujnik4->nr_pomiaru, czujnik4->nr_czujnika, czujnik4->data_i_czas, czujnik4->temp);
	//	czujnik4 = czujnik4->next;
	//}
	//fclose(output);


	//usun(head);
	//usun(czujnik1);
	//usun(czujnik2);
	//usun(czujnik3);
	//usun(czujnik4);

}