/*06_03ex.cpp
Создайте класс с именем time, содержащий три поля типа int, предназначенные для хранения часов, минут и секунд. Один из конструкторов класса должен 
инициализировать поля с нулевыми значениями, а другой конструктор - заданным набором значений. Создайте метод класса, который будет выводить значения полей на экран в формате 11:59:59,
и метод, складывающий значения двух объектов типа time, передаваемых в качестве аргументов.
В функции main() следует создать два инициализированных объекта (подуймате, должны ли они быть константными) и один неинициализированный объект. Затем сложите два инициализированных значения,
а результат присвойте третьему объекту и выведите его значение на экран. Где возможно, сделайте методы константными.*/

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
void sumtime(time1 t1, time1 t2)
{
hours += t1.hours + t2.hours; minutes += t1.minutes + t2.minutes; seconds = t1.seconds + t2.seconds;
	if (seconds > 59) 
	{
		minutes++;
		seconds -= 60; 
	}
	if (minutes > 59) 
	{
		hours++; 
		minutes -= 60; 
	}
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
const time1 t1(14, 43, 11), t2(3, 45, 23), t3;
t1.display(); 
t2.display();
t3.sumtime(t1, t2); 
t3.display();

cout << endl; system("pause"); return 0;
}
