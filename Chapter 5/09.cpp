/*05_09ex.cpp
Переработайте программу из упр. 8 так, чтобы функция swap() принимала в качестве аргументов значения типа time (см. упр. 6).*/

#include <iostream>
using namespace std;

struct time1 
{ 
  int hours, minutes, seconds; 
};
void swap(time1&, time1&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

time1 t1 = {11,43,33}, t2 = {6,23,12}; 
char ch=':';
swap(t1, t2);
cout << "Первое время:" << t1.hours << ch<<t1.minutes<<ch<<t1.seconds << endl;
cout << "Второе время:" << t2.hours << ch << t2.minutes << ch << t2.seconds << endl;

system("pause"); return 0;
}
void swap(time1& t1, time1& t2) 
{ 
  time1 t3 = t1; 
  t1 = t2; 
  t2 = t3; 
}
