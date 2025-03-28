/*06_02ex.cpp
Представьте пункт для взимания платежей за проезд по автостраде. Каждая проезжающая машина должна заплатить за проезд 50 центов, однако часть машин платит за проезд, а часть проезжает бесплатно.
В кассе ведется учет числа проехавших машин и суммарная выручка от платы за проезд. Создайте модель такой кассы с помощью класса tollBooth. Класс должен содержать два поля. Одно из них, типа unsigned int,
предназначено для учета количества проехавших автомобилей, а второе, имеющее тип double, будет содержать суммарную выручку от оплаты проезда. Конструктор должен инициализировать оба поля нулевыми значениями.
Метод payingCar() инкрементирует число машин и увеличивает на 0,50 суммарную выручку. Другой метод, nopayCar(), увеличивает на единицу число автомобилей, но оставляет без изменения выручку. 
Метод display() выводит оба значения на экран. Там, где это возможно, сделайте методы константными. 
Создайте программу, которая продемонстрирует работу класса. Программа должна предложить пользователю нажать одну клавишу для того, чтобы сымитировать заплатившего автолюбителя, и другую клавишу,
чтобы сымитировать недобросовестного водителя. Нажатие клавиши Esc должно привести к выдаче текущих значений количества машин и выручки и завершению программы. */

#include <iostream>
using namespace std;

const char ESC = 27;
const double toll = 0.5;

class tollBoth 
{
private: 
  unsigned int avto; 
  double sum;
public:
tollBoth() : avto(0), sum(0.0) {}
void payingCar() 
{ 
  avto++; 
  sum += toll; 
}
void nopayCar() 
{ 
  avto++; 
}
void display() const 
{ 
  cout << "\n1Число проехавших автомобилей: " << avto << "\nОбщая выручка: " << sum << endl; 
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

char ch; 
tollBoth booth1;
cout << "Нажмите 0 для машины без оплаты," << "\nНажмите 1 для каждой оплачиваемой машины," << "\nEsc для выхода." << endl;
do {
ch = getche();
if (ch == '0') booth1.nopayCar();
if (ch == '1') booth1.payingCar();
} while (ch != ESC);
booth1.display();
			
cout << endl; system("pause"); return 0;
}
