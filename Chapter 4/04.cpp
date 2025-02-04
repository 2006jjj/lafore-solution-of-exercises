/*04_04ex.cpp
Создайте структуру с именем employee, содержащую два поля: номер сотрудника типа int и величину его пособия в долларах типа float.
Запросите с клавиатуры данных о трех сотрудниках, сохраните их в трех структурных переменных типа employee и выведите информацию о каждом из сотрудников на экран.*/

#include <iostream>
#include <iomanip> 
using namespace std;

struct employee
{ 
  int number; 
  float posobie; 
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

employee s1, s2, s3;
cout << "Введите номер первого сотрудника и его пособие:"; 
cin >> s1.number >> s1.posobie;
cout << "Введите номер второго сотрудника и его пособие:"; 
cin >> s2.number >> s2.posobie;
cout << "Введите номер третьего сотрудника и его пособие:"; 
cin >> s3.number >> s3.posobie;
cout << "\nПервый сотрудник: №" << s1.number << ". Пособие: " << s1.posobie << "$" 
  << "\nВторой сотрудник: №" << s2.number << ". Пособие: " << s2.posobie << "$" 
  << "\nТретий сотрудник: №" << s3.number << ". Пособие: " << s3.posobie << "$";
	
system("pause"); return 0;
}
