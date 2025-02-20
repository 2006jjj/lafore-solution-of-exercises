/*12_01ex.cpp
Рассмотрите класс Distance из программы ENGLCON, глава 6. Используя цикл, аналогичный приводимому в программе DISKFUN в этой главе, получите несколько значений
от пользователя и запишите их в файл. Добавьте их к уже записанным там данным (при их наличии). При окончании пользователем ввода прочитайте файл и выведите на экран все значения.*/

#include <fstream>
#include <iostream>
using namespace std;

class Distance
{
private:
  int feet; 
  float inches;
public:
Distance() : feet(0), inches(0) {}
Distance(int ft, float inc) : feet(ft), inches(inc) {}

void getdist()
{
  cout << "\nВведите футы:"; 
  cin >> feet;
  cout << "Введите дюймы:"; 
  cin >> inches;
}
void showdist() const
{
  cout << feet << "\'-" << inches << '\"';
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

char ch; 
Distance d1; 
fstream file;
file.open("E://TEST//Z12-1.DAT", ios::app | ios::out | ios::in | ios::binary);
do 
{
  cout << "\n\nВведите переменную:"; 
  d1.getdist();
  file.write(reinterpret_cast<char*>(&d1), sizeof(d1));
  if (!file) 
  { 
    cerr << "\nERROR!" << endl; 
  }
  cout << "\nЖелаете продолжить? (y/n):"; 
  cin >> ch;
} while (ch != 'n');
 
file.seekg(0);
file.read(reinterpret_cast<char*>(&d1), sizeof(d1));
int n = 0;
while (!file.eof())
{
  cout << "\nРасстояние " << ++n << ":"; 
  d1.showdist();
  file.read(reinterpret_cast<char*>(&d1), sizeof(d1));
}
file.close(); 

cout << endl; system("pause"); return 0;
}
