#pragma once
#include <iostream>
#include "Exception_class.h"

template <class T>
class ArrList
{
protected:
	T* Mas;
	int* Index;
	int Mem, count, c, size;//текущий элемент; количество элементов; текущий свободный; размер
	Exceptions_from_list_arrlist exception;
public:
	ArrList(const int n = 0);
	ArrList(const ArrList<T>& A);
	~ArrList();
	bool IsFull();
	bool IsEmpty();
	void PutStart(const T& A);
	void PutEnd(const T& A);
	T GetStart();
	T GetEnd();
};

template <class T>
ArrList<T>::ArrList(const int n = 0)
{
	if (n < 0)
		exception.except_throw(105);
	else if (n == 0)
	{
		Mas = NULL;
		Index = NULL;
		Mem = count = c = size = 0;
	}
	else
	{
		size = n;
		count = c = 0;
		Mas = new T[size];
		Index = new int[size];
		Mem = -1;
		for (int i = 0; i < size; i++)
			Index[i] = -2;
	}
}

template <class T>
ArrList<T>::ArrList(const ArrList<T>& A)
{
	if (A.size == 0)
	{
		size = c = Mem = count = 0;
		Mas = NULL;
		Index = NULL;
	}
	else
	{
		size = A.size;
		c = A.c;
		Mem = A.Mem;
		counts = A.count;
		for (int i = 0; i < size; i++)
		{
			Mas[i] = A.Mas[i];
			Index[i] = A.Index[i];
		}
	}
}

template <class T>
ArrList<T>::~ArrList()
{
	delete[] Mas;
	delete[] Index;
}

template <class T>
bool ArrList<T>::IsFull()
{
	if (count == size)
		return true;
	else
		return false;
}

template <class T>
bool ArrList<T>::IsEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}

template <class T>
void ArrList<T>::PutStart(const T& A)
{
	if (IsFull() == true)
		exception.except_throw(106);
	else
	{
		Mas[c] = A;
		Index[c] = Mem;
		Mem = c;
		count++;
		for (int i = 0; i < size; i++)
			if (Index[i] == -2)
			{
				c = i;
				break;
			}
	}
}

template <class T>
void ArrList<T>::PutEnd(const T& A)
{
	if (IsFull() == true)
		exception.except_throw(106);
	else if (IsEmpty() == true)
		PutStart(A);
	else
	{
		int i = Mem;
		while (Index[i] != -1)
			i = Index[i]; 
		Mas[c] = A;
		Index[c] = -1;
		Index[i] = c;
		count++;
		for (int k = 0; k < size; k++)
			if (Index[k] == -2)
			{
				c = k;
				break;
			}
	}
}

template <class T>
T ArrList<T>::GetStart()
{
	if (IsEmpty() == true)
		exception.except_throw(107);
	int i = Mem;
	Mem = Index[Mem];
	Index[i] = -2;
	count--;
	return Mas[i];
}

template <class T>
T ArrList<T>::GetEnd()
{
	if (IsEmpty() == true)
		exception.except_throw(107);
	else if (count == 1)
		GetStart();
	else
	{
		int i = Mem;
		int j = Index[i];
		while (Index[j] != -1)
		{
			i = j;
			j = Index[j];
		}
		Index[j] = -2;
		count--;
		c = j;
		Index[i] = -1;
		return Mas[j];
	}
}