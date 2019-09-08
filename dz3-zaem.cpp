#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long S, n;
    long double p, r, m;

    cin >> S >> p >> n;

    r = p / 100;

    m = (S * r * pow((1 + r), n)) / (12 * ((pow((1 + r), n) - 1)));

    cout << m;
}
