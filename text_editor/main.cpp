#include <iostream>
#include <cstdio>
#include <ctime>
#include "Text.h"
//#define TIME_CHECK

using namespace std;

int main()
{
#ifndef TIME_CHECK
  setlocale(LC_ALL, "RUS");
  TText::SetTreeSize(10000);
  char* str = new char[100];
  char* add = new char[20];
  int pos = 0;
  int len = 0;
  cout << "¬ведите строку: " << endl;
  fgets(str, 100, stdin);
  TText text(str);
  cout << *text.GetRoot();
  //text.GetRoot()->Output();
  cout << "¬ведите что и в какое место добавить:" << endl;
  fgets(add, 20, stdin);
  cin >> pos;
  text.Insert(pos, add);
  text.GetRoot()->Output();
  cout << "¬ведите с какого места и сколько удалить:" << endl;
  cin >> pos;
  cin >> len;
  text.Delete(pos, len);
  text.GetRoot()->Output();
  text.ClearMemory();
  delete add;
  delete str;
  return 0;
#else // !TIME_CHECK

  TTree::ClearMemory();
  //TText::SetTreeSize(1000);
  TTree::SetTreeSize(10000);
  TText text("A");
  for (int i = 3; i < 9999; i++)
  {
    text.Insert(0, "B");
  }
  int time_1 = clock();
  text.Delete(9996, 1);
  cout << ((float)(clock() - time_1) / CLOCKS_PER_SEC) << endl;
  TTree::ClearMemory();
#endif
}