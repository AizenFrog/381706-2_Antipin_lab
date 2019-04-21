#pragma once
#include "Elem.h"

template <class T>
class TSortTable
{
protected:
  TElem<T>* node;
  int count;
  int size;
public:
  TSortTable(const int _size = 1);
  TSortTable(const TSortTable<T>& table);
  bool Add(const TElem<T>& elem);
  String& Add(const T& data);
  bool Del(const TElem<T>& elem);
  bool Del(const String& key);
  TElem<T>& Search(const String& _key) const;
  T& operator[](const String& key) const;
protected:
  void InsertSort();
  void MergeSort();
  void QuickSort();
};

template <class T>
TSortTable<T>::TSortTable(const int _size)
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
TSortTable<T>::TSortTable(const TSortTable<T>& table)
{
  size = table.size;
  count = table.count;
  node = new TElem<T>()[size];
  for (int i = 0; i < size; i++)
    node[i] = table.node[i];
}