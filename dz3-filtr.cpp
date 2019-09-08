#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

void create_and_fill() {
	ofstream fout;
	fout.open("task.txt");
	fout << "123\nsfdsfd\n12d3\n123ddsa\n1f3d";
	fout.close();
}

vector<string> get() {
	ifstream fin;
	vector<string> data;
	string str;
	fin.open("task.txt");
	while (fin >> str) {
		data.push_back(str);
	}
	fin.close();

	return data;

}

vector<string> get_nums(vector<string> data) {
	vector<string> out_data;
	for (string str : data) {
		smatch m;
		regex e("^[0-9]+$", regex::icase);
		if (regex_search(str, m, e)) {
			for (string ans : m)
				out_data.push_back(ans);

		}
	}
	return out_data;

}

void show(vector<string> data) {
	for (string str : data)
		cout << str << endl;
}

int main() {
	// Вообще этого не должно быть и файл должен создать сам, но если в падлу создавать
	create_and_fill();

	//Вывод.
	show(get_nums(get()));


}
