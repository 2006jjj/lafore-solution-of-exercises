/*10_06ex.cpp
Создайте свою версию библиотечной функции strcmp(s1,s2), которая сравнивает две строки и возвращает -1, если s1 идет первой по алфавиту, 0, если 
в s1 и s2 одинаковые значения, и 1, если s2 идет первой по алфавиту. Назовите вашу функцию compstr(). Она должна принимать в качестве аргументов два указателя на строки char*,
сравнивать эти строки посимвольно и возвращать число int. Напишите функцию main() для проверки работы вашей функции с разными строками. Используйте указатели во всех возможных ситуациях.*/

#include <iostream>
using namespace std;

int compstr(const char*, const char*);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
const char* str1 = "11234"; 
const char* str2 = "1234";
int res = strcmp(str1, str2); 
cout << "res(strcmp)=" << res << endl;
res = compstr(str1, str2);
cout << "res(compstr)=" << res << endl;

str1 = "123";
str2 = "123";
res = strcmp(str1, str2); 
cout << "\nres(strcmp)=" << res << endl;
res = compstr(str1, str2);
cout << "res(compstr)=" << res << endl;

str1 = "1234";
str2 = "123";
res = strcmp(str1, str2); 
cout << "\nres(strcmp)=" << res << endl;
res = compstr(str1, str2);
cout << "res(compstr)=" << res << endl;

cout << endl; system("pause"); return 0;
}

int compstr(const char* str1, const char* str2) 
{
  while (*str1 && *str2) 
  {
    if (*str1 > *str2) 
      return 1;
    else if (*str1 < *str2) 
      return -1;
    str1++; str2++;
  }
	if (!*str1 && !*str2)
    return 0;
	else if (!*str1) 
    return -1;
	else 
    return 1;
}
