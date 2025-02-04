/*04_12ex.cpp
Переработайте программу-калькулятор для дробей, описанную в упражнении 12 главы 3 так, 
чтобы каждая из дробей хранилась как значение переменной типа struct fraction, по аналогии с упр. 8 этой главы.*/

#include <iostream>
using namespace std;

struct fraction 
{
  int ch, zn; 
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

fraction m, n; 
char c1, ch;
do {
cout << "Введите первую дробь:"; 
cin >> m.ch >> c1 >> m.zn;
cout << "Введите знак операции:";  
cin >> ch;
cout << "Введите вторую дробь:"; 
cin >> n.ch >> c1 >> n.zn;
	switch (ch) 
 	{
		case '+': cout << "Сложение: " << m.ch << c1 << m.zn << ch << n.ch << c1 << n.zn << "=" << (m.ch * n.zn + m.zn * n.ch) << c1 << m.zn * n.zn;  break;
		case '-': cout << "Вычитание: " << m.ch << c1 << m.zn << ch << n.ch << c1 << n.zn << "=" << (m.ch * n.zn - m.zn * n.ch) << c1 << m.zn * n.zn; break;
		case '*': cout << "Умножение: " << m.ch << c1 << m.zn << ch << n.ch << c1 << n.zn << "=" << m.ch * n.ch << c1 << m.zn * n.zn;       break;
		case '/': cout << "Деление: " << m.ch << c1 << m.zn << ch << n.ch << c1 << n.zn << "=" << m.ch * n.zn << c1 << m.zn * n.ch;         break;
	}
	cout << "\nЖелаете продолжить? (y/n):";
	cin >> ch;
} while (ch != 'n'); 

cout<<endl;
system("pause"); return 0;
}
