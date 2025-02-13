/*09_10ex.cpp
В программе EMPMULT этой главы существует только один тип должности менеджера. В любой серьезной компании кроме менеджеров существуют еще и управляющие.
Создадим производный от класса manager класс executive. (Мы предполагаем, что управляющий - это главный менеджер.)
Добавочными данными этого класса будут размер годовой премии и количество его акций в компании. Добавьте подходящие методы для этих данных, позволяющие их вводить и выводить.*/

#include <iostream>
using namespace std;

const int LEN = 80;
class student 
{
private: 
  char school[LEN]; 
  char degree[LEN];
public:
void getedu() 
{
  cout << " Введите название учебного заведения: "; 
  cin >> school;
  cout << " Введите степень высшего образования\n"; 
  cout << " (неполное высшее, бакалавр, магистр, кандидат наук): "; 
  cin >> degree;
}
void putedu() const 
{ 
  cout << "\n Учебное заведение: " << school; 
  cout << "\n Степень: " << degree; 
}
};

class employee 
{
private: 
  char name[LEN]; 
  unsigned long number;
public:
void getdata() 
{ 
  cout << "Введите фамилию: "; 
  cin >> name; 
  cout << " Введите номер: "; 
  cin >> number;
}
void putdata() const 
{
  cout << "\nФамилия: " << name; 
  cout << "\n Номер:" << number;
}
};

class manager : private employee, private student 
{
private: 
  char title[LEN]; 
  double dues;
public:
void getdata() 
{
  employee::getdata(); 
  cout << " Введите должность: "; 
  cin >> title;
  cout << " Введите сумму взносов в гольф-клуб: "; 
  cin >> dues; 
  student::getedu(); 
}
void putdata() const 
{ 
  employee::putdata(); 
  cout << "\n Должность: " << title; 
  cout << "\n Сумма взносов в гольф-клуб: " << dues; 
  student::putedu(); 
}
};

class executive : private manager 
{
private: 
  double year_premia; 
  unsigned long shares;
public:
void getdata() 
{ 
  manager::getdata(); 
  cout << "Введите размер годовой премии:"; 
  cin >> year_premia; 
  cout << "Введите количество акций компании:"; 
  cin >> shares; 
}
void putdata() const
{ 
  manager::putdata(); 
  cout << "\n Размер годовой премии:" << year_premia; 
  cout << "\n Количество акций:" << shares; 
}
};

class scientis : private employee, private student 
{
private: 
  int pubs;
public:
void getdata() 
{ 
  employee::getdata(); 
  cout << " Введите количество публикаций: "; 
  cin >> pubs; 
  student::getedu(); 
}
void putdata() const 
{ 
  employee::putdata(); 
  cout << "\n Количество публикаций: " << pubs;
  student::putedu(); 
}
};

class laborer : public employee {};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

executive e1; 
e1.getdata(); 
e1.putdata(); 

cout << endl; system("pause"); return 0;
}
