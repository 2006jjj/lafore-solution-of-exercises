/*04_05ex.cpp
Создайте структуру типа date, содержащую три поля int: месяц, день и год. Попросите пользователя ввести день, месяц и год в формате 31/12/2002,
сохраните введенное значение в структурной перменной, а затем извлеките данные из этой переменной и выведите их на экран в том же формате, в каком они вводились. */

#include <iostream>
using namespace std;

struct date 
{ 
  int day, mounth, year; 
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
	date data; 
	char ch;
	cout << "Введите дату: "; 
	cin >> data.day >> ch >> data.mounth >> ch >> data.year;
	cout << "\nВы ввели дату:" << data.day << ch << data.mounth << ch << data.year << endl;
	
system("pause"); return 0;
}
