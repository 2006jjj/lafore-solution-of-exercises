/*14_04ex.cpp
Создайте функцию swaps(), обменивающую значения двух аргументов, посылаемых ей. (Возможно, вы догадаетесь передавать эти аргументы по ссылке.)
Сделайте из функции шаблон, чтобы она могла использоваться с любыми числовыми типами данных (int, char, float и т.д.). Напишите main() для тестирования функции.*/

#include <iostream>
using namespace std;

template <class S>
void swaps(S& a, S& b)
{
	S temp;
	temp = a;  
	a = b;
	b = temp;
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int a1 = 5, a2 = 9;
cout << "a1=" << a1 << "\na2=" << a2 << endl; 
cout << "После перемещения:" << endl; 
swaps(a1, a2); 
cout << "a1=" << a1 << "\na2=" << a2 << endl;
 
float b1 = 1.5, b2 = 4.6;
cout << "b1=" << b1 << "\nb2=" << b2 << endl; 
cout << "После перемещения:" << endl; 
swaps(b1, b2); 
cout << "b1=" << b1 << "\nb2=" << b2 << endl; 

cout << endl; system("pause"); return 0;
}
