/*05_05ex.cpp
Напишите функцию с именем hms_to_secs(), имеющую три аргумента типа int: часы, минуты и секунды.
Функция должна возвращать эквивалент переданного ей временнного значения в секундах (типа long). Создайте программу, которая будет циклически запрашивать 
у пользователя ввод значения часов, минут и секунд и выводить результат работы функции на экран.*/

#include <iostream>
using namespace std;

long hms_to_secs(int, int, int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

char ch; 
int hours=0, minutes=0, seconds=0; 
long res=0;
do
{
	cout << "Введите время в формате (12:59:59):"; 
  cin >> hours >> ch >> minutes >> ch >> seconds;
	res = hms_to_secs(hours, minutes, seconds); 
  cout << "Result:" << res << " seconds" << endl;
	cout << "Продолжить (y/n)? "; 
  cin >> ch;
} while (ch != 'n');

system("pause"); return 0;
}

long hms_to_secs(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}
