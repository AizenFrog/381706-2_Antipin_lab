#include <gtest.h>
#include "Polish_string.h"

TEST(Polish_string, can_create_some_string)
{
  ASSERT_NO_THROW(Polich_string PS);
}

TEST(Polish_string, is_servise_char_true)
{
  Polich_string PS;
  PS.WrightString("*");
  EXPECT_EQ(1, PS.IsServiceChar());
}

TEST(Polish_string, is_servise_char_false)
{
  Polich_string PS;
  PS.WrightString("0");
  EXPECT_EQ(0, PS.IsServiceChar());
}

TEST(Polish_string, can_return_next_service_char)
{
  Polich_string PS;
  Number A;
  PS.WrightString("*");
  A = PS.GetNextChar();
  EXPECT_EQ('*', A.number[0]);
}

TEST(Polish_string, can_return_next_char_number)
{
  Polich_string PS;
  Number A;
  PS.WrightString("100");
  A = PS.GetNextChar();
  EXPECT_EQ('1', A.number[0]);
  EXPECT_EQ('0', A.number[1]);
  EXPECT_EQ('0', A.number[2]);
}

TEST(Polish_string, can_return_next_char_from_some_other_chars)
{
  Polich_string PS;
  Number A;
  PS.WrightString("*100+25");
  PS.GetNextChar();
  A = PS.GetNextChar();
  EXPECT_EQ('1', A.number[0]);
  EXPECT_EQ('0', A.number[1]);
  EXPECT_EQ('0', A.number[2]);
}

TEST(Polish_string, can_return_next_char_from_some_other_chars_2)
{
  Polich_string PS;
  Number A;
  PS.WrightString("*100+25");
  PS.GetNextChar();
  PS.GetNextChar();
  A = PS.GetNextChar();
  EXPECT_EQ('+', A.number[0]);
}

TEST(Polish_string, can_return_wright_index)
{
  Polich_string PS;
  PS.WrightString("*100+25");
  PS.GetNextChar();
  PS.GetNextChar();
  EXPECT_EQ(4, PS.GetIndex());
}