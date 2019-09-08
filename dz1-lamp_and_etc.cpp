#include <iostream>
#include <string>

using namespace std;

char answer(const string question){
    char temp;
    do {
        cout << question << endl << "> ";
        cin >> temp;
    }
    while(temp != 'y' && temp != 'n');

    return temp;
}

int main() {
    char light, sun, curtains;
    bool result = false;

    sun = answer("Is it light outside? (y/n)");
    curtains = answer("Curtains open? (y/n)");
    light = answer("Is lamp works? (y/n)");

    cout << endl;

    if (sun == 'y' && curtains == 'y')
        result = true;
    if (light == 'y')
        result = true;

    cout << "RESULT: ";
    result ? cout << "+" : cout << "-";

}
