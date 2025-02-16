/*11_01ex.cpp
Пусть имеется та же издательская компания, которая описана в упр. 1 главы 9, которая продает и книги, и аудио версии печатной продукции. Как и в том упр. создайте класс publication,
хранящий название (фактически, строку) и цену (типа float) публикации. Создайте два порожденных класса: book, в котором происходит изменение счетчика страниц (типа int), и tape,
в котором происходит изменение счетчика записанных на кассету минут. Каждый из классов должен иметь метод getdata(), запрашивающий информацию у пользователя, и putdata() для 
вывода данных на экран.

11_02ex.cpp
Напишите main(), где создавался бы массив указателей на класс publication. Это очень похоже на то, что мы делали в текущей главе на примере VIRTPERS. 
В цикле запрашивайте у пользователя данные о конкретной книге или кассете, используйте new для создания нового объекта book или tape.
Сопоставляйте указатель в массиве с объектом. Когда пользователь закончит ввод исходных данных, выведите результат для всех введенных книг и кассет,
используя цикл for и единственное выражение
  pubarr[j]->putdata();   //для вывода данных о каждом объекте из массива */


#include <iostream>
#include <string>
using namespace std;

class publication 
{
private: 
  string name; 
  float price;
public:
virtual void getdata() 
{
  cout << "Введите название книги:";
  getline(cin, name, '!');
  cout << "Введите цену:";
  cin >> price;
}
virtual void putdata() const 
{ 
  cout << "\nКнига: " << name << "\nЦена: " << price << endl;
}
};

class book : public publication 
{
private: 
  int pages;
public:
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

class type : public publication 
{
private:
  float record;
public:
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

publication* ptrpub[100]; 
int n = 0; 
char choice;
do 
{
  cout << "Вводить данные для книги или для пленки? (b/t):"; 
  cin >> choice;
  if (choice == 'b') 
    ptrpub[n] = new book;
  else if (choice == 't') 
    ptrpub[n] = new type;
  else 
    cout << "ERROR!";
  ptrpub[n++]->getdata();
  cout << "Желаете продолжить?(y/n)"; 
  cin >> choice;
} while (choice != 'n');
 
for (int j = 0; j < n; j++) 
  ptrpub[j]->putdata(); 
 
cout << endl; system("pause"); return 0;
}
