#include "Point.h"

TPoint::TPoint()
{
  x = 0;
  y = 0;
}

TPoint::TPoint(const double _x, const double _y)
{
  x = _x;
  y = _y;
}

TPoint::TPoint(const TPoint& point)
{
  x = point.x;
  y = point.y;
}

TPoint::~TPoint()
{
  x = y = 0;
}

bool TPoint::operator==(const TPoint & point)
{
  if (x == point.x && y == point.y)
    return true;
  else
    return false;
}

bool TPoint::operator!=(const TPoint & point)
{
  if (x == point.x && y == point.y)
    return false;
  else
    return true;
}

void TPoint::SetX(const double _x)
{
  x = _x;
}

void TPoint::SetY(const double _y)
{
  y = _y;
}

double TPoint::GetX()
{
  return x;
}

double TPoint::GetY()
{
  return y;
}

void TPoint::Show()
{
  cout << "x = " << x << " y = " << y << endl;
}