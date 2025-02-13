/*10_03ex.cpp
Используйте массив указателей на строки, представляющие собой названия дней недели, из примера PTROSTR это главы. Напишите функции для сортировки этих строк
в алфавитном порядке, используя в качестве основы функции bsort() и order() из программы PTRSORT этой главы. Сортировать необходимо указатели на строки, а не сами строки.*/

#include <iostream>
#include <cstring>
using namespace std;

void gsort(const char**, int);
void gswap(const char**, const char**);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int DAYS = 7;
const char* arrptrs[DAYS] = { "Понедельник", "Вторник", "Среда","Четверг","Пятница","Суббота", "Воскресенье" };
for (int j = 0; j < DAYS; j++)
	cout << arrptrs[j] << endl;
cout << endl;
gsort(arrptrs, DAYS);
for (int j = 0; j < DAYS; j++)
	cout << *(arrptrs + j) << endl;

cout << endl; system("pause"); return 0;
}

void gsort(const char** ptr, int n) 
{
	int j, k;
	for (j = 0; j < n - 1; j++)
		for (k = j + 1; k < n; k++)
			gswap(ptr + j, ptr + k);
}
void gswap(const char** num1, const char** num2) 
{ 
  if (strcmp(*num1, *num2) > 0) 
  { 
    const char* temp = *num1; 
    *num1 = *num2; 
    *num2 = temp; 
  } 
}
