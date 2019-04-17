#pragma once
#include "Point.h"
#include "Exception_from_figures.h"

class TTriangle
{
protected:
  TPoint* a;
  TPoint* b;
  TPoint* c;
  Exceptions_from_figures exception;
public:
  TTriangle();
  TTriangle(TPoint* _a, TPoint* _b, TPoint* _c);
  TTriangle(const double _x1, const double _y1, const double _x2, const double _y2, const double _x3, const double _y3);
  TTriangle(const TTriangle& triangle);
  ~TTriangle();
  void SetXA(const double _x1);
  void SetYA(const double _y1);
  void SetXB(const double _x2);
  void SetYB(const double _y2);
  void SetXC(const double _x3);
  void SetYC(const double _y3);
  double GetXA();
  double GetYA();
  double GetXB();
  double GetYB(); 
  double GetXC();
  double GetYC();
  void Show();
};