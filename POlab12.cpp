#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class Silnik
{
protected:
	float moc;
	float wymiary;
public:
	Silnik *next;

	void wypisz();
	float get_moc(){ 
		return moc;
	}
	void set_moc(float m){
		moc = m;
	}
	float get_wymiary(){
		return wymiary;
	}
	void set_wymiary(float wym){
		wymiary = wym;
	}

	Silnik();
	Silnik(float moc, float wymiary);
	Silnik(Silnik& si);
	~Silnik();
};

class Samochod
{
protected:
	float cena;
	string rodz_silnika;
public:
	Samochod *next;

	virtual void wypisz();
	float get_cena(){
		return cena;
	}
	void set_cena(float c){
		cena = c;
	}

	string get_rodzaj(){
		return rodz_silnika;
	}
	void set_rodzaj(string r){
		rodz_silnika = r;
	}

	void WypiszWiekszyNiz(int a);
	Samochod();
	Samochod(float cena, string rodzaj);
	Samochod(Samochod& sa);
	~Samochod();
};


class cie :public Samochod{
	protected:
		double ladownosc;
		int kola;
	public:
		cie();
		cie(double, int, double, string);
		cie(cie &c);

		double getLadownosc(){ return ladownosc; };
		int getKola(){ return kola; };

		void setLadownosc(double x);
		void setKola(int y);

		void wypisz();
};

class oso : public Samochod{
	protected:
	double pojemnosc;
	int drzwi;
	string sylwetka;
	public:
		oso();
		oso(double, int, string, double, string);
		oso(oso &o);


		double getPoj(){ return pojemnosc; };
		int getDrzwi(){ return drzwi; };
		string getSylwetka(){ return sylwetka; };

		void setPoj(double x);
		void setDrzwi(int y);
		void setSylwetka(string z);

		void wypisz();
};

//--------------------------------OSO------------------------------------------------
oso::oso() :Samochod(), pojemnosc(1), drzwi(4), sylwetka("sedan"){

}

oso::oso(double p, int d, string s, double c, string r) : Samochod(c, r){

	if (p <= 0){
		pojemnosc = 1;
		printf("wartosc domyslna pojemnosc=1\n");
	}
	else{
		pojemnosc = p;
	}                    
	if (d <= 0){
		drzwi = 4;
		printf("wartosc domyslna drzwi=4\n");
	}
	else{
		drzwi = d;
	}
	if (s!="H" && s!="S" && s!="K" && s!="V"){
		sylwetka = "S";
		printf("wartosc domyslna sylwetki=S\n");
	}
	else{
		sylwetka = s;
	}

}

oso::oso(oso &o) :Samochod(o.cena, o.rodz_silnika), pojemnosc(o.pojemnosc), drzwi(o.drzwi), sylwetka(o.sylwetka){

}


void oso::wypisz(){
	Samochod::wypisz();
	printf("Pojemnosc:%f drzwi:%d sylwetka:%s\n", pojemnosc, drzwi, sylwetka.c_str());
}

void oso::setPoj(double x){
	if (x <= 0){
		printf("wartosc domyslna pojemnosci=1\n");
		pojemnosc = 1;
	}
	else{
		pojemnosc = x;
	}
}

void oso::setDrzwi(int y){
	if (y <= 0){
		printf("wartosc domyslna pojemnosci=4\n");
		drzwi = 4;
	}
	else{
		drzwi = y;
	}
}

void oso::setSylwetka(string z){
	if (z != "H" && z != "S" && z != "K" && z != "V"){
		sylwetka = "S";
		printf("wartosc domyslna sylwetki=S\n");
	}
	else{
		sylwetka= z;
	}
}
//--------------------------------CIE------------------------------------------------

cie::cie() :Samochod(), ladownosc(1), kola(8){

}

cie::cie(double l, int k, double c, string r) : Samochod(c, r){

	if (l <= 0){
		ladownosc = 1;
		printf("ladownosc domyslna=1\n");
	}
	else{
		ladownosc = l;
	}
	if (k <= 0){
		kola = 8;
		printf("kola domyslne=8\n");
	}
	else{
		kola = k;
	}
}

cie::cie(cie &c) :Samochod(c.cena, c.rodz_silnika), ladownosc(c.ladownosc), kola(c.kola){

}

void cie::wypisz(){
	Samochod::wypisz();
	printf("ladownosc:%f kola:%d\n", ladownosc, kola);
}

void cie::setKola(int y){
	if (y <= 0){
		kola = 4;
		printf("ustawiono kola domyslnie=4\n");
	}
	else{
		kola = y;
	}
}


void cie::setLadownosc(double x){
	if (x <= 0){
		ladownosc = 1;
		printf("ustawiono ladownosc domyslnie=1\n");
	}
	else{
		ladownosc = x;
	}
}

class U_optyczne
{
protected:
	float zoom;
	float waga;
public:
	U_optyczne *next;

	void wypisz();
	float get_zoom(){
		return zoom;
	}
	void set_zoom(float z){
		zoom = z;
	}

	float get_waga(){
		return waga;
	}
	void set_waga(float w){
		waga = w;
	}

	U_optyczne();
	U_optyczne(float zoom, float waga);
	U_optyczne(U_optyczne& uo);
	~U_optyczne();
};

class Osoba
{
protected:
	string imie;
	string nazwisko;
	string email;
public:
	Osoba *next;

	void wypisz();
	string get_imie(){
		return imie;
	}
	void set_imie(string i){
		imie = i;
	}

	string get_nazwisko(){
		return nazwisko;
	}
	void set_nazwisko(string n){
		nazwisko = n;
	}

	string get_email(){
		return email;
	}
	void set_email(string e){
		email = e;
	}

	Osoba();
	Osoba(string imie, string nazwisko, string email);
	Osoba(Osoba& os);
	~Osoba();
};





void Samochod::WypiszWiekszyNiz(int x){
	if (cena > x){
		wypisz();
	}
	if (next != NULL){
		next->WypiszWiekszyNiz(x);
	}
}
//-------------------------METODY WYPISZ-----------------------------------
void Silnik::wypisz(){
	printf("moc: %.3f, wymiary: %.3f", moc, wymiary);
}

void Samochod::wypisz(){
	printf("cena: %.3f, rodz_silnika: %s ", cena, rodz_silnika.c_str());
}

void U_optyczne::wypisz(){
	printf("zoom: %.3f, waga: %.3f\n", zoom, waga);
}

void Osoba::wypisz(){
	printf("imie: %s, nazwisko: %s, email: %s\n", imie.c_str(), nazwisko.c_str(), email.c_str());
}
//---------------------------KONSTRUKTORY/DESTRUKTORY---------------------------------
								//---------------------------SILNIK---------------------------------
Silnik::Silnik(): moc(150), wymiary(250), next(NULL){
	
}

Silnik::Silnik(float moc, float wymiary): moc(moc), wymiary(wymiary), next(NULL){


}

Silnik::Silnik(Silnik& si): moc(si.moc), wymiary(si.wymiary), next(NULL){
	
}

Silnik::~Silnik(){
	delete next;
}
								//---------------------------SAMOCHOD---------------------------------
Samochod::Samochod(): cena(1700), rodz_silnika("spalinowy"), next(NULL){
	
}

Samochod::Samochod(float cenax, string rodzaj):next(NULL){
	if (cenax < 0){
		cena = 1;
		printf("wartosc domyslna cena=1\n");
	}
	else{
		cena = cenax;
	}
	if (rodzaj != "gaz"&&rodzaj != "benzyna"&&rodzaj != "diesel"){
		rodz_silnika = "gaz";
	}
	else{
		rodz_silnika = rodzaj;
	}

}

Samochod::Samochod(Samochod& sa): cena(sa.cena), rodz_silnika(sa.rodz_silnika), next(NULL){
	
}

Samochod::~Samochod(){
	delete next;
}
								//---------------------------U_OPTYCZNE---------------------------------
U_optyczne::U_optyczne():zoom(5.0), waga(15.0), next(NULL){
}

U_optyczne::U_optyczne(float zoom, float waga): zoom(zoom), waga(waga), next(NULL){
}

U_optyczne::U_optyczne(U_optyczne& uo): zoom(uo.zoom), waga(uo.waga), next(NULL){
}

U_optyczne::~U_optyczne(){
	delete next;
}
								//---------------------------OSOBA---------------------------------
Osoba::Osoba(): imie("Marcin"), nazwisko("Elegancki"), email("M.Elegancki@gmail.com"), next(NULL){
}

Osoba::Osoba(string imie, string nazwisko, string email): imie(imie), nazwisko(nazwisko), email(email), next(NULL){
}

Osoba::Osoba(Osoba& os): imie(os.imie), nazwisko(os.nazwisko), email(os.email), next(NULL){
}

Osoba::~Osoba(){
	delete next;
}



int main()
{
	Silnik* head1 = NULL;
	Samochod* head2 = NULL;
	U_optyczne* head3 = NULL;
	Osoba* head4 = NULL;
	int t;
	int a;

	/*
	for (int i = 0; i < 5; i++){
	Silnik* silnik = new Silnik();

	if (head1 == NULL){
		head1 = silnik;
	}
	else{
	Silnik* temp=head1;

	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = silnik;
	}
	}

	Silnik* temp = head1;
	while (temp != NULL) {
		temp->wypisz();
		temp = temp->next;
	}
	delete head1;
	*/
	
	do{
		printf("wybierz samochod: Osobowy(1) Ciezarowy(2) Wyjscie(0)\n");
		scanf("%d", &t);
		if (t != 1 && t != 2){
			printf("Wyjscie\n");
			break;
		}
		switch (t){

		case 1:{
			printf("Wybrales osobowy, podaj parametr a:\n");
			scanf("%d", &a);

			oso* samochod = new oso(a, a*2, "H", a, "spalinowy");

			if (head2 == NULL){
				head2 = samochod;
			}
			else{
				Samochod* addsa = head2;

				while (addsa->next != NULL){
					addsa = addsa->next;
				}

				addsa->next = samochod;
			}
		}
			   break;
		case 2:{
			printf("Wybrales ciezarowy, podaj parametr a:\n");
			scanf("%d", &a);

			cie* samochod = new cie(a, a*3, a, "spalinowy");

			if (head2 == NULL){
				head2 = samochod;
			}
			else{
				Samochod* addsa = head2;

				while (addsa->next != NULL){
					addsa = addsa->next;
				}

				addsa->next = samochod;
			}
		}
			   break;

		}
	} while (1);
	Samochod* temp = head2;
	while (temp != NULL) {
		temp->wypisz();
		temp = temp->next;
	}

	putchar('\n');
	head2->WypiszWiekszyNiz(3);



	delete head2;
	
	/*///*
	for (int i = 0; i < 5; i++){
	U_optyczne* urzadzenie = new U_optyczne();

	if (head3 == NULL){
	head3 = urzadzenie;
	}
	else{
	U_optyczne* addu;
	addu = head3;

	while (addu->next != NULL){
	addu = addu->next;
	}

	addu->next = urzadzenie;
	}
	}
	uhead->wypisz();
	delete head3;
	*/
	/*
	for (int i = 0; i < 5; i++){
	Osoba* osoba = new Osoba();

	if (head4 == NULL){
	head4 = osoba;
	}
	else{
	Osoba* addo;
	addo = head4;

	while (addo->next != NULL){
	addo = addo->next;
	}

	addo->next = osoba;
	}
	}
	ohead->wypisz();
	delete head4;
	*/

	return 0;
}