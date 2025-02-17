/*11_04ex.cpp
Как уже говорилось, классы можно заствлять вести себя как массивы. Пример CLARRAY показывает один из способов создания такого класса.
  Листинг 11.26. Программа CLARRAY
  //clarray.cpp
  //создает класс-массив
  #include <iostream>
  using namespace std;
///////////////////////////////////////////////////////
  class Array    //моделирует обычный массив С++
  {
    private: 
      int* ptr;   
      int size;   
    public:
      Array(int s)
      {
        size=s;           
        ptr = new int[s];   
      }
      ~Array()        
        { delete[] ptr; }
      int& operator [] (int j)
      { return *(ptr+j); }
  };
//////////////////////////////////////////////////////////
  int main()
  {
    const int ASIZE = 10;
    Array arr(ASIZE);

    for (int j=0; j<ASIZE; j++)
        arr[j]=j*j;

    for (int j=0; j<ASIZE; j++)
        cout<<arr[j]<< ' ' ;
    cout<<endl;
    return 0;
  }

Результат работы программы:
  0 1 4 9 16 25 36 49 64 81

Взяв за основу приведенную программу, добавьте перегружаемое присваивание и перегружаемый конструктор копирования к классу Array.
Затем добавьте к main() выражение Array arr2(arr1); и arr3=arr1; для проверки того, что перегружаемые операции работают.
Конструктор копирования должен создать новый объект Array со своим собственным местом в памяти, выделенным для хранения элементов массива.
И конструктор копирования, и оператор присваивания должны копировать содержимое старого объекта класса Array в новый.*/


#include <iostream>
#include <string>
using namespace std;

class Array 
{
private: 
  int* ptr; 
  int size;
public:
Array() : ptr(0), size(0) {}
Array(int s)
{ 
  size = s; 
  ptr = new int[s];
}
~Array() 
{ 
	delete[] ptr; 
	cout << "element udalen\n";
}
Array(Array& arr) 
{
  size = arr.size;
  ptr = new int[size];
  for (int j = 0; j < size; j++)
    *(ptr + j) = *(arr.ptr + j);
}
void display() 
{
  for (int j = 0; j < size; j++)
    cout << *(ptr + j) << ' ';
}
int& operator[](int j) 
{ 
  return *(ptr + j); 
}
Array& operator=(Array& arr) 
{
  if (this == &arr)
    return *this;
  delete[] ptr;
  size = arr.size;
  ptr = new int[size];
  for (int j = 0; j < size; j++)
    *(ptr + j) = *(arr.ptr + j);
  return *this;
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int ASIZE = 10;
Array arr1(ASIZE);
for (int j = 0; j < ASIZE; j++)
	arr1[j] = j * j;
cout << "arr1 = "; 
arr1.display(); cout << endl;
 
Array arr2(arr1);
cout << "arr2 = "; 
arr2.display(); cout << endl;
 
Array arr3(10), arr4(5), arr5(15);
arr3 = arr1;  
arr4 = arr1;  
arr5 = arr1;
cout << "arr3 = "; 
arr3.display(); cout << endl;
cout << "arr4 = "; 
arr4.display(); cout << endl;
cout << "arr5 = "; 
arr5.display(); cout << endl;
arr1 = arr1;
cout << "arr1 = "; 
arr1.display(); cout << endl;
Array arr6, arr7;
arr7 = arr6 = arr1;
cout << "arr6 = "; 
arr6.display(); cout << endl;
cout << "arr7 = "; 
arr7.display(); cout << endl; 

cout << endl; system("pause"); return 0;
}
