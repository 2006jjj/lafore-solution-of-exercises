/*14_11ex.cpp
За основу возьмите программу STRPLUS из главы 8. Добавьте класс исключений, генерируйте исключения в конструкторе с одним аргументом 
в случае, если строка инициализации слишком длинная. Генерируйте еще одно исключение в перегруженном операторе "+", если результат конкатенации
оказывается слишком длинным. Сообщайте пользователю о том, какая именно ошибка произошла.*/


#include <iostream>
#include <string.h>
using namespace std;

class String
{
private: 
  static const int SZ = 30; 
  char str[SZ];
public:
class StrEx
{
public:
  int num;
  StrEx(int n) : num(n) {}
};
String() 
{ 
  strcpy(str, ""); 
}
String(const char s[])
{
  if (strlen(s) >= SZ) 
    throw StrEx(1);
  strcpy(str, s);
}
void display() const 
{
  cout << str; 
}
String operator + (String ss)
{
  String temp;
  if (strlen(str) + strlen(ss.str) >= SZ)
  {
    throw StrEx(2);
    strcpy(temp.str, str);
    strcat(temp.str, ss.str);
  }
  return temp;
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

try
{
  String s1 = "\nС Рождестfffffffff! ", s2 = "С Новым Годом!", s3;
  s1.display();
  s2.display(); 
  s3.display();
  s3 = s1 + s2; 
  s3.display();
}
catch (String::StrEx ex)
{
  switch (ex.num)
  {
    case 1: 
      cout << "\nERROR!\nПричина(1): Конструктор с 1 аргументом: Размер строки слишком большой!\n"; 
      break;
    case 2: cout << "\nERROR!\nПричина(2): Результат конкатенации превышает допустимый размер!\n"; 
      break;	
  }
}
 
cout << endl; system("pause"); return 0;
}
