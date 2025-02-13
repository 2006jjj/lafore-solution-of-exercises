/*10_02ex.cpp
Используйте класс String из примера NEWSTR этой главы. Добавьте к нему метод upit(), который будет переводить символы строки в верхний регистр.
Вы можете использовать библиотечную функцию toupper(), которая принимает отдельный символ в качестве аргумента и возвращает символ, переведенный в верхний регистр (если это необходимо).
Эта функция использует заголовочный файл Cctype. Добавьте в функцию main() необходимые строки для тестирования метода upit().*/

#include <iostream>
#include <cstring>
#include <cctype> 
using namespace std;

class String 
{
private: 
  char* str;
public:
String(const char* s) 
{
  int length = strlen(s);
  str = new char[length + 1];
  strcpy(str, s);
}
~String() 
{ 
  cout << "Удаляем строку\n"; 
  delete[]str; 
}
void display() 
{ 
  cout << str << endl;
}
void upit() 
{
  int length = strlen(str);
  cout << length << endl;
  for (int j = 0; j < length; j++)
    *(str + j) = toupper(*(str + j));
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

String s1 = "helloo";
cout << "s1="; 
s1.display();
s1.upit(); 
s1.display(); 

cout << endl; system("pause"); return 0;
}
