#include <iostream>
#include <string>

using namespace std;

double repl(string question) {
    double temp;

    cout << question << endl << "> ";
    cin >> temp;

    return temp;

}

int main() {
    const double pi = 3.14;
    double R, r, l, h, V, S;

    R = repl("Radius of the upper base of the truncated cone (R)");
    r = repl("Radius of the lower base of the truncated cone (r)");
    l = repl("Truncated cone (l)");
    h = repl("Height (h)");

    V = ((double) 1 / (double) 3 * pi * h) * (R * R + R * r + r * r);
    S = pi * (R * R + (R + r) * l + r * r);

    cout << "V: " << V << endl << "S: " << S;



}
