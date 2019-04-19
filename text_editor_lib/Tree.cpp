#include "Tree.h"

int TTree::tree_size = 100;
int TTree::busy_tree_size = 0;
char* TTree::memory = 0;
TTree* TTree::start = NULL;
TTree* TTree::end = NULL;
TTree* TTree::cur_free = NULL;

TTree::TTree(const int _level)
{
  if (_level < 0 || _level > 3)
    exception.except_throw(101);
  Initialization(tree_size);
  level = _level;
  letter = 0;
  same_level = NULL;
  next_level = NULL;
}

TTree::TTree(const char* word)
{
  Initialization(tree_size);
  int len = strlen(word);
  level = 2;
  same_level = NULL;
  next_level = new TTree(word[0]);
  TTree* tmp = next_level;
  for (int i = 1; i < len; i++)
  {
    tmp->same_level = new TTree(word[i]);
    tmp = tmp->same_level;
  }
  letter = 0;
}

TTree::TTree(const char _letter)
{
  Initialization(tree_size);
  level = 3;
  letter = _letter;
  same_level = NULL;
  next_level = NULL;
}

TTree::TTree(const TTree& tree)
{
  Initialization(tree_size);
  level = tree.level;
  letter = tree.letter;
  same_level = tree.same_level;
  next_level = tree.next_level;
}

TTree::~TTree()
{
  TTree* tmp;
  TStackList<TTree*> stack;
  stack.Put(this);
  if (stack.IsEmpty() == false)
    tmp = stack.Get();
  if (tmp->GetSameLevel() != NULL)
    stack.Put(tmp->GetSameLevel());
  if (tmp->GetNextLevel() != NULL)
    stack.Put(tmp->GetNextLevel());
  tmp->letter = -1;
}

TTree& TTree::operator=(const TTree& tree)
{
  if (level != tree.level)
    exception.except_throw(102);
  if (this != &tree)
  {
    same_level = tree.same_level;
    next_level = tree.next_level;
    letter = tree.letter;
  }
  return *this;
}

TTree& TTree::operator+=(const TTree& tree)
{
  TTree* tmp = this;
  if (level != tree.level)
    while (tmp->level != tree.level)
      tmp = tmp->next_level;
  while (tmp->same_level != NULL)
    tmp = tmp->same_level;
  tmp->same_level = new TTree(tree);
  return *this;
}

TTree& TTree::operator+=(const char _letter)
{
  TTree* tmp = new TTree(_letter);
  *this += *tmp;
  return *this;
}

TTree& TTree::operator+=(const char* word)
{
  TTree* tmp = new TTree(word);
  *this += *tmp;
  return *this;
}

void* TTree::operator new (const size_t size)
{
  if (cur_free != 0)
  {
    TTree* tmp1 = cur_free;
    if (busy_tree_size == tree_size)
      throw("No free memory");
    cur_free = cur_free->next_level;
    busy_tree_size++;
    return tmp1;
  }
}

void TTree::operator delete(void* tree/*, const unsigned int size*/)
{
  TTree* tmp = (TTree*)tree;
  tmp->next_level = cur_free;
  cur_free = tmp;
  tmp->letter = -1;
  tmp->level = 0;
  tmp->same_level = NULL;
}

ostream& operator<<(ostream& o, TTree& tree)
{
  char* str = tree.ToString();
  o << str;
  return o;
}

void TTree::Output()
{
  char* str = this->ToString();
  cout << str << endl;
}

void TTree::SetSameLevel(TTree* _same_level)
{
  same_level = _same_level;
}

void TTree::SetNextLevel(TTree* _next_level)
{
  next_level = _next_level;
}

void TTree::SetLetter(const char _letter)
{
  if (level == 3)
    letter = _letter;
  else
    exception.except_throw(103);
}

void TTree::SetLevel(const int _level)
{
  level = _level;
}

void TTree::SetTreeSize(const int size)
{
  tree_size = size;
}

TTree* TTree::GetSameLevel()
{
  return same_level;
}

TTree* TTree::GetNextLevel()
{
  return next_level;
}

char TTree::GetLetter()
{
  if (level == 3)
    return letter;
  else
    exception.except_throw(104);
}

int TTree::GetLevel()
{
  return level;
}

int TTree::GetTreeSize()
{
  return tree_size;
}

int TTree::GetTreeBusySize()
{
  return busy_tree_size;
}

char* TTree::ToString()
{
  TStackList<TTree*> stack;
  stack.Put(this);
  int len = 0;
  int space_array[100];
  int space_count = 0;
  bool trap = false;
  while (stack.IsEmpty() != true)
  {
    TTree* tmp = stack.Get();
    if (tmp->level == 3)
    {
      len++;
      if (trap == false && len > 1)
      {
        space_array[space_count] = len - 1;
        space_count++;
        len++;
      }
      trap = true;
    }
    if (tmp->same_level != NULL)
      stack.Put(tmp->same_level);
    if (tmp->next_level != NULL)
    {
      stack.Put(tmp->next_level);
      trap = false;
    }
  }
  char* res_string = new char[len + 1];
  int j = 0;
  stack.Put(this);
  space_count = 0;
  while (stack.IsEmpty() != true)
  {
    if (j == space_array[space_count])
    {
      res_string[j] = ' ';
      j++;
      space_count++;
    }
    TTree* tmp1 = stack.Get();
    if (tmp1->level == 3)
    {
      res_string[j] = tmp1->letter;
      j++;
    }
    if (tmp1->same_level != NULL)
      stack.Put(tmp1->same_level);
    if (tmp1->next_level != NULL)
      stack.Put(tmp1->next_level);
  }
  res_string[len] = 0;
  return res_string;
}

TTree* TTree::Clone()
{
  TTree* resTree = new TTree(*this);
  TStackList<TTree*> stack;
  TStackList<TTree*> copy;
  stack.Put(this);
  copy.Put(resTree);
  while (stack.IsEmpty() != true)
  {
    TTree* tmp1 = stack.Get();
    TTree* tmp2 = copy.Get();
    if (tmp1->next_level != NULL)
    {
      tmp2->next_level = new TTree(*(tmp1->next_level));
      stack.Put(tmp1->next_level);
      copy.Put(tmp2->next_level);
    }
    if (tmp1->same_level != NULL)
    {
      tmp2->same_level = new TTree(*(tmp1->same_level));
      stack.Put(tmp1->same_level);
      copy.Put(tmp2->same_level);
    }
  }
  return resTree;
}

void TTree::Initialization(const int size)
{
  if (size <= 0)
    exception.except_throw(105);
  if (memory == 0)
  {
    tree_size = size;
    //int a = sizeof(TTree);
    memory = new char[sizeof(TTree) * size];
    start = (TTree*)(memory);
    cur_free = end = start;
    for (int i = 0; i < size - 1; i++)
    {
      end->next_level = (TTree*)(&memory[(i + 1) * sizeof(TTree)]);
      end = end->next_level;
    }
  }
}

void TTree::GarbageCollector()
{
  cur_free = 0;
  TTree* tmp;
  for (int i = 0; i < tree_size; i++)
  {
    if (((TTree*)(&(memory[i * sizeof(TTree)])))->letter == -1)
    {
      tmp = cur_free;
      cur_free = ((TTree*)&(memory[i * sizeof(TTree)]));
      ((TTree*)&(memory[i * sizeof(TTree)]))->next_level = tmp;
      //cur_free = (TTree*)memory;
    }
  }
}

void TTree::ClearMemory(void)
{
  delete[] memory;
  memory = NULL;
  busy_tree_size = 0;
}