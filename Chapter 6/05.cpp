/*06_05ex.cpp
Взяв в качестве основы структуру из упр. 5 главы 4, создайте класс date. Его данные должны размещаться в трех полях типа int: month, day и year.
Метод класс getdate() должен принимать значение для объекта в формате 12/31/02, а метод showdate() - выводить данные на экран.*/

#include <iostream>
using namespace std;

char ch = '/';
class date 
{
private: 
  	int day, month, year;
public:
	date() : day(0), month(0), year(0) {}
	date(int y, int m, int d) : day(d), month(m), year(y) {}
void getdata()
{
	cout << "Введите дату в формате (xx/xx/xxxx):";
	cin >> day >> ch >> month >> ch >> year;
if ((month > 12) || (day > 31)) 
    { 
      cout << "ERROR!"; 
      exit(1); 
    }
}
void showdate() 
{ 
  cout << "Дата:" << day << ch << month << ch << year; 
}
};
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
date d1; 
d1.getdata(); 
d1.showdate(); 
 
cout << endl; system("pause"); return 0;
}
