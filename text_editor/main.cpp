#include <iostream>
#include "Text.h"

using namespace std;

int main()
{
  setlocale(LC_ALL, "RUS");
  TText::SetTreeSize(10000);
  char* str = new char[100];
  char* add = new char[20];
  int pos = 0;
  int len = 0;
  cout << "¬ведите строку: " << endl;
  gets_s(str, 100);
  TText text(str);
  cout << *text.GetRoot() << endl;
  text.GetRoot()->Output();
  cout << "¬ведите что и в какое место добавить:" << endl;
  gets_s(add, 20);
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
}