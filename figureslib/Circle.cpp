#include "Circle.h"

TCircle::TCircle()
{
  center = new TPoint(0, 0);
  radius = 0;
}

TCircle::TCircle(const TPoint* point, double rad)
{
  center = new TPoint(*point);
  if (rad < 0)
    exception.except_throw(1);
  radius = rad;
}

TCircle::TCircle(const double _x, const double _y, const double rad)
{
  center = new TPoint(_x, _y);
  if (rad < 0)
    exception.except_throw(1);
  radius = rad;
}

TCircle::TCircle(const TCircle& circle)
{
  center = new TPoint(*circle.center);
  radius = circle.radius;
}

TCircle::~TCircle()
{
  delete center;
  radius = 0;
}

void TCircle::SetX(const double _x)
{
  center->SetX(_x);
}

void TCircle::SetY(const double _y)
{
  center->SetY(_y);
}

void TCircle::SetR(const double rad)
{
  if (rad < 0)
    exception.except_throw(1);
  radius = rad;
}

double TCircle::GetX()
{
  return center->GetX();
}

double TCircle::GetY()
{
  return center->GetY();
}

double TCircle::GetR()
{
  return radius;
}

void TCircle::Show()
{
  cout << "Center - ";
  center->Show();
  cout << "Radius - " << radius << endl;
}