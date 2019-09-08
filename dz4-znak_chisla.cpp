#include <iostream>

using namespace std;

int signx(int x) {
	if (x < 0)
		return -1;
	if (x == 0)
		return 0;
	else
		return 1;
}

int main() {
	int x;
	cin >> x;
	cout << signx(x);
}