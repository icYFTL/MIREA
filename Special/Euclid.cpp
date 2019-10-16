#include <iostream>

using namespace std;

int eq(int a, int b) {
    if (b == 0)
        return a;

    return eq(b, a % b);
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << eq(a,b);
}

