/*14_06ex.cpp
Начните работу с класса safearray из программы ARROVER3 (глава 8). Сделайте класс шаблоном, чтобы массив мог хранить любые типы данных.
В секции main() создайте, по крайней мере, два массива разных типов.*/

#include <iostream>
using namespace std;

const int LIMIT = 10;
template <class K>
class safearray 
{
private: 
  K arr[LIMIT];
public:
K& operator [] (int n)
{
  if (n < 0 || n >= LIMIT) 
  { 
    cout << "\nОшибочный индекс!"; 
    exit(1); 
  }
  return arr[n];
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

safearray<int> sa1;
for (int j = 0; j < LIMIT; j++)
	sa1[j] = j * 10;
for (int j = 0; j < LIMIT; j++) 
{ 
  int temp = sa1[j]; 
  cout << "Элемент " << j << " равен " << temp << endl; 
}
cout << endl;
 
safearray<float> sa2;
for (int j = 0; j < LIMIT; j++)
	sa2[j] = j * 11.1;
for (int j = 0; j < LIMIT; j++) 
{ 
  float temp = sa2[j]; 
  cout << "Элемент " << j << " равен " << temp << endl; 
}

cout << endl; system("pause"); return 0;
}
