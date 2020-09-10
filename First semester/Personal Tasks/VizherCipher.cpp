// THIS SOLUTION USES OOP. IT'S NOT PROCEDURE PROGRAMMING.

#define CIN_FLUSH if (std::cin.peek()) std::cin.ignore()

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <regex>

using namespace std;

class VizhinerCipher {
private:
	char en_alpha[26][26];
	string newkey = "";

	string key_modifier(string key, int len) {
		
		const regex e("[^a-z]+");
		key = regex_replace(key, e, "");

		if (len > key.length()) {
			newkey = key;
			int iterator = 0;

			while (newkey.length() != len) {
				newkey += key[iterator];
				iterator++;
				if (iterator >= key.length())
					iterator = 0;
			}
		}
		else {
			int iterator = 0;
			while (newkey.length() != len) {
				newkey += key[iterator];
				iterator++;
			}

		}
		

		return newkey;
	}
	void construct_alpha(string alpha) {

		if (alpha == "en") {
			int start_point = 97, iterator = 0;
			for (int i = 0; i < 26; ++i) {
				iterator = start_point;
				for (int j = 0; j < 26; ++j) {
					this->en_alpha[i][j] = char(iterator);
					iterator++;
					if (iterator > 122)
						iterator = 97;
				}
				start_point++;
			}
		}

	}
public:
	string encrypt(string key, string text) {
		key = key_modifier(key, text.length());
		this->construct_alpha("en");

		string encrypted = "";

		for (int i = 0; i < key.length(); ++i) {
			if (int(text[i]) > 96 && int(text[i]) < 123)
				encrypted += this->en_alpha[int(key[i]) - 97][int(text[i] - 97)];
			else
				encrypted += text[i];
		}
		return encrypted;
	}

	string decrypt(string key, string text) {
		key = key_modifier(key, text.length());
		this->construct_alpha("en");

		string decrypted = "";

		for (int i = 0; i < key.length(); ++i) {
			if (int(key[i]) > 96 && int(key[i]) < 123 && int(text[i]) > 96 && int(text[i]) < 123) {
				int temp_index = 0;
				for (int j = 0; j < 26; ++j)
					if (this->en_alpha[int(key[i]) - 97][j] == text[i]) {
						temp_index = j;
						break;
					}

				decrypted += this->en_alpha[0][temp_index];
			}
			else
				decrypted += text[i];




		}
		return decrypted;

	}


};

char asciitolower(char in) {
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}

void routine() {
	char ans;
	cout << "Welcome to Vizher Cipher Tool" << endl << endl;
	cout << "Now you can:" << endl << "1 - Encrypt text" << endl << "2 - Decrypt text";
	do {
		cout << endl << "> ";
		cin >> ans;
		CIN_FLUSH;
	} while (ans != '1' && ans != '2');

	string key;
	string text;
	VizhinerCipher VC;

	if (ans == '1') {

		cout << endl;

		cout << "Give me the key:" << endl << "> ";
		getline(cin, key);

		cout << "Give me the text to encrypt: " << endl << "> ";
		getline(cin, text);


		transform(key.begin(), key.end(), key.begin(), asciitolower);
		transform(text.begin(), text.end(), text.begin(), asciitolower);

		cout << "Encrypted: " << VC.encrypt(key, text);

	}
	if (ans == '2') {
		cout << endl;

		cout << "Give me the key:" << endl << "> ";
		getline(cin, key);


		cout << "Give me the text to decrypt: " << endl << "> ";
		getline(cin, text);

		transform(key.begin(), key.end(), key.begin(), asciitolower);
		transform(text.begin(), text.end(), text.begin(), asciitolower);

		cout << "Decrypted: " << VC.decrypt(key, text);
	}

}

int main() {

	routine();

}