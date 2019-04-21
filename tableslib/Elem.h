#pragma once
#include "TString.h"

template <class T>
class TElem
{
protected:
  T data;
  String key;
public:
  TElem();
  TElem(const T& _data, const String& _key);
  TElem& operator=(const TElem& elem);
  T& GetData();
  void SetData(const T& _data);
  String& GetKey();
  void SetKey(const String& _key);
};

template <class T>
TElem<T>::TElem()
{
  data = NULL;
}

template <class T>
TElem<T>::TElem(const T& _data, const String& _key)
{
  data = _data;
  key = _key;
}

template <class T>
TElem<T>& TElem<T>::operator=(const TElem& elem)
{
  data = elem.data;
  key = elem.key;
  return *this;
}

template <class T>
T& TElem<T>::GetData()
{
  return data;
}

template <class T>
void TElem<T>::SetData(const T& _date)
{
  data = _date;
}

template <class T>
String& TElem<T>::GetKey()
{
  return key;
}

template <class T>
void TElem<T>::SetKey(const String& _key)
{
  key = _key;
}