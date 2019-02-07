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
  Polinom& operator=(const Polinom& polinom);
  Polinom operator+(const Polinom& polinom);
  Polinom operator-(const Polinom& polinom);
  Polinom operator*(const Polinom& polinom);
  Polinom& operator+=(Monom& monom);
  Monom operator[](const int nomber);
  friend std::ostream& operator<<(std::ostream& os, const Polinom& polinom)
  {
    TDatLink<Monom>* tmp = polinom.FirstItem;
    for (int i = 0; i < polinom.ListLen - 1; i++)
    {
      os << polinom.GetValue(i) << '+';
      tmp = tmp->GetNextLink();
    }
    os << polinom.GetValue(polinom.ListLen - 1) << std::endl;
    return os;
  }
};

