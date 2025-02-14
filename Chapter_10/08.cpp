/*10_08ex.cpp
Исправьте функцию additem() из программы LINKLIST так, чтобы она добавляла новый элемент в конец списка, а не в начало. Это будет означать, что первый
вставленный элемент будет выведен первым и результат работы программы будет следующим:
    25
    36
    49
    64
Для того чтобы добавить элемент, вам необходимо будет пройти по цепи до конца списка, а затем изменить указатель последнего элемента так, чтобы он указывал на новый элемент.*/

struct link 
{ 
  int data;
  link* next; 
};

class linklist 
{
private:
  link* head;
public: 
linklist() 
{
  head = NULL; 
}
~linklist();
void additem(int d);
void display();
};

void linklist::additem(int d)
{
  link* newlink = new link;
  newlink->data = d;
  //СТЭК
  //newlink->next = head;  
  //head = newlink;
  //ОЧЕРЕДЬ
  newlink->next = NULL;
  if (head == NULL) 
    head = newlink;
  else 
  {
    link* current = head;
    while (current->next != NULL)
      current = current->next;
    current->next = newlink;
  }
}

void linklist::display()
{
  link* current = head;
  while (current) 
  { 
    cout << current->data << " "; 
    current = current->next; 
  }
}
linklist::~linklist() 
{
  link* current = head;
  while (current) 
  {
    head = current->next;
    delete current;
    cout << "Элемент удален" << endl;
    current = head;
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
