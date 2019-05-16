#pragma once
#include "Elem.h"

template <class T>
class THashTable
{
protected:
	static TElem<T> st;
	TElem<T>* node;
	int count;
	int size;
	const int m = 2;
	int Hash(String& key);
	void Expansion(int newsize);
public:
	THashTable(const int _size = 1);
	THashTable(const THashTable<T>& table);
	~THashTable();
	int GetCount() const;
	void Add(String& key, const T& data);
	void Add(TElem<T>& elem);
	bool Del(String& key);
	T& Search(String& key);
	bool IsSimple(const int number);
	friend std::ostream& operator<<(std::ostream& out, const THashTable<T>& table)
	{
		for (int i = 0; i < table.size; i++)
			if (table.node[i] != st)
				out << table.node[i] << std::endl;
		return out;
	}
};

template <class T>
TElem<T> THashTable<T>::st;

template <class T>
THashTable<T>::THashTable(const int _size)
{
	if (_size <= 0)
		throw 1;
	count = 0;
	size = _size;
	//m = 2;
	//while (size % m == 0)
	//{
	//	if (size == 1)
	//	{
	//		m = 1;
	//		break;
	//	}
	//	m++;
	//}
	node = new TElem<T>[size];
	for (int i = 0; i < size; i++)
		node[i] = st;
}

template <class T>
THashTable<T>::THashTable(const THashTable<T>& table)
{
	count = table.count;
	size = table.size;
	//m = table.m;
	node = new TElem<T>[size];
	for (int i = 0; i < size; i++)
		node[i] = table.node[i];
}

template <class T>
THashTable<T>::~THashTable()
{
	count = size = 0;
	delete[] node;
}

template <class T>
int THashTable<T>::GetCount() const
{
	return count;
}

template <class T>
void THashTable<T>::Add(String& key, const T& data)
{
	if (count == size)
		Expansion(count * 2);
	int i = Hash(key);
	if (i > size)
		Expansion(i + 10);
	while (node[i] != st)
		i = (i + m) % size;
	node[i].SetKey(key);
	node[i].SetData(data);
	count++;
}

template <class T>
void THashTable<T>::Add(TElem<T>& elem)
{
	if (count == size)
		Expansion(count * 2);
	int i = Hash(elem.GetKey());
	if (i > size)
		Expansion(i + 10);
	while (node[i] != st)
		i = (i + m) % size;
	node[i] = elem;
	count++;
}

template <class T>
bool THashTable<T>::Del(String& key)
{
	int i = Hash(key);
	while (node[i].GetKey() != key)
	{
		if (node[i] == st)
			return false;
		i = (i + m) % size;
	}
	node[i] = st;
	return true;
}

template <class T>
T& THashTable<T>::Search(String& key)
{
	int i = Hash(key);
	while (node[i].GetKey() != key)
	{
		i = (i + m) % size;
		if (node[i] == st)
			break;
	}
	return node[i].GetData();
}

template <class T>
bool THashTable<T>::IsSimple(const int nomber)
{
	for (int i = 2; i < nomber / 2; i++)
		if (nomber%i == 0)
			return false;
	return true;
}

template <class T>
int THashTable<T>::Hash(String& key)
{
	unsigned int hashval = 0;
	for (int i = 0; i < key.GetCount(); i++)
		hashval = (hashval >> 1) + key[i];
	/*m = 2;
	while (size % m == 0)
		m++;*/
	return hashval;
}

template <class T>
void THashTable<T>::Expansion(int newsize)
{
	if (newsize > size)
	{
		while (IsSimple(newsize) == 0)
			newsize++;
		TElem<T>* tmp = new TElem<T>[newsize];
		for (int i = 0; i < size; i++)
			tmp[i] = node[i];
		for (int i = size; i < newsize; i++)
			tmp[i] = st;
		size = newsize;
		delete[] node;
		node = tmp;
		/*while (size % m == 0)
			m++;*/
	}
	else
		throw 3;
}