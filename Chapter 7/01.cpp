/*07_01ex.cpp
Напишите функцию reversit(), которая переворачивает строку (массив типа char). Используйте цикл for, который меняет местами первый и последний символы,
затем следующие и т.д. до предпоследнего. Строка должна передаваться в функцию reversit() как аргумент.*/

#include <iostream>
#include <cstring>
using namespace std;

void reversit(char[]);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
const int MAX = 80;
char str[MAX];
cout << "Введите строку:\n";
cin.get(str, MAX);
reversit(str);
 
cout << endl; system("pause"); return 0;
}

void reversit(char s[]) 
{
	int len = strlen(s) - 1;
	for (int j = 0; j < len; j++) 
  {
		char y = s[j]; 
    s[j] = s[len]; 
    s[len--] = y;
		//2 variant
    //char y=s[j]; 
    s[j] = s[len-j-1]; 
    s[len-j-1] = y; 
  }
	cout << "\nРезультат:\n" << s;
}
