#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class U_optyczne
{
protected:
	float zoom;
	float waga;
public:
	U_optyczne *next;

	virtual void wypisz();
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

	void WypiszWiekszyNiz(int a);
	U_optyczne();
	U_optyczne(float zoom, float waga);
	U_optyczne(U_optyczne& uo);
	~U_optyczne();
};

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

	Samochod();
	Samochod(float cena, string rodzaj);
	Samochod(Samochod& sa);
	~Samochod();
};

class kamera :public U_optyczne{
protected:
	double czasPracy;
	string typ; //lustrzanka, kompakt
	string standardNagrywania;
public:
	kamera();
	kamera(double, string, string, float,float);
	kamera(kamera &c);

	double getCzasPracy(){ return czasPracy; };
	string getTyp(){ return typ; };
	string getStandard(){ return standardNagrywania; }

	void setCzasPracy(double x){
		czasPracy = x;
	}
	void setTyp(string typ){
		this->typ = typ;
	}
	void setStandard(string standard){
		standardNagrywania = standard;
	}

	void wypisz();

	kamera& operator+=(const kamera &c) {
		czasPracy += c.czasPracy;
		waga += c.waga;
		zoom += c.zoom;
		return *this;
	}

	kamera& operator=(const kamera &c) {
		czasPracy = c.czasPracy;
		waga = c.waga;
		zoom = c.zoom;
		typ = c.typ;
		standardNagrywania = c.standardNagrywania;
		return *this;
	}


};
class aparat :public U_optyczne{
protected:
	double czasPracy;
	string typ; //lustrzanka, kompakt
	int maxLiczbaZdjec;
public:
	aparat();
	aparat(double, string, int, float,float);
	aparat(aparat &c);

	double getCzasPracy(){ return czasPracy; };
	string getTyp(){ return typ; };
	int getLiczbaZdjec(){ return maxLiczbaZdjec; }

	void setCzasPracy(double x){
		czasPracy = x;
	}
	void setTyp(string typ){
		this->typ = typ;
	}
	void setmaxLiczbaZdjec(int ile){
		maxLiczbaZdjec = ile;
	}

	void wypisz();

	aparat& operator+=(const aparat &c) {
		czasPracy += c.czasPracy;
		waga += c.waga;
		zoom += c.zoom;
		maxLiczbaZdjec += c.maxLiczbaZdjec;
		return *this;
	}

	aparat& operator=(const aparat &c) {
		czasPracy = c.czasPracy;
		waga = c.waga;
		zoom = c.zoom;
		maxLiczbaZdjec = c.maxLiczbaZdjec;
		typ = c.typ;
		return *this;
	}


};

kamera::kamera() : U_optyczne(), czasPracy(1), standardNagrywania("4K"), typ("kompakt"){

}

kamera::kamera(double p, string d, string s, float c, float r) : U_optyczne(c, abs(r)),typ(d),standardNagrywania(s){

	if (p <= 0){
		czasPracy = 1;
		printf("wartosc domyslna czasPracy=1\n");
	}
	else{
		czasPracy = p;
	}


}



void kamera::wypisz(){
	cout << "************ Kamera ************" << endl;
	U_optyczne::wypisz();
	printf("Czas Pracy :%.2f godzin Typ:%s Standard nagrywania: %s\n", czasPracy, typ.c_str(), standardNagrywania.c_str());
	cout << "*********************************" << endl << endl;
}



aparat::aparat() :U_optyczne(), czasPracy(1), typ("lustrzanka"),maxLiczbaZdjec(10000){

}

aparat::aparat(double l, string k, int ile, float c,float r) : U_optyczne(c, abs(r)),typ(k){

	if (l <= 0){
		czasPracy= 1;
		printf("czas Pracy domyslny=1\n");
	}
	else{
		czasPracy = l;
	}
	if (ile <= 0){
		maxLiczbaZdjec = 10000;
		printf("max Liczba zdjec =10000\n");
	}
	else{
		maxLiczbaZdjec = ile;
	}
}


void aparat::wypisz(){
	cout << "************ Aparat ************" << endl;
	U_optyczne::wypisz();
	printf("Czas Pracy :%.2f godzin Typ:%s Max Liczba zdjec: %d\n", czasPracy, typ.c_str(), maxLiczbaZdjec);
	cout << "********************************" << endl << endl;
}



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





void U_optyczne::WypiszWiekszyNiz(int x){
	if (zoom > x){
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
Silnik::Silnik() : moc(150), wymiary(250), next(NULL){

}

Silnik::Silnik(float moc, float wymiary) : moc(moc), wymiary(wymiary), next(NULL){


}

Silnik::Silnik(Silnik& si) : moc(si.moc), wymiary(si.wymiary), next(NULL){

}

Silnik::~Silnik(){
	delete next;
}
//---------------------------SAMOCHOD---------------------------------
Samochod::Samochod() : cena(1700), rodz_silnika("spalinowy"), next(NULL){

}

Samochod::Samochod(float cenax, string rodzaj) : next(NULL){
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

Samochod::Samochod(Samochod& sa) : cena(sa.cena), rodz_silnika(sa.rodz_silnika), next(NULL){

}

Samochod::~Samochod(){
	delete next;
}
//---------------------------U_OPTYCZNE---------------------------------
U_optyczne::U_optyczne() :zoom(5.0), waga(15.0), next(NULL){
}

U_optyczne::U_optyczne(float zoom, float waga) : zoom(zoom), waga(waga), next(NULL){
}

U_optyczne::U_optyczne(U_optyczne& uo) : zoom(uo.zoom), waga(uo.waga), next(NULL){
}

U_optyczne::~U_optyczne(){
	delete next;
}
//---------------------------OSOBA---------------------------------
Osoba::Osoba() : imie("Krzysztof"), nazwisko("Ptak"), email("KPtak@gmail.com"), next(NULL){
}

Osoba::Osoba(string imie, string nazwisko, string email) : imie(imie), nazwisko(nazwisko), email(email), next(NULL){
}

Osoba::Osoba(Osoba& os) : imie(os.imie), nazwisko(os.nazwisko), email(os.email), next(NULL){
}

Osoba::~Osoba(){
	delete next;
}


const kamera operator+(kamera &c, kamera &c2) {


	return kamera(c.getCzasPracy() + c2.getCzasPracy(),  c2.getTyp(),  c2.getStandard(), c.get_zoom() + c2.get_zoom(),c.get_waga()+c2.get_waga()); 
}

const aparat operator+(aparat &c, aparat &c2) {	//czas pracy typ maxliczba zoom waga


	return aparat(c.getCzasPracy() + c2.getCzasPracy(), c2.getTyp(), c.getLiczbaZdjec() + c2.getLiczbaZdjec(), c.get_zoom() + c2.get_zoom(), c.get_waga() + c2.get_waga());
}



int main()
{

	kamera B1, B2,B3;
	//B1.wypisz();
	//B2 = B1 + B2;
	//B2.wypisz();

	aparat* sahead = NULL;
	aparat A1, A2, A3;

	putchar('\n');
	A1.wypisz();
	B1.wypisz();

	//A2 += A3;
	//A1 = A2;
	//B1 = B2 += B3;
	A1 = A2 + A3;
	B1 = B2 + B3;
	A1.wypisz();
	B1.wypisz();


	for (int i = 0; i < 5; i++){
		aparat* aparacik = new aparat();

		if (sahead == NULL){
			sahead = aparacik;
		}
		else{
			U_optyczne* addsa = sahead;

			while (addsa->next != NULL){
				addsa = addsa->next;
			}

			addsa->next = aparacik;
		}
	}
	
	cout << "A1 przed dodaniem listy" << endl;
	A1.wypisz();

	U_optyczne* temp = sahead;
	aparat*temp2 = sahead;
	while (temp != NULL) {
		/*temp->wypisz();*/
		A1 += *temp2;
		temp = temp->next;
	}
	cout << "A1 po dodaniu listy 5 elementowej" << endl;;
	A1.wypisz();


	/*putchar('\n');
	head2->WypiszWiekszyNiz(3);*/



	delete sahead;
	

	////////////////////////////// KONIEC ////////////////////////////// 





	//Silnik* head1 = NULL;
	///*Samochod* head2 = NULL;*/
	//U_optyczne* head2 = NULL;
	//Osoba* head4 = NULL;
	//int t;
	//int a;

	///*
	//for (int i = 0; i < 5; i++){
	//Silnik* silnik = new Silnik();

	//if (head1 == NULL){
	//head1 = silnik;
	//}
	//else{
	//Silnik* temp=head1;

	//while (temp->next != NULL){
	//temp = temp->next;
	//}
	//temp->next = silnik;
	//}
	//}

	//Silnik* temp = head1;
	//while (temp != NULL) {
	//temp->wypisz();
	//temp = temp->next;
	//}
	//delete head1;
	//*/

	//do{
	//	printf("wybierz Urzadzeie Optyczne: Aparat(1) Kamera(2) Wyjscie(0)\n");
	//	scanf("%d", &t);
	//	if (t != 1 && t != 2){
	//		printf("Wyjscie\n");
	//		break;
	//	}
	//	switch (t){

	//	case 1:{
	//		printf("Wybrales Aparat, podaj parametr a:\n");
	//		scanf("%d", &a);

	//		aparat* aparacik = new aparat(a, "kompakt", a*1000, a, a);

	//		if (head2 == NULL){
	//			head2 = aparacik;
	//		}
	//		else{
	//			U_optyczne* addsa = head2;

	//			while (addsa->next != NULL){
	//				addsa = addsa->next;
	//			}

	//			addsa->next = aparacik;
	//		}
	//	}
	//		   break;
	//	case 2:{
	//		printf("Wybrales Kamere, podaj parametr a:\n");
	//		scanf("%d", &a);

	//		kamera* kamerka = new kamera(a, "lustrzanka","FullHD",a,a);

	//		if (head2 == NULL){
	//			head2 = kamerka;
	//		}
	//		else{
	//			U_optyczne* addsa = head2;

	//			while (addsa->next != NULL){
	//				addsa = addsa->next;
	//			}

	//			addsa->next = kamerka;
	//		}
	//	}
	//		   break;

	//	}
	//} while (1);
	//U_optyczne* temp = head2;
	//while (temp != NULL) {
	//	temp->wypisz();
	//	temp = temp->next;
	//}

	//putchar('\n');
	//head2->WypiszWiekszyNiz(20);



	//delete head2;

	///*///*
	//for (int i = 0; i < 5; i++){
	//U_optyczne* urzadzenie = new U_optyczne();

	//if (head3 == NULL){
	//head3 = urzadzenie;
	//}
	//else{
	//U_optyczne* addu;
	//addu = head3;

	//while (addu->next != NULL){
	//addu = addu->next;
	//}

	//addu->next = urzadzenie;
	//}
	//}
	//uhead->wypisz();
	//delete head3;
	//*/
	///*
	//for (int i = 0; i < 5; i++){
	//Osoba* osoba = new Osoba();

	//if (head4 == NULL){
	//head4 = osoba;
	//}
	//else{
	//Osoba* addo;
	//addo = head4;

	//while (addo->next != NULL){
	//addo = addo->next;
	//}

	//addo->next = osoba;
	//}
	//}
	//ohead->wypisz();
	//delete head4;
	//*/

	return 0;
}