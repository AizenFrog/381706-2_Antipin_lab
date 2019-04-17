#pragma once
#include <iostream>

using namespace std;

class TPoint
{
protected:
  double x;//координата по Х
  double y;//координата по У
public:
  TPoint();
  TPoint(const double _x, const double _y);
  TPoint(const TPoint& point);
  ~TPoint();
  bool operator==(const TPoint& point);
  bool operator!=(const TPoint& point);
  void SetX(const double _x);
  void SetY(const double _y);
  double GetX();
  double GetY();
  virtual void Show();
};