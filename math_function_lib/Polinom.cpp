#include "Polinom.h"

Polinom::Polinom() : List<Monom>()
{
}

Polinom::Polinom(const Polinom& polinom)
{
  ListLen = polinom.ListLen;
  TDatLink<Monom>* tmp = polinom.FirstItem;
  FirstItem = new TDatLink<Monom>(tmp->GetMem(), NULL);
  TDatLink<Monom>* TMP = FirstItem;
  TDatLink<Monom>* tmpCurr;
  for (int i = 1; i < polinom.ListLen; i++)
  {
    tmp = tmp->GetNextLink();
    tmpCurr = new TDatLink<Monom>(tmp->GetMem(), NULL);
    TMP->Set_m(tmpCurr);
    TMP = tmpCurr;
  }
  LastItem = tmpCurr;
}

Polinom::Polinom(const List<Monom>& ls)
{
  ListLen = ls.GetListLen();
  FirstItem = new TDatLink<Monom>(ls.GetValue(0), NULL);
  TDatLink<Monom>* tmp = FirstItem;
  TDatLink<Monom>* tmpCurr;
  for (int i = 1; i < ListLen; i++)
  {
    tmpCurr = new TDatLink<Monom>(ls.GetValue(i), NULL);
    tmp->Set_m(tmpCurr);
    tmp = tmp->GetNextLink();
  }
  LastItem = tmpCurr;
}

Polinom& Polinom::operator=(Polinom& polinom)
{
  if (this != &polinom)
  {
    DelList();
    ListLen = polinom.ListLen;
    TDatLink<Monom>* tmp = polinom.FirstItem;
    FirstItem = new TDatLink<Monom>(tmp->GetMem(), NULL);
    TDatLink<Monom>* TMP = FirstItem;
    TDatLink<Monom>* tmpCurr;
    for (int i = 1; i < polinom.ListLen; i++)
    {
      tmp = tmp->GetNextLink();
      tmpCurr = new TDatLink<Monom>(tmp->GetMem(), NULL);
      TMP->Set_m(tmpCurr);
      TMP = tmpCurr;
    }
    LastItem = tmpCurr;
  }
  return *this;
}

Polinom Polinom::operator+(Polinom& polinom)
{
  if (ListLen != polinom.ListLen)
    exception.except_throw(105);
  TDatLink<Monom>* tmp_1 = FirstItem;
  TDatLink<Monom>* tmp_2 = polinom.FirstItem;
  Polinom res;
  while (tmp_1 && tmp_2)
    if (tmp_1->GetMem() == tmp_2->GetMem())
    {
      res.InstLast(tmp_1->GetMem() + tmp_2->GetMem());
      tmp_1 = tmp_1->GetNextLink();
      tmp_2 = tmp_2->GetNextLink();
    }
    else if (tmp_1->GetMem() > tmp_2->GetMem())
    {
      res.InstLast(tmp_1->GetMem());
      tmp_1 = tmp_1->GetNextLink();
    }
    else
    {
      res.InstLast(tmp_2->GetMem());
      tmp_2 = tmp_2->GetNextLink();
    }
  if (!tmp_1)
    tmp_1 = tmp_2;
  while (tmp_1)
  {
    res.InstLast(tmp_1->GetMem());
    tmp_1 = tmp_1->GetNextLink();
  }
  return res;
}

Polinom Polinom::operator-(Polinom& polinom)
{
  if (ListLen != polinom.ListLen)
    exception.except_throw(105);
  TDatLink<Monom>* tmp_1 = FirstItem;
  TDatLink<Monom>* tmp_2 = polinom.FirstItem;
  Polinom res;
  while (tmp_1 && tmp_2)
    if (tmp_1->GetMem() == tmp_2->GetMem())
    {
      res.InstLast(tmp_1->GetMem() - tmp_2->GetMem());
      tmp_1 = tmp_1->GetNextLink();
      tmp_2 = tmp_2->GetNextLink();
    }
    else if (tmp_1->GetMem() > tmp_2->GetMem())
    {
      Monom A(tmp_1->GetMem().GetN(), tmp_1->GetMem().GetPower(), 0);
      res.InstLast(A - tmp_1->GetMem());
      tmp_1 = tmp_1->GetNextLink();
    }
    else
    {
      Monom A(tmp_2->GetMem().GetN(), tmp_2->GetMem().GetPower(), 0);
      res.InstLast(A - tmp_2->GetMem());
      tmp_2 = tmp_2->GetNextLink();
    }
  if (!tmp_1)
    tmp_1 = tmp_2;
  while (tmp_1)
  {
    res.InstLast(tmp_1->GetMem());
    tmp_1 = tmp_1->GetNextLink();
  }
  return res;
}

Polinom Polinom::operator*(Polinom& polinom)
{
  Polinom res;
  TDatLink<Monom>* tmp_1 = FirstItem;
  TDatLink<Monom>* tmp_2 = polinom.FirstItem;
  for (int i = 0; i < ListLen; i++)
  {
    for (int i = 0; i < polinom.ListLen; i++)
    {
      res.InstLast(tmp_1->GetMem() * tmp_2->GetMem());
      tmp_2 = tmp_2->GetNextLink();
    }
    tmp_1 = tmp_1->GetNextLink();
    tmp_2 = polinom.FirstItem;
  }
  return res;
}

Polinom& Polinom::operator+=(Monom& monom)
{
  for (int i = 0; i < ListLen; i++)
  {
    Monom tmp = GetValue(i);
    if (tmp == monom)
    {
      DelCustom(i);
      InstCustom(i, monom + tmp);
      return *this;
    }
    else if (tmp < monom)
    {
      InstCustom(i, monom);
      return *this;
    }
  }
  InstLast(monom);
  return *this;
}

Monom Polinom::operator[](const int nomber)
{
  return GetValue(nomber);
}

std::ostream& operator<<(std::ostream& os, Polinom& polinom)
{
  TDatLink<Monom>* tmp = polinom.FirstItem;
  for (int i = 0; i < polinom.ListLen - 1; i++)
  {
    os << polinom.GetValue(i) << '+';
    tmp = tmp->GetNextLink();
  }
  os << polinom.GetValue(polinom.ListLen - 1) << std::endl;
  return os;
}