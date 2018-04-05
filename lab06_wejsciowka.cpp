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
};

struct pom {
	
	struct pomiar *h1;
	struct pomiar *h2;
	struct pomiar *h3;
	struct pomiar *h4;
};


void printl(struct pomiar* head) {
	pomiar *p;
	p =head;
	while(p){
		printf("%.2f\n", p->temp);
			p = p->next;
		}
}





void dzielenie(pomiar*head, pomiar *head1, pomiar *head2, pomiar *head3, pomiar *head4) {

	pomiar *wsk, *wsk1, *wsk2, *wsk3, *wsk4;
	int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
	wsk = head;
	wsk1 = head1;
	wsk2 = head2;
	wsk3 = head3;
	wsk4 = head4;
	while (wsk != NULL) {
		if (wsk->nr_czujnika == 1) {
			wsk1->next = wsk;
			wsk1 = wsk1->next;
			wsk = wsk->next;
			wsk1->next = NULL;
			i1++;
		}
		else if (wsk->nr_czujnika == 2) {
			wsk2->next = wsk;
			wsk2 = wsk2->next;
			wsk = wsk->next;
			wsk2->next = NULL;
			i2++;
		}
		else if (wsk->nr_czujnika == 3) {
			wsk3->next = wsk;
			wsk3 = wsk3->next;
			wsk = wsk->next;
			wsk3->next = NULL;
			i3++;
		}
		else if (wsk->nr_czujnika == 4) {
			wsk4->next = wsk;
			wsk4 = wsk4->next;
			wsk = wsk->next;
			wsk4->next = NULL;
			i4++;
		}
	}
	head = NULL;
	printf("\nIlosc pomiarow czujnikow 1:%d 2:%d 3:%d 4:%d\n", i1 ,i2,i3,i4);
}
	
	
void usun(pomiar *head) {
	pomiar *p;
	while (head) {
		p = head;
		head = head->next;
		free(p);
	}
}


struct pomiar * fun1(char *nazwa)
{
	FILE*wejscie;
	pomiar *head = NULL;
	pomiar *wsk  = NULL;
	int licznik = 0;
	if ((wejscie = fopen(nazwa, "r")) == NULL)
	{
		printf("Plik wyjsciowy nie zostal otwarty\n");
		exit(0);
	}

	char c = fgetc(wejscie);
	if (c == EOF)
	{
		printf("Plik jest pusty!\n");
		exit(0);
	}
	ungetc(c, wejscie);

	while (!feof(wejscie))
	{
		pomiar *n_wsk = (pomiar*)malloc(sizeof(pomiar));

		fscanf(wejscie,"%d %d %s %lf", &n_wsk->nr_pomiaru, &n_wsk->nr_czujnika, n_wsk->data_i_czas, &n_wsk->temp);
		if (feof(wejscie)) break;
		printf("Wczytuje: %d %d %s %.2f\n", n_wsk->nr_pomiaru, n_wsk->nr_czujnika, n_wsk->data_i_czas, n_wsk->temp);

		if (head == NULL)																	//glowa jest pusta (nie istnieje)
		{
			head = wsk = n_wsk;																//glowa i wsk wskazuja na nowy element
		}
		else
		{
			wsk->next = n_wsk;																//zarezerwuj pamiec dla nastepnego elementu
			wsk = wsk->next;																//przejdz na miejsce tego elementu

			wsk->next = NULL;																//Inicjowanie NULL na ostatni element listy
		}
		licznik++;
	}

	if (licznik < 4) {
		printf("Zbyt malo danych ! \n");
		exit(0);
	}


	fclose(wejscie);

	return head;

}

void fun2(struct pomiar *head)
{
	int ile = 1;
	struct pomiar *wsk = head;
	printf("Pierwszy element %d %d %s %.2f\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);
	while (wsk)
	{
		ile++;
		wsk = wsk->next;
		if (wsk->next == NULL)
		{
			printf("Ostatni element %d %d %s %.2f\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);
			break;
		}
	}

	printf("Lista posiada %d elementow \n", ile);
}


struct pom fun3(struct pomiar *head)
{
	struct pom glowy;
	glowy.h1 = NULL;
	glowy.h2 = NULL;
	glowy.h3 = NULL;
	glowy.h4 = NULL;

	struct pomiar *wsk = head;

	

	for (int i = 0; i < ILE_CZUJNIKOW; i++) {

		pomiar *n_wsk = (pomiar*)malloc(sizeof(pomiar));

		strcpy(n_wsk->data_i_czas, wsk->data_i_czas);
		n_wsk->nr_czujnika = wsk->nr_czujnika;
		n_wsk->nr_pomiaru = wsk->nr_pomiaru;
		n_wsk->temp = wsk->temp;
		n_wsk->next = NULL;


		if (wsk->nr_czujnika == 1)
			glowy.h1 = n_wsk;
		else if (wsk->nr_czujnika == 2)
			glowy.h2 = n_wsk;
		else if (wsk->nr_czujnika == 3)
			glowy.h3 = n_wsk;
		else if (wsk->nr_czujnika == 4)
			glowy.h4 = n_wsk;

		wsk = wsk->next;
	}


	struct pomiar *wsk1 = glowy.h1;
	struct pomiar *wsk2 = glowy.h2;
	struct pomiar *wsk3 = glowy.h3;
	struct pomiar *wsk4 = glowy.h4;




	while (wsk != NULL) {

		pomiar *n_wsk = (pomiar*)malloc(sizeof(pomiar));

		strcpy(n_wsk->data_i_czas, wsk->data_i_czas);
		n_wsk->nr_czujnika = wsk->nr_czujnika;
		n_wsk->nr_pomiaru = wsk->nr_pomiaru;
		n_wsk->temp = wsk->temp;
		n_wsk->next = NULL;


		if (wsk->nr_czujnika == 1) {
			wsk1->next = n_wsk;
			wsk1 = wsk1->next;
		}
		else if (wsk->nr_czujnika == 2) {
			wsk2 ->next = n_wsk;
			wsk2 = wsk2 -> next;
		}
		else if (wsk->nr_czujnika == 3) {
			wsk3->next = n_wsk;
			wsk3 = wsk3->next;
		}
		else if (wsk->nr_czujnika == 4) {
			wsk4->next = n_wsk;
			wsk4 = wsk4->next;
		}

		wsk = wsk->next;

	}



	return glowy;

}


struct pomiar * fun4(struct pomiar*head)
{
	float max_temp = INT_MIN;
	
	struct pomiar *wsk = head;
	int licznik=0;
	int i = 0;

	printl(wsk);

	while (wsk != NULL)
	{
		if (wsk->temp > max_temp) {
			max_temp = wsk->temp;
			licznik = i;
		}

		i++;
		wsk = wsk->next;
	}
	printf("Najwieksza temperatura %.2f\n", max_temp);
	
	if (licznik == 0)
	{
		printf("Usuwam Najwiekszy element %d %d %s %.2f\n", head->nr_pomiaru, head->nr_czujnika, head->data_i_czas, head->temp);
		head = head->next;
		free(wsk);
	}
	else
	{
		wsk = head;
		i = 0;
		while (i < licznik-1) {
			wsk = wsk->next;
			i++;
		}
		
		struct pomiar *wsk2 = wsk->next;
		wsk->next = wsk->next->next;
		printf("Usuwam Najwiekszy element %d %d %s %.2f\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);

		wsk2->next = NULL;
		free(wsk2);

	}
	wsk = head;
	printl(wsk);
	return wsk;
	
}

struct pomiar* fun44(struct pomiar*head)
{
	struct pomiar * wsk = head;
	struct pomiar * wsk2 = head;
	struct pomiar * wsk3 = head;
	struct pomiar * poprz = head;
	struct pomiar * ogon = head;

	printl(wsk);

	float min = INT_MAX;
	int index = 0;
	int i = 0;
	while (wsk) {

		if (wsk->temp < min) {
			min = wsk->temp;
			wsk2 = wsk;
			index = i;
		}
		wsk = wsk->next;
		i++;
	}

	printf("Min temp wynosi %.2f\n",min);

	wsk = head;
	



	while (wsk) {
		ogon = wsk;
		wsk = wsk->next;
	}


	//////// JESLI GLOWA TO NAJMNIEJSZY ELT ////////
	if (index == 0)
	{
		head = head->next;
		ogon->next = wsk2;
		wsk2->next = NULL;
	}
	else if (wsk2->next == NULL) //////// TO JEST JUZ OSTANTI ELEMENT
	{
	}
	else {
		i = 0;
		while (i < index) {
			poprz = wsk3;
			wsk3 = wsk3->next;
			i++;
		}



		poprz->next = wsk2->next;
		ogon->next = wsk2;
		wsk2->next = NULL;


	}
	wsk = head;
	printl(wsk);

	return wsk;


	
}

int main()
{
	struct pomiar *wsk;
	struct pomiar *head = NULL;
	struct pomiar *h1 = NULL;
	struct pomiar *h2 = NULL;
	struct pomiar *h3 = NULL;
	struct pomiar *h4 = NULL;

	FILE *input, *output;
	

	char wejscie[ILE], bufor[ILE], wyjscie[ILE_CZUJNIKOW][ILE];

	
	/////////////////// OTWARCIE WEJSCIA ///////////////////
	strcpy(wejscie, "tmax.txt");


	struct pomiar *glowa = fun1(wejscie);

	printf("\n");

	printf("Glowa Lista\n");
	fun2(glowa); printf("\n"); printf("\n");

	struct pom glowy = fun3(glowa);


	usun(glowa);
	
	///////////////////////////// TMIN/////////////////////////////////////

	printf("\n1 LISTA\n");
	fun2(glowy.h1); 
	glowy.h1 = fun44(glowy.h1);
	fun2(glowy.h1);

	printf("\n2 LISTA\n");
	fun2(glowy.h2);
	glowy.h2 = fun44(glowy.h2);
	fun2(glowy.h2);

	printf("\n3 LISTA\n");
	fun2(glowy.h3);
	glowy.h3 = fun44(glowy.h3);
	fun2(glowy.h3);

	printf("\n4 LISTA\n");
	fun2(glowy.h4);
	glowy.h4 = fun44(glowy.h4);
	fun2(glowy.h4);


	//////////////////////////////// TMAX //////////////////////////////////////



	/*printf("\n1 LISTA\n");
	fun2(glowy.h1);
	glowy.h1 = fun4(glowy.h1);
	fun2(glowy.h1);

	printf("\n2 LISTA\n");
	fun2(glowy.h2);
	glowy.h2 = fun4(glowy.h2);
	fun2(glowy.h2);

	printf("\n3 LISTA\n");
	fun2(glowy.h3);
	glowy.h3 = fun4(glowy.h3);
	fun2(glowy.h3);

	printf("\n4 LISTA\n");
	fun2(glowy.h4);
	glowy.h4 = fun4(glowy.h4);
	fun2(glowy.h4);*/
	
	//////////////////////////////////////////////////////////////////////////

	usun(glowy.h1);
	usun(glowy.h2);
	usun(glowy.h3);
	usun(glowy.h4);
	
	//////////////////////////////////////////////////////////////////////////

	

	//if ((input = fopen(wejscie, "r")) == NULL)
	//{
	//	printf("Plik wejsciowy nie zostal otwarty\n");
	//	exit(0);
	//}



	///////////////////// CZYTANIE Z PLIKU I ZAPISYWANIE DO LISTY ///////////////////

	//while (!feof(input))
	//{
	//	pomiar *n_wsk = (pomiar*)malloc(sizeof(pomiar));					

	//	fscanf(input, "%d %d %s %lf", &n_wsk->nr_pomiaru, &n_wsk->nr_czujnika, n_wsk->data_i_czas, &n_wsk->temp);
	//	if (feof(input)) break;
	//	printf("Wczytuje: %d %d %s %.2f\n", n_wsk->nr_pomiaru, n_wsk->nr_czujnika, n_wsk->data_i_czas, n_wsk->temp);

	//	if (head == NULL)																	//glowa jest pusta (nie istnieje)
	//	{
	//		head = wsk = n_wsk;																//glowa i wsk wskazuja na nowy element
	//	}
	//	else
	//	{
	//		wsk->next = n_wsk;																//zarezerwuj pamiec dla nastepnego elementu
	//		wsk = wsk->next;																//przejdz na miejsce tego elementu

	//		wsk->next = NULL;																//Inicjowanie NULL na ostatni element listy
	//	}

	//}
	//fclose(input);

	//for (int i = 0; i < 4; i++) {
	//	if (head->nr_czujnika == 1)
	//		h1 = head;
	//	else if (head->nr_czujnika == 2)
	//		h2 = head;
	//	else if (head->nr_czujnika == 3)
	//		h3 = head;
	//	else if (head->nr_czujnika == 4)
	//		h4 = head;
	//	head = head->next;
	//}

	///*printl(head);
	//printf("\n");*/

	//dzielenie(head, h1, h2, h3, h4);

	///*printl(h1);
	//printf("\n");

	//printl(h2);
	//printf("\n");

	//printl(h3);
	//printf("\n");

	//printl(h4);
	//printf("\n");
	//printl(head);*/

	////////////////////////////////////

	//printf("\nPodaj nazwe pliku: ");
	//scanf("%s", &bufor);
	//strcpy(wyjscie[0], bufor);
	//strcpy(wyjscie[1], bufor);
	//strcpy(wyjscie[2], bufor);
	//strcpy(wyjscie[3], bufor);

	//char jeden[ILE] = "1.txt";
	//char dwa[ILE] = "2.txt";
	//char trzy[ILE] = "3.txt";
	//char cztery[ILE] = "4.txt";
	//
	//strcat(wyjscie[0], jeden);
	//strcat(wyjscie[1], dwa);
	//strcat(wyjscie[2], trzy);
	//strcat(wyjscie[3], cztery);

	//


	///////////////////// WYJSCIE NR 1 ///////////////////
	//if ((output = fopen(wyjscie[0], "w")) == NULL)
	//{
	//	printf("Plik wyjsciowy nie zostal otwarty\n");
	//	exit(0);
	//}

	//while (h1 != NULL)
	//{
	//	fprintf(output, "%d %d %s %.2f\n", h1->nr_pomiaru, h1->nr_czujnika, h1->data_i_czas, h1->temp);
	//	h1 = h1->next;
	//}
	//	fclose(output);




	///////////////////// WYJSCIE NR 2 ///////////////////
	//if ((output = fopen(wyjscie[1], "w")) == NULL)
	//{
	//	printf("Plik wyjsciowy nie zostal otwarty\n");
	//	exit(0);
	//}

	//while (h2 != NULL)
	//{
	//	fprintf(output, "%d %d %s %.2f\n", h2->nr_pomiaru, h2->nr_czujnika, h2->data_i_czas, h2->temp);
	//	h2 = h2->next;															
	//}
	//fclose(output);



	///////////////////// WYJSCIE NR 3 ///////////////////
	//if ((output = fopen(wyjscie[2], "w")) == NULL)
	//{
	//	printf("Plik wyjsciowy nie zostal otwarty\n");
	//	exit(0);
	//}

	//while (h3 != NULL)
	//{
	//	fprintf(output, "%d %d %s %.2f\n", h3->nr_pomiaru, h3->nr_czujnika, h3->data_i_czas, h3->temp);	
	//	h3 = h3->next;														
	//}
	//fclose(output);



	///////////////////// WYJSCIE NR 4 ///////////////////
	//if ((output = fopen(wyjscie[3], "w")) == NULL)
	//{
	//	printf("Plik wyjsciowy nie zostal otwarty\n");
	//	exit(0);
	//}
	//while (h4 != NULL)
	//{
	//	fprintf(output, "%d %d %s %.2f\n", h4->nr_pomiaru, h4->nr_czujnika, h4->data_i_czas, h4->temp);
	//	h4 = h4->next;														
	//}
	//fclose(output);





	///////////////////// USUWANIE SMIECI ///////////////////
	//usun(head);
	//usun(h1);
	//usun(h2);
	//usun(h3);
	//usun(h4);
	
}