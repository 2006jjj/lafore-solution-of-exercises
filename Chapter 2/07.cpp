//02_07.cpp
//Температуру, измеренную в градусах по Цельсию, можно перевести в градусы по Фаренгейту путем умножения на 9/5 и сложения с числом 32.
//Напишите программу, запрашивающую температуру в градусах по Цельсию и отображающую ее эквивалент по Фаренгейту.

#include <iostream>
using namespace std;
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

float t = 0.0;
cout << "Введите температу по Цельсию:";
cin >> t;
cout << "Температура по Фаренгейту=" << t * 9 / 5 + 32<<endl; 
	
system("pause"); return 0;
}
