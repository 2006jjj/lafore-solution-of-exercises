/*04_06ex.cpp
Как мы говорили, стандартные средства ввода/вывода C++ вместо значений перечисляемых типов данных выводят их внутреннее представление в виде целых чисел.
Для того чтобы преодолеть это ограничение, вы можете использовать конструкцию switch, с помощью которой устанавливается соответствие между значением переменной перечисляемого типа 
и ее внутренним представлением. Пусть, например, в программе определен перечисляемый тип данных etype, отражающий должность сотрудника:
    enum etype { laborer, secretary, manager, accountant, executive, researcher }; 
Напишите программу, которая сначала по первой букве должности, введенной пользователем, определяет соответствующее значение переменной, помещает это значение в переменную типа etype,
а затем выводит полностью название должности, первую букву которой ввел пользователь. Взаимодействие программы с пользователем может выглядеть следующим образом:
    Введите первую букву должности
    (laborer, secretary, manager, accountant, executive, researcher): a
    Полное название должности: accountant
Возможно, вам понадобится два ветвления switch: одно - для ввода значения, другое - для вывода. */

#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
etype x; 
char ch;
cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): "; 
cin >> ch;
cout << "Полное название должности: ";
		switch (ch) 
 		  	 {
			case 'l': x = laborer; break;
			case 's': x = secretary; break;
			case 'm': x = manager; break;
			case 'a': x = accountant; break;
			case 'e': x = executive; break;
			case 'r': x = researcher; break; 
  			  }

		switch (x) 
   			 {
			case laborer: cout << "laborer"; break;
			case secretary: cout << "secretary"; break;
			case manager: cout << "manager"; break;
			case accountant: cout << "accountant"; break;
			case executive: cout << "executive"; break;
			case researcher: cout << "researcher"; break; 
   			 }
cout<<endl; 
system("pause"); return 0;
}
