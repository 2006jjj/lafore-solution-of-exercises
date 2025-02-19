/*11_05ex.cpp
Взяв за основу программу из упр. 1 этой главы, добавьте метод типа bool, называющийся isOversize(), к классам book и tape. Допустим, книга, в которой
больше 800 страниц, или кассета со временем проигрывания более 90 минут, будут считаться объектами с превышением размера. К этой функции можно обращаться из main(),
а результат ее работы выводить в виде строки "Превышение размера!" для соответствующих книг и кассет. Допустим, объекты классов book и tape должны быть доступны через указатели 
на них, хранящиеся в массиве типа publication.*/

#include <iostream>
#include <string>
using namespace std;

class publication 
{
private: 
  wstring name; 
  float price;
public:
virtual void getdata() 
{
  cout << "Введите название книги:";
  getline(ws(wcin), name);
  cout << "Введите цену:";
  wcin >> price;
}
virtual void putdata() const 
{ 
  wcout << L"\nКнига: " << name << L"\nЦена: " << price << endl; 
}
virtual bool isOversize() = 0;
};

class book : public publication 
{
private: 
  int pages;
public:
void getdata() 
{ 
  publication::getdata(); 
  cout << "Введите количество страниц в книге:"; 
  cin >> pages; 
}
void putdata() const 
{ 
  publication::putdata(); 
  cout << "Количество страниц: " << pages << endl;
}
bool isOversize() 
{ 
  return (pages > 800) ? 1 : 0; 
}
};

class type : public publication 
{
private: 
  float record;
public: 
void getdata() 
{ 
  publication::getdata(); 
  cout << "Введите время записи книги:"; 
  cin >> record; 
}
void putdata() const 
{ 
  publication::putdata(); 
  cout << "\nВремя записи: " << record << " minutes";
}
bool isOversize() 
{ 
  return (record > 90) ? 1 : 0; 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

publication* ptrpub[100]; 
int n = 0;
char choice;
do 
{
  cout << "Вводить данные для книги или для пленки? (b/t):";
  cin >> choice;
  if (choice == 'b') 
    ptrpub[n] = new book;
  else if (choice == 't') 
    ptrpub[n] = new type;
  else 
  { 
    cout << "ERROR!";
    exit(1);
  }
  ptrpub[n++]->getdata();
  cout << "Желаете продолжить?(y/n)";
  cin >> choice;
} while (choice != 'n');
for (int j = 0; j < n; j++) 
{
  cout << "\nДанные издания[" << j + 1 << "]:"; 
  ptrpub[j]->putdata();
  if (ptrpub[j]->isOversize()) 
    cout << "Превышение размера!";
}

cout << endl; system("pause"); return 0;
}
