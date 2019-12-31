#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

const double pi = 3.14;

bool is_digits(const std::string& str)
{
	return std::all_of(str.begin(), str.end(), ::isdigit);
}

vector<double> get(vector<string> requests) {
	vector<double> a;
	string inp;
	for (string req : requests) {
		do {
			cout << req << endl << "> ";
			cin >> inp;
			
		} while (!is_digits(inp));
		a.push_back(stoi(inp));
	}

	return a;
}

void rectangle() {
	vector<string> requests = {"Insert a-side of rectangle", "Insert b-side of rectangle"};
	vector<double> data = get(requests);

	cout << "S of rectangle = " << data[0] * data[1];
}

void triangle() {
	vector<string> requests = { "Insert b-side of triangle", "Insert height of triangle" };
	vector<double> data = get(requests);

	cout << "S of triangle = " << data[0] * data[1] * 0.5;
}

void circle() {
	vector<string> requests = { "Insert radius of circle"};
	vector<double> data = get(requests);

	cout << "S of circle = " << pi * data[0] * data[0];
}

void identify(char choise) {
	switch (choise) {
	case '1':
		rectangle();
		break;
	case '2':
		triangle();
		break;
	case '3':
		circle();
		break;
	}
	
}

void menu() {
	char ans;
	do {
		cout << "Write me\n1 - Find rectangle S\n2 - Find triangle S\n3 - Find circle S\n> ";
		cin >> ans;
	} while (ans != '1' && ans != '2' && ans != '3');

	identify(ans);

	
}



int main() {
	menu();
}