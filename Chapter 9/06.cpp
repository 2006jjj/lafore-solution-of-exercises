/*09_06ex.cpp
Вспомним программу ARROVER3 из главы 8. Сохраним класс safearray таким же и, используя наследование, добавим к нему возможность для пользователя определять верхнюю и нижнюю 
границы массивы в конструкторе. Это похоже на упр. 9 из главы 8, за исключением того, что применено наследование для создания нового класса (можно назвать его safehilo) взамен
модификации исходного класса.*/

#include <iostream>
#include <process.h> 
using namespace std;

class safearray 
{
protected: 
  static const int SZ = 101; 
  int arr[SZ];
public: 
safearray() : arr{} {}
int& operator [] (int n) 
{ 
  return arr[n]; 
}
};

class safehilo : public safearray 
{
private: 
  int a, b;
public: 
safehilo() 
{ 
  cout << "Введите первую границу:"; 
  cin >> a; 
  cout << "Введите вторую границу:"; 
  cin >> b; 
  if (a > b || b - a > SZ) 
  { 
    cout << "\nError!"; 
    exit(1); 
  } 
  else b -= a;
}
int getlimit() 
{ 
  return b;
}
};
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

safehilo granici; 
safearray sa1;
for (int j = 1; j <= granici.getlimit(); j++) 
  sa1[j] = j * 10;
for (int j = 1; j <= granici.getlimit(); j++) 
  cout << "Элемент " << j << " равен " << sa1[j] << endl; 

cout << endl; system("pause"); return 0;
}
