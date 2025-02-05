/*05_07ex.cpp
Взяв в качестве основы функцию power() из упр. 2, работающую только со значением типа double, создайте перегруженные функции с этим же именем,
принимающими в качестве аргумента значения типа char, int, long и float. Напишите программу, вызывающую функцию power() со всеми возможными типами аргументов.*/

#include <iostream>
using namespace std;

double power(double, int);
double power(double, long);
double power(double, float);
double power(double, char);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
cout << "Первая функция:" << power(3.0, 2);
cout << "\nВторая функция:" << power(3.0, 3);
cout << "\nТретья функция:" << power(3.0, 4.0F);
cout << "\nЧетвертая функция:" << power(3.0, (char)(34 - ' ')) << endl;
			
system("pause"); return 0;
}
double power(double n, int p) 
{ 
  double result = 1.0; 
  for (int j = 0; j < p; j++) 
    result *= n; 
  return result; 
}

double power(double n, long p) 
{ 
  double result = 1.0; 
  for (int j = 0; j < p; j++) 
    result *= n; 
  return result; 
}

double power(double n, float p) 
{ 
  double result = 1.0; 
  for (int j = 0; j < p; j++) 
    result *= n; 
  return result; 
}

double power(double n, char p) 
{ 
  double result = 1.0; 
  for (int j = 0; j < (int)p; j++) 
    result *= n; 
  return result; 
}
