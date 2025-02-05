/*05_04ex.cpp
Напишите функцию, принимающую в качестве аргументов два значения типа Distance и возвращающую значение наибольшего из аргументов.*/

#include <iostream>
using namespace std;

struct Distance 
{ 
  int feet; 
  float inches; 
};
Distance srav(Distance, Distance);
void print(Distance);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Distance d1, d2, d3;	
cout << "Введите число футов: "; 
cin >> d1.feet;
cout << "Введите количество дюймов: "; 
cin >> d1.inches;
cout << "Введите число футов: "; 
cin >> d2.feet;
cout << "Введите количество дюймов: "; 
cin >> d2.inches;
d3 = srav(d1, d2);
cout << "D1= "; print(d1);
cout << "\nD2= "; print(d2);
cout << "\nD3= "; print(d3);
			
cout<<endl; system("pause"); return 0;
}
Distance srav(Distance dd1, Distance dd2) 
{
	if (dd1.feet > dd2.feet) 
		return dd1;
	else return dd2;
	if (dd1.inches > dd2.inches) 
		return dd1;
	else return dd2;
}
void print(Distance dd) 
{
	cout << dd.feet << "\'-" << dd.inches << "\"";
}
