/*06_08ex.cpp
Создайте класс, одно из полей которого хранит "порядковый номер" объекта, то есть для первого созданного объекта значение этого поля равно 1, 
для второго созданного объекта значение равно 2 и т.д. Для того чтобы создать такое поле, вам необходимо иметь еще одно поле, в которое будет записываться количество 
созданных объектов класса (это означает, что последнее поле должно относиться не к отдельным объектам класса, а ко всему классу в целом. Вспомните, какое ключевое слово необходимо при описании такого поля.)
Каждый раз при создании нового объекта конструктор может получить значение этого поля и в соответствии с ним назначить объекту индивидуальный порядковый номер.
В класс следует включить метод, который будет выводить на экран порядковый номер объекта. Создайте функцию main(), в которой будут созданы три объекта, и каждый объект выведет на экран свой порядковый номер,
например: Мой порядковый номер: 2 и т.п.*/

#include <iostream>
using namespace std;

class Count 
{
private:
	int number; 
	static int count;
public:
Count() 
{ 
  count++; 
  number = count; 
}
void showcount() 
{ 
  cout << "Мой порядковый номер: " << number << endl; 
}
};

int Count::count = 0;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Count c1, c2, c3, c4;
c1.showcount(); 
c2.showcount(); 
c3.showcount(); 
c1.showcount();

cout << endl; system("pause"); return 0;
}
