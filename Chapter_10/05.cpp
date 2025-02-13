/*10_05ex.cpp
Предположим, что в функции main() определены три локальных массива одинакового размера и типа (скажем, float). Первые два уже инициализированы значениями.
Напишите функцию addarrays(), которая принимает в качестве аргументов адреса трех массивов, складывает соответствующие элементы двух массивов и помещает результат
в третий массив. Четвертым аргументом этой функции может быть размерность массивов. На всем протяжении программы используйте указатели.*/

#include <iostream>
using namespace std;

void addarrays(float*, float*, float*, int);
void display(float*, int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
const int SIZE = 7;
float arr1[SIZE] = { 5.4f, 4.2f, 0.53f, 23.2f, 12.3f, 5.0f, 0.4f }, 
      arr2[SIZE] = { 6.5f, 41.2f, 0.59f, 3.2f, 7.6f, 1.7f, 54.1f }, 
      arr3[SIZE];
cout << "Array 1" << endl; 
display(arr1, SIZE);
cout << "\nArray 2" << endl; 
display(arr2, SIZE);
addarrays(arr1, arr2, arr3, SIZE);
cout << "\nArray 3" << endl; 
display(arr3, SIZE);

cout << endl; system("pause"); return 0;
}

void addarrays(float* a1, float* a2, float* a3, int n) 
{
  for (int j = 0; j < n; j++)
    *(a3 + j) = *(a1 + j) + *(a2 + j);
}
void display(float* arr, int n) 
{
  for (int j = 0; j < n; j++)
    cout << "[" << j << "]=" << *(arr + j) << endl;
}
