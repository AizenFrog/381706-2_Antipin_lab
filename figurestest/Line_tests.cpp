#include <gtest.h>
#include "Line.h"

TEST(line, can_create_line_without_throw_0)
{
  ASSERT_NO_THROW(TLine line);
}

TEST(line, can_create_line_without_throw_1)
{
  TPoint point1(1, 1), point2(2, 2);
  ASSERT_NO_THROW(TLine line(&point1, &point2));
}

TEST(line, can_create_line_without_throw_2)
{
  ASSERT_NO_THROW(TLine line(1, 1, 2, 2));
}

TEST(line, can_create_line_without_throw_3)
{
  TPoint point1(1, 1), point2(2, 2);
  TLine line1(&point1, &point2);
  ASSERT_NO_THROW(TLine line2(line1));
}

TEST(line, can_set_X_without_throw)
{
  TLine line;
  ASSERT_NO_THROW(line.SetX(1));
}

TEST(line, can_set_Y_without_throw)
{
  TLine line;
  ASSERT_NO_THROW(line.SetY(1));
}

TEST(line, can_get_X_without_throw)
{
  TLine line;
  ASSERT_NO_THROW(line.GetX());
}

TEST(line, can_get_Y_without_throw)
{
  TLine line;
  ASSERT_NO_THROW(line.GetX());
}

TEST(line, can_set_X_correct)
{
  TLine line;
  line.SetX(1);
  EXPECT_EQ(line.GetX(), 1);
}

TEST(line, can_set_Y_correct)
{
  TLine line;
  line.SetY(1);
  EXPECT_EQ(line.GetY(), 1);
}

TEST(line, can_set_X_1_without_throw)
{
  TLine line;
  ASSERT_NO_THROW(line.SetX1(1));
}

TEST(line, can_set_Y_1_without_throw)
{
  TLine line;
  ASSERT_NO_THROW(line.SetY1(1));
}

TEST(line, can_get_X_1_without_throw)
{
  TLine line;
  ASSERT_NO_THROW(line.GetX1());
}

TEST(line, can_get_Y_1_without_throw)
{
  TLine line;
  ASSERT_NO_THROW(line.GetY1());
}

TEST(line, can_set_X_1_correct)
{
  TLine line;
  line.SetX1(1);
  EXPECT_EQ(line.GetX1(), 1);
}

TEST(line, can_set_Y_1_correct)
{
  TLine line;
  line.SetY1(1);
  EXPECT_EQ(line.GetY1(), 1);
}

TEST(line, can_set_point_1_without_throws)
{
  TLine line;
  TPoint point(1, 1);
  ASSERT_NO_THROW(line.SetPoint1(&point));
}

TEST(line, can_set_point_2_without_throws)
{
  TLine line;
  TPoint point(1, 1);
  ASSERT_NO_THROW(line.SetPoint2(&point));
}