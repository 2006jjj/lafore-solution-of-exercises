/*10_11ex.cpp
Создайте класс, который позволит вам использовать 10 отдельных массивов из упр. 10 как один одномерный массив, допуская применение операций массива.
То есть мы можем получить доступ к элементам массива, записав в функции main() выражение типа a[j], а методы класса могут получить доступ к полям класса,
используя двухшаговый подход. Перегрузим операцию [], чтобы получить нужный нам результат. Заполним массив данными и выведем их. Хотя для интерфейса класса
использованы операции индексации массива, вам следует использовать указатели внутри методов класса.*/

#include <iostream>
using namespace std;

class Array 
{
private: 
  static const int SIZE = 10, NUMARRAYS = 10;
  int* ap[NUMARRAYS];
public:
Array() 
{
  for (int j = 0; j < NUMARRAYS; j++)
    *(ap + j) = new int[SIZE];
}
int& operator [] (int n) 
{
  int j = n / SIZE;
  int k = n % SIZE;
  return *(*(ap + j) + k);
}
};
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Array ar; 
int SIZE = 10;
for (int j = 0; j < SIZE * SIZE; j++)
	ar[j] = j * 10;
for (int j = 0; j < SIZE * SIZE; j++)
	cout << ar[j] << ((j % SIZE == SIZE - 1) ? "\n" : " ");

cout << endl; system("pause"); return 0;
}
