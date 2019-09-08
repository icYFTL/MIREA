#include <iostream>
#include <string>
#include <map>

using namespace std;

map <char, int> rims = { pair<char, int>('I', 1), pair<char, int>('V', 5), pair<char, int>('X', 10), pair<char, int>('L', 50), pair<char, int>('C', 100), pair<char, int>('D', 500), pair<char, int>('M', 1000) };

int decode(string data) {
	int output = 0;
	for (char s : data) {
		output += rims[s];
	}
	return output;
}

int main() {
	string x;
	getline(cin, x);
	cout << decode(x);
}

