/*11_06ex.cpp
Возьмите за основу программу из упр. 8 главы 8, где было перегружено пять арифметических операций для работы с денежным форматом. 
Добавьте два оператора, которые не были перегружены в том упражнении:
  long double * bMoney   //умножать число на деньги
  long double / bMoney   //делить число на деньги
Эти операции требуют наличия дружественных функций, так как справа от оператора находится объект, а слева - обычное число. Убедитесь, что main()
позволяет пользователю ввести две денежные строки и число с плавающей запятой, а затем корректно выполняет все семь арифметических действий с соответствующими парами значений.

11_07ex.cpp
Как и в предыдущем упражнении, возьмите за основу программу из упражнении 8 главы 8. На этот раз от вас требуется добавить функцию, округляющую значение bMoney до ближайшего доллара:
  mo2=round(mo1);
Как известно, значения, не превышающие $0.49, округляются вниз, а числа от $0.50 и более округляются вверх. Можно использовать библиотечную функцию modfl().
Она разбивает переменную типа long double на целую и дробную части. Если дробная часть меньше 0.50, функция просто возвращает целую часть числа. В противном случае 
возвращается увеличенная на 1 целая часть. В main() проверьте работоспособность функции путем передачи в нее последовательно значений, одни из которых меньше $0.49, другие - больше $0.50.*/


#include <iostream>
#include <iomanip> 
#include <sstream>
using namespace std;

class money 
{
private: 
  string s1; 
  long double res;
public:
money() { res = 0.0; }
explicit money(long double n) : res(n) {}

void ldtoms(long double value) 
{
  s1 = "$" + to_string(value); 
  int index = 1;
  for (int j = s1.find(',') - 1; j >= 0; j--) 
  {
    if (index % 3 == 0 && j != 1 && j != 0)
      s1.insert(j, ".");
    index++;
  }
  displays();
}

void puts() 
{
  cout << "Введите строку в формате($1.234.567.890.123,99):\n";
  cin >> s1; 
  string sres;
  for (int j = 0; j < s1.length(); j++) 
  {
    if (((s1[j] >= '0') && (s1[j] <= '9')) || (s1[j] == ','))
      sres.append(1, s1[j]);
  }
  res = stold(sres);
}

void displayld() const 
{ 
  cout << "\nВаша строка:" << s1; 
  cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint) << setprecision(5) << "\nРезультат=" << res << endl; 
}

void displays() const 
{
  cout << "Результат:";
  for (int j = 0; j < s1.find(',') + 3; j++) 
    cout << s1[j];
  cout << endl;
}

money operator+ (money m2) 
{ 
  money sum(res + m2.res); 
  ldtoms(sum); 
  return sum; 
}
money operator-(money m2)
{ 
  ldtoms(res - m2.res); 
  return (money)(res - m2.res);
}
money operator *(long double x) 
{ 
  ldtoms(res * x); 
  return (money)(res * x); 
}
money operator / (money m2) 
{ 
  money div1(res / m2.res); 
  ldtoms(div1); 
  return div1; 
}
money operator / (long double x)
{ 
  money div2(res / x); 
  ldtoms(div2);
  return div2; 
}
operator long double() const 
{ 
  long double number = res; 
  return number; 
}
friend long double operator * (long double, money);
friend long double operator / (long double, money);
friend money okrug(money);
};

long double operator* (long double x, money m1) 
{ 
  long double result = x * m1.res; 
  cout << "Результат:$" << result << endl; 
  return result; 
}
long double operator/ (long double x, money m1) 
{ 
  long double result = x / m1.res;
  cout << "Результат:$" << result << endl; 
  return result; 
}
money okrug(money m4) {
	long double x, res; res = modfl(m4.res, &x);
	if (res < 0.50) return money(x);
	else return money(x + 1.0);
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

money m1, m2, m3; 
long double x = 0.0, res = 0.0;
do 
{
  m1.puts(); 
  m2.puts();
  cout << "Введите число с плавающей точкой:"; 
  cin >> x;
  cout << "\n1: "; 
  m1.displayld(); 
  cout << "\n2: "; 
  m2.displayld();
  cout << "\n1)"; 
  m3 = m1 + m2; 
  cout << " " << okrug(m3) << endl;
  cout << "2)"; 
  m3 = m1 - m2; 
  cout << " " << okrug(m3) << endl;
  cout << "3)"; 
  m3 = m3 * x; 
  cout << " " << okrug(m3) << endl;
  cout << "4)"; 
  x = m1 / m2; 
  cout << " " << round(x) << endl;
  cout << "5)"; 
  m3 = m3 / x; 
  cout << " " << okrug(m3) << endl;
  cout << "6)"; 
  res = x * m1;
  cout << " " << round(res) << endl;
  cout << "7)"; 
  res = x / m2;
  cout << " " << round(res) << endl;
  cout << "\nЖелаете продолжить? Введите (y/n):"; 
  cin.get();
} while (cin.get() != 'n');

cout << endl; system("pause"); return 0;
}
