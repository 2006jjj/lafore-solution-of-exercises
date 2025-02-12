/*08_11ex.cpp
Помните структуру sterling? Мы встречались с ней в упр. 10 главы 2, в упр. 11 главы 5 и в других местах. Преобразуйте ее в класс, 
имеющий переменные для фунтов (типа long), шиллингов (типа int) и пенсов (типа int). Создайте в классе следующие функции:
  -конструктор без аргументов;
  -конструктор с одним аргументом типа double (для преобразования от десятичных фунтов);
  -конструктор с тремя аргументами: фунтами, шиллингами и пенсами;
  -метод getSterling() для получения от пользователя значений количества фунтов, шиллингов и пенсов в формате J9.19.11;
  -метод putSterling() для вывода значений количества фунтов, шиллингов и пенсов в формате J9.19.11;
  -метод для сложения (sterling + sterling), используя перегруженную операцию +;
  -метод вычитания (sterling - sterling), используя перегруженную операцию -;
  -метод умножения (sterling * double), используя перегруженную операцию *;
  -метод деления (sterling / sterling), используя перегруженную операцию /;
  -метод деления (sterling / double), используя перегруженную операцию /;
  -операцию double (для преобразования к типу double)
Выполнять вычисления вы можете, например, складывая отдельно данные объекта: сложить сначала пенсы, затем шиллинги и т.д.
Однако легче использовать операцию преобразования для преобразования объекта класса sterling к типу double, выполнить вычисления с типами double,
а затем преобразовать обратно к типу sterling. Таким образом, операция + выглядит похожей на эту:
  sterling sterling::operator + (sterling s2)
  {
  return sterling (double(sterling(pounds, shillings, pense)) + double (s2));
  }
Так мы создадим две временных переменных типа double, одна происходит от объекта, которые вызывает функцию, а другая от аргумента s2.
Эти переменные затем складываются, результат преобразовывается к типу sterling и возвращается.
Заметим, что мы использовали другой подход для класса sterling, нежели для класса bMoney. В классе sterling мы используем операции преобразования, таким образом
отказавшись от возможности поиска неправильных операций, но получив простоту при записи перегружаемых математических операций.*/

#include <iostream>
#include <iomanip>
using namespace std;

char ch = '.';
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
}
Sterling(long p, int sh, int pe) :pounds(p), shillings(sh), pence(pe) {};

void getSterling() 
{
  cout << "Введите количество фунтов, шиллингов и пенсов (формат-J9.19.11): \nJ:"; 
  cin >> pounds >> ch >> shillings >> ch >> pence;
}
void putSterling() const 
{ 
  cout << "\nРезультат: J" << pounds << ch << shillings << ch << pence << endl; 
}

Sterling operator + (Sterling s2) 
{ 
  return Sterling(double(Sterling(pounds, shillings, pence)) + double(s2)); 
}
Sterling operator - (Sterling s2) 
{ 
  return Sterling(double(Sterling(pounds, shillings, pence)) - double(s2)); 
}
Sterling operator * (double f) 
{ 
  return Sterling(double(Sterling(pounds, shillings, pence)) * f); 
}
Sterling operator / (Sterling s2) 
{ 
  return Sterling(double(Sterling(pounds, shillings, pence)) / double(s2)); 
}
Sterling operator / (double f) 
{ 
  return Sterling(double(Sterling(pounds, shillings, pence)) / f); 
}
operator double() 
{ 
  return (double)pounds + (((double)pence / 12 + (double)shillings) / 20); 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Sterling s1(3, 45, 23), s2(23, 12, 26), s3;
s3 = s1 + s2; 
s3.putSterling();
s3 = s2 - s1; 
s3.putSterling();
s3 = s1 * 3.2; 
s3.putSterling();
s3 = s2 / s1; 
s3.putSterling();
s3 = s2 / 3.2; 
s3.putSterling(); 

cout << endl; system("pause"); return 0;
}
