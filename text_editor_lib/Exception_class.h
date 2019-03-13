#pragma once

class Exceptions_from_tree_text
{
public:
  void except_throw(int nomber)
  {
    switch (nomber)
    {
    case 101:
      throw("Attempt to create tree with wrong level");
      break;
    case 102:
      throw("Attempt to assign tree with different level");
      break;
    case 103:
      throw("Attempt to put letter to tree with hight level");
      break;
    case 104:
      throw("Attempt to get letter from tree with hight level");
      break;
    case 105:
      throw("Attempt to initialize tree with negative size");
      break;
    case 106:
      throw("Attempt to create text with too long start string");
      break;
    default:
      throw("Unknown error");
      break;
    }
  }
};