#include <iostream>
#include <string>
#include <map>

using namespace std;

int fromRoman(string n)
{
map<char, int> m;
m['I'] = 1;
m['V'] = 5;
m['X'] = 10;
m['L'] = 50;
m['C'] = 100;
m['D'] = 500;
m['M'] = 1000;

int tmp = 0;
int res = 0;
// Проходимс по всем эл-там
for (char c : n)
{
//Превращаем символ в число
int n = m[c];
if (n < tmp)
{
// Если идем на уменьшение то прибавляем
res += tmp;
tmp = n;
}
else if (n > tmp)
{
// Если временная переменная равна нулю , то просто присваиваем значение
if (tmp == 0)
tmp = n;
else
{
// Если значение меньше временной , то просто отнимаем
res += n - tmp;
tmp = 0;
}
}
else if (n == tmp)
{
// Если переменные равны ,то просто их складываем
res += tmp + n;
tmp = 0;
}
}
return res + tmp;
}

int main()
{
const char* romanNumbers[] = {
// Ввод значений
"IIIIIIII",
"IIII",
"VIII",
"IX",
"XXXI",
"XLVI",
"XCIX",
"DLXXXIII",
"DCCCLXXXVIII",
"MDCLXVIII",
"MCMLXXXIX",
"MMX",
"MMXI",
"MMXII",
"MMMCMXCIX"

};
//Проходимся по циклу
for (auto r : romanNumbers)
cout << r << " is " << fromRoman(r) << endl;
}