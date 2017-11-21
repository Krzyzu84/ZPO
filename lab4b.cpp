//
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<limits>
//#include<exception>
//#include <iomanip>
//#include <cassert>
//
//using namespace std;
//
//
//bool spr_liczba_pierwsza(int n) {
//
//	if (n == 1)
//		return 0;
//
//	for (int i = 2; i <= n / 2; ++i)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//		return 1;
//}
//
//bool piwko(double i) {
//	int j = int(i / 0.568);
//	if (abs(i - (0.568*j)) < 0.001)
//		return 1;
//	return 0;
//}
//
//
//class Bazowe_Cechy {
//public:
//	static const bool _jest_liczba = false;
//	static const bool _nalezy_do_przedzialu = false;
//	static const bool _jest_liczba_calkowita = false;
//	static const int _dolna_granica_przedzialu = 0;
//	static const int _gorna_granica_przedzialu = 0;
//	static const bool _jest_parzyste = false;
//	static const bool _wielokrot_pinta = false;
//	static const bool _liczba_pierwsza = false;
//
//};
//
//template<typename T>
//class Cechy : public Bazowe_Cechy {
//public:
//	static const double dolna_granica_przedzialu() { return 0; };
//	static const double gorna_granica_przedzialu() { return 0; };
//	static const int _cyfry_po_przecinku = 1;
//};
//
//class temperatura_wody {
//	double t;
//public:
//	temperatura_wody(double temp = 50) : t(temp) {};
//	double operator()() { return t; };
//	temperatura_wody& operator=(double temp) { t = temp; return *this; };
//	friend ostream & operator<<(ostream &os, const temperatura_wody &a);
//
//};
//
//template<>
//class Cechy<temperatura_wody> : public Bazowe_Cechy {
//public:
//	static const bool _jest_liczba = true;
//	static const bool _nalezy_do_przedzialu = true;
//	static const double dolna_granica_przedzialu() { return 0; };
//	static const double gorna_granica_przedzialu() { return 100; };
//	static const int _cyfry_po_przecinku = 10;
//
//};
//
//class piwo {
//	double t;
//public:
//	piwo(double temp = 50) : t(temp) {};
//	double operator()() { return t; };
//	piwo& operator=(double temp) { t = temp; return *this; };
//	friend ostream & operator<<(ostream &os, const piwo &a);
//};
//
//template<>
//class Cechy<piwo> : public Bazowe_Cechy {
//public:
//	static const bool _jest_liczba = true;
//	static const bool _nalezy_do_przedzialu = true;
//	static const double dolna_granica_przedzialu() { return 0; };
//	static const double gorna_granica_przedzialu() { return DBL_MAX; };
//	static const bool _wielokrot_pinta = true;
//	static const int _cyfry_po_przecinku = 10;
//};
//
//
//
//
//
//
//class kostka_do_gry {
//	int n;
//public:
//	kostka_do_gry(int num = 1) : n(num) {};
//	int operator()() { return n; };
//	kostka_do_gry& operator=(int num) { n = num; return *this; };
//	friend ostream & operator<<(ostream &os, const kostka_do_gry &a);
//};
//
//template<>
//class Cechy<kostka_do_gry> : public Bazowe_Cechy {
//public:
//	static const bool _jest_liczba = true;
//	static const bool _nalezy_do_przedzialu = true;
//	static const bool _jest_liczba_calkowita = true;
//	static const int _dolna_granica_przedzialu = 1;
//	static const int _gorna_granica_przedzialu = 6;
//	static const double dolna_granica_przedzialu() { return 0; };
//	static const double gorna_granica_przedzialu() { return 60; };
//	static const int _cyfry_po_przecinku = 10;
//};
//
//
//class liczba_pierwsza {
//	int n;
//public:
//	liczba_pierwsza(int num = 1) : n(num) {};
//	int operator()() { return n; };
//	liczba_pierwsza& operator=(int num) { n = num; return *this; };
//	friend ostream & operator<<(ostream &os, const liczba_pierwsza &a);
//};
//
//template<>
//class Cechy<liczba_pierwsza> : public Bazowe_Cechy {
//public:
//	static const bool _jest_liczba = true;
//	static const bool _nalezy_do_przedzialu = true;
//	static const bool _jest_liczba_calkowita = true;
//	static const int _dolna_granica_przedzialu = 0;
//	static const int _gorna_granica_przedzialu = INT_MAX;
//	static const double dolna_granica_przedzialu() { return 0; };
//	static const double gorna_granica_przedzialu() { return INT_MAX; };
//	static const bool _liczba_pierwsza = true;
//	static const int _cyfry_po_przecinku = 10;
//};
//
//
//
//class minuta_dnia {
//	int n;
//public:
//	minuta_dnia(int num = 0) : n(num) {};
//	int operator()() { return n; };
//	minuta_dnia& operator=(int num) { n = num; return *this; };
//	friend ostream & operator<<(ostream &os, const minuta_dnia &a);
//
//};
//
//template<>
//class Cechy<minuta_dnia> : public Bazowe_Cechy {
//public:
//	static const bool _jest_liczba = true;
//	static const bool _nalezy_do_przedzialu = true;
//	static const bool _jest_liczba_calkowita = true;
//	static const double dolna_granica_przedzialu() { return 0; };
//	static const double gorna_granica_przedzialu() { return 60; };
//	static const int _cyfry_po_przecinku = 10;
//
//};
//
//
//class zegar {
//	int n;
//public:
//	zegar(int num = 2) : n(num) {};
//	int operator()() { return n; };
//	zegar& operator=(int num) { n = num; return *this; };
//	friend ostream & operator<<(ostream &os, const zegar &a);
//};
//
//template<>
//class Cechy<zegar> : public Bazowe_Cechy {
//public:
//	static const bool _jest_liczba = true;
//	static const bool _nalezy_do_przedzialu = true;
//	static const bool _jest_liczba_calkowita = true;
//	static const int _dolna_granica_przedzialu = 2;
//	static const int _gorna_granica_przedzialu = 24;
//	static const double dolna_granica_przedzialu() { return 2; };
//	static const double gorna_granica_przedzialu() { return 24; };
//	static const bool _jest_parzyste = true;
//	static const int _cyfry_po_przecinku = 10;
//};
//
//class Przepelnienie : public exception {
//	char opis[100];
//public:
//	Przepelnienie(const char* o) { strcpy_s(opis, o); }
//	const char* what() const throw() { return opis; };
//};
//class BrakDanych : public exception {
//	char opis[100];
//public:
//	BrakDanych(const char* o) { strcpy_s(opis, o); }
//	const char* what() const throw() { return opis; };
//};
//
//
//template<typename T, int rozmiar, class _Cechy = Cechy<T>>
//class SzablonStosu {
//	T stos[rozmiar];
//	int top;
//public:
//	int zajetosc() { return top; };
//	SzablonStosu() : top(0) {}
//	void push(const T& i) {
//		if (top == rozmiar)
//			throw Przepelnienie(typeid(i).name());
//		stos[top++] = i;
//	}
//	void push(int i) {
//		if (top == rozmiar)
//			throw Przepelnienie(typeid(i).name());
//		if (Cechy<T>::_jest_liczba && Cechy<T>::_jest_liczba_calkowita) {
//			if (Cechy<T>::_nalezy_do_przedzialu) {
//				if ((Cechy<T>::_dolna_granica_przedzialu <= i) && (i <= Cechy<T>::_gorna_granica_przedzialu))
//					if (Cechy<T>::_jest_parzyste) {
//						if (i % 2 == 0)
//							stos[top++] = i;
//					}
//				if (Cechy<T>::_liczba_pierwsza) {
//					if (spr_liczba_pierwsza(i))
//						stos[top++] = i;
//				}
//				else
//					stos[top++] = i;
//			}
//			else
//				stos[top++] = i;
//		}
//	}
//	void push(double i) {
//		if (top == rozmiar)
//			throw Przepelnienie(typeid(i).name());
//		if (Cechy<T>::_jest_liczba && !Cechy<T>::_jest_liczba_calkowita) {
//			if (Cechy<T>::_nalezy_do_przedzialu) {
//				if ((Cechy<T>::dolna_granica_przedzialu() <= i) && (i <= Cechy<T>::gorna_granica_przedzialu()))
//					if (Cechy<T>::_wielokrot_pinta) {
//						if (piwko(i))
//							stos[top++] = i;
//					}
//					else
//						stos[top++] = i;
//			}
//			else
//				stos[top++] = i;
//		}
//	}
//	T pop() {
//		if (top == 0)
//			throw BrakDanych(typeid(stos[0]).name());
//		return stos[--top];
//	}
//
//	class iterator {
//	public:
//		SzablonStosu& s;
//		int index;
//
//		iterator(SzablonStosu& is) : s(is), index(0) {}
//		iterator(SzablonStosu& is, bool) : s(is), index(is.top) {}
//		T operator++() { // Prefix
//			assert(index < s.top);
//			return s.stos[++index];
//		}
//		T operator++(int) { // Postfix
//			assert(index < s.top);
//			return s.stos[index++];
//		}
//		bool operator==(const iterator& rv) const {
//			return index == rv.index;
//		}
//		bool operator!=(const iterator& rv) const {
//			return index != rv.index;
//		}
//		T operator*() const { return s.stos[index]; }
//
//	};
//	iterator begin() { return iterator(*this); }
//	iterator end() { return iterator(*this, true); }
//	friend class iterator;
//
//
//};
//
//
//
//
//
//
//template<typename T, int rozmiar>
//void wypisz(ostream& out, SzablonStosu<T, rozmiar>& arg) {
//	SzablonStosu<T, rozmiar>::iterator it(arg);
//	while (it != arg.end()) {
//		out << *it << ' ';
//		it++;
//	}
//}
//
//
//ostream & operator<<(ostream &os, const temperatura_wody &a) {
//	os.precision(Cechy<temperatura_wody>::_cyfry_po_przecinku);
//	os.setf(ios::fixed);
//	os << a.t; return os;
//}
//
//ostream & operator<<(ostream &os, const kostka_do_gry &a) {
//	os.precision(Cechy<kostka_do_gry>::_cyfry_po_przecinku);
//	os.setf(ios::fixed);
//	os << a.n; return os;
//}
//
//ostream & operator<<(ostream &os, const minuta_dnia &a) {
//	os.precision(Cechy<minuta_dnia>::_cyfry_po_przecinku);
//	os.setf(ios::fixed);
//	os << a.n; return os;
//}
//
//ostream & operator<<(ostream &os, const zegar &a) {
//	os.precision(Cechy<zegar>::_cyfry_po_przecinku);
//	os.setf(ios::fixed);
//	os << a.n; return os;
//}
//
//ostream & operator<<(ostream &os, const piwo &a) {
//	os.precision(Cechy<piwo>::_cyfry_po_przecinku);
//	os.setf(ios::fixed);
//	os << a.t; return os;
//}
//
//ostream & operator<<(ostream &os, const liczba_pierwsza &a) {
//	os.precision(Cechy<liczba_pierwsza>::_cyfry_po_przecinku);
//	os.setf(ios::fixed);
//	os << a.n; return os;
//}
//
//
//
//int main() {
//	SzablonStosu<string, 5> K1;
//	SzablonStosu<temperatura_wody, 10> K2;
//	SzablonStosu<kostka_do_gry, 10> K3;
//	SzablonStosu<minuta_dnia, 10> K4;
//	SzablonStosu<zegar, 10> K5;
//	SzablonStosu<piwo, 10> K6;
//	SzablonStosu<liczba_pierwsza, 10> K7;
//
//
//	// zape�nianie stosu
//	ifstream fi("qv-lab4.txt");
//	string s;
//	try {
//		K1.push("Henryk");
//		K1.push("Sienkiewicz");
//		/*while (fi) {
//		fi >> s;
//		K1.push(s);
//		fi.seekg(ios::beg);
//		fi.clear();
//		};*/
//	}
//	catch (Przepelnienie& e) {
//		cout << "K1 gotowy: " << e.what() << endl;
//	};
//	cout << "Danych na stosie K1: " << K1.zajetosc() << endl;
//
//	K2.push(temperatura_wody());
//	K2.push(temperatura_wody(36.6));
//	K2.push(40.423456);
//	K2.push(71.2);
//	cout << "Danych na stosie K2: " << K2.zajetosc() << endl;
//
//	K3.push(kostka_do_gry(3));
//	K3.push(kostka_do_gry());
//	K3.push(4);
//	K3.push(6);
//	K3.push(10);
//	cout << "Danych na stosie K3: " << K3.zajetosc() << endl;
//
//
//	K4.push(minuta_dnia(3));
//	K4.push(minuta_dnia());
//	K4.push(4.1);
//	K4.push(6);
//	K4.push(10);
//	cout << "Danych na stosie K4: " << K4.zajetosc() << endl;
//
//
//	K5.push(zegar(2));
//	K5.push(zegar());
//	K5.push(4.1);
//	K5.push(-6);
//	K5.push(-10);
//	K5.push(12);
//	cout << "Danych na stosie K5: " << K5.zajetosc() << endl;
//
//
//	/*K6.push(piwo(2));
//	K6.push(piwo());*/
//	K6.push(0.568);
//	K6.push(2 * 0.568);
//	K6.push(5.68);
//	K6.push(12);
//	cout << "Danych na stosie K6: " << K6.zajetosc() << endl;
//
//
//
//
//	K7.push(5);
//	K7.push(7);
//	K7.push(11);
//	K7.push(2);
//	cout << "Danych na stosie K7: " << K7.zajetosc() << endl;
//
//
//
//
//
//
//
//
//
//	wypisz<string, 5>(cout, K1); cout << "\n";
//	wypisz<temperatura_wody, 10>(cout, K2); cout << "\n";
//	wypisz<kostka_do_gry, 10>(cout, K3); cout << "\n";
//	wypisz<minuta_dnia, 10>(cout, K4); cout << "\n";
//	wypisz<zegar, 10>(cout, K5); cout << "\n";
//	wypisz<piwo, 10>(cout, K6); cout << "\n";
//	wypisz<liczba_pierwsza, 10>(cout, K7); cout << "\n";
//
//
//
//
//
//
//	try {
//		while (true)
//			K1.pop();
//	}
//	catch (BrakDanych& e) {
//		cout << "K1 pusty: " << e.what() << endl;
//	}
//	try {
//		while (true)
//			K2.pop();
//	}
//	catch (BrakDanych& e) {
//		cout << "K2 pusty: " << e.what() << endl;
//	}
//	try {
//		while (true)
//			K3.pop();
//	}
//	catch (BrakDanych& e) {
//		cout << "K3 pusty: " << e.what() << endl;
//	}
//
//
//
//	system("pause");
//	return 0;
//}