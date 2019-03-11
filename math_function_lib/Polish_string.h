#pragma once
#include <iostream>

struct Number
{
public:
  char* number;
  int len;
  Number();
};

class Polich_string
{
private:
  char* str;
  int index;
  int char_count;
  const char* servicechar;
public:
  Polich_string();
  int GetIndex();
  void WrightString(const char* string);
  Number GetNextChar();
  bool IsServiceChar();
};