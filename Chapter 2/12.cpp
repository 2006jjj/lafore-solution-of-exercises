/*02_12ex.cpp
Напишите программу, выполняющую действия, обратные тем, которые описаны в упражнении 10, то есть запрашивающую у пользователя сумму, указанную в десятичных фунтах,
и переводящую ее в старую систему фунтов, шиллингов и пенсов. Пример взаимодействия программы с пользователем может выглядеть так:
  Введите число десятичных фунтов: 3.51
  Эквивалентная сумма в старой форме записи: J3.10.2
Обратите внимание на то, что если вам придется присваивать вещественное значение (например, 12,34) переменной целого типа, то его дробная часит (0,34) будет потеряна, 
а целая перменная получит значение 12. Чтобы избежать предупреждения со стороны компилятора, используйте явное преобразование типов. 
Можно использовать операторы, подобные приведенным ниже:
  float decpounds; //сумма в десятичных фунтах
  int pounds;  //сумма в старых фунтах
  float decfrac;  //десятичная дробная часть
  pounds = static_cast<int>(decpounds);  //отбрасывание дробной части
  decfrac=decpounds - pounds;  //прибавление дробной части
Чтобы получить число шиллингов, следует умножить на 20 значение переменной decfrac. Аналогичным образом можно получить число пенсов.  */

#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

	float desyatichiefynts, drobj;
	cout << "Введите число десятичных фунтов:";
	cin >> desyatichiefynts;
	int stariefynts = static_cast<int>(desyatichiefynts);
	drobj = desyatichiefynts - stariefynts;	
     //cout << "Fynti:" << stariefynts << "    drobj:" << drobj << endl;
	int shinning = static_cast<int>(drobj * 20);                 
     //cout << "shinning: " << shinning<<endl;
	int pens = static_cast<int>(((drobj * 20) - shinning) * 12); 
     //cout << "pens:" << pens;
	cout << "Эквивалентная сумма в старой форме записи: J" << stariefynts << "." << shinning << "." << pens << endl;
 
system("pause"); return 0;
}
