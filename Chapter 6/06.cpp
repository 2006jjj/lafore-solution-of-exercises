/*06_06ex.cpp
Расширьте содержание класса employee из упр. 4, включив в него класс date и перечисление etype (см. упр. 6 главы 4). Объект класса date будет использоваться для хранения
даты приема сотрудника на работу. Перечисление будет использовано для хранения статуса сотрудника: лаборант, секретарь, менеджер и т.д.
Последние два поля данных должны быть закрытыми в определении класса employee, как и номер и оклад сотрудника. Вам будет необходимо разработать методы getemploy() и putemploy(),
предназначенные соответственно для ввода и отображения информации о сотруднике. Возможно, при создании методов вам понадобится ветвление switch для работы с перечисляемым типом etype.
Напишите функцию main(), которая попросит пользователя ввести данные о трех сотрудниках, а затем выведет эти данные на экран.*/

#include <iostream>
using namespace std;

char ch = '/';
class date 
{
private:
  int day, month, year;
public: 
date() : day(0), month(0), year(0) {}
date(int y, int m, int d) : day(d), month(m), year(y) {}

void showdate() 
{ 
  cout << "Дата:" << day << ch << month << ch << year; 
}
};

class employee 
{
private: 
  int number; 
  float posobie; 
  date data; 
  enum etype { laborer, secretary, manager, accountant, executive, researcher }; 
  etype x; 
  char c;
public:
employee() : number(0), posobie(0.0F), c(' '), x(laborer) {}

void getemploy() 
{
  cout << "Введите номер сотрудника и его пособие: "; 
  cin >> number >> posobie;
  cout << "Введите дату в формате (xx/xx/xxxx):";
  cin >> data.day >> ch >> data.month >> ch >> data.year;
if ((data.month > 12) || (data.day > 31)) 
  { 
    cout << "ERROR!";  
    exit(1); 
  }
  cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): "; 
  cin >> c;
		switch (c) 
		{
		case 'l': x = laborer; break;
		case 's': x = secretary; break;
		case 'm': x = manager; break;
		case 'a': x = accountant; break;
		case 'e': x = executive; break;
		case 'r': x = researcher; break;
		}
}

void putemploy() const 
{
cout << "\nСотрудник № " << number << "\nПособие: " << posobie << "$" << "\nДата приема на работу: " << data.day << ch << data.month << ch << data.year << "\n" << "Должность: ";
		switch (x) 
		{
		case laborer: cout << "Рабочий\n"; break;
		case secretary: cout << "Секретарь\n"; break;
		case manager: cout << "Менеджер\n"; break;
		case accountant: cout << "Бухгалтер\n"; break;
		case executive: cout << "Руководитель\n"; break;
		case researcher: cout << "Исследователь\n"; break;
		}
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

employee s1, s2, s3;
s1.getemploy(); 
s2.getemploy(); 
s3.getemploy();
 
s1.putemploy(); 
s2.putemploy(); 
s3.putemploy(); 

cout << endl; system("pause"); return 0;
}
