#pragma once
#include "Stack.h"

template<class T>
class Queue : public Stack<T>
{
protected:
  int counts;
  int qIndexFirst;
public:
  Queue();
  Queue(const int _len);
  Queue(const Queue<T>& a);
  void Put(const T& a);
  T Get();
  T GetWithoutDelete();
  bool IsFull();
  bool IsEmpty();
};

template<class T>
Queue<T>::Queue() : Stack<T>()
{
  counts = 0;
  qIndexFirst = 0;
}

template<class T>
Queue<T>::Queue(const int _len)
{
  if (_len < 0)
    this->except.except_throw(106);
  else if (_len == 0)
  {
    this->sLen = 0;
    this->sMem = NULL;
    this->sIndex = 0;
    counts = 0;
    qIndexFirst = 0;
  }
  else
  {
    this->sLen = _len;
    this->sMem = new T[this->sLen];
    for (int i = 0; i < this->sLen; i++)
      this->sMem[i] = 0;
    this->sIndex = 0;
    qIndexFirst = 0;
    counts = 0;
  }
}

template<class T>
Queue<T>::Queue(const Queue<T>& a)
{
  this->sLen = a->sLen;
  this->sMem = new T[this->sLen];
  for (int i = 0; i < this->sLen; i++)
    this->sMem[i] = a->sMem[i];
  this->sIndex = a->sIndex;
  qIndexFirst = a.qIndexFirst;
  counts = a.counts;
}

template<class T>
void Queue<T>::Put(const T& a)
{
  if (IsFull() == false)
  {
    this->sMem[this->sIndex] = a;
    counts++;
    if (counts != this->sLen && this->sIndex != this->sLen)
      this->sIndex++;
    else if (counts != this->sLen && this->sIndex == this->sLen)
      this->sIndex = 0;
    else if (counts == this->sLen)
      this->sIndex = 0;
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
    T A = this->sMem[qIndexFirst];
    if (counts != 0 && qIndexFirst != this->sLen - 1)
      qIndexFirst++;
    else if (counts != 0 && qIndexFirst == this->sLen - 1)
      qIndexFirst = 0;
    else if (counts == 0)
      qIndexFirst = this->sIndex = 0;
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
    T A = this->sMem[qIndexFirst];
    return A;
  }
  else
    this->except.except_throw(108);
}

template<class T>
bool Queue<T>::IsFull()
{
  if (counts == this->sLen)
    return true;
  else if (counts > this->sLen)
    this->except.except_throw(109);
  else
    return false;
}

template<class T>
bool Queue<T>::IsEmpty()
{
  if (counts == 0)
    return true;
  else if (counts > this->sLen)
    this->except.except_throw(110);
  if (counts > 0)
    return false;
}