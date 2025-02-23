/*15_12ex.cpp
Напишите программу, копирующую один файл с целочисленными данными в другой. Используйте для этого потоковые итераторы. Пользователь
должен ввести имена обоих файлов. Можно использовать цикл while. В этом цикле, наверное, будут читаться последовательно значения из входного
итератора и сразу записываться в выходной, после чего будет производиться инкремент обоих итераторов. В качестве исходного можно взять 
файл ITER.DAT, созданный программой FOUTITER.*/

#include <iostream> 
#include <string>
#include <fstream>  
#include <iterator>          
#include <codecvt> 
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

ifstream infile("E://TEST//ITER.txt");
 if (!infile)
   cerr << "Error";
 ofstream outfile("E://TEST//ITER1.txt");
 if (!outfile)
   cerr << "Error";

istream_iterator<int> file_iter_in(infile);
istream_iterator<int> end_of_stream;
ostream_iterator<int> file_iter_out(outfile, " ");

while (file_iter_in != end_of_stream)
{
  *file_iter_out++ = *file_iter_in++;
}
 
list<int> ilist;
ifstream infile1("E://TEST//ITER2.txt");
istream_iterator<int> file_iter_in1(infile1);
copy(file_iter_in1, end_of_stream, back_inserter(ilist));
copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, "--"));
cout << endl;

cout << endl; system("pause"); return 0;
}
