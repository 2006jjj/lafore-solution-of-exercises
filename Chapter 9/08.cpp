/*09_08ex.cpp
В некоторых компьютерных языках, таких, как Visual Basic, есть операции, с помощью которых можно выделить часть строки и присвоить ее другой строке.
(В стандартном классе string предложены различные подходы.) Используя наследование, добавьте такую возможность в класс Pstring из упр. 2. В новом производном классе
Pstring2 разместите три новых функции: left(), mid() и right().
    s2.left (s1, n)    // в строку s2 помещаются n самых левых символов строки s1
    s2.mid (s1, s, n)  // в строку s2 помещаются n символов из строки начиная с символа нормер s
    s2.right (s1, n)   // в строку s2 помещаются n самых правых символов строки s1
Вы можете использовать цикл for для копирования символ за символом подходящих частей строки s1 во временный объект класса Pstring2, который затем их возвратит.
Для получения лучшего результата используйте в этих функциях возврат по ссылке, чтобы они могли быть использованы с левой стороны знака "равно" для изменения части существующей строки.*/

#include <iostream>
#include <string.h>
using namespace std;

class String 
{
protected: 
  static const int SZ = 55; 
  char str[SZ];
public:
String() 
{ 
  str[0] = '\0';
}
String(const char s[]) 
{ 
  strcpy(str, s); 
}
void display() const 
{ 
  cout << str; 
}
operator char* () 
{ 
  return str; 
}
};

class Pstring : public String 
{
public:
Pstring() : String() {}
Pstring(const char s[]) : String(test(s)) {}
private:
const char* test(const char s[]) 
{
  if (strlen(s) >= SZ) 
  {
    char ts[SZ]; 
    int i;
    for (i = 0; i < SZ - 1; i++) 
    {
      ts[i] = s[i]; 
    }
    ts[i] = '\0';
    return ts;
  }
  else 
    return s;
}
};

class Pstring2 : public Pstring 
{
public:
Pstring2() : Pstring() {}
Pstring2(const char s[]) : Pstring(s) {}
Pstring2& left(Pstring2 s1, unsigned int n) 
{
  int i;
  for (i = 0; i < n; i++) 
  { 
    str[i] = s1[i]; 
  }
  str[i] = '\0';
  return *this;
}
Pstring2& mid(Pstring2 s1, unsigned int s, unsigned int n) 
{
  int j = 0;
  for (int i = s; i < s + n; i++) 
  { 
    str[j++] = s1[i]; 
  }
  str[j] = '\0';
  return *this;
}
Pstring2& right(Pstring2 s1, unsigned int n) 
{
  int j = 0;
  for (int i = strlen(s1) - n; i < strlen(s1); i++) 
  { 
    str[j++] = s1[i]; 
  }
  str[j] = '\0';
  return *this;
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Pstring2 s1, s2 = "YABLOKO",
s3 = "\nЭта строка имеет очень большую длину и мы можем быть уверены, что она не "
"уместится в отведенный буфер, что приведет к непредсказуемым последствиям.", s4;
char xstr[] = "Yra, tovariwi! Counter Strike the best game in the world, iyaffffffffffff xddddddd";
s1 = xstr; 
s1.display();
cout << endl;
cout << "\nahaha" << static_cast<char*>(s2) << endl; 
s2.display(); 
s3.display();
cout << "\n\n";
 
s2.left(s1, 7);  
s2.display();  
cout << endl;
 
s4 = s2.left(s1, 18);  
s4.display();  
cout << endl;
 
s2.mid(s1, 5, 6);  
s2.display();  
cout << endl;
 
s4 = s2.mid(s1, 7, 11); 
s4.display();  
cout << endl;
 
s2.right(s1, 7); 
s2.display(); 
cout << endl;
 
s4 = s2.right(s1, 5);
s4.display(); 

cout << endl; system("pause"); return 0;
}
