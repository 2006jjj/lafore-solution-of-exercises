/*15_13ex.cpp
Частотная таблица представляет собой список слов и количество их вхождений в данном тексте. Напишите программу, создающую частотную таблицу для файла,
имя которого введет пользователь. Для решения этой задачи хорошо подходит отображение, содержащее пары значений string-int. Можно использовать библиотечную функцию
С под названием ispunct() (см. заголовочный файл CTYPE.H) для проверки правильности пунктуации, чтобы знать, где кончается каждое слово, и выделять его в подстроку
методом substr(). Кроме того, функцией tolower() можно сделать все буквы слов строчными.*/


#include <iostream> 
#include <string> 
#include <fstream>  
#include <map>     
#include <iterator>  
#include <codecvt>  
#include <iomanip>  
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

ifstream infile("E://TEST//map.txt");
if (!infile)
  cerr << "Error";

string word;
int count = 0;
istream_iterator<string> file_iter(infile);
istream_iterator<string> end_of_stream;
map<string, int> mapstr;
map<string, int>::iterator iter;

while (file_iter != end_of_stream)
{
  word = *file_iter++;
  int len = word.length() - 1;
  while (len >= 0 && ispunct(word[len]))
    len--;
  word = word.substr(0, len + 1);
  
  if (word.empty()) 
    continue;
  
  for (int j = 0; j <= len; j++)
    word[j] = tolower(word[j]);
  mapstr[word]++;
  count++;
}

for (iter = mapstr.begin(); iter != mapstr.end(); iter++)
  cout << (*iter).first << ' ' << (*iter).second << endl; 

cout << endl; system("pause"); return 0;
}
