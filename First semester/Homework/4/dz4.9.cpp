// THIS SOLUTION USES OOP. IT'S NOT PROCEDURE PROGRAMMING.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void clear() {
	for (int i = 0; i < 32; ++i) {
		cout << endl;
	}
}

class Notation {
private:
	string number;
	int current_n, next_n;

	int symb_to_dec(char symb) {
		return int(symb) - 87;
	}

	int to_dec() {
		int sum = 0, iterator = 1;
		for (char k : number) {
			if (int(k) > 47 && int(k) < 58) {
				int num = static_cast<int>(k) - '0';
				sum += num * pow(current_n, number.length() - iterator);
			}
			else {
				int num = symb_to_dec(k);
				sum += num * pow(current_n, number.length() - iterator);
			}
			iterator++;

		}
		return sum;
	}

	string routine() {
		char buff[256];
		_itoa(to_dec(), buff, next_n);

		string repl = "";
		for (char k : buff) {
			if (k == '\0')
				break;
			repl += k;
		}
		transform(number.begin(), number.end(), number.begin(), [](unsigned char c) { return std::toupper(c); });
		return repl;
	}
public:
	Notation(string number, int current_n, int next_n) {
		this->number = number;
		this->current_n = current_n;
		this->next_n = next_n;
	}

	string answer() {
		return routine();
	}
};


int main() {
	string number;
	int current, next;
	
	cout << "Give me a number: " << endl << "> ";
	getline(cin, number);

	cout << "Give me the current number system: " << endl << "> ";
	cin >> current;

	cout << "Give me the next number system: " << endl << "> ";
	cin >> next;

	transform(number.begin(), number.end(), number.begin(), [](unsigned char c) { return std::tolower(c); });

	Notation notate(number, current, next);
	
	cout << endl << endl << "Number in " << current << " number notation: " << number << endl << "Number in " << next << " number notation: " << notate.answer();
	clear();

}
