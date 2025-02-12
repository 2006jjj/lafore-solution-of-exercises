/*09_03ex.cpp
Начните с классов book, type и publication из упр. 1. Добавьте базовый класс sales, в котором содержится массив, состоящий из трех значений
типа float, куда можно записать общую стоимость проданных книг за последние три месяца. Включите в класс методы getdata() для получения значений стоимости
от пользователя и putdata() для вывода этих цифр. Измените классы book и type так, чтобы они стали производными обоих классов: publications и sales.
Объекты классов book и type должны вводить и выводить данные о продажах вместе с другими своими данными. Напишите функцию main() для создания объектов классов book и type,
чтобы протестировать возможности ввода/вывода данных.*/

#include <iostream>
#include <string>
using namespace std;

class publication 
{
private: 
  string name; 
  float price;
public: publication() : name(""), price(0.0F) {}
void getdata() 
{ 
  cout << "Введите название книги:"; 
  getline(cin, name, '!');
  cout << "Введите цену:"; 
  cin >> price; 
}
void putdata() const 
{ 
  cout << "\nКнига: " << name << "\nЦена: " << price << endl; 
}
};

class sales 
{
private: 
  float arr[3];
public: 
sales() 
{ 
  arr[2] = {}; 
}
void getdata() 
{ 
  cout << "Введите 3 общие суммы проданных книг за последние три месяца:" << endl; 
  for (int i = 0; i < 3; i++) 
  { 
    cout << i + 1 << ":"; 
    cin >> arr[i];
  } 
}
void putdata() const 
{ 
  for (int i = 0; i < 3; i++) 
  { 
    cout << "\nОбщая сумма продаж за " << i + 1 << " месяц :" << arr[i] << "P"; 
  } 
}
};

class book : private publication, private sales 
{
private: 
  int pages;
public: 
book() : pages(0) {}
void getdata() 
{ 
  publication::getdata(); 
  cout << "Введите количество страниц в книге:"; 
  cin >> pages; 
  sales::getdata(); 
}
void putdata() const 
{ 
  publication::putdata(); 
  cout << "Количество страниц: " << pages << endl; 
  sales::putdata(); 
}
};

class type : private publication, private sales 
{
private:
  float record;
public: type() : record(0.0F) {}
void getdata() 
{ 
  publication::getdata(); 
  cout << "Введите время записи книги:"; 
  cin >> record; 
  sales::getdata(); 
}
void putdata() const 
{ 
  publication::putdata();
  cout << "\nВремя записи: " << record << " минут"; 
  sales::putdata(); 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

book b1; 
type t1; 
b1.getdata(); 
t1.getdata(); 
b1.putdata(); 
t1.putdata(); 

cout << endl; system("pause"); return 0;
}
