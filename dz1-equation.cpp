#include <iostream>

using namespace std;

int main() {
    double b,c;
    cin >> b >> c;

    if (b != 0)
        cout << -c/b;
    else
        cout << "There's no solutions";

}
