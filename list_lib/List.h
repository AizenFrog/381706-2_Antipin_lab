#pragma once
#include "List_Item.h"
#include "Exception_class.h"
#include <iostream>

template <class T>
class List
{
protected:
  Exceptions_from_list_arrlist* exception;
  TDatLink<T>* tFirstItem;
  TDatLink<T>* tLastItem;
  int pListLen;
  TDatLink<T>* GetLink(T _mem, TDatLink<T>* _m);
  void DelLink(TDatLink<T>* link);
public:
  List();
  ~List();
  T GetValue(const int pos) const;
  bool IsEmpty() const;
  int GetListLen() const;
  void InstFirst(T a);
  void InstCustom(const int pos, T a);
  void InstLast(T a);
  void DelFirst();
  void DelCustom(const int pos);
  void DelList();
};

template <class T>
List<T>::List()
{
  tFirstItem = NULL;
  tLastItem = NULL;
  pListLen = 0;
}

template <class T>
List<T>::~List()
{
  DelList();
}

template <class T>
TDatLink<T>* List<T>::GetLink(T _mem, TDatLink<T>* _m)
{
  TDatLink<T>* tmp = new TDatLink<T>(_mem, _m);
  if (tmp->GetMem() == NULL && tmp->GetNextLink() == NULL)
    exception->except_throw(101);
  else
    return tmp;
}

template <class T>
void List<T>::DelLink(TDatLink<T>* link)
{
  if (link->GetMem() != NULL && link->GetNextLink() != NULL)
  {
    delete link->Mem;
    delete link->m;
  }
  else
    exception->except_throw(102);
}

template <class T>
T List<T>::GetValue(const int pos) const
{
  if (pos >= pListLen || pos < 0)
    exception->except_throw(103);
  TDatLink<T>* tmp = tFirstItem;
  for (int i = 0; i < pos; i++)
    tmp = tmp->GetNextLink();
  return tmp->GetMem();
}

template <class T>
bool List<T>::IsEmpty() const
{
  if (pListLen == 0)
    return true;
  else
    return false;
}

template <class T>
int List<T>::GetListLen() const
{
  return pListLen;
}

template <class T>
void List<T>::InstFirst(T a)
{
  TDatLink<T>* tmp = new TDatLink<T>(a, tFirstItem);
  tFirstItem = tmp;
  pListLen++;
  if (pListLen == 1)
    tLastItem = tmp;
}

template <class T>
void List<T>::InstLast(T a)
{
  TDatLink<T>* tMP = new TDatLink<T>(a, NULL);
  pListLen++;
  if (pListLen == 1)
  {
    tFirstItem = tMP;
    tLastItem = tMP;
  }
  else
  {
    tLastItem->Set_m(tMP);
    tLastItem = tMP;
  }
}

template <class T>
void List<T>::InstCustom(const int pos, T a)
{
  if (pos > pListLen || pos < 0)
    exception->except_throw(103);
  if (pos != 0 && pos != pListLen)
  {
    TDatLink<T>* tmp_1 = tFirstItem;
    TDatLink<T>* tmp_2 = new TDatLink<T>(a, NULL);
    TDatLink<T> tmp_3(a, NULL);
    for (int i = 0; i < pos; i++)
      if (i == pos - 1)
      {
        tmp_3 = *tmp_1;
        tmp_1->Set_m(tmp_2);
        tmp_2->Set_m(tmp_3.GetNextLink());
      }
      else
        tmp_1 = tmp_1->GetNextLink();
    pListLen++;
  }
  else if (pos == 0)
    InstFirst(a);
  else if (pos == pListLen)
    InstLast(a);
}

template <class T>
void List<T>::DelFirst()
{
  if (IsEmpty() == true)
    exception->except_throw(104);
  TDatLink<T>* tmp = tFirstItem;
  tFirstItem = tmp->GetNextLink();
  delete tmp;
  pListLen--;
}

template <class T>
void List<T>::DelCustom(const int pos)
{
  if (pos > pListLen - 1 || pos < 0)
    exception->except_throw(103);
  if (IsEmpty() == true)
    exception->except_throw(104);
  if (pos == 0)
    DelFirst();
  else if (pos == pListLen - 1)
  {
    TDatLink<T>* tmp = tFirstItem;
    TDatLink<T>* TMP;
    for (int i = 0; i < pos - 1; i++)
      tmp = tmp->GetNextLink();
    TMP = tmp->GetNextLink();
    delete TMP;
    tmp->Set_m(NULL);
    pListLen--;
    if (pListLen == 1)
      tLastItem = tFirstItem;
  }
  else
  {
    TDatLink<T>* tmp = tFirstItem;
    TDatLink<T>* tMP;
    for (int i = 0; i < pos - 1; i++)
      tmp = tmp->GetNextLink();
    tMP = tmp->GetNextLink();
    tmp->Set_m(tmp->GetNextLink()->GetNextLink());
    delete tMP;
    pListLen--;
  }
}

template <class T>
void List<T>::DelList()
{
  while (IsEmpty() == false)
    DelFirst();
  tFirstItem = tLastItem = NULL;
}