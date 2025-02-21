/*14_08ex.cpp
Добавьте класс исключений к программе ARROVER из главы 8, чтобы индексы, выходящие за пределы массива, вызывали генерацию исключения.
Блок-ловушка может выводить пользователю сообщение об ошибке.


14_09ex.cpp
Измените программу из предыдущего упражнения таким образом, чтобы в сообщение об ошибке входила информация о значении индекса, приведшего к сбою.*/


#include <iostream>
using namespace std;

const int LIMIT = 6;
template <class K>
class safearray
{
private: 
  K arr[LIMIT];
public:
class Outofrange 
{
  public:
    int num;  
    Outofrange(int n) : num(n) {} 
};
K& operator [] (int n)
{
  if (n < 0 || n >= LIMIT)
    throw Outofrange(n);
  return arr[n];
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

try
{
  safearray<int> sa1;
  for (int j = 1; j < LIMIT; j++)
    sa1[j] = j * 10;
  
  for (int j = 1; j < LIMIT; j++) 
    cout << "Элемент " << j << " равен " << sa1[j] << endl; 
   sa1[-1] = 44; //можно менять индекс для проверки
  
  safearray<float> sa2;
  for (int j = 1; j < LIMIT; j++)
    sa2[j] = j * 11.1;
  
  for (int j = 1; j < LIMIT; j++) 
    cout << "Элемент " << j << " равен " << sa2[j] << endl;
  sa2[6] = 13.3; //можно менять индекс для проверки
}
catch (safearray<int>::Outofrange f) 
  { 
    cout << "Error out of range!(int) \nIndex:" << f.num; 
    exit(1); 
  }
catch (safearray<float>::Outofrange f) 
  { 
    cout << "Error out of range!(float) \nIndex:" << f.num; 
    exit(1); 
  }

cout << endl; system("pause"); return 0;
}
