/*07_04ex.cpp
Начните с программы, которая позволяет пользователю вводить целые числа, а затем сохранять их в массиве типа int.
Напишите функцию maxint(), которая, обрабатывая элементы массива один за другим, находит наибольший. Функция должна принимать в качестве аргумента адрес массива и 
количество элементов в нем, а возвращать индекс наибольшего элемента. Программа должна вызвать эту функцию, а затем вывести наибольший элемент и его индекс.*/

#include <iostream>
using namespace std;

int maxint(int[], int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int SIZE = 6; 
int array[SIZE];
cout << "Введите int числа!:\n";
for (int j = 0; j < SIZE; j++)
	cin >> array[j];
cout << "\nMax chislo v massive:\nIndex[" << maxint(array, SIZE) << "]:" << array[maxint(array, SIZE)];

cout << endl; system("pause"); return 0;
}

int maxint(int arr[], int n) 
{
  int k = 0,m = 0;
  for (int j = 0; j < n; j++) 
  {
    if (k < arr[j]) 
    {
      k = arr[j];
      m = j;
    }
  }
  return m;
}
