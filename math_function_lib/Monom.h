#pragma once
#include <iostream>
#include "Exception_class.h"

using namespace std;

class Monom
{
protected:
  int n;//размер
  double c;//коэффициент
  unsigned int* power;//степени
  Exceptions_from_polinom_and_calculator exception;
public:
  Monom();
  Monom(const int _n, unsigned int* _power, double _c);
  Monom(const Monom& monom);
  ~Monom();
  int GetN();//вернуть размер
  double GetC();//вернуть коэффициент
  unsigned int* GetPower();//вернуть указатель на степени
  void SetN(int _n);//изменить размер
  void SetC(double _c);//изменить коэффициент
  void SetPower(unsigned int* _power);//изменить степени
  Monom& operator=(const Monom& monom);
  Monom operator+(const Monom& monom);
  Monom operator-(const Monom& monom);
  Monom operator*(const Monom& monom);
  bool operator==(const Monom& monom);
  bool operator>(const Monom& monom);
  bool operator<(const Monom& monom);
  friend std::ostream& operator<<(std::ostream& os, Monom& monom)
  {
    os << monom.c << '*';
    for (int i = 0; i < monom.n - 1; i++)
      os << "x" << i << "^" << monom.power[i] << '*';
    os << "x" << monom.n - 1 << "^" << monom.power[monom.n - 1];
    return os;
  }
  friend class Polinim;
};