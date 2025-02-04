/*03_05ex.cpp
При помощи цикла for изобразите на экране пирамиду из символов 'X'.
Верхняя часть пирамиды должна выглядеть следующим образом:
      X
     XXX
    XXXXX
   XXXXXXX 
  XXXXXXXXX   */


#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

 int n = 20;
 for (int i = 0; i < n; i++) 
    {
	for (int j = 0; j < 2*n-1; j++)
	 cout << ((j > n - 2 - i && j < n + i) ? "x" : " ");
	cout << endl; 
    }		
system("pause"); return 0;
}
