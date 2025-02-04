/*04_10ex.cpp
Создайте структуру с именем sterling, хранящую денежные суммы в старой английской системе, описанной в упр. 8 и 11 главы 3.
Поля структуры могут быть названы pounds, shillings и pence и иметь тип int. Программа должна запрашивать у пользователя значение
денежной суммы в новых десятичных фунтах (значение должно храниться в перменной типа double), затем переводить эту сумму в старую систему,
сохранять переведенное значение в переменной типа sterling и выводить на экран полученную сумму в фунтах, шиллингах и пенсах. */

#include <iostream>
using namespace std;

struct sterling 
{ 
  int pounds, shillings, pence; 
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
sterling oldsum;
double newsum, drobj;
cout << "Введите сумму в новых десятичных фунтах:J"; 
cin >> newsum;
oldsum.pounds = static_cast<int>(newsum);
drobj = newsum - oldsum.pounds;
oldsum.shillings = static_cast<int>(drobj * 20);
oldsum.pence = static_cast<int>((drobj * 20 - oldsum.shillings) * 12);
cout << "Сумма в старой системе:J" << oldsum.pounds << "." << oldsum.shillings << "." << oldsum.pence << endl; 
 
system("pause"); return 0;
}
