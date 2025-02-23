/*15_03ex.cpp
Начните с создания списка целых чисел. Используйте два обычных (не обратных) итератора: один для продвижения в прямом направлении, другой для 
продвижения в обратном направлении. Вставьте их в цикл while для переворачивания содержимого списка. Ради экономии нескольких выражений можно использовать
алгоритм swap() (только при этом следует убедиться, что подход работает как с четными, так и с нечетными элементами). Чтобы посмотреть, как это делают настоящие
профессионалы, взгляните на функцию reverse(), в заголовоном файле ALGORITHM.*/


#include <iostream>
#include <list> 
using namespace std;


int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int SZ = 10;
int arr[SZ] = { 2,-4,6,-8,10,-12,14,-16,18,-20 };
list<int> intlist(arr, arr + SZ);
int size = intlist.size();
list<int>::iterator iter1, iter2;
iter1 = intlist.begin();
iter2 = intlist.end();
while (iter1 != iter2)
  swap(*iter1++, *--iter2);
 cout << endl;
 for (iter2 = intlist.begin(); iter2 != intlist.end(); )
   cout << *iter2++ << ' '; 

cout << endl; system("pause"); return 0;
}
