//02_06.cpp
//На биржевых торгах за 1 фунт стерлингов давали $1.487, за франк - $0.172, за немецкую марку - $0.584, а за японскую йену - $0.00955.
//Напишите программу, которая запрашивает денежную сумму в долларах, а затем выводит эквивалентные суммы в других валютах.

#include <io.h> // для функции _setmode
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
	float x=0.0;
	cout << "Введите сумму в долларах:";
	cin >> x;
	cout << "Фунты: " << x / 1.487 << endl;
	cout << "Франки: " << x / 0.172 << endl;
	cout << "Марки: " << x / 0.584 << endl;
	cout << "Йены: " << x / 0.00955 << endl;

system("pause"); return 0;
}
