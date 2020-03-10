#ifndef Menu_H
#define Menu_H
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

static class Menu {
private:
	static string menu_template;
public:
	static void prepare(vector<int> &mas);
	static void init(vector<int> mas);
	static void generate_array(vector<int>& mas, size_t n);
	static void type_array(vector<int>& mas, size_t n);
	static void show_array(vector<int>& mas, string message);

};

#endif // !Menu_H
