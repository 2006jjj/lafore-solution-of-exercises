/*12_05ex.cpp
Создайте класс time, включающий себя целые значения часов, минут и секунд. Напишите метод get_time(), спрашивающий время у пользователя,
и метод put_time(), выводящий время в формате 12:59:59. Внесите в функцию get_time() проверку на ошибки, чтобы минимизировать возможность неправильного ввода пользователем.
Эта функция должна отдельно спрашивать часы, минуты и секунды, проверяя каждое введенное значение на наличие флагов ошибок ios, а также проверяя, укладывается ли значение
в заданный диапазон. Для часов диапазон составляет от 0 до 23, а для минут и секунд - от 0 до 59. Не вводите данные в виде символьных строк с последующим конвертированием.
Вводите значения сразу же как int. Это означает, что вы не сможете выявлять записи с ненужными здесь десятичными запятыми, но это в данной программе не так важно.
В main() используйте цикл для получения значений времени от пользователя функцией get_time(), а затем для их вывода функцией put_time():
    Введите часы: 8
    Введите минуты: 2
    Введите секунды: 39
    Время = 8:02:39
    Продолжить (y/n)? y
    Введите часы: 28
    Значение часов должно лежать между 0 и 23!
    Введите часы: 1
    Введите минуты: 10
    Введите секунды: пять
    Неправильно введены секунды!
    Введите секунды: 5
    Время = 1:10:05   */


#include <iostream>
using namespace std;

class time1 
{
private: 
  int hours, minutes, seconds;
public:
time1() : hours(0), minutes(0), seconds(0) {}
time1(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

void get_time()
{
  cout << "Введите время:";
  while (true)
  {
    cout << "\nВведите часы:";
    cin.unsetf(ios::skipws);
    cin >> hours;
    if (cin.good())
    {
      if (hours >= 0 && hours <= 23)
      {
        cin.ignore(10, '\n');
        break;
      }
      else 
        cout << "Введено неправильное количество часов!" << endl;
    }
    else
    {
      cout << "Неправильно введены часы";
      cin.clear();
    }
    cin.ignore(10, '\n');
  }
  while (true)
  {
    cout << "\nВведите минуты:";
    cin.unsetf(ios::skipws);
    cin >> minutes;
    if (cin.good())
    {
      if (minutes >= 0 && minutes <= 59)
      {
        cin.ignore(10, '\n');
        break;
      }
      else 
        cout << "Введено неправильное количество минут!" << endl;
    }
    else
    {
      cout << "Неправильно введены минуты"; 
      cin.clear();
    }
    cin.ignore(10, '\n');
  }
  while (true)
  {
    cout << "\nВведите секунды:";
    cin.unsetf(ios::skipws);
    cin >> seconds;
    if (cin.good())
    {
      if (seconds >= 0 && seconds <= 59)
      {
        cin.ignore(10, '\n');
        break;
      }
      else 
        cout << "Введено неправильное количество секунд!" << endl;
    }
    else
    {
      cout << "Неправильно введены секунды";
      cin.clear();
    }
    cin.ignore(10, '\n');
  }
}

void put_time()
{
  cout << "\nВРЕМЯ:" << ((hours < 10) ? "0" : "") << hours << ":" << ((minutes < 10) ? "0" : "") << minutes << ":" << ((seconds < 10) ? "0" : "") << seconds;
}
};

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

time1 t; 
char ch;
do 
{
  t.get_time();
  t.put_time();
  cout << "\nЖелаете продолжить? (y/n)"; 
  cin >> ch;
} while (ch != 'n'); 

cout << endl; system("pause"); return 0;
}
