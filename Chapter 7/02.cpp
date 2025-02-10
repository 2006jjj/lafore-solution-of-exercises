/*07_02ex.cpp
Создайте класс employee, который содержит имя (объект класса string) и номер (типа long) служащего. Включите в него метод getdata(), предназначенный для получения данных
от пользователя и помещения их в объект, и метод putdata(), для вывода данных. Предполагаем, что имя может иметь внутренние пробелы.
Напишите функцию main(), использующую этот класс. Вам нужно будет создать массив типа employee, а затем предложить пользователю ввести данные до 100 служащих.
Наконец, вам нужно будет вывести данные всех служащих.*/

#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;

class employee 
{
private: 
  string name; 
  long number;
public:
void getdata() 
{ 
  cout << "Введите имя пользователя:"; 
  getline(cin, name, '!'); 
  cout << "Введите номер пользователя:"; 
  cin >> number; 
}
void putdata() const 
{ 
  cout << "\nПользователь №" << number << "\nИмя: " << name; 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
employee emp[100]; 
int x = 0; 
char ch;
cout << "Введите данные о пользователях!\n";
do 
{ 
  emp[x++].getdata(); 
  cout << "Желаете продолжить?(y/n):"; 
  cin >> ch; 
} while (ch != 'n');
 
for (int j = 0; j < x; j++) 
{ 
  emp[j].putdata(); 
}
cout << endl; system("pause"); return 0;
}
