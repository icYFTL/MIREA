#include "Console.h"

string Console::get_os() {
#ifdef _WIN32 || _WIN64
    return "Windows";
#elif __linux__
    return "Linux";
#endif
    return "Undefined";
}

void Console::clear() {
    if (get_os() == "Windows")
        system("cls");
    else
        system("clear");
}
