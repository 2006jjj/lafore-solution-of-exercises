/*03_11ex.cpp
Создайте калькулятор, выполняющий действия над денежными суммами, выраженными в фунтах, шиллингах и пенсах (см. упр. 10 и 12 главы 2). 
Калькулятор должен складывать и вычитать вводимые значения, а также производить умножение денежной суммы  на вещественное число (операция умножения двух
денежных сумм не имеет смысла, поскольку квадратных денежных единиц не существует. Деление одной денежной суммы на другую мы тоже не будем рассматривать).*/


#include <iostream>
using namespace std;
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

 char c; 
 int f1=0, f2=0, sh1=0, sh2=0, p1=0, p2=0;
 cout << "Введите операцию: ";
 cin >> c;
   switch (c)
   {
	case '+':
	cout << "Введите первую сумму: J";
	cin >> f1 >> c >> sh1 >> c >> p1;
	cout << "Введите вторую сумму: J";
	cin >> f2 >> c >> sh2 >> c >> p2;
	f1 += f2; sh1 += sh2; p1 += p2;
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
	cout << "Всего: J" << f1 << c << sh1 << c << p1 << endl;
	break;
	   
	case '-':
	cout << "Введите первую сумму: J";
	cin >> f1 >> c >> sh1 >> c >> p1;
	cout << "Введите вторую сумму: J";
	cin >> f2 >> c >> sh2 >> c >> p2;
	f1 -= f2; sh1 -= sh2; p1 -= p2;
	while (p1 < 0) 
        {
	  --sh1;
	  p1 -= 12;
        }
	while (sh1 > 19) 
        {
	  ++f1;
	  sh1 -= 20;
        }
	cout << "Всего: J" << f1 << c << sh1 << c << p1 << endl ;
	break;
	   
	case '*': break;
	default: cout << "Error!";
   }
system("pause"); return 0;
}
