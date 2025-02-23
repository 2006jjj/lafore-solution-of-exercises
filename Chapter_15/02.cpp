/*Примените алгоритм sort() к массиву слов, введенных пользователем, выведите результат. Используйте push_back() для добавления слов,
а оператор [] и size() - для вывода их на экран.*/

#include <iostream>
#include <algorithm> 
#include <vector>
#include <string> 
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

vector<string> names;
char ch;
string name;
do
{
  cout << "Введите имя:"; 
  cin >> name;
  names.push_back(name);
  cout << "Желаете продолжить? (y/n):";
  cin >> ch;
} while (ch != 'n');

sort(names.begin(), names.end());
int size = names.size();
for (int j = 0; j < size; j++)
  cout << names[j] << "\n"; 

cout << endl; system("pause"); return 0;
}
