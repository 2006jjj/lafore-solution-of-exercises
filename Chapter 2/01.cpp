//02_01ex.cpp
//Считая, что кубический фут равен 7,481 галлона, написать программу, запрашивающую у пользователя число галлонов 
//и выводящую на экран эквивалентный объем в кубических футах.

#include <io.h> // для функции _setmode
#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
	float g;
	cout << "Введите количество галлонов:";
	cin >> g;
	cout << "\nОбъем в кубических футах=" << g / 7.481 << endl; 
 
system("pause"); return 0;
}
