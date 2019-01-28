#pragma once
#include "Polish_string.h"
#include "Stack.h"

class Calculator
{
private:
  Polich_string str;
  Stack<int>* numbers;
  Stack<char>* s_char;
public:
  Calculator(char* string);
  int Calculate();
  int AddToStacks(Number n);
  int CharToInt(Number st);
  int Priority();
  bool WhatsMore();
};