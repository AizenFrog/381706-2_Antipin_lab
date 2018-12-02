#pragma once
#include "Vector.h"

template<class A>
class Matrix : public Vector<Vector<A>>
{
public:
	Matrix(int _size)
	{
		if (_size < 0)
			throw(1);
		else if (_size == 0)
		{
			l = 0;
			m = NULL;
			StartIndex = 0;
		}
		else
		{

			l = _size;
			m = new Vector<A>[l];
			for (int i = 0; i < l; i++)
				m[i] = Vector<A>(l - i, i);
		}
	}

	Matrix(Matrix<A> &B) : Vector<Vector<A>>(B)
	{
	}

	Matrix(Vector<Vector<A>> &B)
	{
		l = B.l;
		StartIndex = B.GetStartIndex;
		m = new Vector<A>[l];
		for (int i = 0; i < l; i++)
			m[i] = B.m[i];
	}

	Matrix<A>& operator=(Matrix<A>& B)
	{
		if (m != B.m)
		{
			if (m)
			{
				delete[] m;
				l = B.l;
				StartIndex = B.StartIndex;
				m = new Vector<A>[l];
				for (int i = 0; i < l; i++)
					m[i] = B.m[i];
			}
		}
		return *this;
	}

	bool operator==(Matrix<A>& B)
	{
		bool rez = true;
		if (l != B.l)
			rez = false;
		else
			for (int i = 0; i < l; i++)
				if (m[i] != B.m[i])
					rez = false;
		return rez;
	}

	Matrix<A>& operator+(Matrix<A>& B)
	{
		if (l == B.l)
		{
			for (int i = 0; i < l; i++)
				m[i] = m[i] + B.m[i];
		}
		else
			throw(1);
		return *this;
	}

	Matrix<A>& operator-(Matrix<A>& B)
	{
		if (l == B.l)
		{
			for (int i = 0; i < l; i++)
				m[i] = m[i] - B.m[i];
		}
		else
			throw(1);
		return *this;
	}

	Matrix<A> operator*(Matrix<A>& B)
	{
		Matrix<A> rez(l);
		for (int i = 0; i < l; i++)//строки
			for (int g = i; g < l; g++)//столбцы
				for (int inner = i; inner < g + 1; inner++)
					rez.m[i][g] += m[i][inner] * B.m[inner][g];
		return rez;
	}

	friend std::istream & operator>>(std::istream &in, Matrix &mt)
	{
		for (int i = 0; i < mt.l; i++)
			in >> mt.m[i];
		return in;
	}

	friend std::ostream & operator<<(std::ostream &out, Matrix &mt)
	{
		for (int i = 0; i < mt.l; i++)
			out << mt.m[i] << endl;
		return out;
	}
};