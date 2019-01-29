#pragma once
#include "Stack.h"
#include "Exception_class.h"

template <class T>
class Multystack : public Stack<T>
{
protected:
	int Counts;//количество стеков
	int L;//длина общего стека
	int *Len;//длина каждго стека
	T** Index;//индекс начала каждого стека 
	T* GeneralStack;//главный стек
	Stack<T>** stacks;
	int ResizeCount;
	Exceptions_from_stack_queue_multystack exception;
protected:
	int CalcFree();
	bool Resize(int _i);
public:
	Multystack(int _Counts, int _L);
	Multystack(const Multystack& A);
	~Multystack();
	void Put(const int i, const T& A);
	T Get(const int i);
	bool IsEmpty(const int i);
	bool IsFull(const int i);
	int GetResizeCount();
};

template <class T>
Multystack<T>::Multystack(int _Counts, int _L)
{
	if (_Counts < 0 || _L < 0)
		exception.except_throw(111);
	if (_Counts > _L)
		exception.except_throw(112);
	Counts = _Counts;
	L = _L;
	ResizeCount = 0;
	GeneralStack = new T[L];
	Len = new int[Counts];
	int tmp = L / Counts;
	for (int i = 0; i < Counts; i++)
		Len[i] = tmp;
	Len[0] += L % Counts;
	Index = new T*[Counts];
	int t = 0;
	Index[0] = GeneralStack;
	for (int i = 1; i < Counts; i++)
	{
		Index[i] = &GeneralStack[Len[i - 1] + t];
		t += Len[i - 1];
	}
	stacks = new Stack<T>*[Counts];
	for (int i = 0; i < Counts; i++)
	{
		stacks[i] = new Stack<T>(Len[i]);
		stacks[i]->SetMem(Index[i], Len[i]);
	}
}

template <class T>
Multystack<T>::Multystack(const Multystack& A)
{
	Counts = A.Counts;
	L = A.L;
	ResizeCount = A.ResizeCount;
	GeneralStack = new T[L];
	for (int i = 0; i < L; i++)
		GeneralStack[i] = A.GeneralStack[i];
	Len = new int[Counts];
	for (int i = 0; i < Counts; i++)
		Len[i] = A.Len[i];
	int t = 0;
	Index[0] = GeneralStack;
	for (int i = 1; i < Counts; i++)
	{
		Index[i] = &GeneralStack[Len[i - 1] + t];
		t += Len[i - 1];
	}
	stacks = new Stack<T>*[Counts];
	for (int i = 0; i < Counts; i++)
	{
		stacks[i] = new Stack<T>(A.stacks[i]);
		stacks[i]->SetMem(Index[i], Len[i]);
	}
}

template<class T>
Multystack<T>::~Multystack()
{
	delete[] Len;
    //delete[] GeneralStack;
 /*   for (int i = 0; i < Counts; i++)
    {*/
    delete[] Index;
    delete[] stacks;
 //   }
}

template <class T>
int Multystack<T>::CalcFree()
{
	int rez = 0;
	for (int i = 0; i < Counts; i++)
		rez +=stacks[i]->GetLen() - stacks[i]->GetIndex();
	return rez;
}

template<class T>
bool Multystack<T>::Resize(int _i)
{
	bool rez = true;
	int in, j, k, n;
    stacks[_i]->SetLen(stacks[_i]->GetLen() + 1);//Len += 1;///
	int FreeMemSize = CalcFree();
	if (FreeMemSize > -1)
	{
		ResizeCount++;
		Index[0] = &GeneralStack[0];
		for (int i = 1; i < Counts - 1; i++)///////////
			Index[i] = Index[i - 1] + stacks[i - 1]->GetIndex() + FreeMemSize / Counts;
		Index[Counts - 1] = Index[Counts - 2] + stacks[Counts - 2]->GetIndex() + FreeMemSize / Counts + FreeMemSize % Counts;////////////
        stacks[_i]->SetLen(stacks[_i]->GetLen() - 1);//Len -= 1;
		for (in = 0; in < Counts; in++)
			if (Index[in] < stacks[in]->GetMem())
			{
				for (j = 0; j < stacks[in]->GetLen(); j++)///
					Index[in][j] = stacks[in]->GetValue(j);
				stacks[in]->SetMem(Index[in], Index[in + 1] - Index[in]);
			}
			else if (Index[in] > stacks[in]->GetMem())
			{
				k = in;
				if (k < Counts - 1)
					for (; Index[k + 1] > stacks[k + 1]->GetMem(); k++)
						if(k == Counts - 2)
							break;
				for (n = k; n >= in; n--)
				{
					for (j = stacks[n]->GetLen() - 1; j >= 0; j--)
						Index[n][j] = stacks[n]->GetValue(j);
					stacks[n]->SetMem(Index[n], Index[n + 1] - Index[n]);
				}
			}
			else
				stacks[in]->SetMem(Index[in], Index[in + 1] - Index[in]);
		for (int i = 0; i < Counts - 1; i++)
		{
			stacks[i]->SetLen(Index[i + 1] - Index[i]);
			Len[i] = stacks[i]->GetLen();
		}
		stacks[Counts - 1]->SetLen((&GeneralStack[0] + L) - Index[Counts - 2]);
		Len[Counts - 1] = stacks[Counts - 1]->GetLen();
	}
	
	else
		rez = false;
	
	return rez;
}

template<class T>
void Multystack<T>::Put(const int i, const T& A)
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
T Multystack<T>::Get(const int i)
{
	if (stacks[i]->IsEmpty() == true)
      exception.except_throw(114);
	else
		return stacks[i]->Get();
}

template<class T>
bool Multystack<T>::IsFull(const int i)
{
	return stacks[i]->IsFull();
}

template<class T>
int Multystack<T>::GetResizeCount()
{
	return ResizeCount;
}

template<class T>
bool Multystack<T>::IsEmpty(const int i)
{
	return stacks[i]->IsEmpty();
}