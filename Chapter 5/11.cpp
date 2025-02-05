/*05_11ex.cpp
Напишите программу, использующую структуру sterling, которая описана в упр. 10 главы 4. Программа должна получать от пользователя значения двух денежных сумм,
выраженных в фунтах, шиллингах и пенсах, складывать эти значения и выводить результат на экран в том же формате. Необходимо разработать три функции.
Первая из них должна получать от пользователя число фунтов, шиллингов и пенсов и возвращать соответствующее значение типа sterling.
Вторая функция должна принимать в качестве аргументов два значения типа sterling, складывать их и возвращать значение, также имеющее тип sterling.
Третья функция должна принимать аргумент типа sterling и выводить его значение на экран.*/

#include <iostream>
using namespace std;

struct sterling 
{ 
  int pounds, shillings, pence; 
};
sterling one_func();
sterling two_func(sterling, sterling);
void three_func(sterling);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
	
sterling s1=one_func(), s2=one_func(), s3=two_func(s1, s2);
cout << "Первая сумма: ";  
three_func(s1);
cout << "\nВторая сумма: "; 
three_func(s2);
cout << "\nСумма двух сумм: "; 
three_func(s3);
						
system("pause"); return 0;
}

sterling one_func() 
{
	char ch; 
  sterling sum;
	cout << "Введите количество фунтов, шиллингов и пенсов: J";
	cin >> sum.pounds >> ch >> sum.shillings >> ch >> sum.pence;
	return sum;
}
sterling two_func(sterling sum1, sterling sum2) 
{
	sum1.pounds += sum2.pounds;
	sum1.shillings += sum2.shillings;
	sum1.pence += sum2.pence;
	while (sum1.pence > 11) 
  { 
    ++sum1.shillings; 
    sum1.pence -= 12; 
  }
	while (sum1.shillings > 19) 
  { 
    ++sum1.pounds; 
    sum1.shillings -= 20; 
  }
	return sum1;
}

void three_func(sterling sum) 
{ 
  cout << "J" << sum.pounds << '.' << sum.shillings << '.' << sum.pence; 
}
