/*07_10ex.cpp
Матрица - это двумерный массив. Создайте класс matrix, который предоставляет те же меры безопасности, как и класс из упр. 7, то есть осуществляет проверку индексов массива на вхождение
их в границы массива. Полем класса matrix будет массив 10 на 10. Конструктор должен позволять программисту определить реальный размер массива (допустим, сделать его меньше, чем 10 на 10).
Методам, предназначенным для доступа к членам матрицы, теперь нужны два индекса: по одному для каждой размерности массива. Вот фрагмент функции main(), которая работает с таким классом:
    matrix m1(3,4);        //описываем матрицу
    int temp=12345;        //описываем целое
    m1.putel(7,4,temp);    //помещаем значение temp в матрицу
    temp=m1.getel(7,4);    //получаем значение из матрицы*/

#include <iostream>
using namespace std;

class matrix 
{
private:
	static const int limit = 10;
	int array[10][10]{}; 
  int n, m;
public:
matrix() {};
matrix(int a, int b) : n(a), m(b) {};
void zapolnenie(int a, int b)
{
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
      array[a][b] = rand() % 10;
      cout << array[a][b] << " ";
    }
    cout << endl;
  }
}
void putel(int a, int b, int temp)
{
  if (a<0 || a>limit - 1 || b < 0 || b > limit - 1)
  { 
    cout << "Error!";
    exit(1); 
  }
  array[a][b] = temp;
}
int getel(int a, int b)
{
  if (a<0 || a>limit - 1 || b < 0 || b > limit - 1) 
  { 
    cout << "Error!"; 
    exit(1); 
  }
  return array[a][b];
}
void display(int a, int b) const
{
  cout << endl;
  if (a<0 || a>limit - 1 || b < 0 || b > limit - 1) 
  { 
    cout << "Error!"; 
    exit(1); 
  }
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++) 
    { 
      cout << array[a][b] << " "; 
    }
    cout << endl;
  }
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

matrix m1, m2, m3(3, 4);
m1.zapolnenie(5, 5);
m2.display(3, 3);
int temp = 12345;
m3.putel(7, 4, temp);
temp = m3.getel(7, 4); cout << temp << endl;

cout << endl; system("pause"); return 0;
}
