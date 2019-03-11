#include "Polinom.h"

Polinom::Polinom() : List<Monom>()
{
}

Polinom::Polinom(const Polinom& polinom)
{
  this->pListLen = polinom.pListLen;
  TDatLink<Monom>* tmp = polinom.tFirstItem;
  this->tFirstItem = new TDatLink<Monom>(tmp->GetMem(), NULL);
  TDatLink<Monom>* TMP = this->tFirstItem;
  TDatLink<Monom>* tmpCurr;
  for (int i = 1; i < polinom.pListLen; i++)
  {
    tmp = tmp->GetNextLink();
    tmpCurr = new TDatLink<Monom>(tmp->GetMem(), NULL);
    TMP->Set_m(tmpCurr);
    TMP = tmpCurr;
  }
  this->tLastItem = tmpCurr;
}

Polinom::Polinom(const List<Monom>& ls)
{
  this->pListLen = ls.GetListLen();
  this->tFirstItem = new TDatLink<Monom>(ls.GetValue(0), NULL);
  TDatLink<Monom>* tmp = this->tFirstItem;
  TDatLink<Monom>* tmpCurr;
  for (int i = 1; i < this->pListLen; i++)
  {
    tmpCurr = new TDatLink<Monom>(ls.GetValue(i), NULL);
    tmp->Set_m(tmpCurr);
    tmp = tmp->GetNextLink();
  }
  this->tLastItem = tmpCurr;
}

Polinom& Polinom::operator=(const Polinom& polinom)
{
  if (this != &polinom)
  {
    this->DelList();
    this->pListLen = polinom.pListLen;
    TDatLink<Monom>* tmp = polinom.tFirstItem;
    this->tFirstItem = new TDatLink<Monom>(tmp->GetMem(), NULL);
    TDatLink<Monom>* TMP = this->tFirstItem;
    TDatLink<Monom>* tmpCurr;
    for (int i = 1; i < polinom.pListLen; i++)
    {
      tmp = tmp->GetNextLink();
      tmpCurr = new TDatLink<Monom>(tmp->GetMem(), NULL);
      TMP->Set_m(tmpCurr);
      TMP = tmpCurr;
    }
    this->tLastItem = tmpCurr;
  }
  return *this;
}

Polinom Polinom::operator+(const Polinom& polinom)
{
  if (this->pListLen != polinom.pListLen)
    exception.except_throw(105);
  TDatLink<Monom>* tmp_1 = this->tFirstItem;
  TDatLink<Monom>* tmp_2 = polinom.tFirstItem;
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

Polinom Polinom::operator-(const Polinom& polinom)
{
  if (this->pListLen != polinom.pListLen)
    exception.except_throw(105);
  TDatLink<Monom>* tmp_1 = this->tFirstItem;
  TDatLink<Monom>* tmp_2 = polinom.tFirstItem;
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

Polinom Polinom::operator*(const Polinom& polinom)
{
  Polinom res;
  TDatLink<Monom>* tmp_1 = this->tFirstItem;
  TDatLink<Monom>* tmp_2 = polinom.tFirstItem;
  for (int i = 0; i < this->pListLen; i++)
  {
    for (int i = 0; i < polinom.pListLen; i++)
    {
      res.InstLast(tmp_1->GetMem() * tmp_2->GetMem());
      tmp_2 = tmp_2->GetNextLink();
    }
    tmp_1 = tmp_1->GetNextLink();
    tmp_2 = polinom.tFirstItem;
  }
  return res;
}

Polinom& Polinom::operator+=(Monom& monom)
{
  for (int i = 0; i < this->pListLen; i++)
  {
    Monom tmp = GetValue(i);
    if (tmp == monom)
    {
      this->DelCustom(i);
      this->InstCustom(i, monom + tmp);
      return *this;
    }
    else if (tmp < monom)
    {
      this->InstCustom(i, monom);
      return *this;
    }
  }
  this->InstLast(monom);
  return *this;
}

Monom Polinom::operator[](const int nomber)
{
  return this->GetValue(nomber);
}

//std::ostream& operator<<(std::ostream& os, Polinom& polinom)
//{
//  TDatLink<Monom>* tmp = polinom.FirstItem;
//  for (int i = 0; i < polinom.pListLen - 1; i++)
//  {
//    os << polinom.GetValue(i) << '+';
//    tmp = tmp->GetNextLink();
//  }
//  os << polinom.GetValue(polinom.pListLen - 1) << std::endl;
//  return os;
//}