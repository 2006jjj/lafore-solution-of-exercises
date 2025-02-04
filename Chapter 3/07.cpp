/*Напишите программу, рассчитывающую сумму денег, которые вы получите при вложении начальной суммы с фиксированной процентной ставкой дохода через опредленное количество лет.
Пользователь должен вводить с клавиатуры начальный вклад, число лет и процентную ставку. 
Примером результата работы программы может быть следующий:
  Введите начальный вклад: 3000
  Введите число лет: 10
  Введите процентную ставку: 5.5
  Через 10 лет вы получите 5124.43 доллара. */


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
	int y=0; 
  float s=0.0, v=0.0;
	cout << "Введите начальный вклад: "; cin >> v;
	cout << "Введите число лет: "; cin >> y;
	cout << "Введите процентную ставку: "; cin >> s;
	for (int i = 1; i <= y; i++)
		v+= (v * (s / 100.0));
	cout << "Через "<< y<< " лет вы получите " <<v<<" доллара.";

system("pause"); return 0;
}
