/*08_12ex.cpp
Напишите программу, объединяющую в себе классы bMoney из упр. 8 и sterling из упр. 11. Напишите операцию преобразования для преобразования
между классами bMoney и sterling, предполагая, что один фунт (J1.0.0) равен пятидести долларам ($50.00). Это приблизительный курс обмена
для XIX века, когда Британская империя еще использовала меру фунты-шиллинги-пенсы. Напишите программу main(), которая позволит пользователю вводить суммы
в каждой из валют и преобразовывать их в другую валюту с выводом результата. Минимизируйте количество изменений в существующих классах bMoney и sterling.*/

#include <iostream>
#include <iomanip>
using namespace std;

static char ch = '.';
class Sterling; 
class money;

class Sterling
{
private:
	long pounds; 
  int shillings, pence;
public:
Sterling() : pounds(0), shillings(0), pence(0) {};
Sterling(double f)
{
  pounds = static_cast<long>(f);
  double drobj = f - pounds;
  shillings = static_cast<int>(drobj * 20);
  pence = static_cast<int>(((drobj * 20) - shillings) * 12);
  putSterling();
}
Sterling(long p, int sh, int pe) :pounds(p), shillings(sh), pence(pe) {};
Sterling(const money& m1);
  
void getSterling()
  {
    cout << "Введите количество фунтов, шиллингов и пенсов (формат-J9.19.11): \nJ";
    cin >> pounds >> ch >> shillings >> ch >> pence;
  }
void putSterling() const 
  { 
    cout << "Результат: J" << pounds << ch << shillings << ch << pence << endl; 
  }
operator double() 
  { 
    return (double)pounds + (((double)pence / 12 + (double)shillings) / 20); 
  }
};

class money 
{
private:
	long double res;
public:
money() { res = 0.0; };
explicit money(long double n) : res(n) {};
money(Sterling& s1);
long double getres() const 
{ 
  return res; 
}
};

Sterling::Sterling(const money& m1)
{
  long double res1 = m1.getres();
  Sterling s1(res1 / 50.00);
}
money::money(Sterling& s2)
{
  Sterling s3(s2);
  cout << "Результат: $" << setiosflags(ios::fixed) << setiosflags(ios::showpoint) << setprecision(2) << (double)(s2) * 50.00 << endl;
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

long double number = 0.0; 
unsigned short sw = 0;
do {
  cout << "\nВЫБЕРИТЕ ПУНКТ:" << "\n1.Введите сумму в $ (50.00)" << "\n2.Введите сумму в футах, шилингах и пенсах (J9.19.11)" << "\n3.Выход\n" << endl; cin >> sw;
  switch (sw) 
  {
	case 1: 
    {
		cout << "Ваша сумма:\n$"; 
    cin >> number;
		money x(number); 
    Sterling s(x); 
    break; 
    }
	case 2: 
    {
		Sterling s; 
    s.getSterling();
		money x(s); 
    break; 
    }
	case 3: 
    { 
      cout << "\nВсего хорошего!";
      break; 
    }
	}
} while (sw <= 2); 

cout << endl; system("pause"); return 0;
}
