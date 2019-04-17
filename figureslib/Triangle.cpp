#include "Triangle.h"

TTriangle::TTriangle()
{
  a = new TPoint(0, 0);
  b = new TPoint(0, 0);
  c = new TPoint(0, 0);
}

TTriangle::TTriangle(TPoint* _a, TPoint* _b, TPoint* _c)
{
  if (_a->GetX() / _a->GetY() == _b->GetX() / _b->GetY() && _a->GetX() / _a->GetY() == _c->GetX() / _c->GetY())
    exception.except_throw(2);
  a = new TPoint(*_a);
  b = new TPoint(*_b);
  c = new TPoint(*_c);
}

TTriangle::TTriangle(const double _x1, const double _y1, const double _x2, const double _y2, const double _x3, const double _y3)
{
  if (_x1 / _y1 == _x2 / _y2 && _x1 / _y1 == _x3 / _y3)
    exception.except_throw(2);
  a = new TPoint(_x1, _y1);
  b = new TPoint(_x2, _y2);
  c = new TPoint(_x3, _y3);
}

TTriangle::TTriangle(const TTriangle& triangle)
{
  a = new TPoint(*triangle.a);
  b = new TPoint(*triangle.b);
  c = new TPoint(*triangle.c);
}

TTriangle::~TTriangle()
{
  delete a;
  delete b;
  delete c;
}

void TTriangle::SetXA(const double _x1)
{
  if (_x1 / a->GetY() == b->GetX() / b->GetY() && _x1 / a->GetY() == c->GetX() / c->GetY())
    exception.except_throw(2);
  a->SetX(_x1);
}

void TTriangle::SetYA(const double _y1)
{
  if (a->GetX() / _y1 == b->GetX() / b->GetY() && a->GetX() / _y1 == c->GetX() / c->GetY())
    exception.except_throw(2);
  a->SetY(_y1);
}

void TTriangle::SetXB(const double _x2)
{
  if (_x2 / b->GetY() == a->GetX() / a->GetY() && _x2 / b->GetY() == c->GetX() / c->GetY())
    exception.except_throw(2);
  b->SetX(_x2);
}

void TTriangle::SetYB(const double _y2)
{
  if (b->GetX() / _y2 == a->GetX() / a->GetY() && b->GetX() / _y2 == c->GetX() / c->GetY())
    exception.except_throw(2);
  b->SetY(_y2);
}

void TTriangle::SetXC(const double _x3)
{
  if (_x3 / c->GetY() == a->GetX() / a->GetY() && _x3 / c->GetY() == b->GetX() / b->GetY())
    exception.except_throw(2);
  c->SetX(_x3);
}

void TTriangle::SetYC(const double _y3)
{
  if (c->GetX() / _y3 == b->GetX() / b->GetY() && c->GetX() / _y3 == a->GetX() / a->GetY())
    exception.except_throw(2);
  c->SetY(_y3);
}

double TTriangle::GetXA()
{
  return a->GetX();
}

double TTriangle::GetYA()
{
  return a->GetY();
}
double TTriangle::GetXB()
{
  return b->GetX();
}

double TTriangle::GetYB()
{
  return b->GetY();
}

double TTriangle::GetXC()
{
  return c->GetX();
}

double TTriangle::GetYC()
{
  return c->GetY();
}

void TTriangle::Show()
{
  cout << "Point 1 - ";
  a->Show();
  cout << "Point 2 - ";
  b->Show();
  cout << "Point 3 - ";
  c->Show();
}