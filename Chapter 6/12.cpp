/*06_12ex.cpp
Используйте преимущество ООП, заключающееся в том, что однажды созданный класс можно помещать в другие программы. Создайте новую программу,
которая будет включать класс fraction, созданный в упр. 11. Программа должна выводить аналог целочисленной таблицы умножения для дробей. Пользователь вводит знаменатель,
а программа должна подобрать всевозможные целые значения числителя так, чтобы значения получаемых дробей находились между 0 и 1. Дроби из получившегося таким образом
набора перемножаются друг с другом во всевозможных комбинациях, в результате чего получается таблица следующего вида
  (для знаменателя, равного 6):
  1/6 1/3 1/2 2/3 5/6
  -----------------------------------------
  1/6 1/36 1/18 1/12 1/9 5/36
  1/3 1/18 1/9 1/6 2/9 5/18
  1/2 1/12 1/6 1/4 1/3 5/12
  2/3 1/9 2/9 1/3 4/9 5/9
  5/6 5/36 5/18 5/12 5/9 25/36  */

#include <iostream>
using namespace std;

int number=0;
class Fraction 
{
private:
  int num, den;
public: 
	  Fraction() :num(0), den(0) {}
	  void mul_fr(Fraction f1, Fraction f2) 
	  {
		  num = f1.num * f2.num; den = f1.den * f2.den;
	  }
	  void lowterms() 
{
		  long tnum, tden, temp, gcd;
		  tnum = labs(num);
		  tden = labs(den);
		  if (tden == 0) { cout << "Недопустимый знаменатель!"; exit(1); }
		  else if (tnum == 0) { num = 0; den = 1; return; }
		  while (tnum != 0) 
      {
			  if (tnum < tden) { temp = tnum; tnum = tden; tden = temp; }
			  tnum = tnum - tden;
		  }
		  gcd = tden; num /= gcd; den /= gcd;
	}

void disp_fr()const 
{ 
  cout << setw(5) << num << "/" << den; 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Fraction fr1, fr2, fr3;
cout << "enter denominator" << endl; cin >> number;
for (int j = 1; j < number; j++) 
{
	fr1.num = j; 
	fr1.den = number; 
	fr1.lowterms(); 
	fr1.disp_fr();
}
cout << endl;
for (int i = 1; i < number; i++) 
{
	fr2.num = i; 
	fr2.den = number; 
	fr2.lowterms(); 
	fr2.disp_fr();
	for (int j = 1; j < number; j++) 
	{
		fr1.num = j; 
		fr1.den = number; 
		fr3.mul_fr(fr1, fr2); 
		fr3.lowterms(); fr3.disp_fr();
	}
	cout << endl;
}
cout << endl; system("pause"); return 0;
}
