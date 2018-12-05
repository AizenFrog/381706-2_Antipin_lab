//#pragma once
//#include "Stack.h"
//
//template <class T>
//class Multystack
//{
//protected:
//	int Counts;//количество стеков
//	int L;//длина общего стека
//	int *Len;//длина каждго стека
//	T** Index;//индекс начала каждого стека 
//	T* GeneralStack;//главный стек
//	Stack<T>* stacks;
//	int CalcFree();
//	void Resize();
//public:
//	Multystack(int _Counts, int _L);
//	Multystack(const Multystack& A);
//	~Multystack();
//	void Put(const int i, const T& A);
//	T Get(const int i);
//	bool IsEmpty(const int i);
//	bool IsFull(const int i);
//	void SetMem(T* mem, int _l);
//};

//template <class T>
//Multystack<T>::Multystack(int _Counts, int _L)
//{
//	Counts = _Counts;
//	L = _L;
//	GeneralStack = new T[L];
//	Len = new int[Counts];
//	int tmp = L / Counts;
//	for (int i = 0; i < Counts; i++)
//		Len[i] = tmp;
//	Len[0] += L % Counts;
//	Index = new T*[Counts];
//	int t = 0;
//	Index[0] = GeneralStack;
//	for (int i = 1; i < Counts; i++)
//	{
//		Index[i] = GeneralStack[Len[i - 1] + t];
//		t += Len[i - 1];
//	}
//	stacks = new Stack<T>*[Counts];
//	for (int i = 0; i < Counts; i++)
//	{
//		stacks[i] = new Stack<T>(Len[i]);
//		stacks[i]->SetMem(Index[i], Len[i]);
//	}
//}
//
//template <class T>
//Multystack<T>::Multystack(const Multystack& A)
//{
//	Counts = A.Counts;
//	L = A.L;
//	GeneralStack = new T[L];
//	for (int i = 0; i < L; i++)
//		GeneralStack[i] = A.GeneralStack[i];
//	Len = new int[Counts];
//	for (int i = 0; i < Counts; i++)
//		Len[i] = A.Len[i];
//	int t = 0;
//	Index[0] = GeneralStack;
//	for (int i = 1; i < Counts; i++)
//	{
//		Index[i] = GeneralStack[Len[i - 1] + t];
//		t += Len[i - 1];
//	}
//	stacks = new Stack<T>*[Counts];
//	for (int i = 0; i < Counts; i++)
//	{
//		stacks[i] = new Stack<T>(A.stacks[i]);
//		stacks[i]->SetMem(Index[i], Len[i]);
//	}
//}
//
//template <class T>
//void SetMem(T* mem, int _l)
//{
//	GeneralStack = mem;
//	L = _l;
//}