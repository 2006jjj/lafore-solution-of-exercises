/*14_02ex.cpp
Очередь - это тип хранилища данных. Она напоминает по своей сути стек, только вместо правила LIFO (последний вошел - первый вышел) использует
правило FIFO (первый вошел - первый вышел). В общем, как очередь у окошка в банке. Если вы заносите в массив числа 1,2,3 обратно вы их получите в той же последовательности.
Стеку требуется для работы только один индекс массива (top, вершина массива. см. программу STAKARAY из главы 7). Очереди же требуется два индекса: индекс хвоста,
куда добавляются новые элементы, и индекс головы очереди, откуда исчезают старые. Хвост постепенно сдвигается, как и голова. Если хвост или голова достигает конца массива,
он переставляется на начало. Напишите шаблон класса для работы с очередью. Предположим, что программист не будет совершать ошибок при написании ее модели. Например, вместимость очереди
не будет превышена, а из пустой очереди не будет производиться попыток удаления данных. Определите несколько очередей разных типов и поработайте с их данными.*/

#include <iostream>
using namespace std;

template <class Type>
class queue 
{
private:
  static const int MAX = 10; 
  Type st[MAX]; 
  int head, tail, length;
public:
queue() { tail = -1, head = 0, length = 0; }

void push(Type var)
{
  if (length == MAX) 
  { 
    cout << "Очередь переполнена!"; 
    exit(1); 
  }
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
  { 
    cout << "Очередь пуста!"; 
    exit(1); 
  }
  Type x = st[head++];
  length--;
  if (head == MAX)
    head = 0;
  return x;
}
};

int main(int argc, char* argv[])
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

queue<int> q1;
q1.push(10);
q1.push(11);
q1.push(12);
q1.push(13);
q1.push(14);
q1.push(15);
q1.push(16);
q1.push(17);
q1.push(17);
q1.push(17);
cout << "1) " << q1.pop() << endl;
cout << "2) " << q1.pop() << endl;
cout << "3) " << q1.pop() << endl;
cout << "4) " << q1.pop() << endl;
cout << "5) " << q1.pop() << endl;
cout << "6) " << q1.pop() << endl;
cout << "7) " << q1.pop() << endl;
cout << "8) " << q1.pop() << endl;
cout << "9) " << q1.pop() << endl;
cout << "10) " << q1.pop() << endl;
 
queue<float> q2;
q2.push(1.473);
q2.push(5.63);
q2.push(15.83);
q2.push(14.4);
q2.push(177.59);
q2.push(1.3);
q2.push(2.88);
q2.push(7.77);
q2.push(2.79);
q2.push(6.33);
cout << endl;
cout << "1) " << q2.pop() << endl;
cout << "2) " << q2.pop() << endl;
cout << "3) " << q2.pop() << endl;
cout << "4) " << q2.pop() << endl;
cout << "5) " << q2.pop() << endl;
cout << "6) " << q2.pop() << endl;
cout << "7) " << q2.pop() << endl;
cout << "8) " << q2.pop() << endl;
cout << "9) " << q2.pop() << endl;
cout << "10) " << q2.pop() << endl; 

cout << endl; system("pause"); return 0;
}
