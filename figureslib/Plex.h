#pragma once
#include "Point.h"
#include "Line.h"
#include "Stack_on_List.h"

class TPlex : public TPoint
{
protected:
  TPoint* right;
  TPoint* left;
public:
  TPlex();
  TPlex(const TPlex& plex);
  TPlex(TPoint* point1, TPoint* point2);
  ~TPlex();
  void Delete();
  TPlex& operator+=(TLine& line);
  virtual void Show();
};