#pragma once
#include "Tree.h"

class TTreeIterator
{
protected:
  TTree* root;
  TTree* current;
  TStackList<TTree*> stack;
public:
  TTreeIterator(TTree* _root);
  TTree* GoNext();
  void Reset();
  bool IsEnd();
  void PutInStack(TTree* tree);
  TTree* operator()();
  TTreeIterator& operator++();
};