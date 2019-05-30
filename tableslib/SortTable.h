#pragma once
#include "Elem.h"
#include "SeeTable.h"

#define INSERT_SORT 0
#define MERGE_SORT 1
#define QUICK_SORT 2

//int compare_cout = 0;

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
	TSortTable(const TTable<T>& table, const int nomber_sort);
	~TSortTable();
	int GetCount() const;
  bool Add(TElem<T>& elem);
  String& Add(const T& data);
  bool Del(TElem<T>& elem);
  bool Del(const String& key);
  TElem<T>& Search(const String& key) const;
  T& operator[](const String& key) const;
	friend std::ostream& operator<<(std::ostream& out, const TSortTable<T>& table)
	{
		for (int i = 0; i < table.GetCount(); i++)
			out << table.node[i] << std::endl;
		return out;
	}
  static void InsertSort(TTable<T>& seetable);
	static void MergeSort(TTable<T>& seetable, const int n, const int start);
	static void QuickSort(TTable<T>& seetable, const int low, const int high);
protected:
	void Expansion(const int newsize);
};

template <class T>
TElem<T> TSortTable<T>::st;

template <class T>
TSortTable<T>::TSortTable(const int _size)
{
  if (_size <= 0)
    throw 2;
  size = _size;
  count = 0;
  node = new TElem<T>[size];
	for (int i = 0; i < size; i++)
		node[i] = st;
}

template <class T>
TSortTable<T>::TSortTable(const TSortTable<T>& table)
{
  size = table.size;
  count = table.count;
  node = new TElem<T>[size];
  for (int i = 0; i < size; i++)
    node[i] = table.node[i];
}

template <class T>
TSortTable<T>::TSortTable(const TTable<T>& table, const int nomber_sort)
{
	size = table.size;
	count = table.count;
	TTable<T> copy_t(table);
	if (nomber_sort == INSERT_SORT)
		TSortTable<T>::InsertSort(copy_t);
	else if (nomber_sort == MERGE_SORT)
		TSortTable<T>::MergeSort(copy_t, copy_t.count, 0);
	else if (nomber_sort == QUICK_SORT)
		TSortTable<T>::QuickSort(copy_t, 0, copy_t.count - 1);
	node = new TElem<T>[size];
	for (int i = 0; i < count; i++)
		node[i] = copy_t.node[i];
}

template <class T>
TSortTable<T>::~TSortTable()
{
	count = size = 0;
	delete[] node;
}

template <class T>
int TSortTable<T>::GetCount() const
{
	return count;
}

template <class T>
bool TSortTable<T>::Add(TElem<T>& elem)
{
	bool flag = false;
	if (count == 0)
	{
		node[count] = elem;
		count++;
		return true;
	}
	if (count == size)
		Expansion(count * 2);
	TElem<T> tmp;
	for (int i = 0; i <= count; i++)
	{
		if (node[i].GetKey() < elem.GetKey() && i != count)
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
		else if (i == count && flag == false)
		{
			node[count] = elem;
			flag = true;
		}
	}
	count++;
	return flag;
}

template <class T>
String& TSortTable<T>::Add(const T& data)
{
	if (size == count)
		Expansion(count * 2);
	node[count].SetData(data);
	String tmp("First_Key");
	if (count == 0) 
	{
		node[count].SetKey(tmp);
		count++;
		return node[count - 1].GetKey();
	}
	else
	{
		String tmp1(&(node[count - 1].GetKey().GetArrChar()[0]));
		tmp = tmp1;
		node[count].SetKey(tmp);
		TElem<T> temp = node[count - 1];
		node[count - 1] = node[count];
		node[count] = temp;
	}
	count++;
	return node[count - 2].GetKey();
}

template <class T>
bool TSortTable<T>::Del(TElem<T>& elem)
{
	int left = 0;
	int right = count;
	int current = count / 2;
	bool flag = false;
	while (right - left >= 1)
		if (node[current].GetKey() < elem.GetKey())
		{
			left = current;
			current = (right + left) / 2;
		}
		else if (node[current].GetKey() > elem.GetKey())
		{
			right = current;
			current = (right - left) / 2;
		}
		else if (node[current].GetKey() == elem.GetKey())
		{
			for (int i = current; i < count - 1; i++)
				node[i] = node[i + 1];
			count--;
			flag = true;
			break;
		}
	return flag;
}

template <class T>
bool TSortTable<T>::Del(const String& key)
{
	int left = 0;
	int right = count;
	int current = count / 2;
	bool flag = false;
	while (right - left >= 1)
		if (node[current].GetKey() < key)
		{
			left = current;
			current = (right + left) / 2;
		}
		else if (node[current].GetKey() > key)
		{
			right = current;
			current = (right - left) / 2;
		}
		else if (node[current].GetKey() == key)
		{
			for (int i = current; i < count - 1; i++)
				node[i] = node[i + 1];
			count--;
			flag = true;
			break;
		}
	return flag;
}

template <class T>
TElem<T>& TSortTable<T>::Search(const String& key) const
{
	int left = 0;
	int right = count;
	int current = count / 2;
	int tmp = count / 2;
	while (right - left >= 1)
	{
		if (node[current].GetKey() < key)
		{
			left = current;
			current = (right + left) / 2;
		}
		else if (node[current].GetKey() > key)
		{
			right = current;
			current = (right - left) / 2;
		}
		else if (node[current].GetKey() == key)
			return node[current];
		if (right - left == 1)
			break;
	}
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

template <class T>
void TSortTable<T>::InsertSort(TTable<T>& seetable)
{
	for (int i = 1; i < seetable.count; i++)
	{
		TElem<T> temp = seetable.node[i];
		int j = i;
		while (j > 0 && seetable.node[j - 1].GetKey() > temp.GetKey())
		{
			seetable.node[j] = seetable.node[j - 1];
			j--;
			//compare_cout++;
		}
		seetable.node[j] = temp;
	}
	//cout << compare_cout << endl;
	//compare_cout = 0;
}

template <class T>
void TSortTable<T>::MergeSort(TTable<T>& seetable, const int n, const int start)
{
	if (n > 1)
	{
		const int left_size = n / 2;
		const int right_size = n - left_size;
		const int left_start = right_size - left_size + start - (n % 2);
		const int right_start = left_size + start;
		/////////////////////////////////////////////////
		MergeSort(seetable, left_size, left_start);
		MergeSort(seetable, right_size, right_start);
		/////////////////////////////////////////////////
		int	lid = 0, rid = left_size, xid = 0;
		/////////////////////////////////////////////////
		TElem<T>* tmp = new TElem<T>[n];
		while (lid < left_size || rid < n)
		{
			//compare_cout++;
			if (seetable.node[lid + start].GetKey() < seetable.node[rid + start].GetKey())
			{
				tmp[xid] = seetable.node[lid + start];
				lid++;
				xid++;
			}
			else
			{
				tmp[xid] = seetable.node[rid + start];
				xid++;
				rid++;
			}
			if (lid == left_size)
			{
				for (int i = rid; i < n; i++)
				{
					tmp[xid] = seetable.node[i + start];
					xid++;
				}
				break;
			}
			if (rid == n)
			{
				for (int i = lid; i < left_size; i++)
				{
					tmp[xid] = seetable.node[i + start];
					xid++;
				}
				break;
			}
		}
		for (int i = 0; i < n; i++)
			seetable.node[i + start] = tmp[i];
		delete[] tmp;
	}
}

template <class T>
void TSortTable<T>::QuickSort(TTable<T>& seetable, const int low, const int high)
{
	int i = low, j = high;
	TElem<T> d;
	TElem<T> m = seetable.node[(low + high) / 2];
	while (i <= j)
	{
		for (; seetable.node[i].GetKey() < m.GetKey(); i++);
		for (; seetable.node[j].GetKey() > m.GetKey(); j--);
		if (i <= j)
		{
			d = seetable.node[i];
			seetable.node[i++] = seetable.node[j];
			seetable.node[j--] = d;
		}
		//compare_cout++;
	}
	if (low < j)
		QuickSort(seetable, low, j);
	if (i < high)
		QuickSort(seetable, i, high);
}