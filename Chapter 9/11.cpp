/*09_11ex.cpp
В различных ситуациях иногда требуется работать с двумя числами, объединенными в блок. Например, каждая из координат экрана имеет горизонтальную составляющую (х) и вертикальную (у).
Представьте такой блок чисел в качестве структуры pair, которая содержит две переменные типа int.
Теперь предположим, что мы хотим иметь возможность хранить переменные типа pair в стеке. То есть мы хотим иметь возможность положить переменную типа pair в стек путем вызова метода push() 
с переменной типа pair в качестве аргумента и вынуть ее из стека путем вызова метода pop(), возвращающего переменную типа pair. 
Начнем с класса Stack2 программы STAKEN из этой главы. Создадим производный от него класс pairStack. В нем будут содержаться два метода: перегружаемый метод push() и 
перегружаемый метод pop(). Метод pairStack::push() должен будет сделать два вызова метода Stack2::push(), чтобы сохранить оба числа из пары, а метод pairStack::pop() 
должен будет сделать два вызова метода Stack2::pop().*/

#include <iostream>
#include <process.h>
using namespace std;

struct Pair 
{ 
  int x, y; 
};

class Stack 
{
protected:
  static const int MAX = 10; 
  int st[MAX]; 
  int top;
public:
Stack() 
{ 
  top = -1;
}
void push(int var) 
{ 
  st[++top] = var;
}
int pop() 
{ 
  return st[top--]; 
}
};

class Stack2 : public Stack 
{
public:
void push(int var) 
{
  if (top >= MAX - 1) 
  { 
    cout << "Ошибка: стек полон!"; 
    exit(1); 
  }
  Stack::push(var);
}
int pop() 
{
  if (top < 0) 
  { 
    cout << "Ошибка: стек пуст!" << endl; 
    exit(1); 
  }
  return Stack::pop();
}
};

class pairStack : public Stack2 
{
public:
void push(Pair var) 
{ 
  Stack2::push(var.x); 
  Stack2::push(var.y); 
}
Pair pop() 
{ 
  Pair var;
  var.y = Stack2::pop();
  var.x = Stack2::pop(); 
  return var; 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Pair p1{ 2,5 }, p2{ 1,4 }, p3{ 5,8 }, p4{ 9,2 }, pres;
pairStack s1;
s1.push(p1); 
s1.push(p2);
s1.push(p4); 
s1.push(p3);
pres = s1.pop(); 
cout << pres.x << " " << pres.y << endl;
pres = s1.pop(); 
cout << pres.x << " " << pres.y << endl;
pres = s1.pop(); 
cout << pres.x << " " << pres.y << endl;
pres = s1.pop(); 
cout << pres.x << " " << pres.y << endl; 

cout << endl; system("pause"); return 0;
}
