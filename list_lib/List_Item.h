#pragma once
#include <iostream>

template <class T>
class TDatLink
{
protected:
  T tMem;
  TDatLink<T>* m;
public:
  TDatLink();
  TDatLink(const T _mem, TDatLink<T>* _m);
  TDatLink(const TDatLink<T>& a);
  void SetMem(T _mem);
  T GetMem();
  void Set_m(TDatLink<T>* _m);
  TDatLink<T>* GetNextLink();
};

template <class T>
TDatLink<T>::TDatLink()
{

}

template <class T>
TDatLink<T>::TDatLink(const T _mem, TDatLink<T>* _m)
{
  tMem = _mem;
  m = _m;
}

template <class T>
TDatLink<T>::TDatLink(const TDatLink<T>& a)
{
  tMem = a.tMem;
  m = a.m;
}

template <class T>
void TDatLink<T>::SetMem(T _mem)
{
  tMem = _mem;
}

template <class T>
T TDatLink<T>::GetMem()
{
  return tMem;
}

template <class T>
void TDatLink<T>::Set_m(TDatLink<T>* _m)
{
  m = _m;
}

template<class T>
TDatLink<T>* TDatLink<T>::GetNextLink()
{
  return m;
}
