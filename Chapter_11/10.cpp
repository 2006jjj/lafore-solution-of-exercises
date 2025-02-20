/*11_10ex.cpp
Упражнение 4 в главе 10 включало в себя добавление к классу linklist перегружаемого деструктора. Допустим, мы заполняем объект этого класса данными,
а затем присваиваем один класс целиком другому, используя стандартный оператор присваивания:
    list2=list1;
Допустим, что впоследствии мы удалим объект класса list1. Можем ли мы все еще использовать list2 для доступа к введенным данным? Увы, нет, так как при удалении
list1 все его ссылки были удалены. Единственное, что было известно объекту linklist про удаленный объект, это указатель на него. Но его удалили, указатель в list2
стал недееспособным, и все попытки получить доступ к данным приведут к получению мусора вместо данных, а в худшем случае - к зависанию программы.
Один из способов избежать этих проблем - перегрузить оператор присваивания, чтобы он вместе с объектом копировал бы все его ссылки. Но тогда придется пройти по всей цепочке,
поочередно копируя все ссылки. Как отмечалось ранее, следует также перегружать конструктор копирования. Чтобы была возможность удалять объекты linklist в main(), можно создавать
их с помощью указателя и new. В таком случае проще будет проверять работу новых операций. Не переживайте, если обнаружите, что в процессе копирования порядок следования данных изменился.
Понятно, что копирование всех данных не является самым эффективным решением проблемы с точки зрения экономии памяти. Сравните этот подход с представленным в примере STRIMEM (глава 10),
где использовался только один набор данных для всех объектов, и хранить информация о том, сколько объектов указывали на эти данные.*/


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
	linklist() { first = NULL; }
	linklist(linklist& li);
	~linklist();
	void additem(int d);
	void display();
	linklist& operator= (linklist&);
};

linklist::linklist(linklist& li) 
{
  first = NULL;
  link* current = li.first;
  while (current) 
  { 
    additem(current->data); 
    current = current->next; 
  }
}

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

linklist& linklist::operator= (linklist& li) 
{
  if (this == &li) 
    return *this;
  link* current = first;
  while (current) 
  { 
    first = current->next; 
    delete current; 
    current = first; 
  }
  current = li.first;
  while (current) 
  { 
    additem(current->data); 
    current = current->next; 
  }
  return *this;
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

linklist* list1 = new linklist;
list1->additem(25); 
list1->additem(36); 
list1->additem(49); 
list1->additem(64);
cout << "list1="; 
list1->display(); 
cout << endl;
linklist list2(*list1);
linklist list3;
list3 = *list1;
delete list1;
cout << "\nlist2="; 
list2.display(); 
cout << "\nlist3="; 
list3.display(); 

cout << endl; system("pause"); return 0;
}
