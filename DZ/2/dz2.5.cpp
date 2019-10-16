#include <iostream>

using namespace std;

int main() {
    double x;

    for (x = -4; x <= 4; x += 0.5) {
        if (x - 1 == 0) {
            cout << "Using x= " << x << " : " << "Undefined" << endl;
            continue;
        }
        cout << "Using x= " << x << " : " << (x * x - 2 * x + 2) / (x - 1) << endl;
    }


}
