/*03_06ex.cpp
Измените программу factor, приведенную в этой главе, таким образом, чтобы она циклически запрашивала ввод пользователем числа и вычисляла его факториал, пока пользователь не введет 0.
В этом случае программа должна завершиться. При необходимости вы можете использовать соответствующие операторы программы factor в цикле do или while. */

#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

	int numb=0;
	do 
	{
		unsigned long fact=1;
		cout << "Введите целое число: ";
		cin >> numb;
		if (numb == 0) 
			break;
		while (numb-1 > 0)
			fact *= numb--;
		cout << "Факториал числа равен " <<fact<<endl;
	} while (numb!=0);
	
system("pause"); return 0;
}
