/*07_03ex.cpp
Напишите программу, вычисляющую среднее значение 100 интервалов, введенных пользователем. Создайте массив объектов класса Distance, как это было сделано в примере ENGLARAY этой главы.
Для вычисления среднего значения вы можете позаимствовать метод add_dist() из примера ENGLCON главы 6. Вам также понадобится метод, который выделяет целую часть из значения Distance.
Вот одна из возможностей:
    void Distance::div_dist (Distance d2, int divisor)
    {
      float fltfeet = d2.feet + d2.inches / 12.0;
      fltfeet /= divisor;
      fltfeet = int (fltfeet);
      inches = ( fltfeet - feet ) * 12.0;
    }*/

#include <iostream>
using namespace std;

class Distance 
{
private:
	int feet; float inches;
public:
	Distance() : feet(0), inches(0) {}
	Distance(int ft, float inc) : feet(ft), inches(inc) {}

void getdist()
{
  cout << "\nВведите футы:"; cin >> feet;
  cout << "Введите дюймы:"; cin >> inches;
}
void showdist() const 
{ 
  cout << feet << "\'-" << inches << '\"'; 
}
void add_dist(Distance, Distance);
void div_dist(Distance, int);
};

void Distance::add_dist(Distance d2, Distance d3) 
{
  inches = d2.inches + d3.inches;
  feet = 0;
  if (inches >= 12.0) 
  {
    inches -= 12.0; 
    feet++;
  }
  feet += d2.feet + d3.feet;
}

void Distance::div_dist(Distance d2, int divisor) 
{
  float fltfeet = d2.feet + d2.inches / 12.0;
  fltfeet /= divisor;
  fltfeet = int(fltfeet);
  inches = (fltfeet - feet) * 12.0;
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Distance dist[100], total (0, 0.0), average; 
int count = 0; 
char ch;
do {
	cout << "Введите длину номер " << count + 1;
	dist[count++].getdist();
	cout << "Продолжить ввод(y/n)?:";
	cin >> ch;
} while (ch != 'n');
 
for (int j = 0; j < count; j++) 
{
	cout << "\nДлина номер " << j + 1 << " : ";
	dist[j].showdist();
	total.add_dist(total, dist[j]);
}
cout << "\nОбщая сумма:";
total.showdist();
cout << "\nСреднее значение:";
average.div_dist(total, count);
average.showdist();

cout << endl; system("pause"); return 0;
}
