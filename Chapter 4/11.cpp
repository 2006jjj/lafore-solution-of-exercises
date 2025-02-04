/*04_11ex.cpp
Используя структуру time из упр. 9, напишите программу, которая получает от пользователя два значения времени в формате 12:59:59, 
сохраняет их в переменных типа struct time, затем переводит оба значения в секунды, складывает их, переводит сумму в исходный формат,
сохраняет его в переменной типа time и выводит полученный результат на экран в формате 12:59:59 */

#include <iostream>
using namespace std;

struct time 
{ 
  int hours, minutes, seconds; 
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

time t1, t2, t3; 
char ch; 
int x=0;
cout << "Введите первое значение в формате(12:59:59): "; 
cin >> t1.hours >> ch >> t1.minutes >> ch >> t1.seconds;
cout << "Введите второе значение в формате(12:59:59): "; 
cin >> t2.hours >> ch >> t2.minutes >> ch >> t2.seconds;
x = (t1.hours * 3600 + t1.minutes * 60 + t1.seconds) + (t2.hours * 3600 + t2.minutes * 60 + t2.seconds);
cout << "Общее время в секундах:" << x << endl;
cout << "Результат=" << static_cast<int>(x / 3600) << ":" << (x % 3600) / 60 << ":" << (x % 3600) % 60 << endl; 

system("pause"); return 0;
}
