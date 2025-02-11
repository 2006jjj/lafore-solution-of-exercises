/*08_02ex.cpp
Напишите программу, которая заменяет перегруженную операцию + на перегруженную операцию += в программе STRPLUS этой главы. 
Эта операция должна позволять записывать выражения типа:
  s1+=s2;
где s2 прибавляется (объединяется) к строке s1, результат при этом остается в s1. Операция должна также позволять использовать
результат для других вычислений, например в выражениях типа
  s3=s1+=s2;*/


#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class String 
{
private:
  static const int SZ = 80;
  char str[SZ];
public:
String() 
{ 
    strcpy(str, ""); 
}
String(const char s[]) 
{ 
  strcpy(str, s); 
}
void display() onst 
{ 
  cout << str; 
}
String operator+= (String s2) 
{
  if (strlen(str) + strlen(s2.str) >= SZ) 
  {
    cout << "\nПереполнение!"; 
    exit(1);
  }
  return String(strcat(str, s2.str));
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

String s1 = "\nС Рождеством! ", s2 = "С Новым Годом!", s3;
s1.display(); 
s2.display(); 
s3.display();
s1 += s2; 
s1.display();
s3 = s1 += s2; 
s3.display();

cout << endl; system("pause"); return 0;
}
