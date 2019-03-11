#pragma once
#include "Exception_class.h"
#include <iostream>

template<class T>
class Stack
{
protected:
  int sLen;
  T *sMem;
  int sIndex;
  Exceptions_from_stack_queue_multystack except;
public:
  Stack();
  Stack(const int _len);
  Stack(const Stack<T>& a);
  virtual ~Stack();
  int GetIndex();
  int GetLen();
  void Put(const T& A);
  T Get();
  T GetWithoutDelete();
  bool IsFull();
  bool IsEmpty();
};

template<class T>
Stack<T>::Stack()
{
  sLen = 0;
  sMem = NULL;
  sIndex = 0;
}

template<class T>
Stack<T>::Stack(const int _len)
{
  if (_len < 0)
    except.except_throw(101);
  else if (_len == 0)
  {
    sLen = 0;
    sMem = NULL;
    sIndex = 0;
  }
  else
  {
    sLen = _len;
    sMem = new T[sLen];
    for (int i = 0; i < sLen; i++)
      sMem[i] = 0;
    sIndex = 0;
  }
}

template<class T>
Stack<T>::Stack(const Stack<T>& a)
{
  sLen = a.sLen;
  sMem = new T[sLen];
  for (int i = 0; i < sLen; i++)
    sMem[i] = a.sMem[i];
  sIndex = a.sIndex;
}

template<class T>
Stack<T>::~Stack()
{
  if (sMem != NULL)
      delete[] sMem;
  sMem = NULL;
}

template<class T>
int Stack<T>::GetIndex()
{
  return sIndex;
}

template<class T>
int Stack<T>::GetLen()
{
  return sLen;
}

template<class T>
void Stack<T>::Put(const T& a)
{
  if (IsFull() == false)
  {
    sMem[sIndex] = a;
    sIndex++;
  }
  else
    except.except_throw(102);
}

template<class T>
T Stack<T>::Get()
{
  if (IsEmpty() == false)
  {
    sIndex--;
    return sMem[sIndex];
  }
  else
    except.except_throw(103);
}

template<class T>
T Stack<T>::GetWithoutDelete()
{
  if (IsEmpty() == false)
    return sMem[sIndex - 1];
  else
    except.except_throw(103);
}

template<class T>
bool Stack<T>::IsFull()
{
  if (sIndex == sLen)
    return true;
  else if (sIndex > sLen || sIndex < 0)
    except.except_throw(104);
  else
    return false;
}

template<class T>
bool Stack<T>::IsEmpty()
{
  if (sIndex == 0)
    return true;
  else if (sIndex > sLen || sIndex < 0)
    except.except_throw(105);
  if (sIndex > 0)
    return false;
}