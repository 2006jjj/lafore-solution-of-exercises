/*04_03ex.cpp
Создайте структуру с именем Volume, содержащую три поля типа Distance из примера englstrc, для хранения трех измерений помещения. 
Определите переменную типа Volume, инициализируйте ее, вычислите объем, занимаемый помещением, и выведите результат на экран.
Для подсчета объема переведите каждое из значений типа Distance в значение типа float, равное соответствующей длине в футах и хранимое в отдельной переменной.
Затем для вычисления объема следует перемножить три полученные вещественные переменные. */


#include <iostream>
using namespace std;

struct Distance 
{ 
  int feet; 
  float inches;
};

struct Volume 
{ 
  Distance length, wigth, height;
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
Volume room = {{ 15, 6.25 }, { 25, 4.2 }, { 12, 5.8 }};
float l = room.length.feet + room.length.inches / 12, 
      w = room.wigth.feet + room.wigth.inches / 12,
      h = room.height.feet + room.height.inches / 12;
cout << "Длина комнаты: " << l << "\nШирина комнаты: " << w << "\nВысота комнаты: " << h << "\nОбъем комнаты: " << l * w * h << endl;
 
system("pause"); return 0;
}
