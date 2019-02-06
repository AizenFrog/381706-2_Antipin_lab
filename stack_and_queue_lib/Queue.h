#pragma once
#include "Stack.h"

template<class T>
class Queue : public Stack<T>
{
protected:
  int counts;
  int IndexFirst;
public:
  Queue();
  Queue(const int _Len);
  Queue(const Queue<T>& A);
  void Put(const T& A);
  T Get();
  T GetWithoutDelete();
  bool IsFull();
  bool IsEmpty();
};

template<class T>
Queue<T>::Queue() : Stack<T>()
{
  counts = 0;
  IndexFirst = 0;
}

template<class T>
Queue<T>::Queue(const int _Len)
{
  if (_Len < 0)
    this->except.except_throw(106);
  else if (_Len == 0)
  {
    this->Len = 0;
    this->Mem = NULL;
    this->Index = 0;
    counts = 0;
    IndexFirst = 0;
  }
  else
  {
    this->Len = _Len;
    this->Mem = new T[Len];
    for (int i = 0; i < Len; i++)
      Mem[i] = 0;
    this->Index = 0;
    IndexFirst = 0;
    counts = 0;
  }
}

template<class T>
Queue<T>::Queue(const Queue<T>& A)
{
  this->Len = A->Len;
  this->Mem = new T[Len];
  for (int i = 0; i < Len; i++)
    this->Mem[i] = A->Mem[i];
  this->Index = A->Index;
  IndexFirst = A.IndexFirst;
  counts = A.counts;
}

template<class T>
void Queue<T>::Put(const T& A)
{
  if (IsFull() == false)
  {
    this->Mem[Index] = A;
    counts++;
    if (counts != this->Len && Index != this->Len)
      this->Index++;
    else if (counts != this->Len && Index == this->Len)
      this->Index = 0;
    else if (counts == this->Len)
      this->Index = 0;
  }
  else
    this->except.except_throw(107);
}

template<class T>
T Queue<T>::Get()
{
  if (IsEmpty() == false)
  {
    counts--;
    T A = this->Mem[IndexFirst];
    if (counts != 0 && IndexFirst != this->Len - 1)
      IndexFirst++;
    else if (counts != 0 && IndexFirst == this->Len - 1)
      IndexFirst = 0;
    else if (counts == 0)
      IndexFirst = this->Index = 0;
    return A;
  }
  else
    this->except.except_throw(108);
}

template<class T>
T Queue<T>::GetWithoutDelete()
{
  if (IsEmpty() == false)
  {
    T A = this->Mem[IndexFirst];
    return A;
  }
  else
    this->except.except_throw(108);
}

template<class T>
bool Queue<T>::IsFull()
{
  if (counts == this->Len)
    return true;
  else if (counts > this->Len)
    this->except.except_throw(109);
  else
    return false;
}

template<class T>
bool Queue<T>::IsEmpty()
{
  if (counts == 0)
    return true;
  else if (counts > this->Len)
    this->except.except_throw(110);
  if (counts > 0)
    return false;
}