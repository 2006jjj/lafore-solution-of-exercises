/*09_09ex.cpp
Вспомним классы publication, book и type из упр. 1. Предположим, что мы хотим добавить в классы book и type дату выхода книги.
Создайте новый производный класс publication2, который является производным класса publication и включает в себя поле, хранящее эту дату.
Затем измените классы book и type так, чтобы они стали производными класса publication2 вместо publication. Сделайте необходимые изменения функций
классов так, чтобы пользователь мог вводить и выводить дату выхода книги. Для даты можно использовать класс data из упр. 5 главы 6, который хранит
дату в виде трех целых: для месяца, для дня и для года.*/

#include <iostream>
#include <string>
using namespace std;

class date
{
private:
  int day, month, year;
public:
date() : day(0), month(0), year(0) {}
date(int y, int m, int d) : day(d), month(m), year(y) {}
void getdata() 
{
  char ch;
  cout << "Введите дату публикации в формате (xx/xx/xxxx):";
  cin >> day >> ch >> month >> ch >> year;
  if ((month > 12) || (day > 31)) 
  { 
    cout << "ERROR!"; 
    exit(1); 
  }
}
void showdate() const 
{ 
  cout << "\nДата публикации:" << day << "/" << month << "/" << year << endl; 
}
};

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

class publication2 : public publication 
{
private: 
  date ourdata;
public: 
void getdata() 
{ 
  publication::getdata(); 
  ourdata.getdata(); 
}
void putdata() const 
{ 
  publication::putdata();
  ourdata.showdate(); 
}
};

class book : private publication2 
{
private: 
  int pages;
public: book() : pages(0) {}
void getdata() 
{
  publication2::getdata(); 
  cout << "Введите количество страниц в книге:"; 
  cin >> pages;
}
void putdata() const 
{ 
  publication2::putdata(); 
  cout << "Количество страниц: " << pages << endl; 
}
};

class type : private publication2 
{
private: 
  float record;
public: type() : record(0.0F) {}
void getdata() 
{
  publication2::getdata(); 
  cout << "Введите время записи книги:";  
  cin >> record; 
}
void putdata() const 
{ 
  publication2::putdata(); 
  cout << "\nВремя записи: " << record << " minutes"; 
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
