/*04_08ex.cpp
Вернитесь к упр. 9 главы 2. В этом упражнении требуется написать программу, которая хранит значения двух дробей в виде числителя и знаменателя, а затем складывает эти дроби
согласно арифметическому правилу. Измениту эту программу так, чтобы значения дробей хранились в структуре fraction, состоящей из двух полей типа int, предназначенных для хранения
числителя и знаменателя. Все значения дробей должны храниться в переменных типа fraction. */

#include <iostream>
using namespace std;

struct fraction 
{ 
  int chislitel, znamenatel; 
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

fraction m, n; 
char ch;
cout << "Введите первую дробь:"; 
cin >> m.chislitel >> ch >> m.znamenatel;
cout << "Введите вторую дробь:"; 
cin >> n.chislitel >> ch >> n.znamenatel;
cout << "Сумма равна " << (m.chislitel * n.znamenatel + m.znamenatel * n.chislitel) << ch << (m.znamenatel * n.znamenatel)<<endl;

system("pause"); return 0;
}
