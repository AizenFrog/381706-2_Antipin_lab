#include "Polish_string.h"

Polich_string::Polich_string()
{
  str = new char[100];
  index = 0;
  char_count = 0;
  servicechar = { "+-*/^()=" };
}

int Polich_string::GetIndex()
{
  return index;
}

void Polich_string::WrightString(const char* string)
{
  for (int i = 0; i < 100; i++)
  {
    if (string[i - 1] == '=' && i > 0)
      break;
    str[i] = string[i];
    char_count++;
  }
}

Number Polich_string::GetNextChar()
{
  Number tmp;
  int j = 0;
  if (IsServiceChar() == true && index != char_count)
  {
    tmp.number[0] = str[index];
    index++;
    tmp.len++;
  }
  else
    while (!IsServiceChar() && index != char_count)
    {
      tmp.number[j] = str[index];
      index++;
      tmp.len++;
      j++;
    }
  return tmp;
}

bool Polich_string::IsServiceChar()
{
  bool type = false;
  for (int i = 0; i < 8; i++)
    if (str[index] == servicechar[i])
      return true;
  return type;
}

Number::Number()
{
  number = new char[100];
  len = 0;
}