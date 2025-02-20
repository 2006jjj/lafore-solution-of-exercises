/*12_09ex.cpp
Начните с упр. 7 главы 8 и перегрузите операторы извлечения (>>) и вставки (<<) для класса frac в нашем калькуляторе с четырьмя действиями.
Имейте в виду, что операторы могут связываться в цепочки, поэтому при выполнении действий с дробями понадобится только одно выражние: cin>>frac1>>op>>frac2;


12_10ex.cpp
Добавьте к упр. 9 проверку на наличие ошибок в операторе извлечения (>>). Но при этом, видимо, потребуется запрашивать сначала первую дробь, затем оператор,
затем вторую дробь. Одним выражением, как в упр. 9, уже будет не обойтись. Вывод сообщений об ошибках сделает работу с программой более понятной.
    Введите первую дробь: 5/0
    Знаменатель не может быть нулевым!
    Введите первую дробь заново: 5/1
    Введите оператор (+,-,*,/): +
    Введите вторую дробь: одна треть
    Ошибка ввода
    Введите вторую дробь заново: 1/3
    Ответ: -------------------------------- 16/3
    Продолжить (y/n)? n
    
Как показывает этот пример, необходимо следить за флагами ошибок ios и за тем, чтобы знаменатель не был равен нулю. Если возникает ошибка,
пользователю должно быть предложено ввести данные еще раз.*/


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

Fraction operator+ (Fraction b) const 
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
bool operator == (Fraction b) const 
{ 
  ((num == b.num) && (den == b.den)) ? 1 : 0; 
}
bool operator !=(Fraction b) const 
{ 
  ((num == b.num) && (den == b.den)) ? 0 : 1; 
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
friend istream& operator >> (istream& s, Fraction& f);
friend ostream& operator << (ostream& s, Fraction& f);
};

char Fraction::ch = '/';

istream& operator >> (istream& s, Fraction& f)
{
  char ch;
  while (true)
  {
    s.unsetf(ios::skipws); 
    s >> f.num;
    if (s.good())
    {
      s.unsetf(ios::skipws);
      cin >> ch;
      if (ch == '/')
      {
        s.unsetf(ios::skipws); 
        s >> f.den;
        if (s.good())
        {
          if (f.den != 0) 
          { 
            cin.ignore(80, '\n');
            break; 
          }
          else 
            cout << "Знаменатель не может быть 0";
        }
        else 
        { 
          s.clear(); 
          cout << "Введен неправильный знаменатель!"; 
        }
      }
      else 
        cout << "Введите косую черту!";
    }
    else 
    { 
      s.clear();
      cout << "Ошбика! Неправельный числитель!"; 
    }
    s.ignore(80, '\n');
    cout << "\nВведите дробь заново:";
  }
  return s;
}

ostream& operator << (ostream& s, Fraction& f) 
{
  s << f.num << "/" << f.den;
  return s; 
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Fraction f1, f2, res; 
char c1;
do 
{
  cout << "Введите первую дробь:"; 
  cin >> f1;
  cout << "Введите знак операции (+,-,/,*):";
  cin >> c1; 
  cin.ignore(80, '\n');
  cout << "Введите вторую дробь:"; 
  cin >> f2;
  switch (c1) 
  {
    case '+': 
      res = f1 + f2; 
      res.lowterms(); 
      cout << "\nОтвет: ----------- " << res << endl; 
      break;
    case '-': 
      res = f1 - f2; 
      res.lowterms(); 
      cout << "\nОтвет: ----------- " << res << endl; 
      break;
    case '*': 
      res = f1 * f2; 
      res.lowterms(); 
      cout << "\nОтвет: ----------- " << res << endl; 
      break;
    case '/':
      res = f1 / f2; 
      res.lowterms(); 
      cout << "\nОтвет: ----------- " << res << endl; 
      break;
    default: 
      cout << "ERROR, VVEDEN NE TOT ZNAK OPERACII" << endl;
  }
  cout << "\nЖелаете продолжить? (y/n):"; 
  cin >> c1; 
  cin.ignore(80, '\n');
} while (c1 != 'n'); 

cout << endl; system("pause"); return 0;
}
