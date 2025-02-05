/*05_08ex.cpp
Напишите функцию с именем swap(), обменивающую значениями два своих аргумента типа int (обратите внимание, что изменяться должны значения переменных из вызывающей программы,
а не локальных переменных функции). Выберите способ передачи аргументов. Напишите вызывающую программу main(), использующую данную функцию.*/

#include <iostream>
using namespace std;

void swap(int&, int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int x = 12, y = 6;
swap(x, y);
cout << "\nx=" << x << " y=" << y << endl;

system("pause"); return 0;
}

void swap(int& a, int& b) 
{ 
  int temp = a; 
  a = b; 
  b = temp; 
}
