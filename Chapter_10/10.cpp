/*10_10ex.cpp
Описанный в упр. 9 подход нерационален, так как каждый из 10 массивов объявляется отдельно, с использованием отдельного имени,
и каждый адрес получают отдельно. Вы можете упростить программу, используя операцию new, которая позволит вам выделить память для массивов в цикле
и одновременно связать с ними указатели:
  for (j=0; j<NUMARRAYS; j++)         //создаем NUMARRAYS массивов
      *(ap+j) = new int [MAXSIZE];    //по MAXSIZE целых чисел в каждом 
Перепишите программу упр. 9, используя этот подход. Доступ к отдельному элементу массивов вы сможете получить, используя то же выражение, что и в упр. 9,
или аналогичное выражение с указателями: *(*(ap+j)+k).*/

#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int SIZE = 10, NUMARRAYS = 10;
int* ap[NUMARRAYS], j, k;
 
for (j = 0; j < NUMARRAYS; j++)
	*(ap + j) = new int[SIZE];
 
for (j = 0; j < SIZE; j++)
	for (k = 0; k < SIZE; k++)
		*(*(ap + j) + k) = (j * SIZE + k) * SIZE;
 
for (int j = 0; j < SIZE; j++)
	for (int k = 0; k < SIZE; k++)
		cout << *(*(ap + j) + k) << ((k == SIZE - 1) ? "\n" : " ");

cout << endl; system("pause"); return 0;
}
