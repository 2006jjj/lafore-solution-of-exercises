/*03_08ex.cpp
Напишите программу, которая циклически будет запрашивать ввод пользователем двух денежных сумм, выраженных в фунтах, шиллингах и пенсах (см. упр. 10 и 12 главы 2).
Программа должна складывать введенные суммы и выводить на экран результат, также выраженный в фунтах, шиллингах и пенсах. После каждой итерации программа должна спрашивать пользователя,
желает ли он продолжать работу программы. При этом рекомендуется использовать цикл do. Естественной формой взаимодействия программы с пользователем была бы следующая:
  Введите первую сумму: J5.10.6
  Введите вторую сумму: J3.2.6
  Всего: J8.13.0
  Продолжить(y/n)?  */


#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
	
  char c; 
  int f1=0, f2=0, sh1=0, sh2=0, p1=0, p2=0;
do
{
	cout << "Введите первую сумму: J";
	cin >> f1>>c>>sh1>>c>>p1;
	cout << "Введите вторую сумму: J";
	cin >> f2 >> c >> sh2 >> c >> p2;
	f1 += f2; sh1+= sh2; p1 += p2;
	while (p1 > 11) 
	{
		++sh1;
		p1 -= 12; 
	}
	while (sh1 > 19) 
	{
		++f1;
		sh1 -= 20; 
	}
	cout << "Всего: J"<< f1<<c<<sh1<<c<<p1;
	cout << "\nПродолжить(y/n)? " << endl;
	cin >> c;
} while (c != 'n');

system("pause"); return 0;
}
