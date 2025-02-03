//02_02ex.cpp
//Напишите программу, выводящую следующую таблицу:
//1990    135
//1991   7290
//1992  11300
//1993  16200

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
cout <<1990<<setw(8)<<135<<endl
  << 1991<<setw(8)<<7290<<endl 
  << 1992<<setw(8)<<11300<<endl
  << 1993<<setw(8)<<16200<<endl;

system("pause"); return 0;
}
