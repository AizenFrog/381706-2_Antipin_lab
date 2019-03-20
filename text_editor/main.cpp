#include <iostream>
#include "Text.h"

using namespace std;

int main()
{
  setlocale(LC_ALL, "RUS");
  TText::SetTreeSize(10000);
  char* str = new char[100];
  std::cin >> str;
  TText text(str);
  std::cout << text.GetRoot();
  text.ClearMemory();
  return 0;
}