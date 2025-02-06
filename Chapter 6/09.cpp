/*06_09ex.cpp
На основе структуры fraction из упр. 8 главы 4 создайте класс fraction. Данные класса должны быть представлены двумя полями: числителем и знаменателем.
Методы класса должны получать от пользователя значения числителя и знаменателя дроби в формате 3/5 и выводить значение дроби в этом же формате. Кроме того,
должен быть разработан метод, складывающий значения двух дробей. Напишите функцию main(), которая циклически запрашивает у пользователя ввод пары дробей, 
затем складывает их и выводит результат на экран. После каждой такой операции программа должна спрашивать пользователя, следует ли продолжать цикл. */

#include <iostream>
using namespace std;

class fraction 
{
private: 
  int chislitel, znamenatel;
public:
fraction() : chislitel(0), znamenatel(0) {}
fraction(int chi, int zn) : chislitel(chi), znamenatel(zn) {}
char ch;

void put_znachenia() 
{ 
  cout << "Введите дробь:"; 
  cin >> chislitel >> ch >> znamenatel; 
}

void show_drobj() 
{ 
  cout << "Ваша дробь:" << chislitel << "/" << znamenatel << endl; 
}

void sum_drobei(fraction f1, fraction f2) 
{ 
  chislitel = f1.chislitel * f2.znamenatel + f1.znamenatel * f2.chislitel; 
  znamenatel = f1.znamenatel * f2.znamenatel; 
  cout << "Сумма дробей = " << chislitel << "/" << znamenatel; 
}
};
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
fraction f1, f2, f3; 
char c;
do 
 {
   f1.put_znachenia();  
   f1.show_drobj(); 
   f2.put_znachenia(); 
   f2.show_drobj(); 
   f3.sum_drobei(f1, f2); 
   cout << "\nЖелаете продолжить? (y/n):";
   cin >> c;
 } while (c != 'n');

cout << endl; system("pause"); return 0;
}
