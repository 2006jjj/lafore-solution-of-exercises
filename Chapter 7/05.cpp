/*07_05ex.cpp
Начните с класса fraction из упр. 11 и 12 главы 6. Напишите функцию main(), которая получает случайные дробные числа от пользователя, сохраняет их в массиве
типа fraction, вычисляет среднее значение и выводит результат.*/

#include <iostream>
using namespace std;

class Fraction 
{
private:
  int num, den; 
  static char ch;
public:
Fraction() : num(0), den(0) {}

void put_fraction() 
{ 
  cin >> num >> ch >> den; 
}

void display() const
{ 
  cout << num << ch << den; 
}

void fadd(Fraction arr[], int n)
{
  num = arr->num; 
  den = arr->den;
	cout << "\nСложение:";
  for (int j = 1; j < n; j++)
  {
    num = num * arr[j].den + den * arr[j].num;
    den = den * arr[j].den;
    cout << "\nПромежуточная дробь[" << j << "]: " << num << ch << den;
  }
  num /= n;
  den /= n;
  cout << "\nСреднее значение дробей:" << num << ch << den;
}
};
char Fraction::ch = '/';

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int SIZE = 6; 
int j = 0;
char c1;
Fraction arr[SIZE], res;
do 
{
  cout << "Введите дробь:"; arr[j++].put_fraction();
  if (j >= SIZE) break;
  cout << "Желаете продолжить? (y/n):";
  cin >> c1;
} while (c1 != 'n');
for (int j = 0; j < SIZE; j++) 
{
	cout << "\nIndex[" << j << "]:"; arr[j].display();
}
res.fadd(arr, j); 
 
cout << endl; system("pause"); return 0;
}
