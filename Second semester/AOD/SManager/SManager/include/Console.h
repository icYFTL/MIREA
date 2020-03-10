#ifndef Console_H
#define Console_H
#include <string>

using namespace std;

static class Console {
public:
	static void clear();
private:
	static string get_os();
	Console() {};

};

#endif