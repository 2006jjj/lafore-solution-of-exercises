/*14_03ex.cpp
Добавьте механизм обработки исключений в программу из упр. 2. Рассмотрите два исключения: при превышении размера очереди и при попытке
удаления данных из пустой очереди. Это можно сделать, добавив новый элемент данных в класс очереди - счетчик текущего числа элементов в очереди.
Инкрементируйте счетчик при добавлении нового элемента, декрементируйте, соответственно, при удалении элемента из головы очереди. Генерируйте исключение,
если счетчик превысил размер массива или если он стал меньше 0. Можно попробовать сделать main() интерактивной, чтобы пользователь мог вводить и извлекать данные.
Так будет проще проверить работу написанных функций. С помощью механизма исключений программа должна обеспечивать повторную попытку ввода данных пользователем без
нарушения целостности содержимого очереди.*/

#include <iostream>
using namespace std;

template <class Type>
class queue 
{
private:
  static const int MAX = 5; 
  Type st[MAX]; 
  int head, tail, length;
public:
class Full 
{
  public: 
    int max_num;
    Full() 
    { 
      max_num = MAX;
    }
};
class Empty {};
queue() { tail = -1, head = 0, length = 0; }

void push(Type var)
{
  if (length == MAX) 
    throw Full();
  if (tail == MAX - 1) 
  { 
    tail = -1; 
  }
  st[++tail] = var;
  length++;
}
Type pop()
{
  if (length == 0)
    throw Empty();
  Type x = st[head++];
  length--;
  if (head == MAX)
    head = 0;
  return x;
}
void display() const
{
  if (length == 0) 
    cout << "пуста";
  for (int j = 0; j < length; j++) 
    cout << st[head + j] << ' ';
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

char ch; 
unsigned int action_num; 
int elem;
queue<int> q1;
do 
{
  cout << "Введите число для работы с очередью (1-поместить, 2-взять):"; 
  cin >> action_num;
  try 
  {
    switch (action_num) 
    {
      case 1: 
        cout << "\nВведите ваше число:"; 
        cin >> elem; 
        q1.push(elem);
        break;
      case 2: 
        cout << "\nЗначение извлеченного элемента:" << q1.pop();
        break;
      default: 
        cout << "\nНеверный номер! Попробуйте еще!" << endl; 
        continue;
    }
  }
catch (queue<int>::Full f)
    { 
      cout << "Очередь переполнена, в ней уже " << f.max_num << " чисел!"; 
    }
catch (queue<int>::Empty) 
    { 
      cout << "Очередь пуста!"; 
    }
cout << "\nОчередь "; 
q1.display();
cout << "\nХотите еще поработать с очередью? (y/n)";
cin >> ch;
} while (ch != 'n'); 

cout << endl; system("pause"); return 0;
}
