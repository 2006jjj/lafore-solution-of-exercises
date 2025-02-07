/*06_10ex.cpp
Создайте класс с именем ship, который будет содержать данные об учетном номере корабля и координатах его расположения. Для задания номера корабля следует использовать механизм,
аналогичный описанному в упр. 8. Для хранения координат используйте два поля типа angle (см. упр. 7). Разработайте метод, который будет сохранять в объекте данные о корабле,
вводимые пользователем, и метод, выводящий данные о корабле на экран. Напишите функцию main(), создающую три объекта класса ship, затем запрашивающую ввод пользователем информации
о каждом из кораблей и выводящую на экран всю полученную информацию.*/

#include <iostream>
using namespace std;

class angle 
{
public: 
	int degree; 
	float minutes; 
	char course;

	angle() : degree(0), minutes(0.0F), course(' ') {}
	angle(int d, float m, char c) : degree(d), minutes(m), course(c) {}
};

class ship
{
private: 
	static int number_of_ship; 
	int number; 
	angle coordinats;
	char ch;
public:
	ship() : coordinats(0, 0, ' ') 
	{ 
		number_of_ship++;
		number = number_of_ship;
	}

	ship(int num, angle coord) : number(num), coordinats(coord) {}

	void put_info_of_ship() 
	{
		cout << "Введите данные о корабле:\nВведите широту: " << endl;
		cin >> coordinats.degree;
		cout << "Введите долготу: " << endl;
		cin >> coordinats.minutes;
		cout << "Введите направление (N,S,E,W) North(Север) South(Юг) East(Восток) West(Запад)" << endl;
		cin >> coordinats.course;
		if ((coordinats.minutes > 60.0) || (coordinats.degree > 180)) 
		{ 
			cout << "ERROR!"; 
			exit(1); 
		}
	}
	void show_info_of_ship() 
	{ 
		cout << "Данные о корабле:\nКорабль №" << number << "\nЕго координаты: " << coordinats.degree << '\xB0' << coordinats.minutes << "'" << coordinats.course << endl; 
	}
};

int ship::number_of_ship = 0;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

ship s1, s2, s3, s4;
s1.put_info_of_ship(); 
s2.put_info_of_ship(); 
s3.put_info_of_ship();
	
s1.show_info_of_ship(); 
s2.show_info_of_ship(); 
s3.show_info_of_ship(); 
s2.show_info_of_ship();
	
cout << endl; system("pause"); return 0;
}
