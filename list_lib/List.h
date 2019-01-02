#pragma once
#include "List_Item.h"
#include "Exception_class.h"
#include <iostream>
Exceptions_from_list_arrlist exception;

template <class T>
class List
{
protected:
	TDatLink<T>* FirstItem;
	TDatLink<T>* LastItem;
	int ListLen;
	TDatLink<T>* GetLink(T _Mem, TDatLink<T>* _m);
	void DelLink(TDatLink<T>* Link);
public:
	List();
	~List();
	T GetValue(const int Pos) const;
	bool IsEmpty() const;
	int GetListLen() const;
	void InstFirst(T A);
	void InstCustom(const int Pos, T A);
	void InstLast(T A);
	void DelFirst();
	void DelCustom(const int Pos);
	void DelList();
	friend TDatLink<T>;
};

template <class T>
List<T>::List()
{
	FirstItem = NULL;
	LastItem = NULL;
	ListLen = 0;
}

template <class T>
List<T>::~List()
{
	DelList();
}

template <class T>
TDatLink<T>* List<T>::GetLink(T _Mem, TDatLink<T>* _m)
{
	TDatLink<T>* tmp = new TDatLink<T>(_Mem, _m);
	if (tmp->GetMem() == NULL && tmp->GetNextLink() == NULL)
		exception.except_throw(101);
	else
		return tmp;
}

template <class T>
void List<T>::DelLink(TDatLink<T>* Link)
{
	if (Link->GetMem() != NULL && Link->GetNextLink() != NULL)
	{
		delete Link->Mem;
		delete Link->m;
	}
	else
		exception.except_throw(102);
}

template <class T>
T List<T>::GetValue(const int Pos) const
{
	if (Pos >= ListLen || Pos < 0)
		exception.except_throw(103);
	TDatLink<T>* tmp = FirstItem;
	for (int i = 0; i < Pos; i++)
		tmp = tmp->GetNextLink();
	return tmp->GetMem();
}

template <class T>
bool List<T>::IsEmpty() const
{
	if (ListLen == 0)
		return true;
	else
		return false;
}

template <class T>
int List<T>::GetListLen() const
{
	return ListLen;
}

template <class T>
void List<T>::InstFirst(T A)
{
	TDatLink<T>* tmp = new TDatLink<T>(A, FirstItem);
	FirstItem = tmp;
	ListLen++;
	if (ListLen == 1)
		LastItem = tmp;
}

template <class T> 
void List<T>::InstLast(T A)
{
	TDatLink<T>* tmp = FirstItem;
	TDatLink<T>* TMP = new TDatLink<T>(A, NULL);
	for (int i = 0; i < ListLen - 1; i++)
		tmp = tmp->GetNextLink();
	ListLen++;
	if (ListLen == 1)
		FirstItem = TMP;
	else
		tmp->Set_m(TMP);
	LastItem = TMP;
}

template <class T>
void List<T>::InstCustom(const int Pos, T A)
{
	if (Pos > ListLen || Pos < 0)
		exception.except_throw(103);
	if (Pos != 0)
	{
		TDatLink<T>* tmp_1 = FirstItem;
		TDatLink<T>* tmp_2 = new TDatLink<T>(A, NULL);
		TDatLink<T> tmp_3(A, NULL);
		for (int i = 0; i < Pos; i++)
			if (i == Pos - 1)
			{
				tmp_3 = *tmp_1;
				tmp_1->Set_m(tmp_2);
				tmp_2->Set_m(tmp_3.GetNextLink());
			}
			else
				tmp_1 = tmp_1->GetNextLink();
		ListLen++;
	}
	else
		InstFirst(A);
}

template <class T>
void List<T>::DelFirst()
{
	if (IsEmpty() == true)
		exception.except_throw(104);
	TDatLink<T>* tmp = FirstItem;
	FirstItem = tmp->GetNextLink();
	delete tmp;
	ListLen--;
}

template <class T>
void List<T>::DelCustom(const int Pos)
{
	if (Pos > ListLen - 1 || Pos < 0)
		exception.except_throw(103);
	if (IsEmpty() == true)
		exception.except_throw(104);
	if (Pos == 0)
		DelFirst();
	else if (Pos == ListLen - 1)
	{
		TDatLink<T>* tmp = FirstItem;
        TDatLink<T>* TMP = new TDatLink<T>(NULL, NULL);
		for (int i = 0; i < Pos - 1; i++)
			tmp = tmp->GetNextLink();
        TMP = tmp->GetNextLink();
        delete TMP;
		tmp->Set_m(NULL);
		ListLen--;
	}
	else
	{
		TDatLink<T>* tmp = FirstItem;
        TDatLink<T>* TMP = new TDatLink<T>(NULL, NULL);
		for (int i = 0; i < Pos - 1; i++)
			tmp = tmp->GetNextLink();
        TMP = tmp->GetNextLink();
		tmp->Set_m(tmp->GetNextLink()->GetNextLink());
        delete TMP;
		ListLen--;
	}
}

template <class T>
void List<T>::DelList()
{
	while (IsEmpty() == false)
		DelFirst();
	FirstItem = LastItem = NULL;
}