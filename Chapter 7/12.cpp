/*07_12ex.cpp
Создайте класс bMoney. Он должен хранить денежные значения как long double. Используйте метод mstold() для преобразования денежной строки,
введенной пользователем, в long double, и метод ldtoms() для преобразования числа типа long double в денежную строку для вывода (см. упр. 6 и 10). 
Вы можете вызывать для ввода и вывода методы getmoney() и putmoney(). Напишите другой метод класса для сложения двух объектов типа bMoney и назовите его madd().
Сложение этих объектов легко произвести: просто сложите перменную типа long double одного объекта с такой же переменной другого объекта. Напишите функцию main(),
которая просит пользователя несколько раз ввести денежную строку, а затем выводит сумму значений этих строк. Вот как может выглядеть определение класса:
  class bMoney
  {
    private:
      long double money;
    public:
      bMoney();
      bMoney(char s[]);
      void madd (bMoney m1, bMoney m2);
      void getmoney();
      void putmoney();
    }*/

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
money() { res = 0.0; }; 
money(const char s[]) {};
long double mstold(string s) 
{
  string sres;
  for (int j = 0; j < s1.length(); j++) 
  {
    if (((s1[j] >= '0') && (s1[j] <= '9')) || (s1[j] == ','))
      sres.append(1, s1[j]);
  }
  res = stold(sres);
  return res;
}
void ldtoms(long double value) 
{
  s1 = "$" + to_string(value); 
  int index = 1;
  for (int j = s1.find(',') - 1; j >= 0; j--) 
  {
    if (index % 3 == 0 && j != 1 && j != 0)
      s1.insert(j, ".");index++;
  }
  displays();
}
void puts() 
{ 
  cout << "Введите строку в формате($1.234.567.890.123,99):\n"; 
  getline(cin, s1); 
  mstold(s1); 
}
void putld() 
{
  int index = 10;
  while (index-- > 0) 
  {
    cout << "\nВведите число в формате long double(123456.789):\n"; 
    cin >> res;
    if (res > 9999999999999990.00 || res < 0) 
    {
      cout << "Error! Overflow!"; 
      continue;
    }
    ldtoms(res);
  }
}
void displayld() const 
{ 
  cout << "\nВаша строка:" << s1; 
  cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint) << setprecision(2) << "\nРезультат=" << res << endl; 
}
void displays() const 
{
  for (int j = 0; j < s1.find(',') + 3; j++)
    cout << s1[j];
}
void madd(money m1, money m2) 
{
  res = m1.res + m2.res;
  cout << "\nРезультат="; 
  ldtoms(res); 
  cout << endl;
}
};
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

money m1, m2, m3;
m1.puts(); 
m2.puts();
cout << "\n1: "; 
m1.displayld(); 
cout << "\n2: "; 
m2.displayld();
m3.madd(m1, m2); 

cout << endl; system("pause"); return 0;
}
