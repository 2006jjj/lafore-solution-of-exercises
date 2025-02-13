/*09_07ex.cpp
Вспомним программу COUTEN2 из этой главы. В ней можно увеличивать и уменьшать счетчик, используя префиксные операции.
Используя наследование, добавьте возможность использования постфиксных операций для случаев увеличения и уменьшения.*/

#include <iostream>
using namespace std;

class Counter 
{
protected: 
  unsigned int count;
public:
Counter() : count() {}
Counter(int c) : count(c) {}
unsigned int get_count() const 
{ 
  return count; 
}
};

class CountDn : public Counter
{
public:
CountDn() : Counter() {}
CountDn(int c) : Counter(c) {}

CountDn operator -- () 
{ 
  return CountDn(--count); 
}
CountDn operator -- (int) 
{ 
  return CountDn(count--); 
}
CountDn operator++ () 
{ 
  return CountDn(++count); 
}
CountDn operator++ (int) 
{ 
  return CountDn(count++); 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

CountDn c1; 
CountDn c2(100);
cout << "\nc1=" << c1.get_count();
cout << "\nc2=" << c2.get_count();
++c1; 
++c1; 
++c1; 
cout << "\nc1=" << c1.get_count();
CountDn c3 = --c2;
cout << "\nc3=" << c3.get_count(); 
c3++; 
c3++;
c3++; 
cout << "\nc3=" << c3.get_count(); 
c3--; 
cout << "\nc3=" << c3.get_count(); 


cout << endl; system("pause"); return 0;
}
