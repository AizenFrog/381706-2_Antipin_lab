#pragma once
#include "Vector.h"

template<class A>
class Matrix : public Vector<Vector<A>>
{
public:
  Matrix(int _size);
  Matrix(Matrix<A> &b);
  Matrix(Vector<Vector<A>> &b);
  Matrix<A>& operator=(Matrix<A>& b);
  bool operator==(Matrix<A>& b);
  Matrix<A> operator+(Matrix<A>& b);
  Matrix<A> operator-(Matrix<A>& b);
  Matrix<A> operator*(Matrix<A>& b);
  Matrix<A> operator/(Matrix<A>& b);
  friend std::istream & operator>>(std::istream &in, Matrix &mt)
  {
    for (int i = 0; i < mt.l; i++)
      in >> mt.m[i];
    return in;
  }

  friend std::ostream & operator<<(std::ostream &out, Matrix &mt)
  {
    for (int i = 0; i < mt.l; i++)
    {
      if (mt.GetSize() > mt.m[i].GetSize())
      {
        int tmp = mt.GetSize() - mt.m[i].GetSize();
        for (int j = 0; j < tmp; j++)
          cout << 0 << " ";
      }
      out << mt.m[i] << endl;
    }
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
    tStartIndex = 0;
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
  tStartIndex = B.GetStartIndex;
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
      tStartIndex = B.tStartIndex;
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

template<class A>
Matrix<A> Matrix<A>::operator/(Matrix<A>& B)
{
  if (l != B.l)
    except.except_throw(110);
  A det = B.m[0][0];
  for (int i = 1; i < l; i++)
    det = det * B.m[i][i];
  if (det == 0)
    except.except_throw(111);
  Matrix <A> c1(B);
  Matrix <A> res(l);
  for (int i = 0; i < l; i++)
  {
    res[i][i] = 1;
    A k = c1[i][i];
    for (int j = i; j < l; j++)
    {
      c1[i][j] = c1[i][j] / k;
      res[i][j] = res[i][j] / k;
    }
  }
  for (int j = 1; j < l; j++)
    for (int i = j - 1; i >= 0; i--)
    {
      A tmp = c1[i][j];
      for (int k = j; k < l; k++)
      {
        res[i][k] = 0 - res[j][k] * tmp;
        c1[i][k] = c1[i][k] - c1[j][k] * tmp;
      }
    }
  return ((*this) * res);
}
