#pragma once
#include "MStack.h"
#include "Exception_class.h"

template <class T>
class Multistack// : public MStack<T>
{
protected:
  int mCounts;//количество стеков
  int mL;//длина общего стека
  int *mLen;//длина каждго стека
  T** mIndex;//индекс начала каждого стека 
  T* mGeneralStack;//главный стек
  MStack<T>** stacks;
  int mResizeCount;
  Exceptions_from_stack_queue_multystack exception;
protected:
  int CalcFree();
  bool Resize(const int _i);
public:
  Multistack(int _counts, int _l);
  Multistack(const Multistack& a);
  ~Multistack();
  void Put(const int i, const T& a);
  T Get(const int i);
  bool IsEmpty(const int i);
  bool IsFull(const int i);
  int GetResizeCount();
};

template <class T>
Multistack<T>::Multistack(int _counts, int _l)
{
  if (_counts < 0 || _l < 0)
    exception.except_throw(111);
  if (_counts > _l)
    exception.except_throw(112);
  mCounts = _counts;
  mL = _l;
  mResizeCount = 0;
  mGeneralStack = new T[mL];
  mLen = new int[mCounts];
  int tmp = mL / mCounts;
  for (int i = 0; i < mCounts; i++)
    mLen[i] = tmp;
  mLen[0] += mL % mCounts;
  mIndex = new T*[mCounts];
  int t = 0;
  mIndex[0] = mGeneralStack;
  for (int i = 1; i < mCounts; i++)
  {
    mIndex[i] = &mGeneralStack[mLen[i - 1] + t];
    t += mLen[i - 1];
  }
  stacks = new MStack<T>*[mCounts];
  for (int i = 0; i < mCounts; i++)
    stacks[i] = new MStack<T>(mIndex[i], mLen[i]);
}

template <class T>
Multistack<T>::Multistack(const Multistack& a)
{
  mCounts = a.mCounts;
  mL = a.mL;
  mResizeCount = a.mResizeCount;
  mGeneralStack = new T[mL];
  for (int i = 0; i < mL; i++)
    mGeneralStack[i] = a.mGeneralStack[i];
  mLen = new int[mCounts];
  for (int i = 0; i < mCounts; i++)
    mLen[i] = a.mLen[i];
  int t = 0;
  mIndex = new T*[mCounts];
  mIndex[0] = mGeneralStack;
  for (int i = 1; i < mCounts; i++)
  {
    mIndex[i] = &mGeneralStack[mLen[i - 1] + t];
    t += mLen[i - 1];
  }
  stacks = new MStack<T>*[mCounts];
  for (int i = 0; i < mCounts; i++)
  {
    stacks[i] = new MStack<T>(mIndex[i], mLen[i]);
    stacks[i]->SetIndex(a.stacks[i]->GetIndex());
  }
}

template<class T>
Multistack<T>::~Multistack()
{
  delete[] mGeneralStack;
  for (int i = 0; i < mCounts; i++)
    delete stacks[i];
  delete[] mLen;
  delete[] mIndex;
}

template <class T>
int Multistack<T>::CalcFree()
{
  int rez = 0;
  for (int i = 0; i < mCounts; i++)
    rez += stacks[i]->GetLen() - stacks[i]->GetIndex();
  return rez;
}

template<class T>
bool Multistack<T>::Resize(const int _i)
{
  bool rez = true;
  int in, j, k, n;
  int FreeMemSize = CalcFree();
  if (FreeMemSize > 0)
  {
    mResizeCount++;
    mIndex[0] = &mGeneralStack[0];
    for (int i = 1; i < mCounts; i++)
    {
      if (_i + 1 == i)
        mIndex[i] = mIndex[i - 1] + stacks[i - 1]->GetIndex() + FreeMemSize / mCounts + FreeMemSize % mCounts;
      else
        mIndex[i] = mIndex[i - 1] + stacks[i - 1]->GetIndex() + FreeMemSize / mCounts;
    }
    for (in = 0; in < mCounts; in++)
      if (mIndex[in] < stacks[in]->GetMem())
      {
        for (j = 0; j < stacks[in]->GetIndex(); j++)///
          mIndex[in][j] = stacks[in]->GetValue(j);
        stacks[in]->SetMem(mIndex[in], mIndex[in + 1] - mIndex[in]);
      }
      else if (mIndex[in] > stacks[in]->GetMem())
      {
        k = in;
        if (k < mCounts - 1)
          for (; mIndex[k + 1] > stacks[k + 1]->GetMem(); k++)
            if (k == mCounts - 2)
              break;
        for (n = k; n >= in; n--)
        {
          for (j = stacks[n]->GetIndex() - 1; j >= 0; j--)////////
            mIndex[n][j] = stacks[n]->GetValue(j);
          stacks[n]->SetMem(mIndex[n], mIndex[n + 1] - mIndex[n]);
        }
      }
      else
        stacks[in]->SetMem(mIndex[in], mIndex[in + 1] - mIndex[in]);
    for (int i = 0; i < mCounts - 1; i++)
    {
      stacks[i]->SetLen(mIndex[i + 1] - mIndex[i]);
      mLen[i] = stacks[i]->GetLen();
    }
    stacks[mCounts - 1]->SetLen((&mGeneralStack[0] + mL) - mIndex[mCounts - 1]);
    mLen[mCounts - 1] = stacks[mCounts - 1]->GetLen();
  }
  else
    rez = false;
  return rez;
}

template<class T>
void Multistack<T>::Put(const int i, const T& A)
{
  if (stacks[i]->IsFull() == true)
    if (Resize(i) == true)
      stacks[i]->Put(A);
    else
      exception.except_throw(113);
  else
    stacks[i]->Put(A);
}

template<class T>
T Multistack<T>::Get(const int i)
{
  if (stacks[i]->IsEmpty() == true)
    exception.except_throw(114);
  else
    return stacks[i]->Get();
}

template<class T>
bool Multistack<T>::IsFull(const int i)
{
  return stacks[i]->IsFull();
}

template<class T>
int Multistack<T>::GetResizeCount()
{
  return mResizeCount;
}

template<class T>
bool Multistack<T>::IsEmpty(const int i)
{
  return stacks[i]->IsEmpty();
}