#pragma once
#include "Elem.h"
//#include "SortTable.h"

template <class T>
class TSortTable;

template <class T>
class TTable
{
protected:
	static TElem<T> st;
	TElem<T>* node;
  int size;
  int count;
public:
  TTable(const int _size = 1);
  TTable(const TTable<T>& table);
	~TTable();
	int GetCount() const;
  bool Add(const TElem<T>& elem);
  String& Add(const T& data);
  bool Del(TElem<T>& elem);
  bool Del(const String& key);
  TElem<T>& Search(const String& _key) const;
  T& operator[](const String& key) const;
	friend class TSortTable<T>;
	friend std::ostream& operator<<(std::ostream& out, const TTable<T>& table)
	{
		for (int i = 0; i < table.GetCount(); i++)
			out << table.node[i] << std::endl;
		return out;
	}
protected:
	void Expansion(const int newsize);	
};

template <class T>
TElem<T> TTable<T>::st;

template <class T>
TTable<T>::TTable(const int _size)
{
  if (_size < 0)
    throw 2;
  size = _size;
  count = 0;
  node = new TElem<T>[size];
	for (int i = 0; i < size; i++)
		node[i] = st;
}

template <class T>
TTable<T>::TTable(const TTable<T>& table)
{
  size = table.size;
  count = table.count;
  node = new TElem<T>[size];
  for (int i = 0; i < size; i++)
    node[i] = table.node[i];
}

template <class T>
TTable<T>::~TTable()
{
	count = size = 0;
	delete[] node;
}

template <class T>
int TTable<T>::GetCount() const
{
	return count;
}

template <class T>
bool TTable<T>::Add(const TElem<T>& elem)
{
	if (size == count)
		Expansion(count * 2);
  node[count] = elem;
  count++;
  return true;
}

template <class T>
String& TTable<T>::Add(const T& _data)
{
	if (size == count)
		Expansion(count * 2);
  node[count].SetData(_data);
	String tmp("First_Key");
	if (count == 0)
		node[count].SetKey(tmp);
	else
	{	
		char letter = (node[count - 1].GetKey().GetArrChar())[0];
		String tmp1(&letter);
		tmp = tmp1;
		node[count].SetKey(tmp);
	}
  count++;
	return node[count - 1].GetKey();
}

template <class T>
bool TTable<T>::Del(TElem<T>& elem)
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
  return st;
}

template <class T>
T& TTable<T>::operator[](const String& _key) const
{
  return Search(_key).GetData();
}

template <class T>
void TTable<T>::Expansion(const int newsize)
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