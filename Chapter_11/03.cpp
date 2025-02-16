/*11_03ex.cpp
В классе Distance, как показано в примерах FRENGL и FRISQ из этой главы, создайте перегружаемую операцию умножения *, чтобы можно было умножать
два расстояния. Сделайте эту функцию дружественной, тогда можно будет использовать выражение типа Wdist=7.5*dist2. Вам понадобится конструктор
с одним аргументом для перевода величин из формата чисел с плавающей запятой в формат Distance. Напишите какой-либо main() на свое усмотрение для того,
чтобы несколькими способами проверить работу этой перегружаемой операции.*/

#include <iostream>
using namespace std;


class Distance 
{
private: 
  int feet; 
  float inches;
public:
Distance() : feet(0), inches(0.0) {}
Distance(float fltfeet) 
{
  feet = static_cast<int>(fltfeet);
  inches = 12 * (fltfeet - feet);
}
Distance(int ft, float in) : feet(ft), inches(in) {}

void showdist() 
{
  cout << feet << "\'-" << inches << '\"'; 
}
friend Distance operator * (Distance d1, Distance d2);
};

Distance operator*(Distance d1, Distance d2) 
{
  float floatfeet1 = d1.feet + d1.inches / 12;
  float floatfeet2 = d2.feet + d2.inches / 12;
  return Distance(floatfeet1 * floatfeet2);
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Distance dist1(3, 6.0), dist2(2, 3.0), dist3;
dist3 = dist1 * dist2; 
cout << "\ndist3="; 
dist3.showdist();
dist3 = 10.0 * dist3;
cout << "\ndist1="; 
dist1.showdist(); 
cout << "\ndist2="; 
dist2.showdist(); 
cout << "\ndist3="; 
dist3.showdist(); 

cout << endl; system("pause"); return 0;
}
