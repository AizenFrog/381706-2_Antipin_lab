#pragma once
#include "Tree.h"

class TText : public TTree
{
protected:
  TTree* root;
public:
  TText(const char* string);
  TText(TText& text);
  void Insert(const int pos, const char* string);
  void Insert(TTree* start, TTree* string);
  int Find(const char* string);
  TTree* FindTree(const char* string);
  char* Copy(const int start, const int len);
  TTree* Copy(TTree* start, const int len);
  void Delete(const int start_del, const int lenght);
  void Delete(TTree* start_del, const int lenght);
};