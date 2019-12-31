#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    string word;

    getline(cin, word);
    vector<int> chars;

    for (char s : word)
        chars.push_back(int(s));

    sort(chars.begin(), chars.end());

    for (int i : chars)
        cout << char(i);

}
