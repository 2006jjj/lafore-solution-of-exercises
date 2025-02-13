/*09_02ex.cpp
Вспомните пример STRCONV из главы 8. Класс String в этом примере имеет дефект: у него нет защиты на тот случай, если его объекты будут инициализированы
слишком длинной строкой (константа SZ имеет значение 80). 
Например, определение
  String s = "Эта строка имеет очень большую длину и мы можем быть уверены, что она не уместится в отведенный буфер, что приведет к непредсказуемым последствиям.";
будет причиной переполнения массива str строкой s с непредсказуемыми последствиями вплоть до краха системы.
Создадим класс Pstring, производный от класса String, в котором предотвратим возможность переполнения буфера при определении слишком длинной строковой константы.
Новый конструктор производного класса будет копировать в str только SZ-1 символов, если строка окажется слишком длинной, и будет копировать строку полностью,
если она будет иметь длину меньшую, чем SZ. Напишите функцию main() программы для проверки ее работы со строками разной длины.*/

#include <iostream>
#include <string> 
#include <stdio.h> 
#include <string.h> 
#include <locale.h> 
#include <cstring>  
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

void display()const 
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
Pstring() : String() 
{ 
  str[0] = '\0'; 
}
Pstring(const char s[]) 
{
  if (strlen(s) > SZ - 1) 
  {
    for (int j = 0; j < SZ - 1; j++) 
    { 
      str[j] = s[j]; 
    }
    str[SZ - 1] = '\0';
  }
  else 
    String(s);
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Pstring s1;
char xstr[] = "Yra, tovariwi! Counter Strike the best game in the world, yafffffffffffff";
s1 = xstr; 
s1.display();
 
cout << endl; system("pause"); return 0;
}
