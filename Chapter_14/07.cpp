/*14_07ex.cpp
За основу возьмите класс frac и калькулятор с четырьмя функциями из упр. 7 главы 8. Сделайте этот класс шаблоном, чтобы его можно было
реализовывать с использованием различных типов данных в качестве делимого и делителя. Конечно, это должны быть целоцисленные типы, что строго
ограничивает вас в их выборе (char, short, int и long). Можно, впрочем, определить и свой целочисленный класс, никто не запрещает.
В main() реализуйте класс frac<char> и используйте его при разработке калькулятора с четырьмя функциями. Этому классу требуется меньше памяти,
чем frac<int>, но с его помощью невозможно выполнять деление больших чисел.*/

#include <iostream>
using namespace std;

template <class F>
class Fraction 
{
private:
  F num, den; 
  char ch = '/';
public:
Fraction() : num(0), den(0) {}
Fraction(F n, F d) : num(n), den(d) {}

void put_fraction()
{
  long tnum, tden; 
  char ch1;
  cout << "Введите обыкновенную дробь:";
  cin >> tnum >> ch1 >> tden;
  if (tnum == 0 && tden == 0 || tnum == 1 && tden == 1 || tnum == 0 && tden == 1)
  { 
    cout << "\nError"; 
    exit(1); 
  }
  num = tnum;
  den = tden;
}
void display() const 
{ 
  cout << "\nРезультат: " << (long)num << ch << (long)den;
}
Fraction operator+ (Fraction b) 
{ 
  cout << "Сложение: " << (long)num << ch << (long)den << '+' << (long)b.num << ch << (long)b.den;
  return Fraction(num * b.den + den * b.num, den * b.den); 
}
Fraction operator- (Fraction b) 
{ 
  cout << "Вычитание: " << (long)num << ch << (long)den << '-' << (long)b.num << ch << (long)b.den; 
  return Fraction(num * b.den - den * b.num, den * b.den); 
}
Fraction operator* (Fraction b) 
{ 
  cout << "Умножение: " << (long)num << ch << (long)den << "*" << (long)b.num << ch << (long)b.den; 
  return Fraction(num * b.num, den * b.den); 
}
Fraction operator/ (Fraction b) 
{ 
  cout << "Деление: " << (long)num << ch << (long)den << '/' << (long)b.num << ch << (long)b.den; 
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

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));


Fraction <char> m, n, res; 
char c1;
do 
{
  m.put_fraction();
  cout << "Введите знак операции:"; 
  cin >> c1;
  n.put_fraction();
  switch (c1) 
  {
    case '+': 
      res = m + n; 
      break;
    case '-': 
      res = m - n; 
      break;
    case '*': res = m * n; 
      break;
    case '/': 
      res = m / n; 
      break;
  }	
  res.display(); 
  res.lowterms(); 
  res.display();
  cout << "\nЖелаете продолжить? (y/n):";
  cin >> c1;
} while (c1 != 'n'); 

cout << endl; system("pause"); return 0;
}
