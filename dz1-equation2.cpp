#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double d = b * b - 4 * a * c;

    if (d < 0)
        cout << "No solutions.";
    if (d == 0)
        cout << "X: " << -b/(2 * a);
    if (d > 0) {
        cout << "X1: " << (-b + sqrt(d)) / (2 * a) << endl;
        cout << "X2: " << (-b - sqrt(d)) / (2 * a);
    }


}
