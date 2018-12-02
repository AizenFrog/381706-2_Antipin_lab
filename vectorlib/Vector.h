#pragma once
#include <iostream>

template <class T>
class Vector
{
protected:
	int l;
	T* m;
	int StartIndex;
public:
	Vector()
	{
		l = 0; 
		m = NULL;
		StartIndex = 0;
	}

	Vector(const int _l, const int _si)
	{
		if (_l <= 0)
			throw(1);
		StartIndex = _si;
		l = _l;
		m = new T[l];
		for (int i = 0; i < l; i++)
			m[i] = 0;
	}

	Vector(const int _l)
	{
		if (_l <= 0)
			throw(1);
		l = _l;
		StartIndex = 0;
		m = new T[l];
		for (int i = 0; i < l; i++)
			m[i] = 0;
	}

	Vector(Vector<T> &A)
	{
		StartIndex = A.StartIndex;
		l = A.l;
		m = new T[l];
		for (int i = 0; i < l; i++)
			m[i] = A.m[i];
	}

	~Vector()
	{
		delete[] m;
	}

	int GetSize()
	{
		return l;
	}

	int GetStartIndex()
	{
		return StartIndex;
	}

	T& GetValue(const int n)
	{
		if (n < 0 || n > l - 1)
			throw(1);
		return m[n];
	}

	T& operator[](const int n)
	{
		return m[n - StartIndex];
	}

	Vector<T>& operator=(const Vector<T>& A)
	{
		if (m != A.m)
		{
			StartIndex = A.StartIndex;
			l = A.l;
			if (l)
				delete[] m;
			m = new T[l];
			for (int i = 0; i < l; i++)
				m[i] = A.m[i];
		}
		return *this;
	}

	bool operator==(const Vector<T>& A)
	{
		bool rez = true;
		if (l != A.l)
			rez = false;
		else
			for (int i = 0; i < l; i++)
				if (m[i] != A.m[i])
					rez = false;
		return rez;
	}

	bool operator!=(const Vector<T>& A)
	{
		bool rez = false;
		if (l != A.l)
			rez = true;
		else
			for (int i = 0; i < l; i++)
				if (m[i] != A.m[i])
					rez = true;
		return rez;
	}

	Vector<T> operator+(const Vector<T>& A)
	{
		int min = l;
		if (A.l < l)
			min = A.l;
		for (int i = 0; i < min; i++)
			m[i] = m[i] + A.m[i];
		return *this;
	}

	Vector<T> operator-(const Vector<T>& A)
	{
		int min = l;
		if (A.l < l)
			min = A.l;
		for (int i = 0; i < min; i++)
			m[i] = m[i] - A.m[i];
		return *this;
	}

	T operator*(const Vector<T>& A)
	{
		T rez = 0;
		if (A.l != l)
			throw(1);
		else
			for (int i = 0; i < l; i++)
				rez = rez + m[i] * A.m[i];
		return rez;
	}

	Vector<T> operator+(const T& A)
	{
		for (int i = 0; i < l; i++)
			m[i] = m[i] + A;
		return *this;
	}

	virtual Vector<T> operator-(const T& A)
	{
		for (int i = 0; i < l; i++)
			m[i] = m[i] - A;
		return *this;
	}

	Vector<T> operator*(const T& A)
	{
		for (int i = 0; i < l; i++)
			m[i] = m[i] * A;
		return *this;
	}

	friend std::istream &operator>>(std::istream &in, Vector &A)
	{
		for (int i = 0; i < A.l; i++)
			in >> A.m[i];
		return in;
	}

	friend std::ostream &operator<<(std::ostream &out, Vector &A)
	{
		for (int i = 0; i < A.l; i++)
			out << A.m[i] << ' ';
		return out;
	}
};