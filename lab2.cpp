#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;



int TABLE = 1;
int KONIEC_TABLE = 0;
int CAPTION = 0;
int TR = 0;


int sprtag(string s){



	if (TR){

		if (s.compare(0, 4, "<TH>") == 0){
			if (s.compare(s.size()-5, 5, "</TH>") == 0){
				return 1;
			}
			else 	return 4;	//ZLE ZAKONCZENIE KODU
		}
	


		else if (s.compare(0, 4, "<TD>") == 0){
			if (s.compare(s.size()-5, 5, "</TD>") == 0){
				return 1;
			}
			else return 4;	//ZLE ZAKONCZENIE KODU
		}



		else if (s == "</TR>"){
			if (TR == 1){
				TR = 0;
			return 1;
			}
			else{
				return 3; 		
			}
		}


		else if (s == "<TR>"){
			if (TR == 0){
				TR++;
				return 1;
			}
			else return 5;		// MOZE TYLKO RAZ OTWORZYC TR

		}

		else if (s == "</TD>")
		{
			return 5;
		}
		else if (s == "</TH>")
		{
			return 4;
		}

		else return 2;

	}	////////// TR //////////////



	 if (s.compare(0, 9, "<CAPTION>") == 0){
		if (s.compare(s.size()-10, 10, "</CAPTION>") == 0 ){
			return 1;
		}
		else  { 
			return 4; 
		}		//ZLE ZAKONCZENIE KODU
	}


	else if (s == "<TR>"){
		TR++;
		return 1;
	}


	else if (s == "</TABLE>"){
		if (TABLE == 1){
			TABLE--;
			return 1;
		}
		else
			throw 6;
	
	}



	else if (s == "<TABLE>"){
		if (TABLE == 0){
			return 1;
		}
		else return 7;
	}


	else{
		return 2;
	}


	


}

void check(ifstream &in){

	string test;
	string t;
	int line = 1;
	
	getline(in, test, '\n');

	


	if (test != "<TABLE>"){
		cout << "<TABLE> nie otwiera tabeli\n";
		exit(EXIT_FAILURE);
	}


	cout << "<TABLE>" << endl;

	while (getline(in, t, '\n')){

		line++;

		cout << t << endl;

		ostringstream os("Blad ! Nieoczekiwana wartosc - niepoprawna linia nr    ");
		switch (sprtag(t)){
		case 1:break;
		case 2:os.seekp(-2, ios::end);
			os << line;
			throw string(os.str());
			break;
		case 3: throw string("Blad przy usuwaniu </TR>");
			break;
		case 4: throw string("Niepoprawne zakonczenie polecenia </TD> </TH> <CAPTION>");
			break;
		case 5: throw string("Niedomkniecie TR");
			break;
		case 6: throw string("Niedomkniecie Tagu </TR>");
			break;
		case 7:throw string("Niedomkniecie </TABLE> ");
			break;

		}


	}

	try{
		if (TABLE)
			throw string("Niepoprawnie zakonczony TABLE");
		else if (TR)
			throw string("Niesparowanie tagow TR");
		}
		catch (string &d)
		{
			cout << d << endl;
		}
	



}





int main(){



	ifstream in("1.txt");
	//ifstream in("niedomkniecie.txt");
	//ifstream in("niedomkniecie2.txt");
	//ifstream in("nieoczekiwana.txt");
	//ifstream in("nieoczekiwana2.txt");
	//ifstream in("niesparowanie.txt");
	//ifstream in("niesparowanie2.txt");
	//ifstream in("poprawne.txt");
	//ifstream in("uciete.txt");


	//ifstream in("rniedomkniecie.txt");
	//ifstream in("rniedomkniecie2.txt");
	//ifstream in("rniedomkniecie3.txt");
	//ifstream in("rnieoczekiwana wartosc.txt");
	//ifstream in("rnieoczekiwana wartosc2.txt");
	//ifstream in("rniesparowanie.txt");
	//ifstream in("rniesparowanie2.txt");
	//ifstream in("rpoprawna rozszerzona.txt");
	//ifstream in("rpoprawna rozszerzona2.txt");
	//ifstream in("ruciety.txt");

	try{
		check(in);
	}
	catch (string s){
		cout << s << endl;
	}

	cout << "\n****Koniec sprawdzania****\n";

	
}