#pragma once
#include "Exception_class.h"
#include <iostream>

template<class T>
class Stack
{
protected:
  int Len;
  T *Mem;
  int Index;
  Exceptions_from_stack_queue_multystack except;
public:
  Stack();
  Stack(const int _Len);
  Stack(T* _Mem, const int _Len);
  Stack(const Stack<T>& A);
  ~Stack();
  void SetMem(T* _Mem, int _Len);
  int GetIndex();
  int GetLen();
  void SetLen(const int N);
  T* GetMem();
  T GetValue(const int N);
  void Put(const T& A);
  T Get();
  T GetWithoutDelete();
  bool IsFull();
  bool IsEmpty();
};

template<class T>
Stack<T>::Stack()
{
  Len = 0;
  Mem = NULL;
  Index = 0;
}

template<class T>
Stack<T>::Stack(const int _Len)
{
  if (_Len < 0)
    except.except_throw(101);
  else if (_Len == 0)
  {
    Len = 0;
    Mem = NULL;
    Index = 0;
  }
  else
  {
    Len = _Len;
    Mem = new T[Len];
    for (int i = 0; i < Len; i++)
      Mem[i] = 0;
    Index = 0;
  }
}

template<class T>
Stack<T>::Stack(T* _Mem, const int _Len)
{
    Len = _Len;
    Mem = _Mem;
    Index = 0;
}

template<class T>
Stack<T>::Stack(const Stack<T>& A)
{
  Len = A.Len;
  Mem = new T[Len];
  for (int i = 0; i < Len; i++)
    Mem[i] = A.Mem[i];
  Index = A.Index;
}

template<class T>
Stack<T>::~Stack()
{
  if (Mem != NULL)
      delete Mem;
  Mem = NULL;
}

template <class T>
void Stack<T>::SetMem(T* _Mem, int _Len)
{
  Mem = _Mem;
  Len = _Len;
}

template<class T>
int Stack<T>::GetIndex()
{
  return Index;
}

template<class T>
int Stack<T>::GetLen()
{
  return Len;
}

template<class T>
void Stack<T>::SetLen(const int N)
{
  Len = N;
}

template<class T>
T* Stack<T>::GetMem()
{
  return Mem;
}

template<class T>
T Stack<T>::GetValue(const int N)
{
  return Mem[N];
}

template<class T>
void Stack<T>::Put(const T& A)
{
  if (IsFull() == false)
  {
    Mem[Index] = A;
    Index++;
  }
  else
    except.except_throw(102);
}

template<class T>
T Stack<T>::Get()
{
  if (IsEmpty() == false)
  {
    Index--;
    return Mem[Index];
  }
  else
    except.except_throw(103);
}

template<class T>
T Stack<T>::GetWithoutDelete()
{
  if (IsEmpty() == false)
    return Mem[Index - 1];
  else
    except.except_throw(103);
}

template<class T>
bool Stack<T>::IsFull()
{
  if (Index == Len)
    return true;
  else if (Index > Len || Index < 0)
    except.except_throw(104);
  else
    return false;
}

template<class T>
bool Stack<T>::IsEmpty()
{
  if (Index == 0)
    return true;
  else if (Index > Len || Index < 0)
    except.except_throw(105);
  if (Index > 0)
    return false;
}