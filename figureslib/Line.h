#pragma once
#include "Point.h"

class TLine 
{
protected:
  TPoint* point_1;
  TPoint* point_2;
  bool del_flag_1;
  bool del_flag_2;
public:
  TLine();
  TLine(const TPoint* _point_1, const TPoint* _point_2);
  TLine(const double x1, const double y1, const double x2, const double y2);
  TLine(const TLine& line);
  ~TLine();
  void SetX(const double _x1);
  void SetY(const double _y1);
  void SetX1(const double _x2);
  void SetY1(const double _y2);
  double GetX();
  double GetY();
  double GetX1();
  double GetY1();
  TPoint* GetPoint1();
  TPoint* GetPoint2();
  void SetPoint1(TPoint* point1);//////TESTS
  void SetPoint2(TPoint* point2);//////TESTS
  void Show();
};