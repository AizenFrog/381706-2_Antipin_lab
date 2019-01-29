#pragma once
class Exceptions_from_polinom_and_calculator
{
public:
  void except_throw(int nomber)
  {
    switch (nomber)
    {
    case 101:
      throw("Attempt to create monom with negative size");
      break;
    case 102:
      throw("Attempt to put negative monom power stack");
      break;
    case 103:
      throw("Monomial sizes do not match");
      break;
    case 104:
      throw("Degrees of monomials do not coincide");
      break;
    case 105:
      throw("Polynomial sizes do not match");
      break;
    case 106:
      throw("There is an invalid character in math expression");
      break;
    default:
      throw("Unknown error");
      break;
    }
  }
};