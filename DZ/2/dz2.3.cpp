#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x,y,b,z;

    cin >> x >> y >> b;

    try{
        z = log(b-y) * sqrt(b-x);
        if (isnan(z))
            cout << "There's no solutions";
        else
            cout << z;
    }
    catch (int a){
        cout << "There's no solutions";
        return 0;
    }





}
