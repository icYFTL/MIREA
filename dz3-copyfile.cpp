#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void create_and_fill() {
    ofstream fout;
    fout.open("task.txt");
    fout << "123";
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

void show(vector<string> data){
    for (string str : data)
        cout << str << endl;
}

int main() {
    // Вообще этого не должно быть и файл должен создать сам, но если в падлу создавать
    //create_and_fill();

    //Вывод
    show(get());



}
