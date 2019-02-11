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
  this->Len = _Len;
  this->Mem = _Mem;
  this->Index = 0;
}

template<class T>
MStack<T>::~MStack()
{
  this->Mem = NULL;
}

template <class T>
void MStack<T>::SetMem(T* _Mem, int _Len)
{
  this->Mem = _Mem;
  this->Len = _Len;
}

template<class T>
void MStack<T>::SetLen(const int N)
{
  this->Len = N;
}

template<class T>
T* MStack<T>::GetMem()
{
  return this->Mem;
}

template<class T>
T MStack<T>::GetValue(const int N)
{
  return this->Mem[N];
}

template<class T>
void MStack<T>::SetIndex(const int _i)
{
  this->Index = _i;
}