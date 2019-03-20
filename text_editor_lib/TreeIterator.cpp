#include "TreeIterator.h"

TTreeIterator::TTreeIterator(TTree* _root)
{
  root = _root;
  current = root;
  stack.Put(root);
}

TTree* TTreeIterator::GoNext()
{
  TTree* tmp;
  if (stack.IsEmpty() == false)
    tmp = stack.Get();
  if (tmp->GetSameLevel() != NULL)
    stack.Put(tmp->GetSameLevel());
  if(tmp->GetNextLevel() != NULL)
    stack.Put(tmp->GetNextLevel());
  current = tmp;
  return current;
}

void TTreeIterator::Reset()
{
  stack.Clear();
  stack.Put(root);
  current = root;
}

bool TTreeIterator::IsEnd()
{
  if (stack.IsEmpty() == true)
    return true;
  else
    return false;
}

void TTreeIterator::PutInStack(TTree* tree)
{
  stack.Put(tree);
}

TTree* TTreeIterator::operator()()
{
  return current;
}

TTreeIterator& TTreeIterator::operator++()//////?????????
{
  TTreeIterator tmp(root);
  return tmp;
}