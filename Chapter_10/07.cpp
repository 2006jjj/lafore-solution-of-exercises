/*10_07ex.cpp
Модифицируйте класс person из программы PERSORT этой главы так, чтобы он включал в себя не только имя человека, но и сведения о его зарплате в виде
поля salary типа float. Вам будет необходимо изменить методы setName() и printName() на setData() и printData(), включив в них возможность ввода и вывода
значения salary, как это можно сделать с именем. Вам также понадобится метод getSalary(). Используя указатели, напишите функцию salsort(), которая сортирует указатели
массива persPtr по значениям зарплаты. Попробуйте вместить всю сортировку в функцию salsort(), не вызывая других функций, как это сделано в программе PERSORT.
При этом не забывайте, что операция -> имеет больший приоритет, чем операция *, и вам нужно будет написать 
  if((*(pp+j))->getSalary() > (*(pp+k))->getSalary())
  { /*меняем указатели местами*/} */

#include <iostream>
#include <string>
using namespace std;

class person 
{
protected: 
  string name; 
  float salary;
public:
void setData() 
{ 
  cout << "Введите имя:"; 
  cin >> name; 
  cout << "Введите зарплату:"; 
  cin >> salary; 
}
void printData() const 
{ 
  cout << "\n Имя:" << name << "\n Зарплата:" << salary;
}
string getName() const 
{ 
  return name;
}
float getSalary() const
{
  return salary; 
}
};

void salsort(person**, int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

person* ptrPts[100]; 
int n = 0; 
char choice;
do 
{
  ptrPts[n] = new person;
  ptrPts[n]->setData();
  n++;
  cout << "Желаете продолжить? (y/n):"; 
  cin >> choice;
} while (choice != 'n');
cout << "\nНеотсортированный список:";
for (int j = 0; j < n; j++) 
{ 
  cout << "\n" << j + 1 << ")"; 
  (*(ptrPts + j))->printData();
}
salsort(ptrPts, n);
cout << "\n\nОтсортированный список:";
for (int j = 0; j < n; j++) 
{ 
  cout << "\n" << j + 1 << ")"; 
  (*(ptrPts + j))->printData();
}

cout << endl; system("pause"); return 0;
}

void salsort(person** ptr, int n) 
{
	for (int j = 0; j < n - 1; j++)
		for (int k = j + 1; k < n; k++)
			if ((*(ptr + j))->getSalary() > ((*(ptr + k)))->getSalary()) 
			{
				person* temp = *(ptr + j); 
				*(ptr + j) = *(ptr + k); 
				*(ptr + k) = temp; 
			}
}
