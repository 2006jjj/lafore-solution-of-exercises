/*03_03ex.cpp
Операции ввода, такие, как cin, должны уметь преобразовывать последовательность символов в число. Напишите программу, которая позволяет пользователю ввести шесть цифр,
а затем выводит результат типа long на экране. Каждая цифра должна считываться отдельно при помощи функции getche(). Вычисление значения переменной производится путем умножения 
текущего ее значения на 10 и сложения с последней введенной цифрой (для того, чтобы из кода символа получить цифру, вычтите из него 48 или '0').
Примером результата работы программы может служить следующий:
  Введите число: 123456
  Вы ввели число 123456 */


#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

	long x=0; 
  char ch;
	cout << "Введите число:";
	while ((ch = getche()) != '\r')
	x = x * 10 + ch - 48;
	cout <<"\nПолучилось число:"<< x << endl;

system("pause"); return 0;
}
