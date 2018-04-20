#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <ctime>
#include <time.h>

#include <conio.h>

#include<assert.h>

#include <math.h>
#include <ctype.h>

#define ILE 100

char * data() {
	time_t rawtime = time(0);
	struct tm info;
	static char buffer[80];
	info = *localtime(&rawtime);
	strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", &info);
	return buffer;
}

int istnieje(char *nazwa) {
	FILE *plik;

	plik=fopen(nazwa,"r");
	if (plik == NULL) {
		return 0;
	}
	else {
		return 1;
	}

}


void gra(FILE* log, FILE *output, time_t start,int &poprawnych)
{


	srand(time(NULL));

	/*int type = rand() % 3;*/
	int litera;
	int litera2;



	litera = rand() % 25 + 97;
	litera2 = rand() % 25 + 97;


	//litera = rand() % 10 + 48;
	//litera2 = rand() % 10 + 48;


	while (litera == litera2 || abs(litera-litera2) < 2 )
	{

		litera2 = rand() % 25 + 97;

	/*	litera2 = rand() % 10 + 48;*/

	}

	if (litera > litera2)
	{
		int temp = litera;
		litera = litera2;
		litera2 = temp;
	}



	printf("%c %c\n", litera, litera2);







	/*if (type == 0)
	{
		litera = rand() % 10 + 48;
	}
	else if (type == 1)
	{
		litera = rand() % 25 + 65;
	}
	else if (type == 2)
	{
		litera = rand() % 25 + 97;
	}
	printf("%c\n", litera);*/

	time_t actual = time(0);
	char * czas = data();
	fprintf(output, "%s Wylosowano: %c %c ", czas, litera,litera2);
	if (ferror(log))
	{
		fprintf(stderr, "Blad zapisu do logu w funkcji gra\n");
	}
	char odp = _getch();

	if (odp > litera && odp < litera2 )
	{
		fprintf(output, "Poprawna odpowiedz    %c \t %d\n", odp,1);
		poprawnych++;
	}
	else
		fprintf(output, "Niepoprawna odpowiedz %c \t %d\n", odp,0);

	if (ferror(log))
		perror("Blad podczas pisania do log w funkcji gra\n");


	time(&actual);
	/*fprintf(output, "Czas: %.1lf sek.\tWynik:%d\n", difftime(actual, start), poprawnych);*/
	if (ferror(output))
	{
		perror("Blad podczas pisania do pliku z gra.txt");
	}


}

int main() {

	while (1) {
		FILE *output;

		freopen("log.txt", "a+", stderr);

		char nick[ILE] = "gra-";
		char nazwa[ILE];
		int liczba = 0;
		time_t now = time(0);

		srand(time(NULL));

		/*	if ((log = fopen("log.txt", "a")) == NULL)
			{
				fprintf(stderr, "Blad przy otwieraniu pliku log.txt %s ", strerror(errno));
				exit(0);
			}*/
		char *czas = data();

		printf("Podaj nick i liczbe: ");
		scanf("%s %d", nazwa, &liczba);

		assert(!isalpha(liczba));
		assert(liczba > 0);
		assert(liczba = floor(liczba));

		fprintf(stderr, "Start programu %s \n", czas);
		fprintf(stderr, "Nick: %s  liczba: %d\t czas: %s\n", nazwa, liczba, czas);

		if (ferror(stderr))
		{
			fprintf(stderr, "%s %s", asctime(localtime(&now)), "Blad podczas zapisu do log.txt");
		}

		strcat(nick, nazwa);
		strcat(nick, ".txt");

		output = fopen(nick, "r+");


		if (!istnieje(nick))
		{
			printf("Zakladam nowy plik.\n");

			if ((output = fopen(nick, "w")) == NULL)
			{
				fprintf(stderr, "Blad przy otwieraniu pliku %s %s \n", nick, strerror(errno));
				exit(0);
			}
			if (output == NULL)
			{
				printf("Blad podczas otwierania pliku: %s\n", nick);
			}
			else
				system("cd");

		}
		else {

			fclose(output);
			if ((output = fopen(nick, "a")) == NULL)
			{
				fprintf(stderr, "Blad przy otwieraniu pliku %s %s ", nick, strerror(errno));
				exit(0);
			}

		}

		printf("Rozpoczecie gry: \n");
		int poprawnych = 0;
		int i = 0;
		time_t start, finish;
		time(&start);

		while (i < liczba)
		{
			gra(stderr, output, start, poprawnych);
			i++;
		}
		char *teraz = data();
		fprintf(stderr, "Koniec gry %s\n", teraz);
		printf("Czy chcesz zagrac ponownie ? (t/n): ");
		char z = _getch();
		if (z != 't' && z != 'T')
		{
			char *t1 = data();
			fprintf(stderr, "Koniec programu: %s \n", t1);
			break;
		}

	}

	//time(&finish);
	//czas = data();
	//fprintf(log, "KONIEC GRY: %s\n", czas);

	//printf("Twoj czas to %.1lf sekund\nTwoj wynik wynosi %d\n", difftime(finish, start), poprawnych);

	return 0;



}