/*07_06ex.cpp
В игре бридж каждому из игроков раздают 13 карт, таким образом колода расходуется полностью. Модифицируйте программу CARDARAY этой главы так, чтобы после
перемешивания колоды она делилась на четыре части по 13 карт каждая. Каждая из четырех групп карт затем должна быть выведена.*/

#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
const int jack = 11; 
const int queen = 12; 
const int king = 13; 
const int ace = 14;

class card 
{
private:
	int number; 
  Suit suit;
public:
card() {}
void set(int n, Suit s) 
{ 
  suit = s; 
  number = n; 
}
void display() const;
};

void card::display() const 
{
  if (number >= 2 && number <= 10)
    cout << number;
  else
  {
    switch (number) 
    {
      case jack:cout << 'J'; break;
      case queen:cout << 'Q'; break;
      case king:cout << 'K'; break;
      case ace: cout << 'A'; break;
    }
  }
  switch (suit) 
  {
    case 0:cout << static_cast<char>(5) << " "; break;
    case 1:cout << static_cast<char>(4) << " "; break;
    case 2:cout << static_cast<char>(3) << " "; break;
    case 3:cout << static_cast<char>(6) << " "; break;
  }
}

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int SIZE = 52; 
int j = 0;
card deck[SIZE];
 
for (j = 0; j < SIZE; j++)
{
  int num = (j % 13) + 2;
  Suit su = Suit(j / 13);
  deck[j].set(num, su);
}
 
cout << "Исходная колода:\n";
for (j = 0; j < SIZE; j++)
{
  deck[j].display();
  if (!((j + 1) % 13))
    cout << endl;
}

for (j = 0; j < SIZE; j++)
{
  int k = rand() % SIZE;
  card temp = deck[j];
  deck[j] = deck[k];
  deck[k] = temp;
}
cout << "\nПеремешанная колода:\n";
for (j = 0; j < SIZE; j++)
{
	deck[j].display();
	if (!((j + 1) % 13))
		cout << endl;
}
cout << endl;
for (j = 0; j < SIZE; j++) 
{ 
  if ((j % 13) == 0) 
    cout << "Игрок[" << (j / 13) + 1 << "]:\n"; 
  deck[j].display(); 
  if (!((j + 1) % 13)) 
    cout << endl; 
} 
cout << endl; system("pause"); return 0;
}
