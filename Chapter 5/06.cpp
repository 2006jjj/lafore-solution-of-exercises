/*05_06ex.cpp
Модифицируйте программу, описанную в упр. 11 главы 4, складывающую два структурных значения типа time.
Теперь программа должна включать в себя две функции. Первая, time_to_secs(), принимает в качестве аргумента значение типа time и возвращает 
эквивалентное значение в секундах типа long. Вторая, secs_to_time(), в качестве аргумента принимает число секунд, имеющее тип long, а возвращает эквивалентное значение типа time.*/

#include <iostream>
using namespace std;

struct time1 
{ 
  int hours, minutes, seconds; 
};
long time_to_secs(time1);
time1 secs_to_time(long);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
time1 t1, t2; 
char ch; 
long sec=0;
cout << "Введите первое значение в формате(12:59:59): "; 
cin >> t1.hours >> ch >> t1.minutes >> ch >> t1.seconds;
sec=time_to_secs(t1);
cout << "Время в секундах: " << sec;
cout << "\nВведите количество секунд: ";  
cin >> sec;
t2=secs_to_time(sec);
cout << "Время переведенное из секунд:" << t2.hours << ch << t2.minutes << ch << t2.seconds<<endl;
			
system("pause"); return 0;
}

long time_to_secs(time1 t) 
{ 
  return t.hours * 3600 + t.minutes * 60 + t.seconds; 
}
time1 secs_to_time(long sec) 
{ 
  time1 t = { static_cast<int>(sec / 3600) , (sec % 3600) / 60 , (sec % 3600) % 60 }; 
  return t; 
}
