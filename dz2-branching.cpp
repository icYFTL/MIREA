#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double w, x, a;

    cin >> x >> a;

    if (abs(x) < 1)
        w = a * log(abs(x));
    else {
        if (a - x * x < 0) {
            cout << "There's no solutions.";
            return 0;
        }
        w = sqrt(a - x * x);
    }

    cout << "W: " << w;


}
