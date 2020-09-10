// THIS SOLUTION USES OOP. IT'S NOT PROCEDURE PROGRAMMING.
// USE LAZAREV_T's SOLUTION INSTEAD.

#define FILENAME "task.txt"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <random>
#include <regex>
#include <stdio.h>

using namespace std;

class File {
public:
	virtual void create(vector<string> a) = 0;
	virtual vector<int> get() = 0;

};

class RoutineIO : public File {
public:
	void create(vector<string> a) override {
		ofstream fout(FILENAME, ios::trunc);
		for (string str : a)
			fout << str << endl;
		fout.close();
	}
	vector<int> get() override {
		ifstream fin(FILENAME);
		string str;
		vector<int> out_data;
		while (fin >> str) {
			smatch m;
			regex e("^[0-9]+$", regex::icase);
			if (regex_search(str, m, e)) {
				for (string ans : m)
					out_data.push_back(stoi(ans));

			}
		}
		return out_data;
	}

	void clear() {
		remove(FILENAME);
	}

};

class RoutineMT {
public:
	vector<string> get_random_nums() {
		srand(time(NULL));
		vector<string> nums;

		for (int i = 0; i < 10; ++i)
			nums.push_back(to_string(0 + rand() % (1000 - 0)));

		return nums;
	}

	void show(vector <int> a) {
		int sum = 0;
		cout << "Massive: ";
		for (int val : a) {
			cout << val << " ";
			sum += val;
		}
		cout << endl;
		
		cout << "Sum: " << sum;

	}
};

int main() {
	RoutineMT RMT;
	RoutineIO RIO;

	RIO.create(RMT.get_random_nums());

	RMT.show(RIO.get());

	RIO.clear();

}
