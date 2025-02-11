/*08_06ex.cpp
Добавьте в класс time из упр. 5 возможность вычитать значения времени, используя перегруженную операцию -, и умножать эти значения,
используя тип float и перегруженную операцию *.   */

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

time1 operator-(time1 t2) 
{
  long totalsecs = ((hours * 3600) + (minutes * 60) + seconds) - ((t2.hours * 3600) + (t2.minutes * 60) + t2.seconds);
  int h = totalsecs / (60 * 60);
  int m = totalsecs % (60 * 60) / 60;
  int s = totalsecs % (60 * 60) % 60;
  if (totalsecs < 0)
    return time1();
  return time1(h, m, s);
}

time1 operator*(time1 t2) 
{
  int d = 0; 
  long totalsecs = ((hours * 3600) + (minutes * 60) + seconds) * ((t2.hours * 3600) + (t2.minutes * 60) + t2.seconds);
  int h = totalsecs / (60 * 60);
  int m = totalsecs % (60 * 60) / 60;
  int s = totalsecs % (60 * 60) % 60;
  while (h >= 24) 
  { 
    d++; 
    h--; 
  }
  cout << "Days:" << d << endl;
  return time1(h, m, s);
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

time1 t1(3, 9, 22), t2(4, 12, 3), t3;
t1.display();
t2.display();
t3 = t1 + t2;
t3.display();
t3 = t1 - t2;
t3.display();
t3 = t1 * t2;
t3.display();

cout << endl; system("pause"); return 0;
}
