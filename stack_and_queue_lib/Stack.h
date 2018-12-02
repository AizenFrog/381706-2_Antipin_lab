#pragma once

template<class T>
class Stack
{
protected:
	int Len;
	T *Mem;
	int Index;
public:
	Stack();
	Stack(const int _Len);
	Stack(const Stack<T>& A);
	~Stack();
	void Put(const T& A);
	T Get();
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
		throw(1);
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
	delete[] Mem;
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
		throw("Stack is full");
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
		throw("Stack is empty");
}

template<class T>
bool Stack<T>::IsFull()
{
	if (Index == Len)
		return true;
	else if (Index > Len)
		throw("Error!!!");
	else
		return false;
}

template<class T>
bool Stack<T>::IsEmpty()
{
	if (Index == 0)
		return true;
	else if (Index > Len)
		throw("Error");
	if (Index > 0)
		return false;
}