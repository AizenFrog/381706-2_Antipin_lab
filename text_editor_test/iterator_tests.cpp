#include <gtest.h>
#include "TreeIterator.h"

TEST(iterator, can_create_iterator_without_throws)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hello");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  ASSERT_NO_THROW(TTreeIterator iter(&text));
}

TEST(iterator, can_return_next_element_without_throws)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hello");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  TTreeIterator iter(&text);
  ASSERT_NO_THROW(iter.GoNext());
}

TEST(iterator, can_return_next_element_1)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hello");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  TTreeIterator iter(&text);
  EXPECT_EQ(iter.GoNext(), &text);
}

TEST(iterator, can_return_next_element_2)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hello");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  TTreeIterator iter(&text);
  iter.GoNext();
  EXPECT_EQ(iter.GoNext(), &string);
}

TEST(iterator, can_reset_iterator_without_throws)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hello");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  TTreeIterator iter(&text);
  iter.GoNext();
  ASSERT_NO_THROW(iter.Reset());
}

TEST(iterator, can_reset_iterator)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hello");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  TTreeIterator iter(&text);
  iter.GoNext();
  iter.GoNext();
  iter.Reset();
  EXPECT_EQ(iter.GoNext(), &text);
}

TEST(iterator, can_return_false_if_iterator_is_not_end_without_throw)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hello");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  TTreeIterator iter(&text);
  ASSERT_NO_THROW(iter.IsEnd());
}

TEST(iterator, can_return_false_if_iterator_is_not_end)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hello");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  TTreeIterator iter(&text);
  EXPECT_EQ(iter.IsEnd(), false);
}

TEST(iterator, can_return_true_if_iterator_is_end)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hi");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  TTreeIterator iter(&text);
  iter.GoNext();
  iter.GoNext();
  iter.GoNext();
  iter.GoNext();
  iter.GoNext();
  EXPECT_EQ(iter.IsEnd(), true);
}

TEST(iterator, can_return_curent_element)
{
  TTree text(0);
  TTree string(1);
  TTree word("Hello");
  text.SetNextLevel(&string);
  string.SetNextLevel(&word);
  TTreeIterator iter(&text);
  EXPECT_EQ(iter(), &text);
  TTree::ClearMemory();
}