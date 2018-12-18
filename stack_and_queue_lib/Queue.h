#pragma once
#include "Stack.h"

template<class T>
class Queue : public Stack<T>
{
public:
	Queue();
	Queue(const int _Len);
	Queue(const Queue<T>& A);
	void Put(const T& A);
	T Get();
	bool IsFull();
	bool IsEmpty();
};

template<class T>
Queue<T>::Queue() : Stack<T>()
{
}

template<class T>
Queue<T>::Queue(const int _Len)
{
	if (_Len < 0)
		except.except_throw(106);
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
Queue<T>::Queue(const Queue<T>& A)
{
	Len = A.Len;
	Mem = new T[Len];
	for (int i = 0; i < Len; i++)
		Mem[i] = A.Mem[i];
	Index = A.Index;
}

template<class T> 
void Queue<T>::Put(const T& A)
{
	if (IsFull() == false)
	{
		Mem[Index] = A;
		Index++;
	}
	else
		except.except_throw(107);
}

template<class T>
T Queue<T>::Get()
{
	if (IsEmpty() == false)
	{
		Index--;
		T A = Mem[0];
		for (int i = 0; i < Index; i++)
			Mem[i] = Mem[i + 1];
		Mem[Index] = 0;
		return A;
	}
	else
		except.except_throw(108);
}

template<class T>
bool Queue<T>::IsFull()
{
	if (Index == Len)
		return true;
	else if (Index > Len)
		except.except_throw(109);
	else
		return false;
}

template<class T>
bool Queue<T>::IsEmpty()
{
	if (Index == 0)
		return true;
	else if (Index > Len)
		except.except_throw(110);
	if (Index > 0)
		return false;
}