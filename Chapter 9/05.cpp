/*09_05ex.cpp
Создайте производный класс employee2 от базового класса employee из программы EMPLOY этой главы. Добавьте в новый класс поле compensation типа double 
и поле period типа enum для обозначения периода оплаты работы служащего: почасовая, понедельная или помесячная. Для простоты вы можете изменить классы
laborer, manager и scientist так, чтобы они стали производными нового класса employee2. Однако заметим, что во многих случаях создание отдельного класса 
compensation и трех его производных классов manager2, scientist2 и laborer2 более соответствовало бы духу ООП. Затем можно применить множественное наследование
и сделать так, чтобы эти три новых класса стали производными класса compensation и первоначальных классов manager, scientist и laborer. Таким путем можно
избежать модификации исходных классов.*/

#include <iostream>
using namespace std;

const int LEN = 80;
class employee {
private: 
  char name[LEN]; 
  unsigned long number;
public:
void getdata() 
{ 
  cout << "\n Введите фамилию: "; 
  cin >> name; 
  cout << " Введите номер: "; 
  cin >> number; 
}
void putdata() const 
{ 
  cout << "\n Фамилия: " << name; 
  cout << "\n Номер:" << number; 
} 
};

class compensation 
{
private: 
  double comp; 
  enum etype { hourly = 1, weekly, monthly }; 
  etype PO;
public: 
compensation() : comp(0.0), PO(hourly) {}
void getdata() 
{
  unsigned short x = 0; 
  cout << "Выберите период оплаты служащего(1-почасовая, 2-понедельная, 3-помесячная):"; 
  cin >> x;
  switch (x) 
  { 
    case 1: PO = hourly; 
      break; 
    case 2: PO = weekly; 
      break; 
    case 3: PO = monthly;
      break; 
    default: cout << "ERROR"; 
      exit(1); 
  }
  cout << "Введите ставку:"; 
  cin >> comp; 
}

void putdata() const 
{
  cout << "\nПериод оплаты служащего:";
  switch (PO)
    { 
      case 1: cout << "почасовая"; 
        break; 
      case 2: cout << "понедельная"; 
        break; 
      case 3: cout << "помесячная"; 
        break; 
      default: cout << "ERROR"; 
        exit(1); 
    }
  cout << "\nСумма ставки:" << comp << endl; 
} 
};

class manager : public employee 
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
}
void putdata() const 
{ 
  employee::putdata(); 
  cout << "\n Должность: " << title; 
  cout << "\n Сумма взносов в гольф-клуб: " << dues; 
} 
};

class scientis : public employee 
{
private: 
  int pubs;
public:
void getdata() 
{ 
  employee::getdata();
  cout << " Введите количество публикаций: ";
  cin >> pubs; 
}
void putdata() const 
{ 
  employee::putdata(); 
  cout << "\n Количество публикаций: " << pubs; 
} 
};

class laborer : public employee {};

class manager2 : public manager, public compensation 
{
public:
void getdata() 
{ 
  manager::getdata(); 
  compensation::getdata(); 
}
void putdata() 
{ 
  manager::putdata(); 
  compensation::putdata(); 
} 
};

class scientis2 : public scientis, public compensation 
{
public:
void getdata() 
{ 
  scientis::getdata(); 
  compensation::getdata(); 
}
void putdata() 
{ 
  scientis::putdata(); 
  compensation::putdata(); 
} 
};

class laborer2 : public laborer, public compensation 
{
public:
void getdata() 
{
  laborer2::getdata(); 
  compensation::getdata(); 
}
void putdata() 
{ 
  laborer2::putdata(); 
  compensation::putdata(); 
} 
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

manager2 m1; 
scientis2 s1; 
laborer l1; 
m1.getdata(); 
m1.putdata(); 
s1.getdata(); 
s1.putdata(); 
l1.getdata(); 
l1.putdata(); 

cout << endl; system("pause"); return 0;
}
