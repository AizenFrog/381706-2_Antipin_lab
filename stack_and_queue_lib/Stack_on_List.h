#pragma once
#include "List_Item.h"
#include <iostream>
#include "Exception_class.h"

template <class T>
class tStackList
{
protected:
	TDatLink<T>* pFirstItem;
	int ListLen;
	Exceptions_from_stack_queue_multystack exception;
public:
	tStackList();
	~tStackList();
	int GetLen();
	bool IsEmpty();
	void Put(T A);
	T Get();
};

template <class T>
tStackList<T>::tStackList()
{
	pFirstItem = NULL;
	ListLen = 0;
}

template <class T>
tStackList<T>::~tStackList()
{
	while (IsEmpty() == false)
	{
		TDatLink<T>* tmp = pFirstItem;
		pFirstItem = pFirstItem->GetNextLink();
		delete tmp;
	}
}

template<class T>
int tStackList<T>::GetLen()
{
	return ListLen;
}

template <class T>
bool tStackList<T>::IsEmpty()
{
	if (pFirstItem == NULL)
		return true;
	else
		return false;
}

template <class T>
void tStackList<T>::Put(T A)
{
	TDatLink<T>* tmp_1 = new TDatLink<T>(A, NULL);
	if (ListLen == 0)
		pFirstItem = tmp_1;
	else
	{
		TDatLink<T>* tmp_2 = pFirstItem;
		for (int i = 0; i < ListLen - 1; i++)
			tmp_2 = tmp_2->GetNextLink();
		tmp_2->Set_m(tmp_1);
	}
	ListLen++;
}

template <class T>
T tStackList<T>::Get()
{
	if (ListLen == 0)
		exception.except_throw(103);
	T A;
	if (ListLen == 1)
	{
		A = pFirstItem->GetMem();
		pFirstItem = NULL;
	}
	else
	{
		TDatLink<T>* tmp_2 = pFirstItem;
		for (int i = 0; i < ListLen - 2; i++)
			tmp_2 = tmp_2->GetNextLink();
		A = tmp_2->GetNextLink()->GetMem();
		delete tmp_2->GetNextLink();
		tmp_2->Set_m(NULL);
	}
	ListLen--;
	return A;
}

