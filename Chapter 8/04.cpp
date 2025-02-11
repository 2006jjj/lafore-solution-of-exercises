/*08_04ex.cpp
Создайте класс Int, основанный на упр. 1 из главы 6.
Перегрузите четыре целочисленных арифметических операции (+, -, *, /) так, чтобы их можно было использовать для операций с объектами класса Int.
Если результат какой-либо их операций выходит за границы типа int (в 32-битной системе), имеющие значение от 2 147 483 648 до -2 147 483 648, то
операция должна послать сообщение об ошибке и завершить программу. Такие типы данных полезны там, где ошибки могут быть вызваны арифметическим переполнением, которое недопустимо.
Подсказка: для облегчения проверки переполнения выполняйте вычисления с использованием типа long double. Напишите программу для проверки этого класса.*/

#include <iostream>
using namespace std;

class Int 
{
private:
	int x;
public:
Int() : x(0) {}
Int(int j) : x(j) {}
void show() 
{ 
  cout << x << endl; 
}
Int checkit(long double answer)
{
  if (answer > 2147483647.0L || answer < -2147483647.0L) 
  {
    cout << "ERROR:)"; 
    exit(1);
  }
  return Int(int(answer));
}
operator int() { return x; }
Int operator+ (Int x2) { return checkit(long double(x) + long double(x2)); }
Int operator- (Int x2) { return checkit(long double(x) - long double(x2)); }
Int operator* (Int x2) { return checkit(long double(x) * long double(x2)); }
Int operator/ (Int x2) { return checkit(long double(x) / long double(x2)); }
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Int alpha(20), beta(7), delta, gamma;
gamma = alpha + beta; 
cout << "\ngamma="; 
gamma.show();
 
gamma = alpha - beta; 
cout << "\ngamma="; 
gamma.show();
 
gamma = alpha * beta; 
cout << "\ngamma="; 
gamma.show();
 
gamma = alpha / beta; 
cout << "\ngamma=";
gamma.show();
 
delta = -2147483647; 
gamma = delta - alpha;

cout << endl; system("pause"); return 0;
}
