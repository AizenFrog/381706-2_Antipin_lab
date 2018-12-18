#pragma once
#include <iostream>

template <class T>
class TDatLink
{
protected:
	T Mem;
	TDatLink<T>* m;
public:
	TDatLink(const T _Mem, TDatLink<T>* _m);
	TDatLink(TDatLink<T>& A);
	void SetMem(T _Mem);
	T GetMem();
	void Set_m(TDatLink<T>* _m);
	TDatLink<T>* GetNextLink();
};

template <class T>
TDatLink<T>::TDatLink(const T _Mem, TDatLink<T>* _m = NULL)
{
	Mem = _Mem;
	m = _m;
}

template <class T>
TDatLink<T>::TDatLink(TDatLink<T>& A)
{
	Mem = A.Mem;
	m = A.m;
}

template <class T>
void TDatLink<T>::SetMem(T _Mem)
{
	Mem = _Mem;
}

template <class T>
T TDatLink<T>::GetMem()
{
	return Mem;
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
