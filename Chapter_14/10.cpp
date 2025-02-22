/*14_10ex.cpp
Есть разные мнения на тему того, когда целесообразно использовать механизм исключений. Обратимся к программе ENGLERR из главы 12.
Надо ли в виде исключений оформлять ошибки, которые делает пользователь при вводе данных? Для этого упражнения будем считать, что надо.
Добавьте класс исключений к классу Distance в указанной программе (см. также примеры XDIST и XDIST2 в этой главе). Сгенерируйте исключения во всех
местах, где ENGLERR выводила сообщение об ошибке. Для выявления конкретной причины исключения (вместо дюймов введены какие-то символы, значение дюймов выходит
за область допустимых значений и т.д.). Кроме того, исключения должны генерироваться в качестве реакции на ошибки, возникающие в функции isint() (ничего не было
введено, введено слишком много разрядов значений, введен символ вместо числа, число выходит за область допустимых значений). Вопрос к вам: если функция isint() 
сгенерировала исключение, может ли она оставаться независимой?
Можно зациклить блок повторных попыток и блок-ловушку (создать цикл do), чтобы после обработки исключения программа продолжала работу, предлагая пользователю повторно
ввести данные. Если еще немного подумать, то может возникнуть желание генерировать исключение в конструкторе с двумя аргументами (в том случае, если программист 
инициализирует Distance значениями, выходящими за область допустимых).*/


#include <iostream>
#include <string>    
#include <cstdlib> 
using namespace std;

int isFeet(string);
class Distance
{
private: 
  int feet; 
  float inches;
public:
class DError 
{ 
public: 
  int num; 
  DError(int n) : num(n) {} 
};

Distance() { feet = 0, inches = 0.0; }
Distance(int ft, float in)
{
  if (ft < -999 || ft >999)
    throw DError(7);
  feet = ft;
  if (in >= 12.0 || in < 0.0)
    throw DError(8);
  inches = in;
}
void showdist() 
{ 
  cout << feet << "\-" << inches << '\"';
}
void getdist();
};

void Distance::getdist()
{
  string instr;
  while (true)
  {
    cout << "\n\nВведите футы: "; 
    cin.unsetf(ios::skipws); 
    cin >> instr;
    if (isFeet(instr))
    {
      cin.ignore(10, '\n');
      feet = atoi(instr.c_str());
      break;
    }
    cin.clear(); 
    cin.ignore(10, '\n'); 
    throw DError(1);
  }
  while (true)
  {
    cout << "Введите дюймы: "; 
    cin.unsetf(ios::skipws); 
    cin >> inches;
    if (inches >= 12.0 || inches < 0.0) 
    { 
      throw DError(2);
      cin.clear(ios::failbit); 
    }
    if (cin.good()) 
    { 
      cin.ignore(10, '\n');
      break; 
    }
    cin.clear();
    cin.ignore(10, '\n');
    throw DError(3);
  }
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

try 
  { 
    Distance d2(1002, 1.2); 
    d2.showdist(); 
  }
catch (Distance::DError err)
{
  switch (err.num)
  {
    case 7: 
      cout << "Конструктор с двумя аргументами: Неверно введены дюймы (от -999 до 999)\n"; 
      break;
    case 8:
      cout << "Конструктор с двумя аргументами: Неверно введеный футы (от 0.0 до 12.0)\n"; 
      break;
  }
}

Distance d; 
char ans;
do
{
  try 
    { 
      d.getdist(); 
    }
  catch (Distance::DError err)
  {
    switch (err.num)
    {
      case 1: 
        cout << "1) Функция getdist(): Футы должны быть целыми<1000\n"; 
        cin.clear(); 
        cin.ignore(10, '\n'); 
        break;
      case 2: 
        cout << "2) Функция getdist(): Дюймы должны быть между 0.0 и 11.99\n"; 
        cin.clear(); 
        cin.ignore(10, '\n'); 
        break;
      case 3: 
        cout << "3) Функция getdist(): Неверно введены дюймы\n"; 
        break;
      case 4: 
        cout << "4) Функция isfeet(): Ничего не введено или введено много символов\n"; 
        cin.clear(); 
        cin.ignore(10, '\n'); 
        break;
      case 5: 
        cout << "5) Функция isfeet(): Количество дюймов может содержать только цифры и знак минус;\n"; 
        cin.clear();
        cin.ignore(10, '\n'); 
        break;
      case 6: 
        cout << "6) Функция isfeet(): Количество дюймов должно быть в диапазоне от 999 до 999\n"; 
        cin.clear(); 
        cin.ignore(10, '\n'); 
        break;
    }
    cout << "Введите заново:\n"; 
    ans = 'y'; 
    continue;
  }
  cout << "\nРасстояние = ";
  d.showdist();
  cout << "\nЕЩе раз? (y/n):"; 
  cin >> ans;
  cin.ignore(10, '\n');
} while (ans != 'n'); 

cout << endl; system("pause"); return 0;
}


int isFeet(string str)
{
  int slen = str.size();
  if (slen == 0 || slen > 5) 
    throw Distance::DError(4);
  for (int j = 0; j < slen; j++)
    if ((str[j] < '0' || str[j]>'9' && str[j] != '-'))
      throw Distance::DError(5);
  double n = atof(str.c_str());
  if (n < -999.0 || n>999.0) 
    throw Distance::DError(6);
  return 1;
}
