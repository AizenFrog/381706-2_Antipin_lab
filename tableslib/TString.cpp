#include "TString.h"

String::String()
{
  count = 0;
  str = NULL;
}

String::String(const char* _str)
{
  count = strlen(_str);
  str = new char[count + 1];
  for (int i = 0; i < count; i++)
    str[i] = _str[i];
	str[count] = '\0';
}

String::String(const String& _str)
{
  count = _str.count;
  str = new char[count + 1];
  for (int i = 0; i < count; i++)
    str[i] = _str.str[i];
	str[count] = '\0';
}

String::~String()
{
  count = 0;
  delete[] str;
}

int String::GetCount() const
{
	return count;
}

String& String::operator=(const String& _str)
{
  count = _str.count;
  delete[] str;
  str = new char[count + 1];
  for (int i = 0; i < count; i++)
    str[i] = _str.str[i];
	str[count] = '\0';
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

bool String::operator!=(const String& _str) const
{
	if (count != _str.count)
		return true;
	for (int i = 0; i < count; i++)
		if (str[i] != _str.str[i])
			return true;
	return false;
}

bool String::operator<(const String& _str) const
{
  bool result = false;
  if (count < _str.count)
    return true;
  else if (count > _str.count)
    return false;
  else
  {
    for (int i = 0; i < count; i++)
			if (str[i] < _str.str[i])
			{
				result = true;
				break;
			}
  }
  return result;
}

bool String::operator>(const String& _str) const
{
  bool result = false;
  if (count < _str.count)
    return false;
  else if (count > _str.count)
    return true;
  else
    for (int i = 0; i < count; i++)
			if (str[i] > _str.str[i])
			{
				result = true;
				break;
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