/*12_04ex.cpp
В цикле запрашивайте у пользователя данные, состоящие из имени, отчества, фамилии и номера работника (типа unsigned long). Затем осуществите
форматированный вывод в объект ofstream с помощью оператора вставки (<<). Не забывайте, что строки данных должны оканчиваться пробелами или другими
разделителями. Когда пользователь сообщит об окончании ввода, закройте объект ofstream, откройте объект ifstream, прочитайте и выведите на экран все данные
из файла, после чего завершите программу.*/

#include <fstream>
#include <iostream>
#include <string> 
#include <codecvt>
#include <locale>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

string name, surname, otc; 
unsigned long number; 
char ch; 
static int n = 0;
ofstream outfile("E://TEST//Z12-4.TXT");
do 
{
  cout << "Введите номер сотрудника:"; 
  cin >> number;
  cout << "Введите фамилия, имя и отчество (через пробел):"; 
  cin >> surname >> name >> otc;
  outfile << ++n << ":" << number << " " << surname << " " << name << " " << otc << endl;
  cout << "Пользователь " << n << " записан в файл!";
  cout << "\n\nПродолжить или нет (y/n)?"; 
  cin >> ch;
} while (ch != 'n');
outfile.close();
ifstream infile("E://TEST//Z12-4.TXT");
while (infile >> n >> ch >> number >> surname >> name >> otc)
cout << "Пользователь " << n << ch << " " << number << " " << surname << " " << name << " " << otc << " " << endl;

cout << endl; system("pause"); return 0;
}
