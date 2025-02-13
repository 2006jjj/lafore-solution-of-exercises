/*10_01ex.cpp
Напишите программу, которая принимает группу чисел от пользователя и помещает их в массив типа float. После того как числа будут помещены в массив, программа
должна подсчитать их среднее арифметическое и вывести результат на дисплей. Используйте указатели везде, где только возможно.*/

#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int MAX = 10;
float arr[MAX], average=0.0, sum = 0.0; 
int num = 0; 
char ch;
cout << "Введите числа которые будут помещены в массив:";
do 
{
  cout << "\nВведите число:"; 
  cin >> *(arr + num++);
  cout << "Продолжить? (y/n):"; 
  cin >> ch;
} while (ch != 'n');
 
for (int j = 0; j < num; j++)
	sum += *(arr + j);
cout << sum; 
average = sum / num; 
cout << "\nAverage=" << average; 

cout << endl; system("pause"); return 0;
}
