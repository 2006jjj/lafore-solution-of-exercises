/*08_03ex.cpp
Модифицируйте класс time из упр. 3 главы 6 так, чтобы вместо метода add_time() можно было использовать операцию + для складывания двух значений времени.
Напишите программу для проверки класса.*/

#include <iostream>
using namespace std;

class time1 
{
private:
	int hours, minutes, seconds;
public:
time1() : hours(0), minutes(0), seconds(0) {}
time1(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
void display() const 
{ 
  cout << "Время: " << hours << ":" << minutes << ":" << seconds << endl; 
}
time1 operator+(time1 t2) 
{
  int h = hours + t2.hours;
  int m = minutes + t2.minutes;
  int s = seconds + t2.seconds;
  if (s > 59) 
  { 
    s -= 60; 
    m++; 
  }
  if (m > 59) 
  { 
    m -= 60; 
    h++; 
  }
  return time1(h, m, s);
}
};
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

time1 t1(14, 43, 11), t2(3, 45, 23), t3;
t1.display();  
t2.display();
t3 = t1 + t2; 
t3.display(); 

cout << endl; system("pause"); return 0;
}
