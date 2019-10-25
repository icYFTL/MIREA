#include <iostream>

using namespace std;

int main()
{
	long int m = 37, S, i = 3, c = 64;
	//long int m = 25173, S, i = 13849, c = 65537;
	S = ((m + i) % c);
	
	for (i = 3; i <= 15; i++)
	{
		S = ((m * S + i) % c);
		cout << S << endl;
	}
	return 0;
}