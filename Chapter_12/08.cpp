/*12_08ex.cpp
Основываясь на программе LINKLIST из главы 10, напишите программу, позволяющую пользователю выбрать одно из четерых действий нажатием соответствующей кнопки.
Действия таковы:
    -добавить ссылку в список (от пользователя требуется ввести целое число)
    -показать данные по всем ссылкам из спика;
    -записать в файл данные для всех ссылок (создание или переписывание файла);
    -считать все данные из файла и создать новый список ссылок, куда и поместить их.
Первые два действия могут использовать методы, уже имеющиеся в LINKLIST. От вас требуется написать функции для чтения и записи файла.
И для того, и для другого можно использовать один и тот же файл. В нем должны храниться только данные; нет никакого смысла хранить
содержимое указателей, которые, возможно, уже не будут нужны во время чтения списка.*/

#include <fstream>  
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
void additem(int d);
void display();
void diskOut()
{
  ofstream file;
  file.open("E://TEST//z12-12.txt");
  if (!file)
  { 
    cerr << "ERROR! dont open file";
    exit(0); 
  }
  link* current = first;
  while (current)
  {
    file << current->data << ' ';
    current = current->next;
  }
}
void diskIn()
{
  ifstream file;
  file.open("E://TEST//z12-12.txt");
  if (!file) 
  { 
    cerr << "ERROR! dont open file"; 
    exit(0); 
  }
  link* current = first;
  while (current)
  {
    first = current->next;
    delete current;
    current = first;
  }
  cout << "(Если числа *1*-делим на 2, если *11*-делим на 3, если *111*- не делим)";
  file.seekg(0, ios::end);
  int kolichestvo_elementov = (int)file.tellg() / (sizeof(int) / 2);
  int n = sizeof(int) / 2;
  int i = 0;
  for (int j = kolichestvo_elementov; j > 0; j--)
  {
    file.seekg(-n, ios::cur);
    file >> i;
    additem(i);
    file.seekg(-n + 1, ios::cur);
  }
  cout << "\nНаш список:" << endl;
  display();
}
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
  if (current == 0) 
  { 
    cout << "Ваш список пуст!";
  }
  while (current)
  {
    cout << current->data << ' ';
    current = current->next;
  }
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

linklist li; 
char ch1; 
int y; 
cout << "HELLO!";
while (true)
{
  cout << "\n\n1) Добавить ссылку в список\n2) Показать данные по всем ссылкам из списка\n"
    "3) Записать в файл данные из всех ссылок\n4) Считать все данные из файла и создать новый список ссылку, куда и поместить их"
    "\n5) Выход\nВыберите пункт:";
  cin >> ch1;
  switch (ch1)
  {
    case '1': 
      cout << "Введите число для добавления:"; 
      cin >> y; 
      li.additem(y);
      break;
    case '2': 
      cout << "Ваш список:" << endl; 
      li.display(); 
      break;
    case '3': 
      li.diskOut(); 
      cout << "Запись в файл произведена!"; 
      break;
    case '4': 
      li.diskIn(); 
      break;
    case '5': 
      cout << "Goodbye"; 
      exit(0);
    default: 
      cout << "Не был выбран ни один из пунктов!"; 
      break;
  }
}

cout << endl; system("pause"); return 0;
}
