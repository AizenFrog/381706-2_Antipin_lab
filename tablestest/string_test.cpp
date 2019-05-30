#include <gtest.h>
#include "TString.h"

TEST(string, can_create_string_without_throws_0)
{
  ASSERT_NO_THROW(String str);
}

TEST(string, can_create_string_without_throws_1)
{
  ASSERT_NO_THROW(String str("Hello World"));
}

TEST(string, can_return_array_of_chars_0)
{
  String str("Hello World");
  ASSERT_NO_THROW(str.GetArrChar());
}

TEST(string, can_return_array_of_chars_1)
{
  String str("Hello World");
  EXPECT_EQ(str.GetArrChar()[0], 'H');
  EXPECT_EQ(str.GetArrChar()[2], 'l');
  EXPECT_EQ(str.GetArrChar()[5], ' ');
  EXPECT_EQ(str.GetArrChar()[7], 'o');
}

TEST(string, can_assign_without_throws)
{
  String str1("A");
  String str2("Hello World");
  ASSERT_NO_THROW(str1 = str2);
}

TEST(string, can_assign_correct)
{
  String str1;
  String str2("Hello World");
  str1 = str2;
  EXPECT_EQ(str1.GetArrChar()[0], 'H');
  EXPECT_EQ(str1.GetArrChar()[2], 'l');
  EXPECT_EQ(str1.GetArrChar()[5], ' ');
  EXPECT_EQ(str1.GetArrChar()[7], 'o');
}

TEST(string, can_compare_strings_true_without_throws)
{
  String str1("Hello World");
  String str2("Hello World");
  ASSERT_NO_THROW(str1 == str2);
}

TEST(string, can_compare_strings_true_correct)
{
  String str1("Hello World");
  String str2("Hello World");
  EXPECT_EQ(str1 == str2, 1);
}

TEST(string, can_compare_strings_false_without_throws)
{
  String str1("Hello World");
  String str2("Hello");
  ASSERT_NO_THROW(str1 == str2);
}

TEST(string, can_compare_strings_false_correct_0)
{
  String str1("Hello World");
  String str2("Hello");
  EXPECT_EQ(str1 == str2, 0);
}

TEST(string, can_compare_strings_false_correct_1)
{
  String str1("Hello World");
  String str2("Hello world");
  EXPECT_EQ(str1 == str2, 0);
}

TEST(string, can_compare_less_strings_true_without_throws_0)
{
  String str1("Hello");
  String str2("Hello World");
  ASSERT_NO_THROW(str1 < str2);
}

TEST(string, can_compare_less_strings_true_without_throws_1)
{
  String str1("Hello World");
  String str2("Hello");
  ASSERT_NO_THROW(str1 < str2);
}

TEST(string, can_compare_less_strings_true_without_throws_2)
{
  String str1("Hello Worlf");
  String str2("Hello World");
  ASSERT_NO_THROW(str1 < str2);
}

TEST(string, can_compare_less_strings_true_correct_0)
{
  String str1("Hello");
  String str2("Hello World");
  EXPECT_EQ(str1 < str2, 1);
}

TEST(string, can_compare_less_strings_true_correct_1)
{
  String str1("Hello Worlc");
  String str2("Hello World");
  EXPECT_EQ(str1 < str2, 1);
}

TEST(string, can_compare_less_strings_false_correct_0)
{
  String str1("Hello World");
  String str2("Hello");
  EXPECT_EQ(str1 < str2, 0);
}

TEST(string, can_compare_less_strings_false_correct_1)
{
  String str1("Hello world");
  String str2("Hello World");
  EXPECT_EQ(str1 < str2, 0);
}

TEST(string, can_compare_more_strings_true_without_throws_0)
{
  String str1("Hello World");
  String str2("Hello");
  ASSERT_NO_THROW(str1 > str2);
}

TEST(string, can_compare_more_strings_true_without_throws_1)
{
  String str1("Hello World");
  String str2("Hello");
  ASSERT_NO_THROW(str2 > str1);
}

TEST(string, can_compare_more_strings_true_without_throws_2)
{
  String str1("Hello Worlf");
  String str2("Hello World");
  ASSERT_NO_THROW(str2 > str1);
}

TEST(string, can_compare_more_strings_true_correct_0)
{
  String str1("Hello");
  String str2("Hello World");
  EXPECT_EQ(str2 > str1, 1);
}

TEST(string, can_compare_more_strings_true_correct_1)
{
  String str1("Hello Worlc");
  String str2("Hello World");
  EXPECT_EQ(str2 > str1, 1);
}

TEST(string, can_compare_more_strings_false_correct_0)
{
  String str1("Hello World");
  String str2("Hello");
  EXPECT_EQ(str2 > str1, 0);
}

TEST(string, can_compare_more_strings_false_correct_1)
{
  String str1("Hello world");
  String str2("Hello World");
  EXPECT_EQ(str2 > str1, 0);
}

TEST(string, can_throw_if_trying_to_return_wrong_element_0)
{
  String str("Hello World");
  ASSERT_ANY_THROW(str[-1]);
}

TEST(string, can_throw_if_trying_to_return_wrong_element_1)
{
  String str("Hello World");
  ASSERT_ANY_THROW(str[11]);
}

TEST(string, can_return_element)
{
  String str("Hello World");
  EXPECT_EQ(str[10], 'd');
}