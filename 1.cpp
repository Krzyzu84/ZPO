#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

struct greater {
	bool operator()(const string &a, const string &b) {
		return a.size() < b.size();
	}
};

struct sortkolej{
	bool operator()(priority_queue<string, vector<string>, greater>  &a,priority_queue<string, vector<string>, greater>  &b){
		return a.size() < b.size();
}
};

typedef list < priority_queue<string, vector<string>, greater> > P;


class FileEditor :
	public P {
public:

	void open(const char* filename);
	FileEditor(const char* filename)
	{
		open(filename);
	};
	FileEditor() {};
	~FileEditor() {
	
		for (P::iterator it = p.begin(); it != p.end(); it++) {
			while (!it->empty()) {
				it->pop();
			}
		}
	}
	void write(std::ostream& out =
		std::cout);

	void execute() {
		p.sort(sortkolej());
	}
private:
	P p;
};


//ostream & operator<<(ostream &os, priority_queue<string, vector<string>, greater> a) {
//	os << a.size() << ": ";
//	while (!a.empty())
//	{
//		os << a.top << " ";
//		a.pop();
//	}
//}


ostream & operator<<(ostream & os, P a) {
	for (P::iterator it = a.begin(); it != a.end(); it++) {
		os << it->size() << ": ";
		while (!it->empty()) {
			os << it->top() << " ";
			it->pop();
		}
		os << endl;
	}
	return os;
}
void FileEditor::open(
	const char* filename) {
	ifstream in(filename);
	string line;
	while (getline(in, line)) {
		if (line == "")
			continue;
		stringstream ss(line);
		string word;
		priority_queue<string, vector<string>, greater> a;

		while (ss >> word) {
			a.push(word);
		}

		p.push_back(a);

	}

};


void FileEditor::write(
	ostream& out) {

	out << p << endl;
};

int main() {
	FileEditor a;
	a.open("mustafa.txt");
	a.execute();
	ofstream of("FINALNY.txt");
	a.write(of);
	
}