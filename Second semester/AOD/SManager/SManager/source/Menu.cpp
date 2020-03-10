#define CIN_FLUSH if (cin.peek()) cin.ignore();
#define HIGH_RANDOM_LIMIT 100
#define LOW_RANDOM_LIMIT -100

#include "Menu.h"
#include "Console.h"
#include "Sorts.h"

void Menu::init(vector<int> mas) {
	cout <<
		"# Ordo #\n"
		"1 - Bubble sort\n"
		"2 - Insertion sort\n"
		"3 - Selection sort\n"
		"4 - Shell sort\n"
		"5 - Shaker sort\n"
		"6 - Merge sort\n"
		"7 - Natural merge sorting\n"
		"8 - Back";

	char _t = '-';

	do {
		cout << "\n> ";
		cin >> _t;
		CIN_FLUSH;
	} while (_t != '1' && _t != '2' && _t != '3' && _t != '4' && _t != '5' && _t != '6' && _t != '7' && _t != '8');

	if (_t == '8') {
		mas.clear();
		Console::clear();
		Menu::prepare(mas);
		return;
	}

	Sorts _sorts(mas);
	vector<int> _temp;

	show_array(mas, "Initial array: ");
	cout << "\n";

	switch (_t) {
	case '1':
		_temp = _sorts.bubble();
		show_array(_temp, "# Bubble sort #");
		break;
	case '2':
		_temp = _sorts.insertion();
		show_array(_temp, "# Insertion sort #");
		break;
	case '3':
		_temp = _sorts.selection();
		show_array(_temp, "# Selection sort #");
		break;
	case '4':
		_temp = _sorts.shell();
		show_array(_temp, "# Shell sort #");
		break;
	case '5':
		_temp = _sorts.shaker();
		show_array(_temp, "# Shaker sort #");
		break;
	case '6':
		_temp = _sorts.merge();
		show_array(_temp, "# Merge sort #");
		break;
	case '7':
		//_sorts.natural_merge_sort();
		break;
		
	}
	cout << "\nEstimated time: " << _sorts.estimated_time << " sec.";
	cout << "\n\nPress any button to continue";
	cout << '\a';
	cin.get();
	Console::clear();

}

void Menu::prepare(vector<int>& mas) {
	cout << "# Ordo #\n"
		"1 - Type a massive manually\n"
		"2 - Generate an array\n"
		"3 - Exit";

	char _t = '-';

	do {
		cout << "\n> ";
		cin >> _t;
		CIN_FLUSH;
	} while (_t != '1' && _t != '2' && _t != '3');

	if (_t == '3')
		exit(0);

	int n;
	cout << "Give me the count of array's cells";
	do 
	{
		cout << "\n> "; 
		cin >> n;
	} while (n <= 0);





	if (_t == '1')
		type_array(mas, n);
	if (_t == '2')
		generate_array(mas, n);

	show_array(mas, "Massive is:");

	cout << "\nPress any button to continue";
	cin.get();
	CIN_FLUSH;

	Console::clear();

	while (1)
		init(mas);
}

void Menu::show_array(vector<int>& mas, string message) {
	cout << message << "\n";

	if (mas.size() < 11)
		for (int i : mas)
			cout << i << " ";
	else {
		for (size_t i = 0; i < 5; ++i)
			cout << mas[i] << " ";
		cout << " ... ";
		for (size_t i = mas.size() - 6; i < mas.size() - 1; ++i)
			cout << mas[i] << " ";
	}

}


void Menu::type_array(vector<int>& mas, size_t n) {
	int _t;
	for (size_t i = 0; i < n; ++i) {
		cout << "[" << i << "]: ";
		cin >> _t;
		mas.push_back(_t);
		cout << "\n";
	}
}

void Menu::generate_array(vector<int>& mas, size_t n) {
	srand(time(NULL));
	for (size_t i = 0; i < n; ++i)
		mas.push_back(LOW_RANDOM_LIMIT + rand() % (HIGH_RANDOM_LIMIT - LOW_RANDOM_LIMIT + 1));
}