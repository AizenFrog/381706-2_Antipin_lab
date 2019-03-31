#pragma once
#include "Stack_on_List.h"
#include <iostream>
#include <cstring>
#include "Exception_class.h"

using namespace std;

class TTree
{
protected:
  TTree* same_level;//указатель на следующий элемент текста
  TTree* next_level;//указатель на внутренний элемент в текущем элементе текста
  char letter;//буква
  int level;//текущий уровень структуры
  static char* memory;
  static TTree* start;
  static TTree* end;
  static TTree* cur_free;
  static int tree_size;
  static int busy_tree_size;
  Exceptions_from_tree_text exception;
public:
  TTree(const int _level);
  TTree(const char* word);
  TTree(const char _letter = 0);
  TTree(const TTree& tree);
  ~TTree();
  TTree& operator=(const TTree& tree);
  TTree& operator+=(const TTree& tree);
  TTree& operator+=(const char _letter);
  TTree& operator+=(const char* word);
  void* operator new (const size_t size);
  void operator delete (void* tree/*, const unsigned int size*/);
  friend ostream& operator<<(ostream& o, TTree& text);
  void Output();
  char* ToString();
  void SetSameLevel(TTree* _same_level);
  void SetNextLevel(TTree* _next_level);
  void SetLetter(const char _letter);
  void SetLevel(const int _level);
  static void SetTreeSize(const int size);
  TTree* GetSameLevel();
  TTree* GetNextLevel();
  char GetLetter();
  int GetLevel();
  static int GetTreeSize();//////tests!!!!!!
  static int GetTreeBusySize();//////
  TTree* Clone();
  void Initialization(const int size = 100);
  void GarbageCollector();
  static void ClearMemory(void);
};