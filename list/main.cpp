#include "List.h"
#include "Arr_List.h"
#include <iostream>
#define ARRLIST

#ifndef ARRLIST
int main()
{
  setlocale(LC_ALL, "RUS");
  List<int> st;
  std::cout << "Тестирование списка" << std::endl;
  for (int i = 0; i < 100; i++)
  {
    st.InstLast(i);
    std::cout << "В список поступило число - " << i << std::endl;
  }
  std::cout << "//////////////////////////////////////////////////////////" << std::endl;
  for (int i = 99; i >= 0; i--)
  {
    std::cout << "Из списка взяли число - " << st.GetValue(i) << std::endl;
  }
  return 0;
}
#else
int main()
{
  setlocale(LC_ALL, "RUS");
  ArrList<int> al(100);
  std::cout << "Тестирование списка" << std::endl;
  for (int i = 0; i < 100; i++)
  {
    al.PutStart(i);
    std::cout << "В список поступило число - " << i << std::endl;
  }
  std::cout << "//////////////////////////////////////////////////////////" << std::endl;
  for (int i = 99; i >= 0; i--)
  {
    std::cout << "Из списка взяли число - " << al.GetEnd() << std::endl;
  }
  return 0;
}
#endif