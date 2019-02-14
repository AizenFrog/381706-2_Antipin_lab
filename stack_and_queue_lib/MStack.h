#pragma once
#include "Stack.h"

template <class T>
class MStack : public Stack<T> 
{
public:
  MStack();
  MStack(T* _Mem, const int _Len);
  ~MStack() override;
  void SetMem(T* _Mem, int _Len);
  void SetLen(const int N);
  T* GetMem();
  T GetValue(const int N);
  void SetIndex(const int _i);
};

template<class T>
MStack<T>::MStack()
{
}

template <class T>
MStack<T>::MStack(T* _Mem, const int _Len)
{
  this->sLen = _Len;
  this->sMem = _Mem;
  this->sIndex = 0;
}

template<class T>
MStack<T>::~MStack()
{
  this->sMem = NULL;
}

template <class T>
void MStack<T>::SetMem(T* _Mem, int _Len)
{
  this->sMem = _Mem;
  this->sLen = _Len;
}

template<class T>
void MStack<T>::SetLen(const int N)
{
  this->sLen = N;
}

template<class T>
T* MStack<T>::GetMem()
{
  return this->sMem;
}

template<class T>
T MStack<T>::GetValue(const int N)
{
  return this->sMem[N];
}

template<class T>
void MStack<T>::SetIndex(const int _i)
{
  this->sIndex = _i;
}