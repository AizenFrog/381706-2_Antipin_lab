#pragma once
#include "Vector.h"

template<class A>
class Matrix : public Vector<Vector<A>>
{
public:
	Matrix(int _size);
	Matrix(Matrix<A> &B);
	Matrix(Vector<Vector<A>> &B);
	Matrix<A>& operator=(Matrix<A>& B);
	bool operator==(Matrix<A>& B);
	Matrix<A> operator+(Matrix<A>& B);
	Matrix<A> operator-(Matrix<A>& B);
	Matrix<A> operator*(Matrix<A>& B);
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

template<class A>
Matrix<A>::Matrix(int _size)
{
	if (_size < 0)
		except.except_throw(106);
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

template<class A>
Matrix<A>::Matrix(Matrix<A> &B) : Vector<Vector<A>>(B)
{
}

template<class A>
Matrix<A>::Matrix(Vector<Vector<A>> &B)
{
	l = B.l;
	StartIndex = B.GetStartIndex;
	m = new Vector<A>[l];
	for (int i = 0; i < l; i++)
		m[i] = B.m[i];
}

template<class A>
Matrix<A>& Matrix<A>::operator=(Matrix<A>& B)
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

template<class A>
bool Matrix<A>::operator==(Matrix<A>& B)
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

template<class A>
Matrix<A> Matrix<A>::operator+(Matrix<A>& B)
{
	Matrix<A> rez(l);
	if (l == B.l)
	{
		for (int i = 0; i < l; i++)
			rez.m[i] = m[i] + B.m[i];
	}
	else
		except.except_throw(107);
	return rez;
}

template<class A>
Matrix<A> Matrix<A>::operator-(Matrix<A>& B)
{
	Matrix<A> rez(l);
	if (l == B.l)
	{
		for (int i = 0; i < l; i++)
			rez.m[i] = m[i] - B.m[i];
	}
	else
		except.except_throw(108);
	return rez;
}

template<class A>
Matrix<A> Matrix<A>::operator*(Matrix<A>& B)
{
	if (l != B.l)
		except.except_throw(109);
	Matrix<A> rez(l);
	for (int i = 0; i < l; i++)//строки
		for (int g = i; g < l; g++)//столбцы
			for (int inner = i; inner < g + 1; inner++)
				rez.m[i][g] += m[i][inner] * B.m[inner][g];
	return rez;
}