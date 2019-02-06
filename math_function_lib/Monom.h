#pragma once
#include <iostream>
#include "Exception_class.h"

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
  friend std::ostream& operator<<(std::ostream& os, Monom& monom);
};

