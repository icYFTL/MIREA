#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	ofstream fout("data.txt");
	
	if (!fout.is_open()) 
		cout << "Ошибка! Файл не может быть открыт.";
	else
	{
		fout << "1 5 7 1 9 3 4 8 1 3";
		fout.close();
	}
	
	ifstream fin("data.txt");
	float sum = 0, sum_tmp;
	
	if (!fin.is_open()) 
		cout << "Ошибка! Файл не может быть открыт.";
	else 
		while (fin >> sum_tmp)
			sum += sum_tmp; 
	cout << "Сумма чисел из файла: " << sum;
	return 0;
}
