/*08_01ex.cpp
Добавьте в класс Distance из программы ENGLPLUS этой главы перегруженную операцию -, которая вычисляет разность двух интервалов. Она должна позволять выполнение выражений типа dist3=dist1-dist2;.
Предполагаем, что эта операция никогда не будет использоваться для вычитания большего интервала из меньшего (так как отрицательного интервала быть не может).*/

#include <iostream>
using namespace std;

class Distance 
{
private:
	int feet; 
  float inches;
public:
	Distance() : feet(0), inches(0.0) {}
	Distance(int f, float in) : feet(f), inches(in) {}
void getdist() 
{ 
  cout << "Введите футы:"; 
  cin >> feet; 
  cout << "Введите дюймы:"; 
  cin >> inches; 
}
void showdist() const 
{ 
  cout << feet << "\'-" << inches << '\"'; 
}
Distance operator+ (Distance d2) const;
Distance operator- (Distance d2) const;
};

Distance Distance::operator+ (Distance d2) const 
{
  int f = feet + d2.feet; 
  float i = inches + d2.inches;
  if (i >= 12.0) 
  { 
    i -= 12.0; 
    f++; 
  }
  return Distance(f, i);
}
Distance Distance::operator-(Distance d2) const 
{
  int f = feet - d2.feet; 
  float i = inches - d2.inches;
  if (i < 0) 
  { 
    i += 12.0; 
    f--; 
  }
  return Distance(f, i);
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

Distance dist1, dist2(11, 6.25), dist3; 
dist1.getdist();
dist3 = dist1 - dist2;
cout << "\ndist1="; 
dist1.showdist(); 
cout << "\ndist2="; 
dist2.showdist(); 
cout << "\ndist3="; 
dist3.showdist();

cout << endl; system("pause"); return 0;
}
