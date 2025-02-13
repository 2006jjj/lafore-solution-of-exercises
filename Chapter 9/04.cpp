/*09_04ex.cpp
Предположим, что издатель из упр. 1 и 3 решил добавить к своей продукции версии книг на компьютерных дисках для тех, кто любит читать книги на своих компьютерах.
Добавьте класс disk, который, как book и type, является производным класса publication. Класс disk должен включать в себя те же функции, что и в других классах.
Поле только этого класса будет тип диска: CD или DVD. Для хранения этих данных вы можете ввести тип enum. Пользователь должен выбрать подходящий тип, набрав на клавиатуре c или d.*/

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

class disk : private publication 
{
private: 
  enum edisk { CD, DVD, _ERROR }; 
  char ch = '\0'; 
  edisk tdisk = _ERROR;
public: 
void getdata() 
{ 
  publication::getdata(); 
  cout << "Введите тип диска (c=cd / d=dvd):"; 
  cin >> ch; 
  ch == 'c' ? tdisk = CD : tdisk = DVD; 
  if (ch != 'c' && ch != 'd') 
    tdisk = _ERROR; 
}
void putdata() const 
{ 
  publication::putdata(); 
  cout << "Тип диска:"; 
  if (tdisk == 0) 
    cout << "CD"; 
  else if (tdisk == 2) 
    cout << "ERROR!"; 
  else 
    cout << "DVD"; 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

disk d1; 
d1.getdata(); 
d1.putdata(); 

cout << endl; system("pause"); return 0;
}
