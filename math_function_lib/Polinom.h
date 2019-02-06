#pragma once
#include "Monom.h"
#include "List.h"

class Polinom : public List<Monom>
{
protected:
  Exceptions_from_polinom_and_calculator exception;
public:
  Polinom();
  Polinom(const Polinom& polinom);
  Polinom(const List<Monom>& MonomList);
  Polinom& operator=(Polinom& polinom);
  Polinom operator+(Polinom& polinom);
  Polinom operator-(Polinom& polinom);
  Polinom operator*(Polinom& polinom);
  Polinom& operator+=(Monom& monom);
  Monom operator[](const int nomber);
  friend std::ostream& operator<<(std::ostream& os, Polinom& polinom);
};

