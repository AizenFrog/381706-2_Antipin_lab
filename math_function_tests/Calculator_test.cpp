#include <gtest.h>
#include "Polish_record.h"

TEST(calculator, can_create_calculator)
{
  char string[] = "100";
  ASSERT_NO_THROW(Calculator calc(string));
}

TEST(calculator, can_create_calculator_1)
{
  char string[] = "100";
  ASSERT_NO_THROW(Calculator calc(string));
}

TEST(calculator, can_transformate_char_to_int)
{
  char string[] = "100=";
  Calculator calc(string);
  Polich_string str;
  str.WrightString(string);
  Number num = str.GetNextChar();
  EXPECT_EQ(calc.CharToInt(num), 100);
}

TEST(calculator, can_add_to_stack)
{
  Number sign;
  sign.number ="+";
  sign.len = 1;
  Number num;
  num.number = "100";
  num.len = 3;
  Calculator calc_sign("+");
  ASSERT_NO_THROW(calc_sign.AddToStacks(sign));
  ASSERT_NO_THROW(calc_sign.AddToStacks(num));
}

TEST(calculator, can_calculate_something)
{
  char string[] = "100+50=";
  Calculator calc(string);
  EXPECT_EQ(calc.Calculate(), 150);
}

TEST(calculator, can_calculate_something_hard)
{
  char string[] = "100+50*3=";
  Calculator calc(string);
  EXPECT_EQ(calc.Calculate(), 250);
}

TEST(calculator, can_calculate_something_hard_2)
{
  char string[] = "100*3+50=";
  Calculator calc(string);
  EXPECT_EQ(calc.Calculate(), 350);
}

TEST(calculator, can_calculate_something_hard_3)
{
  char string[] = "149/2=";
  Calculator calc(string);
  EXPECT_EQ(calc.Calculate(), 74);
}

TEST(calculator, can_calculate_something_very_hard)
{
  char string[] ="100*(2+3)=";
  Calculator calc(string);
  EXPECT_EQ(calc.Calculate(), 500);
}

TEST(calculator, can_calculate_something_very_very_hard)
{
  char string[] = "100*(2*(3+1))=";
  Calculator calc(string);
  EXPECT_EQ(calc.Calculate(), 800);
}

TEST(calculator, can_calculate_something_very_very_hard_2)
{
  char string[] = "10*(2*(3+1)+4)=";
  Calculator calc(string);
  EXPECT_EQ(calc.Calculate(), 120);
}

TEST(calculator, can_raise_to_a_power)
{
  char string[] = "5^3=";
  Calculator calc(string);
  EXPECT_EQ(calc.Calculate(), 125);
}

TEST(calculator, can_raise_to_a_hard_power)
{
  char string[] = "5^(2+1)=";
  Calculator calc(string);
  EXPECT_EQ(calc.Calculate(), 125);
}

TEST(calculator, can_throw_if_whrong_record)
{
  char string[] = "S^(2+1)=";
  Calculator calc(string);
  ASSERT_ANY_THROW(calc.Calculate());
}

TEST(calculator, can_throw_if_whrong_record_2)
{
  char string[] = "5^(;+1)=";
  Calculator calc(string);
  ASSERT_ANY_THROW(calc.Calculate());
}

TEST(calculator, can_throw_if_record_without_equally)
{
  char string[] = "2+1";
  Calculator calc(string);
  ASSERT_ANY_THROW(calc.Calculate());
}