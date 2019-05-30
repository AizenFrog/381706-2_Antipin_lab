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
	if (i > size)
		return false;
	while (node[i].GetKey() != key)
	{
		if (node[i] == st)
			return false;
		i = (i + m) % size;
	}
	node[i] = st;
	count--;
	return true;
}

template <class T>
T& THashTable<T>::Search(String& key)
{
	int i = Hash(key);
	if (i > size)
		return st.GetData();
	while (node[i].GetKey() != key)
	{
		i = (i + m) % size;
		if (node[i] == st)
			break;
	}
	return node[i].GetData();
}

template <class T>
bool THashTable<T>::IsSimple(const int number)
{
	for (int i = 2; i < number / 2; i++)
		if (number%i == 0)
			return false;
	return true;
}

template <class T>
int THashTable<T>::Hash(String& key)
{
	unsigned int hashval = 0;
	for (int i = 0; i < key.GetCount(); i++)
		hashval = (hashval >> 1) + key[i];
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

//////////////////////////////////////////////////////////

template <class T>
class THashTable_1
{
protected:
	static THashElem<T> st;
	THashElem<T>* node;
	int count;
	int size;
	//const int m = 2;
	int Hash(String& key);
	void Expansion(int newsize);
public:
	THashTable_1(const int _size = 1);
	THashTable_1(const THashTable_1<T>& table);
	~THashTable_1();
	int GetCount() const;
	void Add(String& key, const T& data);
	void Add(THashElem<T>& elem);
	bool Del(String& key);
	T& Search(String& key);
	friend std::ostream& operator<<(std::ostream& out, const THashTable_1<T>& table)
	{
		for (int i = 0; i < table.size; i++)
			if (table.node[i] != st)
				out << table.node[i] << std::endl;
		return out;
	}
};

template <class T>
THashElem<T> THashTable_1<T>::st;

template <class T>
THashTable_1<T>::THashTable_1(const int _size)
{
	if (_size <= 0)
		throw 1;
	count = 0;
	size = _size;
	node = new THashElem<T>[size];
	for (int i = 0; i < size; i++)
		node[i] = st;
}

template <class T>
THashTable_1<T>::THashTable_1(const THashTable_1<T>& table)
{
	count = table.count;
	size = table.size;
	node = new THashElem<T>[size];
	for (int i = 0; i < size; i++)
		node[i] = table.node[i];
}

template <class T>
THashTable_1<T>::~THashTable_1()
{
	count = size = 0;
	delete[] node;
}

template <class T>
int THashTable_1<T>::GetCount() const
{
	return count;
}

template <class T>
void THashTable_1<T>::Add(String& key, const T& data)
{
	if (count == size)
		Expansion(count * 2);
	int i = Hash(key);
	if (i > size)
		Expansion(i + 10);
	if (node[i] != st)
	{
		THashElem<T>* tmp = &node[i];
		while (tmp->GetNext() != NULL)
			tmp = tmp->GetNext();
		tmp->SetNext(new THashElem<T>(data, key));
	}
	else
	{
		node[i].SetKey(key);
		node[i].SetData(data);
	}
	count++;
}

template <class T>
void THashTable_1<T>::Add(THashElem<T>& elem)
{
	if (count == size)
		Expansion(count * 2);
	int i = Hash(elem.GetKey());
	if (i > size)
		Expansion(i + 10);
	if (node[i] != st)
	{
		THashElem<T>* tmp = &node[i];
		while (tmp->GetNext() != NULL)
			tmp = tmp->GetNext();
		tmp = new THashElem<T>(elem);
	}
	else
		node[i] = elem;
	count++;
}

template <class T>
bool THashTable_1<T>::Del(String& key)
{
	int i = Hash(key);
	bool flag = false;
	if (i > size)
		return flag;
	if (node[i].GetKey() != key)
	{
		THashElem<T>* tmp = node[i].GetNext();
		THashElem<T>* par = &node[i];
		while (tmp != NULL)
		{
			if (tmp->GetKey() == key)
			{
				if (tmp->GetNext() != NULL)
				{
					THashElem<T>* temp = tmp->GetNext();
					tmp->SetPtr(NULL);
					delete tmp;
					par->SetPtr(temp);
				}
				else
				{
					par->SetPtr(NULL);
					delete tmp;
				}
				flag = true;
				count--;
				break;
			}
			else
			{
				tmp = tmp->GetNext();
				par = par->GetNext();
			}
		}
	}
	else if (node[i].GetKey() == key)
	{
		THashElem<T>* tmp = node[i].GetNext();
		if (tmp != NULL)
		{
			node[i].SetPtr(NULL);
			node[i] = *tmp;
			//tmp->SetPtr(nullptr);
			//delete tmp;
		}
		else
			node[i] = st;
		flag = true;
		count--;
	}
	return flag;
}

template <class T>
T& THashTable_1<T>::Search(String& key)
{
	int i = Hash(key);
	if (node[i].GetKey() != key)
	{
		THashElem<T>* tmp = node[i].GetNext();
		while (tmp != NULL)
		{ 
			if (tmp->GetKey() != key)
				tmp = tmp->GetNext();
			else if (tmp->GetKey() == key)
				return tmp->GetData();
		}
		return st.GetData();
	}
	return node[i].GetData();
}

template <class T>
int THashTable_1<T>::Hash(String& key)
{
	unsigned int hashval = 0;
	for (int i = 0; i < key.GetCount(); i++)
		hashval = (hashval >> 1) + key[i];
	return hashval;
}

template <class T>
void THashTable_1<T>::Expansion(int newsize)
{
	if (newsize > size)
	{
		THashElem<T>* tmp = new THashElem<T>[newsize];
		for (int i = 0; i < size; i++)
			tmp[i] = node[i];
		for (int i = size; i < newsize; i++)
			tmp[i] = st;
		size = newsize;
		delete[] node;
		node = tmp;
	}
	else
		throw 3;
}