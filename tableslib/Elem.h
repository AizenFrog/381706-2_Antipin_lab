#pragma once
#include "TString.h"
#include <iostream>

using namespace std;

template <class T>
class TElem
{
protected:
  T data;
  String key;
public:
  TElem();
  TElem(const T& _data, const String& _key);
  TElem& operator=(const TElem<T>& elem);
	bool operator==(const TElem<T>& elem);
	bool operator!=(const TElem<T>& elem);
  T& GetData();
  void SetData(const T& _data);
  String& GetKey();
  void SetKey(const String& _key);
  friend std::ostream& operator<<(std::ofstream& out, TElem<T>& elem)
	{
		out << elem.GetKey().GetArrChar() << "\t";
		out << elem.GetData() << std::endl;
		return out;
	}
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
TElem<T>& TElem<T>::operator=(const TElem<T>& elem)
{
  data = elem.data;
  key = elem.key;
  return *this;
}

template <class T>
bool TElem<T>::operator==(const TElem<T>& elem)
{
	if (data == elem.data && key == elem.key)
		return true;
	return false;
}

template <class T>
bool TElem<T>::operator!=(const TElem<T>& elem)
{
	if (data == elem.data && key == elem.key)
		return false;
	return true;
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

//template <class T>
//std::ofstream& operator<<(std::ostream& out, TElem<T>& elem)
//{
//	out << elem.GetKey().GetArrChar() << "\t";
//	out << elem.GetData() << std::endl;
//	return out;
//}