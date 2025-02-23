/*15_01ex.cpp
Напишите программу, являющуюся примером применения алгоритма sort() к массиву типа float. Значения вводятся пользователем, результат работы выводится на экран.*/


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

float arrf[5];
cout << "Введите числа в массив (float):";
for (int j = 0; j < 5; j++)
	cin >> arrf[j];

sort(arrf, arrf + 5);
cout << "Отсортированный массив:";
for (int j = 0; j < 5; j++)
	cout << arrf[j] << ' '; 

cout << endl; system("pause"); return 0;
}
