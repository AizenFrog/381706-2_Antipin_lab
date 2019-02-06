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
  T GetWithoutDelete() const;
  bool IsFull() const;
  bool IsEmpty() const;
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
    except->except_throw(106);
  else if (_Len == 0)
  {
    Len = 0;
    Mem = NULL;
    Index = 0;
    counts = 0;
    IndexFirst = 0;
  }
  else
  {
    Len = _Len;
    Mem = new T[Len];
    for (int i = 0; i < Len; i++)
      Mem[i] = 0;
    Index = 0;
    IndexFirst = 0;
    counts = 0;
  }
}

template<class T>
Queue<T>::Queue(const Queue<T>& A)
{
  Len = A->Len;
  Mem = new T[Len];
  for (int i = 0; i < Len; i++)
    Mem[i] = A->Mem[i];
  Index = A->Index;
  IndexFirst = A.IndexFirst;
  counts = A.counts;
}

template<class T>
void Queue<T>::Put(const T& A)
{
  if (IsFull() == false)
  {
    Mem[Index] = A;
    counts++;
    if (counts != Len && Index != Len)
      Index++;
    else if (counts != Len && Index == Len)
      Index = 0;
    else if (counts == Len)
      Index = 0;
  }
  else
    except->except_throw(107);
}

template<class T>
T Queue<T>::Get()
{
  if (IsEmpty() == false)
  {
    counts--;
    T A = Mem[IndexFirst];
    if (counts != 0 && IndexFirst != Len - 1)
      IndexFirst++;
    else if (counts != 0 && IndexFirst == Len - 1)
      IndexFirst = 0;
    else if (counts == 0)
      IndexFirst = Index = 0;
    return A;
  }
  else
    except->except_throw(108);
}

template<class T>
T Queue<T>::GetWithoutDelete() const
{
  if (IsEmpty() == false)
  {
    T A = Mem[IndexFirst];
    return A;
  }
  else
    except->except_throw(108);
}

template<class T>
bool Queue<T>::IsFull() const
{
  if (counts == Len)
    return true;
  else if (counts > Len)
    except->except_throw(109);
  else
    return false;
}

template<class T>
bool Queue<T>::IsEmpty() const
{
  if (counts == 0)
    return true;
  else if (counts > Len)
    except->except_throw(110);
  if (counts > 0)
    return false;
}