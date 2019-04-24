#pragma once
#include "Elem.h"

template <class T>
class TSortTable
{
protected:
	static TElem<T> st;
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
  TElem<T>& Search(const String& key) const;
  T& operator[](const String& key) const;
	friend std::ofstream& operator<<(const std::ostream& out, const TSortTable<T>& table);
protected:
  void InsertSort();
  void MergeSort();
  void QuickSort();
	void Expansion(const int newsize);
};

template <class T>
TElem<T> TSortTable<T>::st;

template <class T>
TSortTable<T>::TSortTable(const int _size)
{
  if (_size < 0)
    throw 2;
  size = _size;
  count = 0;
  node = new TElem<T>()[size];
	for (int i = 0; i < size; i++)
		node[i] = st;
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

template <class T>
bool TSortTable<T>::Add(const TElem<T>& elem)
{
	if (count == 0)
		node[count] = elem;
	if (count == size)
		Expansion(count * 2);
	bool flag = false;
	TElem<T> tmp;
	for (int i = 0; i <= count; i++)
	{
		if (node[i].GetKey() < elem.GetKey())
			continue;
		else if (node[i].GetKey() > elem.GetKey() && flag == false)
		{
			flag = true;
			tmp = node[i];
			node[i] = elem;
			continue;
		}
		else if (flag == true)
		{
			TElem<T> temp = node[i];
			node[i] = tmp;
			tmp = temp;
		}
	}
	count++;
}

template <class T>
TElem<T>& TSortTable<T>::Search(const String& key) const
{
	int left = 0;
	int right = count;
	int current = count / 2;
	while (right - left >= 1)
		if (node[current].GetKey() > key)
		{
			left = current;
			current = (right + left) / 2;
		}
		else if (node[current].GetKey() < key)
		{
			right = current;
			current = (right - left) / 2;
		}
		else if (node[current].GetKey() == key)
			return node[current];
	return st;
}

template <class T>
T& TSortTable<T>::operator[](const String& key) const
{
	return Search(key).GetData();
}

template <class T>
void TSortTable<T>::Expansion(const int newsize)
{
	if (newsize > size)
	{
		TElem<T>* tmp = new TElem<T>[newsize];
		for (int i = 0; i < count; i++)
			tmp[i] = node[i];
		for (int i = count; i < newsize; i++)
			tmp[i] = st;
		size = newsize;
		delete[] node;
		node = tmp;
	}
	else
		throw 3;
}