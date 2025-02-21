/*14_05ex.cpp
Создайте функцию amax(), возвращающую значение максимального элемента массива. Аргументами функции должны быть адрес и размер массива.
Сделайте из функции шаблон, чтобы она могла работать с массивом любого числового типа. Напишите секцию main(), в которой проверьте работу функции с разными типами массивов.*/

#include <iostream>
using namespace std;

template<class F>
F amax(F* array, const unsigned int size)
{
  F res = array[0];
  for (int j = 0; j < size; j++)
  {
    cout << array[j] << ' ';
    if (res < array[j])
      res = array[j];
  }
  cout << "\nMax Element=" << res;
  return res;
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const unsigned int SZ = 5;
int intA[SZ] = { 6,22,3,4,5 };
amax(intA, SZ); 
cout << endl;
 
float floatA[SZ] = { 4.54, 7.54, 88.88, 23.33, 1.23 };
amax(floatA, SZ); 
 
cout << endl; system("pause"); return 0;
}
