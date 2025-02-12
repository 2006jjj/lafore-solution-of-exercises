/*08_07ex.cpp
Модифицируйте класс fraction в четырехфункциональном дробном калькуляторе из упр. 11 главы 6 так, чтобы он использовал перегруженные операции сложения,
вычитания, умножения и деления. (Вспомните правила арифметики с дробями в упр. 12 главы 3). Также перегрузите операции сравнения == и != и используйте их для выхода 
из цикла, когда пользователь вводит 0/1, 0 и 1 значения двух частей дроби. Вы можете модифицировать и функцию lowterms() так, чтобы она возвращала значение ее аргумента,
уменьшенное до несократимой дроби. Это будет полезным в арифметических функциях, которые могут быть выполнены сразу после получения ответа.*/

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
  if (num == 0 && den == 0 || num == 1 && den == 1 || num == 0 && den == 1) 
  { 
    cout << "\nError"; 
    exit(1); 
  }
}
void display() const 
{
  cout << "\nРезультат: " << num << ch << den;
}

Fraction operator+ (Fraction b) 
{
  cout << "Сложение: " << num << ch << den << '+' << b.num << ch << b.den;
  return Fraction(num * b.den + den * b.num, den * b.den);
}
Fraction operator- (Fraction b) 
{
  cout << "Вычитание: " << num << ch << den << '-' << b.num << ch << b.den;
  return Fraction(num * b.den - den * b.num, den * b.den);
}
Fraction operator* (Fraction b) 
{
  cout << "Умножение: " << num << ch << den << "*" << b.num << ch << b.den;
  return Fraction(num * b.num, den * b.den);
}
Fraction operator/ (Fraction b) 
{
  cout << "Деление: " << num << ch << den << '/' << b.num << ch << b.den;
  return Fraction(num * b.den, den * b.num);
}
Fraction lowterms() 
{
  long tnum, tden, temp;
  tnum = labs(num);
  tden = labs(den);
  while (tnum != 0) 
  {
    if (tnum < tden) 
    { 
      temp = tnum;  
      tnum = tden; 
      tden = temp; 
    }
    tnum -= tden;
  }
  return Fraction(num /= tden, den /= tden);
}
};
char Fraction::ch = '/';

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Fraction m, n, res; 
char c1;
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
	case '+': res = m + n; break;
	case '-': res = m - n; break;
	case '*': res = m * n; break;
	case '/': res = m / n; break;
  }
  res.display(); 
  res.lowterms(); 
  res.display();
  cout << "\nЖелаете продолжить? (y/n):"; 
  cin >> c1;
} while (c1 != 'n'); 

cout << endl; system("pause"); return 0;
}
