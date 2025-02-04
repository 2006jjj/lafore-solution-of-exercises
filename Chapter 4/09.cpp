/*04_09ex.cpp
Создайте структуру с именем time. Три ее поля, имеющие тип int, будут называться hours, minutes, и seconds.
Напишите программу, которая просит пользователя ввести время в формате часы, минуты, секунды.
Можно запрашивать на ввод как три значения сразу, так и выводить для каждой величины отдельное приглашение.
Программа должна хранить время в структурной перменной типа time и выводить количество секунд в введенном времени, определяемое следующим образом:
    long totalsecs = t1.hours*3600 + t1.minutes*60 + t1.seconds */

#include <iostream>
using namespace std;

struct time1 
{
  int hours, minutes, seconds; 
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
time1 t;
cout << "Введите часы, минуты, секунды: "; 
cin >> t.hours >> t.minutes >> t.seconds;
cout << "Общее время в секундах:" << t.hours * 3600 + t.minutes * 60 + t.seconds<<endl;;
 
system("pause"); return 0;
}

