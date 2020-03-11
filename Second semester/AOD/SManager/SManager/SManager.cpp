// SManager.cpp : Defines the entry point for the application.
//

#include "SManager.h"

using namespace std;

int main() {
#ifdef _WIN32 || _WIN64
    SetConsoleTitle("SManager");
#endif
#ifdef _DEBUG
	cout << "DEBUG MODE ACTIVATED.\nSorts will work slowly.\nWanna continue?(y/n)";
	char _ans;
	do {
		cout << "\n> ";
		cin >> _ans;
	} while (tolower(_ans) != 'y' && tolower(_ans) != 'n');
	if (_ans == 'n')
		exit(0);
	Console::clear();
#endif

	vector <int> a;
	Menu::prepare(a);
}







