#pragma once
#include "Elem.h"

template <class T>
class TTable
{
protected:
  TElem<T>* node;
  int size;
  int count;
public:
  TTable(const int _size = 1);
  TTable(const TTable<T>& table);
  bool Add(const TElem<T>& elem);
  String& Add(const T& data);
  bool Del(const TElem<T>& elem);
  bool Del(const String& key);
  TElem<T>& Search(const String& _key) const;
  T& operator[](const String& key) const;
};

template <class T>
TTable<T>::TTable(const int _size)
{
  if (_size < 0)
    throw 2;
  size = _size;
  count = 0;
  node = new TElem<T>()[size];
  for (int i = 0; i < size; i++)
  {
    node[i].SetData(NULL);
    node[i].SetKey("0");
  }
}

template <class T>
TTable<T>::TTable(const TTable<T>& table)
{
  size = table.size;
  count = table.count;
  node = new TElem<T>()[size];
  for (int i = 0; i < size; i++)
    node[i] = table.node[i];
}

template <class T>
bool TTable<T>::Add(const TElem<T>& elem)
{
  if (size == count)
    return false;
  node[count] = elem;
  count++;
  return true;
}

template <class T>
String& TTable<T>::Add(const T& _data)
{
  if (size == count)
    return String();
  node[count].SetData(_data);
  String tmp(node[count - 1].GetKey().GetArrChar + 1);
  node[count].SetKey(tmp);
  count++;
  return tmp;
}

template <class T>
bool TTable<T>::Del(const TElem<T>& elem)
{
  if (count == 0)
    return false;
  bool flag = false;
  for (int i = 0; i < count; i++)
    if (node[i].GetKey() == elem.GetKey())
    {
      for (int j = i; j < count - 1; j++)
        node[j] = node[j + 1];
      flag = true;
      break;
    }
  if (flag == true)
    count--;
  return flag;
}

template <class T>
bool TTable<T>::Del(const String& _key)
{
  if (count == 0)
    return false;
  bool flag = false;
  for (int i = 0; i < count; i++)
    if (node[i].GetKey() == _key)
    {
      for (int j = i; j < count - 1; j++)
        node[j] = node[j + 1];
      flag = true;
      break;
    }
  if (flag == true)
    count--;
  return flag;
}

template <class T>
TElem<T>& TTable<T>::Search(const String& _key) const
{
  for (int i = 0; i < count; i++)
    if (node[i].GetKey() == _key)
      return node[i];
  return TElem<T>();
}

template <class T>
T& TTable<T>::operator[](const String& _key) const
{
  return Search(_key).GetData();
}