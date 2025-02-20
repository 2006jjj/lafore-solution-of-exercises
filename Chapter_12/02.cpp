/*12_02ex.cpp
Напишите программу, эмулирующую команду COPY (MS DOS). То есть программа должна копировать содержимое одного файла в другой.
Должно использоваться два аргумента командной строки - исходный файл и файл назначения. Например:
    C:\>ocopy srcfile.cpp destfile.cpp
Осуществляйте проверку числа аргументов командной строки и возможность открытия указанных пользователем файлов.*/

#include <fstream>
#include <iostream>
#include <codecvt>
#include <locale>
#include <process.h>
using namespace std;


int main(int argc, char* argv[])
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

cout << "argc = " << argc << endl; 
for (int j = 0; j < argc; j++) 
  cout << " Аргумент " << j << " = " << argv[j] << endl << endl;
 
if (argc != 3) 
{ 
  cerr << "\nERROR"; 
  exit(-1); 
}
 
char ch;
ifstream infile;
 
infile.open(argv[1]);
if (!infile) 
{ 
  cerr << "\nНевозможно открыть " << argv[1];
  exit(-1); 
}
ofstream outfile;
outfile.open(argv[2], ios::app);
if (!outfile) 
{
  cerr << "\nНевозможно открыть " << argv[2]; 
  exit(-1);
}
while (infile.get(ch))
  outfile.put(ch);
 cout << "All okey, check your file!"; 

cout << endl; system("pause"); return 0;
}
