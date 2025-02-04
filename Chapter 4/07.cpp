/*04_07ex.cpp
Добавьте поля типа enum etype (см. упр. 6) и struct date (см. упр. 5) в структуру employee из упр. 4. 
Организуйте программу таким образом, чтобы пользователь вводил 4 пункта данных о каждом из трех сотрудников: eго номер, величину зарплаты, его должность и дату принятия на работу.
Программа должна хранить введенные значения в трех перменных типа employee и выводить их содержимое на экран. */

#include <iostream>
using namespace std;

struct date 
{ 
  int day, mounth, year; 
};
struct employee 
{ 
  int number; 
  float salary; 
  date data; 
  etype dolzhnost; 
};
enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

employee s1;
char ch, s;
cout << "Введите информацию первого сотрудника: \n(Номер, зарплата, первую букву должности (laborer, secretary, manager, accountant, executive, researcher), дата принятия на работу):" << endl;
cin >> s1.number >> s1.salary >> s >> s1.data.day >> ch >> s1.data.mounth >> ch >> s1.data.year;
  switch (s) 
  {
    case 'l': s1.dolzhnost = laborer; break;
    case 's': s1.dolzhnost = secretary; break;
    case 'm': s1.dolzhnost = manager; break;
    case 'a': s1.dolzhnost = accountant; break;
    case 'e': s1.dolzhnost = executive; break;
    case 'r': s1.dolzhnost = researcher; break;
  }
cout << "Первый сотрудник:\n" << "Номер:" << s1.number << "\nЗарплата:" << s1.salary << "$\n" << "Должность:" << endl;
  switch (s1.dolzhnost) 
  {
    case laborer: cout << "laborer"; break;
    case secretary: cout << "secretary"; break;
    case manager: cout << "manager"; break;
    case accountant: cout << "accountant"; break;
    case executive: cout << "executive"; break;
    case researcher: cout << "researcher"; break;
  }
cout << "\nДата принятия на работу:" << s1.data.day << ch << s1.data.mounth << ch << s1.data.year << endl;
system("pause"); return 0;
}
