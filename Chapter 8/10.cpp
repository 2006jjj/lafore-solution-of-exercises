/*08_10ex.cpp
Только для любителей математики: создайте класс Polar, который предназначен для хранения полярных координат (радиуса и угла). 
Перегрузите операцию + для выполнения сложения для объектов класса Polar. Сложение двух объектов выполняется путем сложения координат X объектов,
а затем координат Y. Результат будет координатами новой точки. Таким образом, вам нужно будет преобразовать полярные координаты к прямоугольным,
сложить их, а затем обратно преобразовать прямоугольные координаты результата к полярным.*/

#include <iostream>
#include <iomanip> // для манипулятора setprecision
using namespace std;

const double PI = 3.141592653589793; 
class Dekartova; 
class Polar;
class Polar 
{
private:
	double corner, radius;
public:
Polar() : radius(0.0), corner(0.0) {}
Polar(double c, double r) : corner(c), radius(r) {}
Polar(const Dekartova& d1);

void put() 
{
  cout << "Введите полярные координаты\nВведите угол:"; 
  cin >> corner;
  if (corner < 0.0 || corner >360.0)
    exit(1);
  cout << "Введите радиус:"; 
  cin >> radius;
}
void display() const 
{ 
  cout << "Corner=" << corner << "\nRadius=" << radius << endl; 
}
double get_radius() const 
{ 
  return radius; 
}
double get_corner() const 
{ 
  return corner;
}
};

class Dekartova
{
private:
	double X, Y;
public:
Dekartova() : X(0.0), Y(0.0) {}
Dekartova(double x, double y) : X(x), Y(y) {}
Dekartova(const Polar& p1);

double get_x() const 
{ 
  return X; 
}
double get_y() const 
{
  return Y; 
}
Dekartova operator+(Dekartova d1) 
{ 
  return Dekartova(X + d1.X, Y + d1.Y); 
}
};
Dekartova::Dekartova(const Polar& p1)
{
	X = p1.get_radius() * cos(p1.get_corner() * PI / 180);
	Y = p1.get_radius() * sin(p1.get_corner() * PI / 180);
}
Polar::Polar(const Dekartova& d1)
{
	corner = atan2(d1.get_y(), d1.get_x()) * 180 / PI;
	radius = sqrt(d1.get_x() * d1.get_x() + d1.get_y() * d1.get_y());
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Polar p1, p2, sump;
Dekartova d1, d2, sumd;
p1.put(); 
cout << "\n(P1)Полярная\nCorner=" << p1.get_corner() << "\nRadius=" << p1.get_radius() << endl;
p2.put(); 
cout << "\n(P2)Полярная\nCorner=" << p2.get_corner() << "\nRadius=" << p2.get_radius() << endl;
d1 = p1; 
cout << "\n(D1)Декартовая\nX=" << d1.get_x() << "\nY=" << d1.get_y() << endl;
d2 = p2; 
cout << "\n(D2)Декартовая\nX=" << d2.get_x() << "\nY=" << d2.get_y() << endl;
sumd = d1 + d2; 
cout << "\n(SUMD)Декартовая\nX=" << sumd.get_x() << "\nY=" << sumd.get_y() << endl;
sump = sumd; 
cout << "\n(SUMP)Полярная\nCorner=" << sump.get_corner() << "\nRadius=" << sump.get_radius() << endl; 

cout << endl; system("pause"); return 0;
}
