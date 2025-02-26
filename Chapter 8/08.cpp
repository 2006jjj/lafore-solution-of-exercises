/*08_08ex.cpp
Модифицируйте класс bMoney из упр. 12 главы 7, включив арифметические операции, выполненные с помощью перегруженных операций:
  bMoney = bMoney + bMoney
  bMoney = bMoney - bMoney
  bMoney = bMoney * long double (цена за единицу времени, затраченного на изделие)
  long double = bMoney / bMoney (общая цена, деленная на цену за изделие)
  bMoney = bMoney / long double (общая цена, деленная на количество изделий)
  
Заметим, что операция / перегружена дважды. Компилятор может различить оба варианта, так как их аргументы разные. Помним, что легче выполнять арифметические операции
с объектами класса bMoney, выполняя те же операции с его long double данными.
Убедитесь, что программа main() запросит ввод пользователем двух денежных строк и числа с плавающей точкой. Затем она выполнит все пять операций и выведет результаты.
Это должно происходить в цикле, так, чтобы пользователь мог ввести еще числа, если это понадобится.
Некоторые операции с деньгами не имеют смысла: bMoney*bMoney не представляет ничего реального, так как нет такой вещи, как денежный квадрат;
вы не можете прибавить bMoney к long double (что же будет, если рубли сложить с изделиями?). Чтобы сделать это невозможным, скомпилируйте такие неправильные операции,
не включая операции преобразования для bMoney в long double или long double в bMoney. Если вы это сделаете и запишете затем выражение типа:
	bmon2 = bmon 1 + widgets; //это не имеет смысла
то компилятор будет автоматически преобразовывать widgets в bMoney и выполнять сложение. Без них компилятор будет отмечать такие преобразования как ошибки, 
что позволит легче найти концептуальные ошибки. Также сделайте конструкторы преобразований явными.
Вот некоторые другие вероятные операции с деньгами, которые мы еще не умеем выполнять с помощью перегруженных операций, так как они требуют объекта справа от знака операции, а не слева:
	long double * bMoney  // Пока не можем это сделать: bMoney возможен только справа
 	long double / bMoney  // Пока не можем это сделать: bMoney возможен только справа
Мы рассмотрим выход из этой ситуации при изучении дружественных функций в главе 11.*/

#include <iostream>
#include <iomanip>
using namespace std;

class money 
{
private:
	string s1; 
  long double res;
public:
money() { res = 0.0; };
explicit money(long double n) : res(n) {};

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
  cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint) << setprecision(2) << "\nРезультат=" << res << endl;
}

void displays() const 
{
  cout << "Результат:";
  for (int j = 0; j < s1.find(',') + 3; j++)
    cout << s1[j];cout << endl;
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
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

money m1, m2, m3; 
long double x = 0.0;
do {
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
  cout << "2)"; 
  m3 = m1 - m2;
  cout << "3)"; 
  m3 = m3 * x; 
  cout << "4)"; 
  x = m1 / m2; 
  cout << "5)"; 
  m3 = m3 / x;
  cout << "\nЖелаете продолжить? Введите (y/n):"; 
  cin.get();
} while (cin.get() != 'n'); 

cout << endl; system("pause"); return 0;
}
