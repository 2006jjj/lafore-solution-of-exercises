/*15_06ex.cpp
В упр. 3 два обычных итератора использовались для переворачивания содержимого контейнера. Теперь используйте один прямой и один обратный
контейнер для выполнения того же задания, на сей раз в применении к вектору*/


#include <iostream>
#include <vector> 
#include <iterator>   
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int SZ = 10;
int arr[SZ] = { 2,-4,6,-8,10,-12,14,-16,18,-20 };
vector<int> ivect(arr, arr + SZ);
int size = ivect.size();
vector<int>::iterator iter1;
vector<int>::reverse_iterator iter2;
iter1 = ivect.begin();
iter2 = ivect.rbegin();

while (!ivect.size() / 2)
  swap(*iter1++, *iter2++);
cout << "Вектор:" << endl;
for (iter1 = ivect.end(); iter1 != ivect.begin(); )
  cout << *--iter1 << ' '; 

cout << endl; system("pause"); return 0;
}
