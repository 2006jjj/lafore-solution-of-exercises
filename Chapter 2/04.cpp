//02_04ex.cpp
//Напишите программу, выводящую на экран ваше любимое стихотворение.
//Для разбиения на строчки используйте подходящую управляющую последовательность.

#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
	
char line = '\n';
cout << "У лукоморья дуб зеленый" <<line;
cout << "Златая цепь на дубе том" << line;
cout << "И днём и ночью кот учёный" << line;
cout << "Всё ходит по цепи кругом" << line;

system("pause"); return 0;
}
