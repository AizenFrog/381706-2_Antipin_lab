#pragma once
#include "List_Item.h"
#include <iostream>
#include "Exception_class.h"

template <class T>
class TStackList
{
protected:
  TDatLink<T>* pLastItem;
  int pListLen;
  Exceptions_from_stack_queue_multystack exception;
public:
  TStackList();
  ~TStackList();
  int GetLen();
  bool IsEmpty();
  void Put(const T A);
  T Get();
  void Clear();
};

template <class T>
TStackList<T>::TStackList()
{
  pLastItem = NULL;
  pListLen = 0;
}

template <class T>
TStackList<T>::~TStackList()
{
  while (IsEmpty() == false)
  {
    TDatLink<T>* tmp = pLastItem;
    pLastItem = pLastItem->GetNextLink();
    delete tmp;
    pListLen--;
  }
}

template<class T>
int TStackList<T>::GetLen()
{
  return pListLen;
}

template <class T>
bool TStackList<T>::IsEmpty()
{
  if (pListLen == 0)
    return true;
  else
    return false;
}

template <class T>
void TStackList<T>::Put(const T a)
{
  TDatLink<T>* tmp_1 = new TDatLink<T>(a, NULL);
  if (pListLen == 0)
    pLastItem = tmp_1;
  else
  {
    tmp_1->Set_m(pLastItem);
    pLastItem = tmp_1;
  }
  pListLen++;
}

template <class T>
T TStackList<T>::Get()
{
  if (pListLen == 0)
    exception.except_throw(103);
  T A;
  if (pListLen == 1)
  {
    A = pLastItem->GetMem();
    delete pLastItem;
    //pLastItem = NULL;
  }
  else
  {
    A = pLastItem->GetMem();
    TDatLink<T>* tmp = pLastItem;
    pLastItem = pLastItem->GetNextLink();
    delete tmp;
  }
  pListLen--;
  return A;
}

template <class T>
void TStackList<T>::Clear()
{
  while (IsEmpty() == false)
  {
    TDatLink<T>* tmp = pLastItem;
    pLastItem = pLastItem->GetNextLink();
    delete tmp;
    pListLen--;
  }
}