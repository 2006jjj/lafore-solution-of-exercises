/*14_01ex.cpp
Напишите шаблон функции, возвращающей среднее арифметическое всех элементов массива. Аргументами функции должны быть имя и размер массива (типа int).
В main() проверьте работу функции с массивами типа int, long, double и char.*/


#include <iostream>
using namespace std;

template <class T>
T average(T* array, const unsigned int size)
{
  double res = 0.0;
  for (int j = 0; j < size; j++)
    res += array[j];
  return res / size;
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const unsigned int SZ = 5;
int intA[SZ] = { 1,2,3,4,5 };
cout << "AVERAGE INT ARRAY = " << average(intA, SZ) << endl;
 
double doubleA[SZ] = { 1.4, 2.3, 6.4, 6.2, 8.4 };
cout << "AVERAGE DOUBLE ARRAY = " << average(doubleA, SZ) << endl;
 
long longA[SZ] = { 45L, 123L, 677L, 777L, 3434L };
cout << "AVERAGE LONG ARRAY = " << average(longA, SZ) << endl;
 
char charA[SZ] = { "NIKE" };
cout << "AVERAGE CHAR ARRAY = " << average(charA, SZ) << " code of this symbol=" << (int)average(charA, SZ) << endl; 

cout << endl; system("pause"); return 0;
}
