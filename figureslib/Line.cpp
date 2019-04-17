#include "Line.h"

TLine::TLine()
{
  point_1 = new TPoint(0, 0);
  point_2 = new TPoint(0, 0);
  del_flag_1 = false;
  del_flag_2 = false;
}

TLine::TLine(const TPoint* _point_1, const TPoint* _point_2)
{
  point_1 = new TPoint(*_point_1);
  point_2 = new TPoint(*_point_2);
  del_flag_1 = false;
  del_flag_2 = false;
}

TLine::TLine(const double x1, const double y1, const double x2, const double y2)
{
  point_1 = new TPoint(x1, y1);
  point_2 = new TPoint(x2, y2);
  del_flag_1 = false;
  del_flag_2 = false;
}

TLine::TLine(const TLine& line)
{
  point_1 = new TPoint(*line.point_1);
  point_2 = new TPoint(*line.point_2);  
  del_flag_1 = false;
  del_flag_2 = false;
}

TLine::~TLine()
{
  if (del_flag_1 == false)
    delete point_1;
  if (del_flag_2 == false)
    delete point_2;
}

void TLine::SetX(const double _x1)
{
  point_1->SetX(_x1);
}

void TLine::SetY(const double _y1)
{
  point_1->SetY(_y1);
}

void TLine::SetX1(const double _x2)
{
  point_2->SetX(_x2);
}

void TLine::SetY1(const double _y2)
{
  point_2->SetY(_y2);
}

double TLine::GetX()
{
  return point_1->GetX();
}

double TLine::GetY()
{
  return point_1->GetY();
}

double TLine::GetX1()
{
  return point_2->GetX();
}

double TLine::GetY1()
{
  return point_2->GetY();
}

TPoint* TLine::GetPoint1()
{
  return point_1;
}

TPoint* TLine::GetPoint2()
{
  return point_2;
}

void TLine::SetPoint1(TPoint * point1)
{
  delete point_1;
  point_1 = point1;
  del_flag_1 = true;
}

void TLine::SetPoint2(TPoint * point2)
{
  delete point_2;
  point_2 = point2;
  del_flag_2 = true;
}

void TLine::Show()
{
  cout << "Point 1 - ";
  point_1->Show();
  cout << "Point 2 - ";
  point_2->Show();
}