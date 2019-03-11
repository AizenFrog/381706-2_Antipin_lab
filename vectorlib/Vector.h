#pragma once
#include <iostream>
#include "Exception_class.h"

using namespace std;

template <class T>
class Vector
{
protected:
  int l;
  T* m;
  int tStartIndex;
  Exceptions_from_vector_and_matrix except;
public:
  Vector();
  Vector(const int _l, const int _si);
  Vector(const int _l);
  Vector(const Vector<T> &a);
  ~Vector();
  int GetSize() const;
  int GetStartIndex() const;
  T& GetValue(const int n);
  T& operator[](const int n);
  Vector<T>& operator=(const Vector<T>& a);
  bool operator==(const Vector<T>& a);
  bool operator!=(const Vector<T>& a);
  Vector<T> operator+(const Vector<T>& a);
  Vector<T> operator-(const Vector<T>& a);
  T operator*(const Vector<T>& a);
  Vector<T> operator+(const T& a);
  Vector<T> operator-(const T& a);
  Vector<T> operator*(const T& a);

  friend std::istream &operator>>(std::istream &in, Vector &a)
  {
    for (int i = 0; i < a.l; i++)
      in >> a.m[i];
    return in;
  }

  friend std::ostream &operator<<(std::ostream &out, const Vector &a)
  {
    for (int i = 0; i < a.l; i++)
      out << a.m[i] << ' ';
    return out;
  }
};

template <class T>
Vector<T>::Vector()
{
  l = 0;
  m = NULL;
  tStartIndex = 0;
}

template <class T>
Vector<T>::Vector(const int _l, const int _si)
{
  if (_l <= 0)
    except.except_throw(101);
  tStartIndex = _si;
  l = _l;
  m = new T[l];
  for (int i = 0; i < l; i++)
    m[i] = 0;
}

template <class T>
Vector<T>::Vector(const int _l)
{
  if (_l <= 0)
    except.except_throw(101);
  l = _l;
  tStartIndex = 0;
  m = new T[l];
  for (int i = 0; i < l; i++)
    m[i] = 0;
}

template <class T>
Vector<T>::Vector(const Vector<T> &A)
{
  tStartIndex = A.tStartIndex;
  l = A.l;
  m = new T[l];
  for (int i = 0; i < l; i++)
    m[i] = A.m[i];
}

template <class T>
Vector<T>::~Vector()
{
  delete[] m;
}

template <class T>
int Vector<T>::GetSize() const
{
  return l;
}

template <class T>
int Vector<T>::GetStartIndex() const
{
  return tStartIndex;
}

template <class T>
T& Vector<T>::GetValue(const int n) 
{
  if (n < 0 || n > l - 1)
    except.except_throw(102);
  return m[n];
}

template <class T>
T& Vector<T>::operator[](const int n)
{
  if (n >= tStartIndex)
    return m[n - tStartIndex];
  except.except_throw(102);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& A)
{
  if (m != A.m)
  {
    tStartIndex = A.tStartIndex;
    l = A.l;
    if (m)
      delete[] m;
    m = new T[l];
    for (int i = 0; i < l; i++)
      m[i] = A.m[i];
  }
  return *this;
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& A)
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

template <class T>
bool Vector<T>::operator!=(const Vector<T>& A)
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

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& A)
{
  if (l != A.l)
    except.except_throw(103);
  int min = l;
  if (A.l < l)
    min = A.l;
  Vector<T> rez(min, tStartIndex);
  for (int i = 0; i < min; i++)
    rez.m[i] = m[i] + A.m[i];
  return rez;
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector<T>& A)
{
  if (l != A.l)
    except.except_throw(104);
  int min = l;
  if (A.l < l)
    min = A.l;
  Vector<T> rez(min, tStartIndex);
  for (int i = 0; i < min; i++)
    rez.m[i] = m[i] - A.m[i];
  return rez;
}

template <class T>
T Vector<T>::operator*(const Vector<T>& A)
{
  T rez = 0;
  if (l != A.l)
    except.except_throw(105);
  else
    for (int i = 0; i < l; i++)
      rez += m[i] * A.m[i];
  return rez;
}

template <class T>
Vector<T> Vector<T>::operator+(const T& A)
{
  Vector<T> rez(l, tStartIndex);
  for (int i = 0; i < l; i++)
    rez.m[i] = m[i] + A;
  return rez;
}

template <class T>
Vector<T> Vector<T>::operator-(const T& A)
{
  Vector<T> rez(l, tStartIndex);
  for (int i = 0; i < l; i++)
    rez.m[i] = m[i] - A;
  return rez;
}

template <class T>
Vector<T> Vector<T>::operator*(const T& A)
{
  Vector<T> rez(l, tStartIndex);
  for (int i = 0; i < l; i++)
    rez.m[i] = m[i] * A;
  return rez;
}