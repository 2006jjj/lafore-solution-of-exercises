/*15_05ex.cpp
Заполните массив четными числами, а множество - нечетными. С помощью алгоритма merge() объедините эти контейнеры в вектор.
Выведите его содержимое, чтобы удостовериться, что слияние прошло успешно.*/


#include <iostream>
#include <set>   
#include <vector>  
#include <algorithm> 
#include <iterator>   
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
const int SZ = 11;
int array[SZ] = {};
for (int j = 0; j < SZ; j++)
  array[j] = j * 2;
cout << "Массив:" << endl;
for (int j = 1; j < SZ; j++) 
  cout << array[j] << ' ';

set<int> iset;
set<int>::iterator iters;
for (int j = 1; j < SZ; j++)
  iset.insert(j * 2 - 1);
cout << "\nМножество:" << endl;
for (iters = iset.begin(); iters != iset.end(); iters++) 
  cout << *iters << ' ';

vector<int> fvector(SZ * 2);
vector<int>::iterator fiter;
merge(array, array + SZ, iset.begin(), iset.end(), fvector.begin());
cout << "\nВектор:" << endl;
for (fiter = fvector.begin() + 1; fiter != fvector.end() - 1; fiter++)
  cout << *fiter << ' '; 

cout << endl; system("pause"); return 0;
}
