/*06_11ex.cpp
Модифицируйте калькулятор, созданный в упр. 12 главы 5 так, чтобы вместо структуры fraction использовался одноименный класс.
Класс должен содержать методы для ввода и вывода данных объектов, а также для выполнения арифметических операций. Кроме того, необходимо включить в состав 
класса функцию, приводящую дробь к несократимому виду. Функция должна находить наибольший общий делитель числителя и знаменателя и делить числитель и знаменатель на это значение.
Код функции, названной lowterms(), приведен ниже:
  void fraction::lowterms()
  {
  long tnum, tden, temp, gcd;
  tnum = labs(num);
  tden = labs(den);
  if (tden == 0)
  {cout <<"Недопустимый знаменатель!"; exit(1);}
  else if (tnum == 0)
  { num=0; den=1; return;}
  while(tnum!=0)
  {
    if(tnum<tden)
    {temp=tnum; tnum=tden; tden=temp;}
    tnum = tnum - tden;
  }
  gcd=tden;
  num=num/gcd;
  den=den/gcd;
  }
Можно вызывать данную функцию в конце каждого метода, выполняющего арифметическую операцию, либо непосредственно перед выводом на экран результата.
Кроме перечисленных методов, вы можете включить в класс конструктор с двумя аргументами, что также будет полезно.*/

#include <iostream>
using namespace std;

class Fraction 
{
private: 
	int num, den; 
	static char ch;
public:
	Fraction() : num(0), den(0) {}
	Fraction(int n, int d) : num(n), den(d) {}

void put_fraction() 
{ 
  cin >> num >> ch >> den; 
}

void display() const 
{ 
  cout << "\nРезультат: " << num << ch << den; 
}

void fadd(Fraction a, Fraction b)
{
		cout << "Сложение: " << a.num << ch << a.den << '+' << b.num << ch << b.den;
		num = a.num * b.den + a.den * b.num; den = a.den * b.den;
}
void fsub(Fraction a, Fraction b) 
{
		cout << "Вычитание: " << a.num << ch << a.den << '-' << b.num << ch << b.den;
		num = a.num * b.den - a.den * b.num; den = a.den * b.den;
}
void fmul(Fraction a, Fraction b) 
{
		cout << "Умножение: " << a.num << ch << a.den << '*' << b.num << ch << b.den;
		num = a.num * b.num; den = a.den * b.den;
}
void fdiv(Fraction a, Fraction b) 
{
		cout << "Деление: " << a.num << ch << a.den << '/' << b.num << ch << b.den;
		num = a.num * b.den; den = a.den * b.num;
}
void lowterms() 
{
long tnum, tden, temp, gcd;
tnum = labs(num); 
tden = labs(den);
if (tden == 0) 
    { 
      cout << "Недопустимый знаменатель!"; 
      exit(1); 
    }
else if (tnum == 0) 
    { 
      num = 0; 
      den = 1; 
      return; 
    }
while (tnum != 0) 
{
	if (tnum < tden) 
     	 { 
      	  temp = tnum; 
      	  tnum = tden; 
      	  tden = temp; 
      	 }
tnum = tnum - tden;
}
gcd = tden; 
num /= gcd; 
den /= gcd;
}
};
char Fraction::ch = '/';
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Fraction m, n, res; char c1;
do 
{
cout << "Введите первую дробь:"; 
m.put_fraction();
cout << "Введите знак операции:"; 
cin >> c1;
cout << "Введите вторую дробь:"; 
n.put_fraction();
switch (c1) 
    {
	case '+': res.fadd(m, n); break;
	case '-': res.fsub(m, n); break;
	case '*': res.fmul(m, n); break;
	case '/': res.fdiv(m, n); break; 
    }
res.display(); 
res.lowterms();
res.display();
cout << "\nЖелаете продолжить? (y/n):"; 
cin >> c1;
} while (c1 != 'n');

cout << endl; system("pause"); return 0;
}
