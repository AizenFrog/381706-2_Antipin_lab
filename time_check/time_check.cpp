#include "Matrix.h"
#include "Stack.h"
#include "Multystack.h"
#include "Queue.h"
#include <time.h>
#include <iostream>
#include <chrono>

#define VECTOR_AND_MATRIX
//#define STACK_QUEUE_MULTYSTACK

void main()
{
#ifdef VECTOR_AND_MATRIX
	Vector<int> A(1000);
	Vector<int> _A(1000);
	for (int i = 0; i < 1000; i++)
	{
		A[i] = i;
		_A[i] = i;
	}
	Vector<int> B(10000);
	Vector<int> _B(10000);
	for (int i = 0; i < 10000; i++)
	{
		B[i] = i;
		_B[i] = i;
	}
	Vector<int> C(100000);
	Vector<int> _C(100000);
	for (int i = 0; i < 100000; i++)
	{
		C[i] = i;
		_C[i] = i;
	}
	Vector<int> D(1000000);
	Vector<int> _D(1000000);
	for (int i = 0; i < 1000000; i++)
	{
		D[i] = i;
		_D[i] = i;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Addition of vectors:" << std::endl;
	auto begin = std::chrono::high_resolution_clock::now();
	A + _A;
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "1000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	B + _B;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "10000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	C + _C;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "100000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	D + _D;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Comparing vectors:" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	A == _A;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	B == _B;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "10000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	C == _C;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "100000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	D == _D;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Matrix<int> Q(100);
	Matrix<int> _Q(100);
	for (int i = 0; i < 100; i++)
		for (int j = i; j < 100; j++)
		{
			Q[i][j] = i;
			_Q[i][j] = i;
		}
	Matrix<int> W(1000);
	Matrix<int> _W(1000);
	for (int i = 0; i < 1000; i++)
		for (int j = i; j < 1000; j++)
		{
			W[i][j] = i;
			_W[i][j] = i;
		}
	Matrix<int> E(1500);
	Matrix<int> _E(1500);
	for (int i = 0; i < 1500; i++)
		for (int j = i; j < 1500; j++)
		{
			E[i][j] = i;
			_E[i][j] = i;
		}
	Matrix<int> R(2000);
	Matrix<int> _R(2000);
	for (int i = 0; i < 2000; i++)
		for (int j = i; j < 2000; j++)
		{
			R[i][j] = i;
			_R[i][j] = i;
		}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Addition of matrixs:" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	Q + _Q;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "100 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	W + _W;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	E + _E;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "5000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	R + _R;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "10000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Multiplication of matrixs:" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	Q * _Q;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "100 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	W * _W;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	E * _E;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1500 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	R * _R;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "2000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
//#elif STACK_QUEUE_MULTYSTACK
/*	Stack<int> A(1000);
	Stack<int> B(10000);
	Stack<int> C(100000);
	Stack<int> D(1000000);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Put in stack:" << std::endl;
	auto begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		A.Put(i);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "1000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		B.Put(i);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "10000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++)
	{
		C.Put(i);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "100000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++)
	{
		D.Put(i);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Get from stack:" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		A.Get();
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		B.Get();
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "10000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++)
	{
		C.Get();
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "100000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++)
	{
		D.Get();
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Queue<int> A(1000);
	Queue<int> B(10000);
	Queue<int> C(100000);
	Queue<int> D(1000000);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Put in queue:" << std::endl;
	auto begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		A.Put(i);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "1000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		B.Put(i);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "10000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++)
	{
		C.Put(i);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "100000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++)
	{
		D.Put(i);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Get from queue:" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		A.Get();
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		B.Get();
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "10000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++)
	{
		C.Get();
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "100000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++)
	{
		D.Get();
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "1000000 elements - " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;*/
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
}