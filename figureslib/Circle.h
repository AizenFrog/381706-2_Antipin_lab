#pragma once
#include "Point.h"
#include "Exception_from_figures.h"

class TCircle
{
protected:
  TPoint* center;
  double radius;
  Exceptions_from_figures exception;
public:
  TCircle();
  TCircle(const TPoint* point, double rad);
  TCircle(const double _x, const double _y, const double rad);
  TCircle(const TCircle& circle);
  ~TCircle();
  void SetX(const double _x);
  void SetY(const double _y);
  void SetR(const double rad);
  double GetX();
  double GetY();
  double GetR();
  void Show();
};