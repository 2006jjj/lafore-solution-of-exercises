/*03_12ex.cpp
Создайте калькулятор, выполняющий четыре арифметических действия над дробями (см. упр. 9 главы 2 и упр. 4 этой главы).
Формулы, демонстрирующие выполнение арифметических операций над дробями, приведены ниже:
    Сложение: a/b + c/d = (a*d + b*c) / (b*d)
    Вычитание: a/b - c/d = (a*d - b*c) / (b*d)
    Умножение: a/b * c/d = (a*c) / (b*d)
    Деление: a/b / c/d = (a*d) / (b*c)
Пользователь должен сначала ввести первый операнд, затем знак операции и второй операнд. После вычисления результата программа должна отобразить его на экраны 
и запросить пользователя о его желании произвести еще одну операцию. */


#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
	
int a, b, c, d; 
char c1, ch;
do {
	cout << "Введите первый операнд:"; cin >> a >> c1 >> b;
	cout << "Введите знак операции:";  cin >> ch;
	cout << "Введите второй операнд:"; cin >> c >> c1 >> d;
	switch (ch) 
  {
	case '+': cout << "Сложение: " << a << c1 << b << ch << c << c1 << d << "=" << (a * d + b * c) << c1 << b * d;  break;
	case '-': cout << "Вычитание: " << a << c1 << b << ch << c << c1 << d << "=" << (a * d - b * c) << c1 << b * d; break;
	case '*': cout << "Умножение: " << a << c1 << b << ch << c << c1 << d << "=" << a * c << c1 << b * d;       break;
	case '/': cout << "Деление: " << a << c1 << b << ch << c << c1 << d << "=" << a * d << c1 << b * c;         break;
	}
	cout << "\nЖелаете продолжить? (y/n):";
	cin >> ch;
} while (ch != 'n'); 
 
system("pause"); return 0;
}
