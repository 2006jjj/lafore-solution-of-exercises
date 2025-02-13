/*10_04ex.cpp
Добавьте деструктор в программу LINKLIST. Он должен удалять все элементы списка при удалении объекта класса linklist.
Элементы должны удаляться по очереди, в соответствии с их расположением в списке. Протестируйте деструктор путем вывода сообщения об удалении каждого
из элементов списка; удалено должно быть также количество элементов, какое было положеное в список (деструктор вызывается автоматически для каждого существующего объекта).*/

#include <iostream>
using namespace std;

struct link 
{ 
  int data; 
  link* next; 
};

class linklist 
{
private: 
  link* first;
public:
linklist() 
{ 
  first = NULL; 
}
~linklist();
void additem(int d);
void display();
};

void linklist::additem(int d) 
{
  link* newlink = new link;
  newlink->data = d;
  newlink->next = first;
  first = newlink;
}
void linklist::display() 
{
  link* current = first;
  while (current) 
  {
    cout << current->data << " ";
    current = current->next;
  }
}
linklist::~linklist() 
{
  link* current = first;
  while (current) 
  {
    first = current->next;
    delete current;
    cout << "Элемент удален" << endl;
    current = first;
  }
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

linklist li; 
li.additem(25); 
li.additem(36); 
li.additem(49); 
li.additem(64); 
li.display(); 

cout << endl; system("pause"); return 0;
}
