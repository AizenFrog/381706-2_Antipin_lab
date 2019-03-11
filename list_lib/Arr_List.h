#pragma once
#include <iostream>
#include "Exception_class.h"

template <class T>
class ArrList
{
protected:
  T* arMas;
  int* arIndex;
  int arMem, count, c, size;//текущий элемент; количество элементов; текущий свободный; размер
  Exceptions_from_list_arrlist exception;
public:
  ArrList(const int n = 0);
  ArrList(const ArrList<T>& a);
  ~ArrList();
  bool IsFull();
  bool IsEmpty();
  void PutStart(const T& a);
  void PutEnd(const T& a);
  T GetStart();
  T GetEnd();
};

template <class T>
ArrList<T>::ArrList(const int n)
{
  if (n < 0)
    exception.except_throw(105);
  else if (n == 0)
  {
    arMas = NULL;
    arIndex = NULL;
    arMem = count = c = size = 0;
  }
  else
  {
    size = n;
    count = c = 0;
    arMas = new T[size];
    arIndex = new int[size];
    arMem = -1;
    for (int i = 0; i < size; i++)
      arIndex[i] = -2;
  }
}

template <class T>
ArrList<T>::ArrList(const ArrList<T>& a)
{
  if (a.size == 0)
  {
    size = c = arMem = count = 0;
    arMas = NULL;
    arIndex = NULL;
  }
  else
  {
    size = a.size;
    c = a.c;
    arMem = a.arMem;
    count = a.count;
    for (int i = 0; i < size; i++)
    {
      arMas[i] = a.arMas[i];
      arIndex[i] = a.arIndex[i];
    }
  }
}

template <class T>
ArrList<T>::~ArrList()
{
  delete[] arMas;
  delete[] arIndex;
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
void ArrList<T>::PutStart(const T& a)
{
  if (IsFull() == true)
    exception.except_throw(106);
  else
  {
    arMas[c] = a;
    arIndex[c] = arMem;
    arMem = c;
    count++;
    for (int i = 0; i < size; i++)
      if (arIndex[i] == -2)
      {
        c = i;
        break;
      }
  }
}

template <class T>
void ArrList<T>::PutEnd(const T& a)
{
  if (IsFull() == true)
    exception.except_throw(106);
  else if (IsEmpty() == true)
    PutStart(a);
  else
  {
    int i = arMem;
    while (arIndex[i] != -1)
      i = arIndex[i];
    arMas[c] = a;
    arIndex[c] = -1;
    arIndex[i] = c;
    count++;
    for (int k = 0; k < size; k++)
      if (arIndex[k] == -2)
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
  int i = arMem;
  arMem = arIndex[arMem];
  arIndex[i] = -2;
  count--;
  return arMas[i];
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
    int i = arMem;
    int j = arIndex[i];
    while (arIndex[j] != -1)
    {
      i = j;
      j = arIndex[j];
    }
    arIndex[j] = -2;
    count--;
    c = j;
    arIndex[i] = -1;
    return arMas[j];
  }
}