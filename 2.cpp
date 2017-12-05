//#include <iostream>
//#include <queue>
//#include <list>
//#include <algorithm>
//#include <sstream>
//#include <fstream>
//
//using namespace std;
//
//struct greater {
//	bool operator()(list<string> &a, list<string> &b) {
//		return a.size() > b.size();
//	}
//};
//
//typedef priority_queue<list<string>, vector<list<string>>, greater >  P;
//
//bool g6(string v) {
//	return v.size() > 6;
//}
//
//
//class FileEditor :
//	public P {
//	P p;
//	static int ile;
//public:
//	void open(const char* filename);
//	FileEditor(const char* filename)
//	{
//		open(filename);
//	};
//	FileEditor() {};
//	~FileEditor(){
//
//
//		while (!p.empty()) {
//
//			cout << "DESTRUKTOR" << endl;
//			/*cout << p.top();*/
//
//			p.pop();
//		}
//
//		
//	};
//	void write(std::ostream& out =
//		std::cout);
//	void execute() {
//		P a(p);
//
//		while (!a.empty()) {
//			list<string> b = a.top();
//
//			ile += count_if(b.begin(), b.end(), g6);
//
//			a.pop();
//
//		}
//		cout << "Ile wynosi " << ile << endl;
//	}
//};
//
//
//ostream & operator <<(ostream &out, list<string> a) {
//		out << a.size() << ": ";
//		for (list<string>::iterator it = a.begin(); it != a.end(); it++) {
//		out << *it << " ";
//	}
//		return out;
//}
//
//
//ostream & operator <<(ostream &out, P a ) {
//	
//
//	while (!a.empty()) {
//		out << a.top() << endl;
//		a.pop();
//	}
//	return out;
//}
//
//
//void FileEditor::open(
//	const char* filename) {
//	ifstream in(filename);
//	
//
//	if (!in.is_open()) {
//		exit(EXIT_FAILURE);
//	}
//
//	string line;
//	while (getline(in, line)) {
//
//		if (line == "")
//			continue;
//		stringstream ss(line);
//		list<string> a;
//		string word;
//		while (ss >> word) {
//			a.push_back(word);
//		}
//		p.push(a);
//	}
//		
//};
//void FileEditor::write(
//	ostream& out) {
//	out << p << endl;
//	
//};
//
//
//int FileEditor::ile = 0;
//
//int main() {
//	FileEditor a;
//	a.open("mustafa.txt");
//	ofstream of("0.txt");
//	a.execute();
//	a.write(cout);
//	
//}