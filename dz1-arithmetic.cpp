#include <iostream>

using namespace std;

int main() {
    double a,b;
    cin >> a >> b;

    cout << "Sum: " << a + b << endl;
    cout << "Diminution: " << a - b << endl;
    cout << "Intersection: " << a * b << endl;
    if (b != 0)
        cout << "Partially: " << a / b;
    else
        cout << "Partially: None";

}
