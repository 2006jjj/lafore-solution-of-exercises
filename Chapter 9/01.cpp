/*09_01ex.cpp
Представьте себе издательскую компанию, которая торгует книгами и аудио-записами этих книг. Создайте класс publication, в котором
хранятся название (строка) и цена (типа float) книги. От этого класса наследуются еще два класса: book, который содержит инфорамцию о количестве
страниц в книге (типа int), и type, который содержит время записи книги в минутах (тип float). В каждом из этих трех классов должен быть метод getdata(),
через который можно получать данные от пользователя с клавиатуры, и putdata(), предназначенный для вывода этих данных.
Напишите функцию main() программы для проверки классов book и type. Создайте их объекты в программе и запросите пользователя ввести и вывести данные с использованием 
методов getdata() и putdata().*/

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
  cout << "Введите название книги:"; getline(cin, name, '!');
  cout << "Введите цену:"; cin >> price;
}
void putdata() const 
{ 
  cout << "\nКнига: " << name << "\nЦена: " << price << endl; 
}
};

class book : private publication 
{
private: 
  int pages;
public: book() : pages(0) {}
void getdata() 
{ 
  publication::getdata(); 
  cout << "Введите количество страниц в книге:"; 
  cin >> pages; 
}
void putdata() const 
{ 
  publication::putdata(); 
  cout << "Количество страниц: " << pages << endl; 
}
};

class type : private publication 
{
private: 
  float record;
public: type() : record(0.0F) {}
void getdata() 
{ 
  publication::getdata();	
  cout << "Введите время записи книги:"; 
  cin >> record; 
}
void putdata() const 
{ 
  publication::putdata(); 
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
