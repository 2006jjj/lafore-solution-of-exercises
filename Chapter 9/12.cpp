/*09_12ex.cpp
Рассмотрим старую Британскую платежную систему фунты-стерлинги-пенсы (см. упр. 10 главы 4). Пенни в дальнейшем делятся на фартинги и полупенни.
Фартинг это 1/4 пенни. Существовали монеты фартинг, полфартинга и пенни. Любые сочетания монет выражались через восьмые части пенни:
  1/8 пенни - это полфартинга;
  1/4 пенни - это фартинг;
  3/8 пенни - это фартинг с половиной;
  1/2 пенни - это полпенни;
  5/8 пенни - это полфартинга плюс полпенни;
  3/4 пенни - это полпенни плюс фартинг;
  7/8 пенни - это полпенни плюс фартинг с половиной.
Давайте предположим, что мы хотим добавить в класс sterling возможность пользоваться этими дробными частями пенни.
Формат ввода/вывода может быть похожим на J1.1.1-1/4 или J9.19.11-7/8, где дефисы отделяют дробные части от пенни.
Создайте новый класс sterfrac, производный от класса sterling. В нем должна быть возможность выполнения четырех основных арифметических операций
со стерлингами, включая восьмые части пенни. Поле eighths типа int определяет количество восьмых. Вам нужно будет перегрузить методы класса sterling, чтобы они 
могли работать с восьмыми частями. Пользователь должен иметь возможность ввести и вывести дробные части пенни. Не обязательно использовать класс fraction полностью (см. упр. 11 главы 6),
но вы можете это сделать для большей точности.*/


#include <iostream>
#include <iomanip>
using namespace std;

char ch = '.';
class sterling 
{
protected: 
  long pounds;  
  int shillings, pence;
public:
sterling() : pounds(0), shillings(0), pence(0) {};
sterling(double f) 
{ 
  pounds = f; 
  shillings = (f - pounds) * 20; 
  pence = ((f - pounds) * 20 - shillings) * 12; 
}
sterling(long p, int sh, int pe) :pounds(p), shillings(sh), pence(pe) {};

void getSterling() 
{ 
  cout << "Введите количество фунтов, шиллингов и пенсов (формат-J9.19.11): \nJ:"; 
  cin >> pounds >> ch >> shillings >> ch >> pence; 
}
void putSterling() const 
{ 
  cout << "\nРезультат: J" << pounds << ch << shillings << ch << pence;
}
operator double() const 
{ 
  return pounds + ((pence / 12.0 + shillings) / 20.0);   //return (pounds + shillings / 20.0 + pence / 240.0);
}  
sterling operator + (sterling s2) const 
{ 
  return sterling(double(sterling(pounds, shillings, pence)) + double(s2)); 
}
sterling operator - (sterling s2) const 
{ 
  return sterling(double(sterling(pounds, shillings, pence)) - double(s2)); 
}
sterling operator * (double f) const 
{ 
  return sterling(double(sterling(pounds, shillings, pence)) * f); 
}
double operator / (sterling s2) const 
{ 
  return (double(sterling(pounds, shillings, pence)) / double(s2)); 
}
sterling operator / (double f) const 
{ 
  return sterling(double(sterling(pounds, shillings, pence)) / f); 
}
};

class sterfrac : public sterling 
{
private: 
  int eighths;
public:
sterfrac() : sterling(), eighths(0) {}
sterfrac(double f) 
{
  pounds = f;
  shillings = (f - pounds) * 20;
  pence = ((f - pounds) * 20 - shillings) * 12;
  eighths = round((((f - pounds) * 20 - shillings) * 12 - pence) * 8);
}
sterfrac(long p, int sh, int pe, int ei) : sterling(p, sh, pe), eighths(ei) {}

void getSterling() 
{
  unsigned int num = 0, den = 0; 
  char ch;
  cout << "Введите количество фунтов, шиллингов и пенсов (формат-J9.19.11-1/4): \nJ:";
  cin >> pounds >> ch >> shillings >> ch >> pence >> ch >> num >> ch >> den;
  if ((num >= den) || (den != 2 && den != 4 && den != 8) || (num > 7 && num < 0)) 
  {
    cout << "Числитель должен быть больше или равен знаменателю!\nЗнаменатель должен быть равен 2 или 4 или 8!\nЧислитель должен быть от 0 до 7"; 
    exit(1);
  }
  if (den == 2)
    num *= 4;
  if (den == 4) 
    num *= 2;
  eighths = num;
}
void putSterling() const 
{
  sterling::putSterling(); 
  cout << "-";
  switch (eighths)
    {
      case 2: cout << "1/4";
        break;
      case 4: cout << "1/2";
        break;
      case 6: cout << "3/4"; 
        break;
      default: cout << eighths << "/8"; 
        break;
    }
}
operator double() const 
{ 
  return (sterling::operator double() + eighths / 1920.0); 
}
sterfrac operator + (sterfrac s2) const 
{ 
  return sterfrac(double(sterfrac(pounds, shillings, pence, eighths)) + double(s2)); 
}
sterfrac operator - (sterfrac s2) const 
{ 
  return sterfrac(double(sterfrac(pounds, shillings, pence, eighths)) - double(s2)); 
}
sterfrac operator * (double f) const 
{ 
  return sterfrac(double(sterfrac(pounds, shillings, pence, eighths)) * f); 
}
double operator / (sterfrac s2) const 
{
  return (double(sterfrac(pounds, shillings, pence, eighths)) / double(s2));
}
sterfrac operator / (double f) const 
{ 
  return sterfrac(double(sterfrac(pounds, shillings, pence, eighths)) / f); 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

sterfrac s, s1, s2;   //s1(3, 45, 23,5), s2(23, 12, 26,2),
double n; 
s1.putSterling(); 
s2.putSterling();
cout << "\n1. "; 
s1.getSterling();
cout << "2. "; 
s2.getSterling(); 
cout << endl;
cout << "\n1. В десятичных фунтах: " << fixed << setprecision(2) << double(s1) << endl;
cout << "2. В десятичных фунтах: " << fixed << setprecision(2) << double(s2) << endl;
s = s1 + s2; 
s.putSterling();
s = s2 - s1; 
s.putSterling();
s = s1 * 1.05; 
s.putSterling();
n = s1 / s2; 
cout << "\nРезультат: " << n;
s = s1 / 3.5; 
s.putSterling(); 

cout << endl; system("pause"); return 0;
}
