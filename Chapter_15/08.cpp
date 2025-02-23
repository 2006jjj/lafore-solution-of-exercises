/*15_08ex.cpp
Алгоритм copy() можно использовать для копирования последовательностей в контейнере. Тем не менее нужно внимательно следить за тем, чтобы целевая последовательность
не перекрывала исходную. Напишите программу, позволяющую производить копирование последовательностей внутри контейнера. Допустим, пользователь вводит значения fist1, last1 и first2.
Осуществляйте в программе проверку того, что последовательность, перекрывающая другую, сдвигается налево, а не направо. (Например, можно сдвигать некоторые данные из позиции 10
в позицию 9, но не в позицию 11.) Так делается потому, что copy() начинает работу с самого крайнего элемента слева.*/


#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int SZ = 20;
int first1, last1, first2, len;
int array[SZ] = {};
for (int j = 0; j < SZ; j++)
  array[j] = j;
for (int j = 0; j < SZ; j++)
  cout << array[j] << ((j == SZ - 1) ? '\n' : ' ');
cout << "Введите индексы:"; 
cin >> first1 >> last1 >> first2;

if (first1 < 0 || first1 >= SZ || last1 >= SZ || last1<0 || first1>last1) 
{ 
  cout << "ERROR! Неверные индексы!"; 
  exit(1);
}
 
if (first2 == first1) 
{
  cout << "ERROR! Нет смысла копирования с того же места"; 
  exit(1);
}
len = last1 - first1;
if (first2 < 0 - len || first2 >= SZ) 
{ 
  cout << "ERROR! Нельзя начинать копировать за пределами массива!"; 
  exit(1); 
}
if (first2 < 0)
{
  first1 = first1 - first2;
  first2 = 0;
  cout << "Копирование происходит с выходом за пределы массива слева!" << endl;
}
if (first2 + len >= SZ)
{
  cout << "Копирование происходит с выходом за пределы массива справа!" << endl;
  last1 = (SZ - first2 - 1) + first1;
}
copy(array + first1, array + last1 + 1, array + first2);
for (int j = 0; j < SZ; j++)
  cout << array[j] << ((j == SZ - 1) ? '\n' : ' ');

cout << endl; system("pause"); return 0;
}
