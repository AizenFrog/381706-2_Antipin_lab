#include <gtest.h>
#include "Text.h"

TEST(text, can_create_text_without_throws)
{
  ASSERT_NO_THROW(TText text("Hello world"));
}

TEST(text, can_create_copy_text_without_throws)
{
  TText text1("Hello world");
  ASSERT_NO_THROW(TText text(text1));
}

TEST(text, can_insert_text_1_without_throws)
{
  TText text("Hello world");
  ASSERT_NO_THROW(text.Insert(5, "HI"));
}

TEST(text, can_insert_text_1)
{
  TTree::ClearMemory();
  TText text("Hello world");
  //text.GetNextLevel()->ToString();
  text.Insert(5, "HI");
  EXPECT_EQ(text.GetRoot()->ToString()[5], 'H');
  EXPECT_EQ(text.GetRoot()->ToString()[6], 'I');
}

TEST(text, can_insert_text_2_without_throws)
{
  TText text("Hello world");
  TTree word("HI");
  TTree* tmp;
  tmp = text.GetRoot()->GetNextLevel()->GetNextLevel();
  ASSERT_NO_THROW(text.Insert(tmp, &word));
}

TEST(text, can_insert_text_2)
{
  TText text("Hello world");
  TTree word("HI");
  TTree* tmp;
  tmp = text.GetRoot()->GetNextLevel()->GetNextLevel();
  text.Insert(tmp, &word);
  EXPECT_EQ(text.GetRoot()->ToString()[6], 'H');
  EXPECT_EQ(text.GetRoot()->ToString()[7], 'I');
}

TEST(text, can_find_text_1_without_throws)
{
  TText text("Hello world");
  ASSERT_NO_THROW(text.Find("llo"));
}

TEST(text, can_find_text_1)
{
  TText text("Hello world");
  EXPECT_EQ(text.Find("llo"), 2);
}

TEST(text, can_find_text_2_without_throws)
{
  TText text("Hello world");
  ASSERT_NO_THROW(text.FindTree("llo"));
}

TEST(text, can_find_text_2)
{
  TTree::ClearMemory();
  TText text("Hello world");
  TTree* tmp = text.FindTree("He");
  EXPECT_EQ(text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel(), tmp);
}

TEST(text, can_copy_text_1_without_throws)
{
  TText text("Hello world");
  ASSERT_NO_THROW(text.Copy(2, 3));
}

TEST(text, can_copy_text_1)
{
  TText text("Hello world");
  char* tmp = text.Copy(2, 3);
  EXPECT_EQ(tmp[0], 'l');
  EXPECT_EQ(tmp[1], 'l');
  EXPECT_EQ(tmp[2], 'o');
}

TEST(text, can_copy_text_2_without_throws)
{
  TText text("Hello world");
  TTree* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel();
  ASSERT_NO_THROW(text.Copy(tmp, 3));
}

TEST(text, can_copy_text_2)
{
  TText text("Hello world");
  TTree* tmp_1 = text.GetRoot()->GetNextLevel()->GetNextLevel();
  TTree* tmp_2 = text.Copy(tmp_1, 2);
  EXPECT_EQ(tmp_2->GetNextLevel()->GetNextLevel()->GetNextLevel()->GetLetter(), 'H');
  EXPECT_EQ(tmp_2->GetNextLevel()->GetNextLevel()->GetNextLevel()->GetSameLevel()->GetLetter(),'e');
  TTree::ClearMemory();
}

TEST(text, can_delete_element_1_without_throws)
{
  TText text("Hello world");
  ASSERT_NO_THROW(text.Delete(2, 3));
  TTree::ClearMemory();
}

TEST(text, can_delete_element_1)
{
  TText text("Hello world");
  text.Delete(2, 3);
  EXPECT_EQ(text.GetRoot()->ToString()[2], ' ');
  EXPECT_EQ(text.GetRoot()->ToString()[3], 'w');
  EXPECT_EQ(text.GetRoot()->ToString()[4], 'o');
}

TEST(text, can_delete_element_2_without_throws)
{
  TText text("Hello world");
  TTree* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel();
  ASSERT_NO_THROW(text.Delete(tmp, 2));
}

TEST(text, can_delete_element_2)
{
  TText text("Hello world");
  TTree* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel();
  text.Delete(tmp, 2);
  EXPECT_EQ(text.GetRoot()->ToString()[0], 'l');
  EXPECT_EQ(text.GetRoot()->ToString()[1], 'l');
  TTree::ClearMemory();
}