/*05_03ex.cpp
Напишите функцию с именем zeroSmaller(), в которую передаются с помощью ссылок два аргумента типа int, присваивающую меньшему из аргументов нулевое значение.
Напишите программу для проверки работы функции. */

#include <iostream>
using namespace std;

void zeroSmaller(int&, int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
int a=2, b=5, c=6, d=3;
zeroSmaller(a, b); 
cout << "a=" << a << " b=" << b;
zeroSmaller(c, d); 
cout << "\nc=" << c << " d=" << d << endl;
	
system("pause"); return 0;
}

void zeroSmaller(int& x, int& y) 
{
	if (x < y) x = 0;
	else y = 0;
}
