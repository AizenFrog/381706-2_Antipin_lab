#include "Monom.h"
#include <iostream>

Monom::Monom()
{

}

Monom::Monom(const int _n, unsigned int* _power, double _c)
{
  if (_n <= 0)
    exception.except_throw(101);
  n = _n;
  c = _c;
  power = new unsigned int[n];
  if (power != NULL)
    for (int i = 0; i < n; i++)
      power[i] = _power[i];
  else
    for (int i = 0; i < n; i++)
      power[i] = 0;
}

Monom::Monom(const Monom& monom)
{
  n = monom.n;
  c = monom.c;
  power = new unsigned int[n];
  for (int i = 0; i < n; i++)
    power[i] = monom.power[i];
}

Monom::~Monom()
{
  if (power != NULL)
    delete[] power;
}

int Monom::GetN()
{
  return n;
}

double Monom::GetC()
{
  return c;
}

unsigned int* Monom::GetPower()
{
  return power;
}

void Monom::SetN(int _n)
{
  if (_n <= 0)
    exception.except_throw(101);
  unsigned int* tmp = new unsigned int[n];
  for (int i = 0; i < n; i++)
    tmp[i] = power[i];
  delete[] power;
  power = new unsigned int[_n];
  bool flag = true;
  int more = _n;
  int less = n;
  if (n > _n)
  {
    flag = false;
    more = _n;
    less = n;
  }
  for (int i = 0; i < less; i++)
    power[i] = tmp[i];
  if (flag = true)
    for (int i = less; i < more; i++)
      power[i] = 1;
  delete[] tmp;
  n = _n;
}

void Monom::SetC(double _c)
{
  c = _c;
}

void Monom::SetPower(unsigned int* _power)
{
  try
  {
    for (int i = 0; i < n; i++)
      if (_power[i] >= 0)
        power[i] = _power[i];
      else
        exception.except_throw(102);
  }
  catch (int ex)
  {
    exception.except_throw(100);
  }
}

Monom& Monom::operator=(const Monom& monom)
{
  if (this != &monom)
  {
    n = monom.n;
    c = monom.c;
    if (power)
    {
      power = NULL;
      delete[] power;
    }
    power = new unsigned int[n];
    for (int i = 0; i < n; i++)
      power[i] = monom.power[i];
  }
  return *this;
}

Monom Monom::operator+(const Monom& monom)
{
  if (n != monom.n)
    exception.except_throw(103);
  Monom tmp(monom);
  bool flag = true;
  for (int i = 0; i < n; i++)
    if (this->power[i] != monom.power[i])
      flag = false;
  if (flag == true)
    tmp.c = c + monom.c;
  else
    exception.except_throw(104);
  return tmp;
}

Monom Monom::operator-(const Monom& monom)
{
  if (n != monom.n)
    exception.except_throw(103);
  Monom tmp(monom);
  bool flag = true;
  for (int i = 0; i < n; i++)
    if (this->power[i] != monom.power[i])
      flag = false;
  if (flag == true)
    tmp.c = c - monom.c;
  else
    exception.except_throw(104);
  return tmp;
}

Monom Monom::operator*(const Monom& monom)
{
  if (n != monom.n)
    exception.except_throw(103);
  Monom tmp(monom);
  tmp.c = c * monom.c;
  for (int i = 0; i < n; i++)
    tmp.power[i] = power[i] + monom.power[i];
  return tmp;
}

bool Monom::operator==(const Monom& monom)
{
  bool res = true;
  if (n != monom.n)
    exception.except_throw(103);
  for (int i = 0; i < n; i++)
    if (power[i] != monom.power[i])
      res = false;
  if (c != monom.c)
    res = false;
  return res;
}

bool Monom::operator>(const Monom& monom)
{
  bool res = true;
  if (n != monom.n)
    exception.except_throw(103);
  for (int i = 0; i < n; i++)
    if (power[i] > monom.power[i])
      return true;
    else if (power[i] < monom.power[i])
      return false;
    else
      res = false;
  if (res == false)
    if (c < monom.c)
      res = false;
    else
      res = true;
  return res;
}

bool Monom::operator<(const Monom& monom)
{
  bool res = true;
  if (n != monom.n)
    exception.except_throw(103);
  for (int i = 0; i < n; i++)
    if (power[i] < monom.power[i])
      return true;
    else if (power[i] > monom.power[i])
      return false;
    else
      res = false;
  if (res == false)
    if (c > monom.c)
      res = false;
    else
      res = true;
  return res;
}

std::ostream& operator<<(std::ostream& os, Monom& monom)
{
  os << monom.c << '*';
  for (int i = 0; i < monom.n - 1; i++)
    os << "x" << i << "^" << monom.power[i] << '*';
  os << "x" << monom.n - 1 << "^" << monom.power[monom.n - 1];
  return os;
}