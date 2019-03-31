#include <gtest.h>
#include "Tree.h"

TEST(tree, can_create_tree_with_zero_level)
{
  ASSERT_NO_THROW(TTree tree(0));
}

TEST(tree, can_create_tree_with_first_level)
{
  ASSERT_NO_THROW(TTree tree(1));
}

TEST(tree, can_create_tree_with_second_level)
{
  ASSERT_NO_THROW(TTree tree(2));
}

TEST(tree, can_create_tree_with_third_level)
{
  ASSERT_NO_THROW(TTree tree(3));
}

TEST(tree, can_throw_if_create_tree_with_wrong_level)
{
  ASSERT_ANY_THROW(TTree tree(4));
}

TEST(tree, can_create_tree_using_letter)
{
  ASSERT_NO_THROW(TTree tree('d'));
  TTree::ClearMemory();
}

TEST(tree, can_create_tree_using_word)
{
  ASSERT_NO_THROW(TTree tree("hello"));
}

TEST(tree, can_throw_if_assign_trees_with_different_levels)
{
  TTree tree1("hello");
  TTree tree2;
  ASSERT_ANY_THROW(tree2 = tree1);
  TTree::ClearMemory();
}

TEST(tree, can_assign_trees_without_throws)
{
  TTree tree1("hello");
  TTree tree2("hi");
  ASSERT_NO_THROW(tree2 = tree1);
}

TEST(tree, can_assign_trees_correct)
{
  TTree tree1("hello");
  TTree tree2("hi");
  tree2 = tree1;
  EXPECT_EQ(tree2.GetNextLevel()->GetLetter(), 'h');
  EXPECT_EQ(tree2.GetNextLevel()->GetSameLevel()->GetLetter(), 'e');
}

TEST(tree, can_add_trees_without_throws)
{
  TTree word1("hello");
  TTree word2("hi");
  TTree text1(0);
  TTree string(1);
  string.SetNextLevel(&word1);
  text1.SetNextLevel(&string);
  ASSERT_NO_THROW(text1 += word2);
}

TEST(tree, can_add_letter_to_tree_without_throws)
{
  TTree word1("hello");
  char letter = 'D';
  TTree text1(0);
  TTree string(1);
  string.SetNextLevel(&word1);
  text1.SetNextLevel(&string);
  ASSERT_NO_THROW(text1 += letter);
}

TEST(tree, can_add_word_to_tree_without_throws)
{
  TTree word1("hello");
  char* word = "world";
  TTree text1(0);
  TTree string(1);
  string.SetNextLevel(&word1);
  text1.SetNextLevel(&string);
  ASSERT_NO_THROW(text1 += word);
}

TEST(tree, can_add_trees_correct)
{
  TTree word1("hello");
  TTree word2("hi");
  TTree text1(0);
  TTree string(1);
  string.SetNextLevel(&word1);
  text1.SetNextLevel(&string);
  text1 += word2;
  EXPECT_EQ(word1.GetSameLevel()->GetNextLevel()->GetLetter(), 'h');
  EXPECT_EQ(word1.GetSameLevel()->GetNextLevel()->GetSameLevel()->GetLetter(), 'i');
}

TEST(tree, can_add_letter_to_tree_correct)
{
  TTree word1("hi");
  char letter = 'D';
  TTree text1(0);
  TTree string(1);
  string.SetNextLevel(&word1);
  text1.SetNextLevel(&string);
  text1 += letter;
  EXPECT_EQ(word1.GetNextLevel()->GetSameLevel()->GetSameLevel()->GetLetter(), 'D');
}

TEST(tree, can_add_word_to_tree_correct)
{
  TTree word1("hello");
  char* word = "world";
  TTree text1(0);
  TTree string(1);
  string.SetNextLevel(&word1);
  text1.SetNextLevel(&string);
  text1 += word;
  EXPECT_EQ(word1.GetSameLevel()->GetNextLevel()->GetLetter(), 'w');
  EXPECT_EQ(word1.GetSameLevel()->GetNextLevel()->GetSameLevel()->GetLetter(), 'o');
}

TEST(tree, can_convert_tree_to_string)
{
  TTree word1("hello");
  TTree text1(0);
  TTree string(1);
  string.SetNextLevel(&word1);
  text1.SetNextLevel(&string);
  //EXPECT_EQ(text1.ToString()[0], 'h');
  EXPECT_EQ(text1.ToString()[1], 'e');
  EXPECT_EQ(text1.ToString()[2], 'l');
  EXPECT_EQ(text1.ToString()[3], 'l');
  EXPECT_EQ(text1.ToString()[4], 'o');
}

TEST(tree, can_create_copy_of_tree)
{
  TTree word1("hello");
  TTree text1(0);
  TTree string(1);
  string.SetNextLevel(&word1);
  text1.SetNextLevel(&string);
  TTree copy = *text1.Clone();
  EXPECT_EQ(copy.GetNextLevel()->GetNextLevel()->GetNextLevel()->GetLetter(), 'h');
  EXPECT_EQ(copy.GetNextLevel()->GetNextLevel()->GetNextLevel()->GetSameLevel()->GetLetter(), 'e');
}

TEST(tree, can_set_next_level_without_throws)
{
  TTree word1("hello");
  TTree string(1);
  ASSERT_NO_THROW(string.SetNextLevel(&word1));
}

TEST(tree, can_set_and_get_next_level)
{
  TTree word1("hello");
  TTree string(1);
  string.SetNextLevel(&word1);
  //EXPECT_EQ(&(string.GetNextLevel()), &word1);
}

TEST(tree, can_set_same_level_without_throws)
{
  //TTree::ClearMemory();
  TTree word1("hello");
  TTree word2("hi");
  ASSERT_NO_THROW(word1.SetSameLevel(&word2));
  TTree::ClearMemory();
}

//TEST(tree, can_throw_if_memory_is_end)
//{
//  ASSERT_ANY_THROW(TTree word1("hello_world"));
//  TTree::ClearMemory();
//}

TEST(tree, can_set_and_get_same_level)
{
  TTree word1("hello");
  TTree word2("hi");
  word1.SetSameLevel(&word2);
  //EXPECT_EQ(word1.GetSameLevel(), word2);
}

TEST(tree, can_create_and_delete_tree_element)
{
  //TTree::ClearMemory();
  TTree* word = new TTree(0);
  delete word;
  TTree* word2 = new TTree(1);
  EXPECT_EQ(word, word2);
}

TEST(tree, can_set_letter_without_throws)
{
  TTree word1('h');
  ASSERT_NO_THROW(word1.SetLetter('D'));
}

TEST(tree, can_set_and_get_letter)
{
  TTree word1('h');
  word1.SetLetter('D');
  EXPECT_EQ(word1.GetLetter(), 'D');
}

TEST(tree, can_set_level_without_throws)
{
  TTree word1(0);
  ASSERT_NO_THROW(word1.SetLevel(1));
}

TEST(tree, can_set_and_get_level)
{
  TTree word1(0);
  word1.SetLevel(1);
  EXPECT_EQ(word1.GetLevel(), 1);
  TTree::ClearMemory();
}