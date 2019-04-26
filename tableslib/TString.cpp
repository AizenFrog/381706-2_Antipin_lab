#include "TString.h"

String::String()
{
  count = 0;
  str = NULL;
}

String::String(const char* _str)
{
  count = strlen(_str);
  str = new char[count];
  for (int i = 0; i < count; i++)
    str[i] = _str[i];
}

String::String(const String& _str)
{
  count = _str.count;
  str = new char[count];
  for (int i = 0; i < count; i++)
    str[i] = _str.str[i];
}

String::~String()
{
  count = 0;
  delete[] str;
}

String& String::operator=(const String& _str)
{
  count = _str.count;
  delete[] str;
  str = new char[count];
  for (int i = 0; i < count; i++)
    str[i] = _str.str[i];
  return *this;
}

bool String::operator==(const String& _str) const
{
  if (count != _str.count)
    return false;
  for (int i = 0; i < count; i++)
    if (str[i] != _str.str[i])
      return false;
  return true;
}

bool String::operator<(const String& _str) const
{
  bool result = true;
  if (count < _str.count)
    return true;
  else if (count > _str.count)
    return false;
  else
  {
    for (int i = 0; i < count; i++)
      if (str[i] > _str.str[i])
        result = false;
  }
  return result;
}

bool String::operator>(const String& _str) const
{
  bool result = true;
  if (count < _str.count)
    return false;
  else if (count > _str.count)
    return true;
  else
  {
    for (int i = 0; i < count; i++)
      if (str[i] < _str.str[i])
        result = false;
  }
  return result;
}

char& String::operator[](const int pos) const
{
  if (pos < 0 || pos > count - 1)
    throw 1;
  return str[pos];
}

char* String::GetArrChar()
{
  return str;
}