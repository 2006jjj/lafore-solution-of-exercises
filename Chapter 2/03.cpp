//02_03ex.cpp
//Напишите программу, генерирующую следующий вывод:
//10
//20
//19
//Используйте представление числа 10 в виде целой константы. 
//Для вывода числа 20 воспользуйтесь одной из арифметических операций с присваиванием, 
//а для вывода числа 19 - операцией декремента.

#include <io.h>
#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
	int  a = 10; cout << a << endl;
	a *= 2; cout << a << endl;
	cout << --a << endl;
 
system("pause"); return 0;
}
