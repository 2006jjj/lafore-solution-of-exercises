/*06_04ex.cpp
Создайте класс employee, используя упр. 4 главы 4. Класс должен включать поле типа int для хранения номера сотрудника и поле типа float для хранения величины его оклада.
Методы класса должны позволять пользователю вводить и отображать данные класса. Напишите функцию main(), 
которая запросит пользователя ввести данные для трех сотрудников и выведет полученную информацию на экран.*/

#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

class employee 
{
private: 
  int number; 
  float posobie;
public:
	employee() : number(0), posobie(0.0F) {}
void enter() 
{ 
  cout << "Введите номер сотрудника и его пособие: "; 
  cin >> number >> posobie; 
}
void display() const 
{ 
  cout << "\nСотрудник № " << number << "\nПособие:" << posobie << "$" << endl; 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

employee s1, s2, s3;
s1.enter(); 
s2.enter(); 
s3.enter();
cout << "\nИнформация о введенных сотрудниках:";
s1.display(); 
s2.display(); 
s3.display();

cout << endl; system("pause"); return 0;
}
