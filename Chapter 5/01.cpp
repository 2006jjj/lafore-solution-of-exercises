/*05_01ex.cpp
Вернитесь к рассмотрению примера CIRCAREA главы. Напишите функцию с именем circarea(), которая аналогичным образом вычисляет площадь круга.
Функция должна принимать один аргумент типа float и возвращать значение типа float. 
Напишите функцию main(), которая просит пользователя ввести значение радиуса, вызывает функцию circarea(), а затем отображает результат вычисления на экране.*/


#include <iostream>
using namespace std;

float circarea(float);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
float r;
cout << "Введите радиус окружности:";
cin >> rr;
cout << circarea(rr) << endl;

 
system("pause"); return 0;
}

float circarea(float rad)
{
	const float PI = 3.14159F;
	return PI * rad * rad;
}
