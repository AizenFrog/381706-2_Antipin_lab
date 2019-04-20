#include "Plex.h"

TPlex::TPlex()
{
  right = NULL;
  left = NULL;
}

TPlex::TPlex(const TPlex& plex)
{
  TPlex* tmp1 = dynamic_cast<TPlex*>(plex.left);
  TPlex* tmp2 = dynamic_cast<TPlex*>(plex.right);
  if (tmp1 != NULL)
    left = new TPlex(*tmp1);
  else
    left = new TPoint(*plex.left);
  if (tmp2 != NULL)
    right = new TPlex(*tmp2);
  else
    right = new TPoint(*plex.right);
}

TPlex::TPlex(TPoint* point1, TPoint* point2)
{
  TPlex* tmp1 = dynamic_cast<TPlex*>(point1);
  TPlex* tmp2 = dynamic_cast<TPlex*>(point2);
  if (tmp1 != NULL)
    left = new TPlex(*tmp1);
  else
    left = new TPoint(*point1);
  if (tmp2 != NULL)
    right = new TPlex(*tmp2);
  else
    right = new TPoint(*point2);
}

TPlex::~TPlex()
{
  Delete();
}

void TPlex::Delete()
{
  TPlex* tmp1 = dynamic_cast<TPlex*>(left);
  TPlex* tmp2 = dynamic_cast<TPlex*>(right);
  if (tmp1 != NULL)
    tmp1->Delete();
  else
    delete left;
  if (tmp2 != NULL)
    tmp2->Delete();
  else
    delete right;
}

TPlex& TPlex::operator+=(TLine& line)
{
  if (right == NULL && left == NULL)
  {
    left = line.GetPoint1();
    right = line.GetPoint2();
  }
  else
  {
    TStackList<TPoint*> stack1;
    TStackList<TPoint*> stack2;
    stack1.Put(left);
    stack1.Put(right);
    stack2.Put(this);
    stack2.Put(this);
    bool flag = true;
    while (flag == true)
    {
      TPoint* tmp = stack1.Get();
      TPlex* pl = dynamic_cast<TPlex*>(stack2.Get());
      if (*tmp != *line.GetPoint1() && *tmp != *line.GetPoint2())
      {
        TPlex* px = dynamic_cast<TPlex*>(tmp);
        if (px != NULL)
        {
          stack1.Put(px->left);
          stack1.Put(px->right);
          stack2.Put(px);
          stack2.Put(px);
        }
      }
      else if (*tmp == *line.GetPoint1())
      {
        flag = false;
        if (*tmp == *pl->left)
        {
          pl->left = new TPlex(line.GetPoint2(), line.GetPoint1());
        }
        else
        {
          pl->right = new TPlex(line.GetPoint2(), line.GetPoint1());
        }
      }
      else if (*tmp == *line.GetPoint2())
      {
        flag = false;
        if (*tmp == *pl->left)
          pl->left = new TPlex(line.GetPoint1(), line.GetPoint2());
        else
          pl->right = new TPlex(line.GetPoint1(), line.GetPoint2());
      }
    }
  }
  return *this;
}

void TPlex::Show()
{
  TPlex* tmp1 = dynamic_cast<TPlex*>(left);
  TPlex* tmp2 = dynamic_cast<TPlex*>(right);
  if (tmp1 != NULL)
    tmp1->Show();
  else
    left->Show();
  if (tmp2 != NULL)
    tmp2->Show();
  else
    right->Show();
}