#pragma once
class Exceptions_from_figures
{
public:
  void except_throw(int nomber)
  {
    switch (nomber)
    {
    case 101:
      throw("Attempt to create cercle with negative size");
      break;
    case 102:
      throw("Attempt create triangle using saame points");
      break;
    default:
      throw("Unknown error");
      break;
    }
  }
};