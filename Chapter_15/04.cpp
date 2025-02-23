/*15_04ex.cpp
Начните с класса person. Создайте мультимножество для хранения указателей на объекты этого класса. Определите его с помощью функционального 
объекта comparePersons, чтобы сортировка производилась автоматически по именам людей. Определите с полдюжины элементов, внесите их в мультимножество.
Выведите его содержимое. Задайте имена людей таким образом, чтобы некоторые из них совпадали. Тем самым можно будет удостовериться в том, что мультимножество
может хранить несколько объектов с одинаковым ключом.*/

#include <iostream>
#include <set>  
#include <algorithm>
#include <string>    
#include <iomanip>
using namespace std;


class person
{
private:
  string lastName, firstName; 
  long phoneNumber;
public:
person() : lastName("пусто"), firstName("пусто"), phoneNumber(0L) {}
person(string lana, string fina, long pho) : lastName(lana), firstName(fina), phoneNumber(pho) {}

friend bool operator < (const person&, const person&);
friend bool operator == (const person&, const person&);
friend bool operator != (const person&, const person&);
friend bool operator> (const person&, const person&);

void display() const 
{
  cout << endl << lastName << ",\t" << firstName << "\t\tТелефон: " << phoneNumber; 
}
long get_phone() const 
{ 
  return phoneNumber;
}
};

bool operator <(const person& p1, const person& p2)
{
  if (p1.firstName == p2.firstName && p1.lastName == p2.lastName)
    return (p1.phoneNumber < p2.phoneNumber) ? 1 : 0;
  else if (p1.firstName == p2.firstName)
    return (p1.lastName < p2.lastName) ? 1 : 0;
  return (p1.firstName < p2.firstName) ? 1 : 0;
}
bool operator ==(const person& p1, const person& p2) 
{ 
  return (p1.lastName == p2.lastName && p1.firstName == p2.firstName) ? true : false; 
}
bool operator !=(const person& p1, const person& p2) 
{
  return !(p1 == p2);
}
bool operator > (const person& p1, const person& p2)
{ 
  return !(p1 < p2) && !(p1 == p2); 
}

class comparePersons
{
public: 
bool operator() (const person* ptrP1, const person* ptrP2) const
{ 
  return *ptrP1 < *ptrP2; 
}
};

class displayPerson
{
public:
void operator() (const person* ptrP) const 
{ 
  ptrP->display(); 
}
};


int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

multiset<person*, comparePersons> persSet;
multiset<person*, comparePersons>::iterator iterp;
 
persSet.insert(new person("Deauville", "William", 8435150L));
persSet.insert(new person("Deauville", "William", 6946473L));
persSet.insert(new person("McDonald", "Stacey", 3327563L));
persSet.insert(new person("KuangThu", "Stacey", 4157300L));
persSet.insert(new person("Wellington", "John", 9207404L));
persSet.insert(new person("McDonald", "Amanda", 8435150L));

for_each(persSet.begin(), persSet.end(), displayPerson());
cout << endl;
 
for (iterp = persSet.begin(); iterp != persSet.end(); iterp++)
  (*iterp)->display();
 
iterp = persSet.begin();
int count = 0; 
cout << endl;
 
while (iterp != persSet.end())
{
  delete* iterp;
  persSet.erase(iterp++);
  cout << "Элемент " << ++count << " удален!" << endl;
  if (persSet.empty())
    cout << "\n\nМножество пусто!";
}

cout << endl; system("pause"); return 0;
}
