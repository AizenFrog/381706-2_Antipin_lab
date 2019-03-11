#pragma once
#include "Vector.h"

template<class A>
class Matrix : public Vector<Vector<A> >
{
public:
  Matrix(int _size);
  Matrix(const Matrix<A> &b);
  Matrix(const Vector<Vector<A> > &b);
  Matrix<A>& operator=(const Matrix<A>& b);
  bool operator==(const Matrix<A>& b);
  Matrix<A> operator+(const Matrix<A>& b);
  Matrix<A> operator-(const Matrix<A>& b);
  Matrix<A> operator*(const Matrix<A>& b);
  Matrix<A> operator/(const Matrix<A>& b);
  friend std::istream & operator>>(std::istream &in, Matrix &mt)
  {
    for (int i = 0; i < mt.l; i++)
      in >> mt.m[i];
    return in;
  }

  friend std::ostream & operator<<(std::ostream &out, const Matrix &mt)
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
    this->except.except_throw(106);
  else if (_size == 0)
  {
    this->l = 0;
    this->m = NULL;
    this->tStartIndex = 0;
  }
  else
  {

    this->l = _size;
    this->m = new Vector<A>[this->l];
    for (int i = 0; i < this->l; i++)
      this->m[i] = Vector<A>(this->l - i, i);
  }
}

template<class A>
Matrix<A>::Matrix(const Matrix<A> &B) : Vector<Vector<A> >(B)
{
}

template<class A>
Matrix<A>::Matrix(const Vector<Vector<A> > &B)
{
  this->l = B->l;
  this->tStartIndex = B->GetStartIndex;
  this->m = new Vector<A>[this->l];
  for (int i = 0; i < this->l; i++)
    this->m[i] = B->m[i];
}

template<class A>
Matrix<A>& Matrix<A>::operator=(const Matrix<A>& B)
{
  if (this->m != B.m)
  {
    if (this->m)
    {
      delete[] this->m;
      this->l = B.l;
      this->tStartIndex = B.tStartIndex;
      this->m = new Vector<A>[this->l];
      for (int i = 0; i < this->l; i++)
        this->m[i] = B.m[i];
    }
  }
  return *this;
}

template<class A>
bool Matrix<A>::operator==(const Matrix<A>& B)
{
  bool rez = true;
  if (this->l != B.l)
    rez = false;
  else
    for (int i = 0; i < this->l; i++)
      if (this->m[i] != B.m[i])
        rez = false;
  return rez;
}

template<class A>
Matrix<A> Matrix<A>::operator+(const Matrix<A>& B)
{
  Matrix<A> rez(this->l);
  if (this->l == B.l)
  {
    for (int i = 0; i < this->l; i++)
      rez.m[i] = this->m[i] + B.m[i];
  }
  else
    this->except.except_throw(107);
  return rez;
}

template<class A>
Matrix<A> Matrix<A>::operator-(const Matrix<A>& B)
{
  Matrix<A> rez(this->l);
  if (this->l == B.l)
  {
    for (int i = 0; i < this->l; i++)
      rez.m[i] = this->m[i] - B.m[i];
  }
  else
    this->except.except_throw(108);
  return rez;
}

template<class A>
Matrix<A> Matrix<A>::operator*(const Matrix<A>& B)
{
  if (this->l != B.l)
    this->except.except_throw(109);
  Matrix<A> rez(this->l);
  for (int i = 0; i < this->l; i++)//строки
    for (int g = i; g < this->l; g++)//столбцы
      for (int inner = i; inner < g + 1; inner++)
        rez.m[i][g] += this->m[i][inner] * B.m[inner][g];
  return rez;
}

template<class A>
Matrix<A> Matrix<A>::operator/(const Matrix<A>& B)
{
  if (this->l != B.l)
    this->except.except_throw(110);
  A det = B.m[0][0];
  for (int i = 1; i < this->l; i++)
    det = det * B.m[i][i];
  if (det == 0)
    this->except.except_throw(111);
  Matrix <A> c1(B);
  Matrix <A> res(this->l);
  for (int i = 0; i < this->l; i++)
  {
    res[i][i] = 1;
    A k = c1[i][i];
    for (int j = i; j < this->l; j++)
    {
      c1[i][j] = c1[i][j] / k;
      res[i][j] = res[i][j] / k;
    }
  }
  for (int j = 1; j < this->l; j++)
    for (int i = j - 1; i >= 0; i--)
    {
      A tmp = c1[i][j];
      for (int k = j; k < this->l; k++)
      {
        res[i][k] = 0 - res[j][k] * tmp;
        c1[i][k] = c1[i][k] - c1[j][k] * tmp;
      }
    }
  return ((*this) * res);
}
