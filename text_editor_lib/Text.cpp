#include "Text.h"

TText::TText(const char* string)
{
  root = new TTree(0);
  root->SetNextLevel(new TTree(1));
  TTree* tmp = root->GetNextLevel();
  char* word;
  int len = strlen(string);
  int space_pos[100];
  int space_count = 0;
  int iter = 0;
  for (int i = 0; i < len; i++)
    if (string[i] == ' ')
    {
      if (space_count > 98)
        exception.except_throw(106);;
      space_pos[space_count] = i;
      space_count++;
    }
  space_pos[space_count] = len;
  word = new char[space_pos[0] + 1];
  space_count = 0;
  for (int i = 0; i <= len; i++)
  {
    if (string[i] != ' ' && i != len)
    {
      word[iter] = string[i];
      iter++;
    }
    else if (string[i] == ' ' || i == len)
    {
      word[iter] = 0;
      if (i == iter)
      {
        tmp->SetNextLevel(new TTree(word));
        tmp = tmp->GetNextLevel();
      }
      else
      {
        tmp->SetSameLevel(new TTree(word));
        tmp = tmp->GetSameLevel();
      }
      delete[] word;
      iter = 0;
      if (i == len)
        break;
      word = new char[space_pos[space_count + 1] - space_pos[space_count]];
    }
  }
  //delete[] word;
}

TText::TText(TText& text)
{
  root = text.Clone();
}

TText::TText(TTree& tree)
{
  root = new TTree(0);
  root->SetNextLevel(new TTree(1));
  root->GetNextLevel()->SetNextLevel(new TTree(*(tree.GetNextLevel()->GetNextLevel())));
}

TTree* TText::GetRoot()
{
  return root;
}

void TText::Insert(const int pos, const char* string)
{
  int string_len = strlen(string);
  TTree* str = new TTree(string[0]);
  TTree* start_str = str;
  int i = 1;
  for (i; i < string_len; i++)
  {
    str->SetSameLevel(new TTree(string[i]));
    str = str->GetSameLevel();
  }
  TTreeIterator iter(root);
  //TStackList<TTree*> stack;
  //stack.Put(root);
  int len = 0;
  while (iter.IsEnd() != true)
  {
    TTree* tmp = iter.GoNext();//stack.Get();
    if (tmp->GetLevel() == 2 && pos == 0)
    {
      iter.PutInStack(tmp);
      break;
    }
    if (tmp->GetLevel() == 3)
      len++;
    if (len == pos - 1)
      break;
    /*if (tmp->GetSameLevel() != NULL)
      stack.Put(tmp->GetSameLevel());
    if (tmp->GetNextLevel() != NULL)
      stack.Put(tmp->GetNextLevel());*/
  }
  TTree* point = iter.GoNext();//stack.Get();
  if (pos == 0)
  {
    str->SetSameLevel(point->GetNextLevel());
    point->SetNextLevel(start_str);
  }
  else
  {
    str->SetSameLevel(point->GetSameLevel());
    point->SetSameLevel(start_str);
  }
}

void TText::Insert(TTree* start, TTree* string)
{
  TTree* tmp1 = string;
  TTree* tmp2 = root;
  TTreeIterator iter(root);
  //TStackList<TTree*> stack;
  //stack.Put(root);
  while (tmp2 != start)
  {
    tmp2 = iter.GoNext();//stack.Get();
    /*if (tmp2->GetSameLevel() != NULL)
      stack.Put(tmp2->GetSameLevel());
    if (tmp2->GetNextLevel() != NULL)
      stack.Put(tmp2->GetNextLevel());*/
  }
  tmp1->SetSameLevel(tmp2->GetSameLevel());
  tmp2->SetSameLevel(tmp1);
}

int TText::Find(const char* string)
{
  TTreeIterator iter(root);
  //TStackList<TTree*> stack;
  //stack.Put(root);
  int len = strlen(string);
  int i = 0;//итератор
  int pos = 0;//позиция
  while (iter.IsEnd() != true/*stack.IsEmpty() != true*/)
  {
    TTree* tmp = iter.GoNext();//stack.Get();
    if (tmp->GetLevel() == 3 && tmp->GetLetter() == string[i])
      i++;
    else if (tmp->GetLevel() == 3 && tmp->GetLetter() != string[i])
    {
      if (i != 0)
      {
        //stack.Put(tmp);
        iter.PutInStack(tmp);
        pos += i;
        i = 0;
      }
      else
        pos++;
    }
    if (i == len)
      break;
    /*if (tmp->GetSameLevel() != NULL)
      stack.Put(tmp->GetSameLevel());
    if (tmp->GetNextLevel() != NULL)
      stack.Put(tmp->GetNextLevel());*/
  }
  return pos;
}

TTree* TText::FindTree(const char* string)
{
  TTreeIterator iter(root);
  //TStackList<TTree*> stack;
  //stack.Put(root);
  TTree* res = NULL;
  int len = strlen(string);
  int i = 0;//итератор
  int pos = 0;//позиция
  while (iter.IsEnd() != true/*stack.IsEmpty() != true*/)
  {
    TTree* tmp = iter.GoNext()/*stack.Get()*/;
    if (tmp->GetLevel() == 3 && tmp->GetLetter() == string[i])
    {
      if (i == 0)
        res = tmp;
      i++;
    }
    else if (tmp->GetLevel() == 3 && tmp->GetLetter() != string[i])
    {
      if (i != 0)
      {
        iter.PutInStack(tmp);
        //stack.Put(tmp);
        res = NULL;
        i = 0;
      }
    }
    if (i == len)
      break;
    /*if (tmp->GetSameLevel() != NULL)
      stack.Put(tmp->GetSameLevel());
    if (tmp->GetNextLevel() != NULL)
      stack.Put(tmp->GetNextLevel());*/
  }
  return res;
}

char* TText::Copy(const int start, const int len)
{
  char* res = new char[len];
  //TStackList<TTree*> stack;
  //stack.Put(root);
  TTreeIterator iter(root);
  int i = 0;//итератор
  int pos = 0;//позиция
  while (iter.IsEnd() != true/*stack.IsEmpty() != true*/)
  {
    TTree* tmp = iter.GoNext();//stack.Get();
    if (tmp->GetLevel() == 3 && pos == start + i)
    {
      pos++;
      res[i] = tmp->GetLetter();
      i++;
    }
    else if (tmp->GetLevel() == 3)
      pos++;
    if (i == len)
      break;
    /*if (tmp->GetSameLevel() != NULL)
      stack.Put(tmp->GetSameLevel());
    if (tmp->GetNextLevel() != NULL)
      stack.Put(tmp->GetNextLevel());*/
  }
  return res;
}

TTree* TText::Copy(TTree* start, const int len)
{
  TTree* res = new TTree(0);
  TTree* res_s = new TTree(1);
  TTree* res_w = new TTree(*start);
  res->SetNextLevel(res_s);
  res_s->SetNextLevel(res_w);
  //TStackList<TTree*> stack;
  //stack.Put(root);
  TTreeIterator iter(root);
  int i = len;//итератор
  bool flag = false;
  while (iter.IsEnd() != true/*stack.IsEmpty() != true*/)
  {
    TTree* tmp = iter.GoNext();//stack.Get();
    if (tmp == start)
    {
      i--;
      flag = true;
    }
    else if (flag == true && tmp->GetLevel() == 3)
    {
      res_w->SetSameLevel(new TTree(*tmp));
      res_w = res_w->GetSameLevel();
      i--;
    }
    if (i == 0)
      break;
    /*if (tmp->GetSameLevel() != NULL)
      stack.Put(tmp->GetSameLevel());
    if (tmp->GetNextLevel() != NULL)
      stack.Put(tmp->GetNextLevel());*/
  }
  return res;
}

void TText::Delete(const int start_del, const int lenght)
{
  //TStackList<TTree*> stack;
  //stack.Put(root);
  TTreeIterator iter(root);
  int i = 0;//итератор
  int pos = 0;//позиция
  TTree* temp1 = NULL;
  TTree* temp2;
  bool flag = false;
  while (iter.IsEnd() != true/*stack.IsEmpty()*/)
  {
    TTree* tmp = iter.GoNext();//stack.Get();
    if (tmp->GetLevel() == 3 && flag == false)
    {
      pos++;
      if (pos == start_del)
      {
        tmp->SetSameLevel(NULL);
        temp1 = tmp;
      }
    }
    if (tmp->GetLevel() == 3 && pos - 1 == start_del)
    {
      //temp1 = tmp;
      temp2 = tmp->GetSameLevel();
      delete tmp;
      pos++;
      i++;
      flag = true;
    }
    else if (tmp->GetLevel() == 3 && pos - 1 == start_del + i)
    {
      TTree* tmp_1 = tmp;
      if (i == lenght - 1)
        temp2 = tmp->GetSameLevel();
      delete tmp_1;
      pos++;
      i++;
    }
    if (i == lenght)
      break;
    /*if (tmp->GetSameLevel() != NULL)
      stack.Put(tmp->GetSameLevel());
    if (tmp->GetNextLevel() != NULL)
      stack.Put(tmp->GetNextLevel());*/
  }
  temp1->SetSameLevel(temp2);
  //root->GarbageCollector();
}

void TText::Delete(TTree* start_del, const int lenght)
{
  //TStackList<TTree*> stack;
  //stack.Put(root);
  TTreeIterator iter(root);
  int i = lenght;//итератор
  bool flag = false;
  bool nextflag = false;
  bool sameflag = false;
  TTree* temp1;
  TTree* temp2;
  TTree* temp3;
  while (iter.IsEnd() != true/*stack.IsEmpty()*/)
  {
    TTree* tmp = iter.GoNext();//stack.Get();
    if (tmp->GetSameLevel() == start_del)
    {
      temp1 = tmp;
      sameflag = true;
    }
    if (tmp->GetNextLevel() == start_del)
    {
      temp3 = tmp;
      nextflag = true;
    }
    if (tmp == start_del)
    {
      //temp1 = tmp;
      //TTree* tmp_1 = tmp;
      delete tmp;
      i--;
      flag = true;
    }
    else if (flag == true && tmp->GetLevel() == 3)
    {
      //TTree* tmp_1 = tmp;
      if (i == 1)
        temp2 = tmp->GetSameLevel();
      delete tmp;
      i--;
    }
    if (i == 0)
      break;
    /*if (tmp->GetSameLevel() != NULL)
      stack.Put(tmp->GetSameLevel());
    if (tmp->GetNextLevel() != NULL)
      stack.Put(tmp->GetNextLevel());*/
  }
  if (nextflag == true)
    temp3->SetNextLevel(temp2);
  if (sameflag == true)
    temp1->SetNextLevel(temp2);
  //root->GarbageCollector();
}