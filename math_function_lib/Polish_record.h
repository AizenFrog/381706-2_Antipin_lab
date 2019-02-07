#pragma once
#include "Polish_string.h"
#include "Stack.h"
#include "Exception_class.h"

class Calculator
{
private:
  Polich_string str;
  Stack<int>* numbers;
  Stack<char>* s_char;
  Exceptions_from_polinom_and_calculator exception;
public:
  Calculator(const char* string);
  int Calculate();
  int AddToStacks(Number n);
  int CharToInt(Number st);
  int Priority();
  bool WhatsMore();
};