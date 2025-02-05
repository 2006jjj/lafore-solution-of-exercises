/*05_12ex.cpp
Модифицируйте калькулятор, созданный в упр. 12 главы 4, так, чтобы каждая арифметическая операция выполнялась с помощью функции.
Функции могут называться fadd(), fsub(), fmul() и fdiv(). Каждая из функций должна принимать два структурных аргумента типа fraction и возвращать значение того же типа.*/

#include <iostream>
using namespace std;

fraction fadd(fraction, fraction);
fraction fsub(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fdiv(fraction, fraction);
char c1, ch;

struct fraction 
{ 
  int ch, zn; 
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

fraction m, n, res;
do {
	cout << "Введите первую дробь:";  
  cin >> m.ch >> c1 >> m.zn;
	cout << "Введите знак операции:"; 
  cin >> ch;
	cout << "Введите вторую дробь:";  
  cin >> n.ch >> c1 >> n.zn;
	switch (ch) 
  {
	case '+': res = fadd(m, n); cout << res.ch << c1 << res.zn; break;
	case '-': res = fsub(m, n); cout << res.ch << c1 << res.zn; break;
	case '*': res = fmul(m, n); cout << res.ch << c1 << res.zn; break;
	case '/': res = fdiv(m, n); cout << res.ch << c1 << res.zn; break;
	}
	cout << "\nЖелаете продолжить? (y/n):"; 
  cin >> ch;
} while (ch != 'n');

cout << endl; system("pause"); return 0;
}

fraction fadd(fraction x, fraction y) 
{
	fraction result; 
  cout << "Сложение: " << x.ch << c1 << x.zn << ch << y.ch << c1 << y.zn << "=";
	result.ch = x.ch * y.zn + x.zn * y.ch; result.zn = x.zn * y.zn; 
  return result;
}

fraction fsub(fraction x, fraction y) 
{
	fraction result; 
  cout << "Вычитание: " << x.ch << c1 << x.zn << ch << y.ch << c1 << y.zn << "=";
	result.ch = x.ch * y.zn - x.zn * y.ch; result.zn = x.zn * y.zn; 
  return result;
}

fraction fmul(fraction x, fraction y) 
{
	fraction result; 
  cout << "Умножение: " << x.ch << c1 << x.zn << ch << y.ch << c1 << y.zn << "=";
	result.ch = x.ch * y.ch; result.zn = x.zn * y.zn; 
  return result;
}

fraction fdiv(fraction x, fraction y) 
{
	fraction result; 
  cout << "Деление: " << x.ch << c1 << x.zn << ch << y.ch << c1 << y.zn << "=";
	result.ch = x.ch * y.zn; result.zn = x.zn * y.ch; 
  return result;
}
