/*15_07ex.cpp
В примере PLUSAIR мы показали применение версии accumulate() с четырьмя аргументами. Перепишите этот пример, используя версию с тремя аргументами.*/


#include <iostream>
#include <list>       
#include <numeric>  
using namespace std;

class airtime
{
private: 
  int hours, minutes;
public:
airtime() : hours(0), minutes(0) {}
airtime(int h, int m) : hours(h), minutes(m) {}

void display() const 
{ 
  cout << hours << ':' << minutes; 
}
void get() 
{ 
  char ch; 
  cout << "Введите время (формат 12:59): "; 
  cin >> hours >> ch >> minutes; 
}

airtime operator + (const airtime right) const
{
  int temph = hours + right.hours;
  int tempm = minutes + right.minutes;
  if (tempm >= 60) 
  {
    temph++; 
    tempm -= 60;
  }
  return airtime(temph, tempm);
}
bool operator == (const airtime& at2) const 
{
  return (hours == at2.hours) && (minutes == at2.minutes);
}
bool operator < (const airtime& at2) const 
{
  return (hours < at2.hours) || (hours == at2.hours && minutes < at2.minutes);
}
bool operator != (const airtime& at2) const 
{
  return !(*this == at2);
}
bool operator > (const airtime& at2) const 
{
  return !(*this < at2) && !(*this == at2);
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

char ch;
int x1, x2; 
airtime temp, sum;
list<airtime> airlist;
do 
{
  temp.get();
  airlist.push_back(temp);
  cout << "Продолжить? (y/n):";
  cin >> ch;
} while (ch != 'n');
cout << "Введите часы:"; 
cin >> x1; 
cout << "Введите минуты:";
cin >> x2;
sum = accumulate(airlist.begin(), airlist.end(), airtime(x1, x2));
cout << "\nСумма = "; 
sum.display(); 
cout << endl; 

cout << endl; system("pause"); return 0;
}
