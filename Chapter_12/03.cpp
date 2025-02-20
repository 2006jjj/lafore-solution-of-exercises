/*12_03ex.cpp
Напишите программу, возвращающую размер файла, указанного в командой строке:
    C:\filesize program.ext.*/


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
  cerr << "\nНевозможно открыть " << argv[1]; exit(-1); 
}
else
{ 
  infile.seekg(0, ios::end); 
  cout << "Размер файла " << argv[1] << " " << infile.tellg() << " байта(ов)" << endl; 
}
ofstream outfile;
outfile.open(argv[2], ios::app);
if (!outfile) 
{
  cerr << "\nНевозможно открыть " << argv[2];
  exit(-1);
}
else 
{ 
  outfile.seekp(0, ios::end); 
  cout << "Размер файла " << argv[2] << " " << outfile.tellp() << " байта(ов)" << endl; 
}

cout << endl; system("pause"); return 0;
}
