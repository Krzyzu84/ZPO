#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<exception>
#include <math.h>
#include <assert.h>

using namespace std;


bool isPowerOfTwo(int n) {
	if (n == 0) return 0;
	while (n != 1) {
		if (n % 2 != 0)
			return 0;
		n /= 2;
	}
	return 1;
}

bool num_polow(double i) {

	double j = floor(i * 10) / 10;
	if (abs(i - j) < 0.001)
		return 1;
	return 0;
}




class Bazowe_Cechy {
public:
	static const bool _jest_liczba = false;
	static const bool _nalezy_do_przedzialu = false;
	static const bool _jest_liczba_calkowita = false;
	static const int _dolna_granica_przedzialu = 0;
	static const int _gorna_granica_przedzialu = 0;
	static const bool _numeracja_polowkowa = false;
	static const bool _potega_dwa = false;
	static const int _cyfry_po_przecinku = 0;

};

template<typename T>
class Cechy : public Bazowe_Cechy {
public:
	static const double dolna_granica_przedzialu() { return 0; };
	static const double gorna_granica_przedzialu() { return 0; };
};

class temperatura_wody {
	double t;
public:
	temperatura_wody(double temp = 50) : t(temp) {};
	double operator()() { return t; };
	temperatura_wody& operator=(double temp) { t = temp; return *this; };
	friend ostream & operator <<(ostream &os, const temperatura_wody &a);
};

template<>
class Cechy<temperatura_wody> : public Bazowe_Cechy {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const double dolna_granica_przedzialu() { return 0; };
	static const double gorna_granica_przedzialu() { return 100; };
	static const int _cyfry_po_przecinku = 2;
};



class UKF {
	double t;
public:
	UKF(double temp = 90) : t(temp) {};
	double operator()() { return t; };
	UKF& operator=(double temp) { t = temp; return *this; };

	friend ostream & operator <<(ostream &os, const UKF &a);
};

template<>
class Cechy<UKF> : public Bazowe_Cechy {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const double dolna_granica_przedzialu() { return 87.5; };
	static const double gorna_granica_przedzialu() { return 108; };
	static const int _cyfry_po_przecinku = 2;
};


class rozmiar_buta {
	double t;
public:
	rozmiar_buta(double temp = 41.5) : t(temp) {};
	double operator()() { return t; };
	rozmiar_buta& operator=(double temp) { t = temp; return *this; };
	friend ostream & operator <<(ostream &os, const rozmiar_buta &a);
};

template<>
class Cechy<rozmiar_buta> : public Bazowe_Cechy {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const double dolna_granica_przedzialu() { return 38.0; };
	static const double gorna_granica_przedzialu() { return 47.9; };
	static const bool _numeracja_polowkowa = true;
	static const int _cyfry_po_przecinku = 3;
};





class kostka_do_gry {
	int n;
public:
	kostka_do_gry(int num = 1) : n(num) {};
	int operator()() { return n; };
	kostka_do_gry& operator=(int num) { n = num; return *this; };
	friend ostream & operator <<(ostream &os, const kostka_do_gry &a) {
		os << a.n;
		return os;
	}
};

template<>
class Cechy<kostka_do_gry> : public Bazowe_Cechy {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const int _dolna_granica_przedzialu = 1;
	static const int _gorna_granica_przedzialu = 6;


	static const double dolna_granica_przedzialu() { return 1.0; };
	static const double gorna_granica_przedzialu() { return 6.0; };
};

class MicroSD {
	int n;
public:
	MicroSD(int num = 1) : n(num) {};
	int operator()() { return n; };
	MicroSD& operator=(int num) { n = num; return *this; };
	friend ostream & operator <<(ostream &os, const MicroSD &a) {
		os << a.n;
		return os;
	}

};

template<>
class Cechy<MicroSD> : public Bazowe_Cechy {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const int _dolna_granica_przedzialu = 1;
	static const int _gorna_granica_przedzialu = 128;
	static const bool _potega_dwa = true;

	static const double dolna_granica_przedzialu() { return 1; };
	static const double gorna_granica_przedzialu() { return 128; };
};


class srednica_opony {
	int n;
public:
	srednica_opony(int num = 12) : n(num) {};
	int operator()() { return n; };
	srednica_opony& operator=(int num) { n = num; return *this; };
	friend ostream & operator <<(ostream &os, const srednica_opony &a) {
		os << a.n;
		return os;
	}
};

template<>
class Cechy<srednica_opony> : public Bazowe_Cechy {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const int _dolna_granica_przedzialu = 10;
	static const int _gorna_granica_przedzialu = 24;
	static const double dolna_granica_przedzialu() { return 10; };
	static const double gorna_granica_przedzialu() { return 24; };
	static const int _cyfry_po_przecinku = 10;
};




class Przepelnienie : public exception {
	char opis[100];
public:
	Przepelnienie(const char* o) { strcpy_s(opis, o); }
	const char* what() const throw() { return opis; };
};
class BrakDanych : public exception {
	char opis[100];
public:
	BrakDanych(const char* o) { strcpy_s(opis, o); }
	const char* what() const throw() { return opis; };
};


template<typename T, int rozmiar, class _Cechy = Cechy<T>>
class SzablonStosu {
	T stos[rozmiar];
	int top;
public:
	int zajetosc() { return top; };
	SzablonStosu() : top(0) {}
	void push(const T& i) {
		if (top == rozmiar)
			throw Przepelnienie(typeid(i).name());
		stos[top++] = i;
	}
	void push(int i) {
		if (top == rozmiar)
			throw Przepelnienie(typeid(i).name());
		if (Cechy<T>::_jest_liczba && Cechy<T>::_jest_liczba_calkowita) {
			if (Cechy<T>::_nalezy_do_przedzialu) {
				if ((Cechy<T>::_dolna_granica_przedzialu <= i) && (i <= Cechy<T>::_gorna_granica_przedzialu))
					if (Cechy<T>::_potega_dwa) {
						if (isPowerOfTwo(i))
							stos[top++] = i;
					}
					else
						stos[top++] = i;
			}
			else
				stos[top++] = i;
		}
	}
	void push(double i) {
		if (top == rozmiar)
			throw Przepelnienie(typeid(i).name());
		if (Cechy<T>::_jest_liczba && !Cechy<T>::_jest_liczba_calkowita) {
			if (Cechy<T>::_nalezy_do_przedzialu) {
				if ((Cechy<T>::dolna_granica_przedzialu() <= i) && (i <= Cechy<T>::gorna_granica_przedzialu()))
					if (Cechy<T>::_numeracja_polowkowa) {
						if (num_polow(i))
							stos[top++] = i;
					}
					else
						stos[top++] = i;
			}
			else
				stos[top++] = i;
		}
	}
	T pop() {
		if (top == 0)
			throw BrakDanych(typeid(stos[0]).name());
		return stos[--top];
	}


	class iterator {
	public:
		SzablonStosu& s;
		int index;

		iterator(SzablonStosu& is) : s(is), index(0) {}
		iterator(SzablonStosu& is, bool) : s(is), index(is.top) {}
		T operator++() { // Prefix
			assert(index < s.top);
			return s.stos[++index];
		}
		T operator++(int) { // Postfix
			assert(index < s.top);
			return s.stos[index++];
		}
		bool operator==(const iterator& rv) const {
			return index == rv.index;
		}
		bool operator!=(const iterator& rv) const {
			return index != rv.index;
		}
		T operator*() const { return s.stos[index]; }
	};
	iterator begin() { return iterator(*this); }
	iterator end() { return iterator(*this, true); }
	friend class iterator;



};

template<typename T, int rozmiar>
void wypisz(ostream& out, SzablonStosu<T, rozmiar>& arg) {
	SzablonStosu<T, rozmiar>::iterator it(arg);
	while (it != arg.end()) {
		out << *it << ' ';
		it++;
	}
}

ostream & operator <<(ostream &os, const temperatura_wody &a) {
	os.setf(ios::fixed);
	os.precision(Cechy<temperatura_wody>::_cyfry_po_przecinku);
	os << a.t;
	return os;
}
ostream & operator <<(ostream &os, const UKF &a) {
	os.setf(ios::fixed);
	os.precision(Cechy<UKF>::_cyfry_po_przecinku);
	os << a.t;
	return os;
}
ostream & operator <<(ostream &os, const rozmiar_buta &a) {
	os.setf(ios::fixed);
	os.precision(Cechy<rozmiar_buta>::_cyfry_po_przecinku);
	os << a.t;
	return os;
}


class Stos2  {
	static const int rozmiar = 10;
protected:
	double stos[rozmiar];
	int top;
public:
	int zajetosc() { return top; };
	Stos2() : top(0) {}
	virtual void push(const double& i) { if (top == rozmiar)    throw Przepelnienie(typeid(i).name());   stos[top++] = i; }
	virtual double pop() {
		if (top == 0)
			throw BrakDanych(typeid(stos[0]).name());
		return stos[--top];
	}
};

template<class T>
class pop1 :public T {
public:
	 double pop() {

		cout << "Stos posiada " <<  T::top << " element-y" << endl;
		double a =  T::pop();
		cout << "Zwracana wartosc: " << a << endl;
		return a;
	}
};




template<class T>
class suma1 :public T {
public:
 static double suma;
	
	 void push(const double& i) {

		  double j = i;
		  T::push(j);
		suma += j;
	cout << "Suma po push wynosi: " << suma << endl;

	}


	  double pop() {

		double a =  T::stos[--top];
		suma -= a;
		cout << "Suma po pop wynosi " << suma << endl;
		return a;

	}
};

template<typename T>
double suma1<T>::suma = 0.0;

int main() {

	cout.precision(1);
	cout.setf(ios::fixed);

	pop1< suma1 < Stos2 > > t1;

	t1.push(5.1);
	t1.push(3.1);
	t1.push(6.1);

	t1.pop();
	t1.pop();
	t1.pop();


	cout << "\n\n";

	SzablonStosu<string, 5> K1;
	SzablonStosu<temperatura_wody, 10> K2;
	SzablonStosu<kostka_do_gry, 10> K3;
	SzablonStosu<srednica_opony, 10> K4;
	SzablonStosu<UKF, 10> K5;
	SzablonStosu<rozmiar_buta, 10> K6;
	SzablonStosu<MicroSD, 10> K7;
	// zape³nianie stosu
	ifstream fi("qv-lab4.txt");
	string s;
	try {
		K1.push("Henryk");
		K1.push("Sienkiewicz");
		/*	while (fi) {
		fi >> s;
		K1.push(s);
		fi.seekg(ios::beg);
		fi.clear();
		};*/
	}
	catch (Przepelnienie& e) {
		cout << "K1 gotowy: " << e.what() << endl;
	};
	cout << "Danych na stosie K1: " << K1.zajetosc() << endl;

	K2.push(temperatura_wody(5));
	K2.push(temperatura_wody(36.6));
	K2.push(40);
	K2.push(71.2);
	cout << "Danych na stosie K2: " << K2.zajetosc() << endl;

	K3.push(kostka_do_gry(3));
	K3.push(kostka_do_gry());
	K3.push(4.9);
	K3.push(6);
	K3.push(10);
	cout << "Danych na stosie K3: " << K3.zajetosc() << endl;



	K4.push(srednica_opony(21));
	K4.push(srednica_opony());
	K4.push(19);
	K4.push(23);
	K4.push(21.4);
	cout << "Danych na stosie K4: " << K4.zajetosc() << endl;

	K5.push(UKF(90.3));
	K5.push(UKF());
	K5.push(9);
	K5.push(91.4);
	K5.push(91.6);
	cout << "Danych na stosie K5: " << K5.zajetosc() << endl;



	K6.push(rozmiar_buta(46.5));
	K6.push(rozmiar_buta());
	K6.push(1);
	K6.push(-41.5);
	K6.push(42.699);
	K6.push(42.6);
	cout << "Danych na stosie K6: " << K6.zajetosc() << endl;


	K7.push(MicroSD(1));
	K7.push(MicroSD(2));
	K7.push(4);
	K7.push(-4);
	K7.push(129);
	K7.push(3);
	cout << "Danych na stosie K7: " << K7.zajetosc() << endl;


	cout << "\tK1" << endl;
	wypisz<string, 5>(cout, K1); cout << '\n';
	cout << "\tK2" << endl;
	wypisz<temperatura_wody, 10>(cout, K2); cout << '\n';
	cout << "\tK3" << endl;
	wypisz<kostka_do_gry, 10>(cout, K3); cout << '\n';
	cout << "\tK4" << endl;
	wypisz<srednica_opony, 10>(cout, K4); cout << '\n';
	cout << "\tK5" << endl;
	wypisz<UKF, 10>(cout, K5); cout << '\n';
	cout << "\tK6" << endl;
	wypisz<rozmiar_buta, 10>(cout, K6); cout << '\n';
	cout << "\tK7" << endl;
	wypisz<MicroSD, 10>(cout, K7); cout << '\n';


	// opró¿nianie stosu


	try {
		while (true)
			K1.pop();
	}
	catch (BrakDanych& e) {
		cout << "K1 pusty: " << e.what() << endl;
	}
	try {
		while (true)
			K2.pop();
	}
	catch (BrakDanych& e) {
		cout << "K2 pusty: " << e.what() << endl;
	}
	try {
		while (true)
			K3.pop();
	}
	catch (BrakDanych& e) {
		cout << "K3 pusty: " << e.what() << endl;
	}



	system("pause");
	return 0;
}
