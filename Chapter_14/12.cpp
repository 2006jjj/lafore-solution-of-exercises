/*14_12ex.cpp
Иногда проще всего бывает использовать механизм исключений, если создать новый класс, чьим компонентом является класс исключений.
Попробуйте проделать такую операцию с классом, использующим исключения для обработки файловых ошибок. Создайте класс dofile, включающий
в себя класс исключений и методы чтения, и записи файлов. Конструктор этого класса в качестве аргумента может брать имя файла, а действием
конструктора, соответственно, может быть открытие этого файла. Можно сделать так, чтобы метод переставлял указатель позиции в начало файла.
Используйте программу REWERR из главы 12 в качестве примера, напишите секцию main(), в которой сохранилась бы функциональность прежней версии,
но использовались бы методы класса dofile.*/

#include <fstream> 
#include <iostream>
#include <process.h>
using namespace std;

class dofile
{
private: 
  fstream file;
public:
class exfile
{
public: 
  int num; 
  exfile(int n) : num(n) {}
};
dofile(const char* filename)
{
  file.open(filename, ios::trunc | ios::out | ios::in | ios::binary);
  if (!file) 
    throw exfile(1);
}
void write(int* buff, const int MAX)
{
  file.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
  for (int j = 0; j < MAX; j++) 
    file << buff[j] << ' ';
  if (!file) 
    throw exfile(2);
}
void read(int* buff, const int MAX)
{
  file.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));
  cout << "\nДанные в файле:" << endl;
  for (int j = 0; j < MAX; j++)
    { 
      file >> j; 
      cout << j << ' '; 
    }
  if (!file) 
    throw exfile(3);
}
void checkdata(int* buff, int MAX)
{
  for (int j = 0; j < MAX; j++) 
    if (buff[j] != j) 
      throw exfile(4);
  cout << "\nДанные в порядке\n";
}
void goseekg() 
{ 
  file.seekg(0); 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int MAX = 10;	
int buff[MAX];
for (int j = 0; j < MAX; j++)
  buff[j] = j;
try
{
  dofile f("E://TEST//edata.txt");
  cout << "Идет запись...\n";
  f.write(buff, MAX);
  f.goseekg();
  cout << "Идет чтение...\n";
  f.read(buff, MAX);
  f.checkdata(buff, MAX);
}
catch (dofile::exfile ex)
{
  switch (ex.num)
  {
    case 1: 
      cerr << "Невозможно открыть файл\n"; 
      break;
    case 2: 
      cerr << "Запись в файл невозможна!\n ";
      break;
    case 3: 
      cerr << "Невозможно чтение файла\n";
      break;
    case 4: 
      cerr << "\nДанные некорректны\n"; 
      break;
  }
}

cout << endl; system("pause"); return 0;
}
