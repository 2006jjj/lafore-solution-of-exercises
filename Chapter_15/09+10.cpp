/*15_09ex.cpp
В табл. 15.10 мы привели все предопределенные функциональные объекты С++. В программе PLUSAIR показали, как применять функциональный объект plus<>()
с алгоритмом accumulate(). В том примере не было необходимости в передаче каких-либо аргументов в функциональный объект, но иногда по логике работы программы 
это требуется. Оказывается, в данном случае нельзя просто указать аргумент в скобках, как мы привыкли делать. Вместо этого нужно использовать специальный "адаптер функции",
называющийся bind1dt или bind2nd, для связывания аргумента с функциональным объектом. Пусть, например, мы ищем строку SearchName в строковом контейнере names.
В этом случае необходимо писать такое выражение:
    ptr = find_if(names.begin(), names.end(), bind2nd(equal_to<string>(), SearchName));  
    

15_10ex.cpp
Здесь аргументами bind2nd, в свою очередь, являются equal_to<>() и SearchName. Это выражение возвращает итератор, указывающий на первую строку в контейнере, равную SearchName.
Напишите программу, в которой используется подобное выражение для поиска строки в строковом контейнере. На экран должна выводиться позиция SearchName в контейнере.*/


#include <iostream>
#include <vector>   
#include <string>    
#include <algorithm>
#include <functional>
using namespace std;


int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

vector<string> names;
vector<string>::iterator iter;
string str;

names.push_back("Sergey");
names.push_back("Тatyana");
names.push_back("Elena");
names.push_back("Dmitry");
names.push_back("Mihail");
names.push_back("Vladimir");
names.push_back("ddd");
for (iter = names.begin(); iter < names.end(); iter++)
  cout << *iter << endl;
cout << "\nВведите вашу строку:"; 
getline(cin, str);
iter = find_if(names.begin(), names.end(), bind2nd(equal_to<string>(), str));
if (iter == names.end()) 
{ 
  cout << "Нет соответствий!"; 
  exit(1); 
}
else
{ 
  cout << "\nНомер ее позиции=" << iter - names.begin(); 
  cout << ' ' << *iter; 
}

cout << endl; system("pause"); return 0;
}
