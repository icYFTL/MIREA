#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	double s, m, n, p = 1;
	
	cout << "Величина ссуды -> "; cin >> s;
	cout << "Ежемесячный платёж -> "; cin >> m;
	cout << "Срок погашения ссуды -> "; cin >> n;
	
	while ((s * (p / 100) * pow(1 + p / 100, n)) / (12 * (pow(1 + p / 100, n) - 1)) < m) p += 0.1;
	cout << p;
	return 0;
}
