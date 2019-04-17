#include <gtest.h>
#include "Circle.h"

TEST(circle, can_create_circle_without_throws_0)
{
  ASSERT_NO_THROW(TCircle circle);
}

TEST(circle, can_create_circle_without_throws_1)
{
  TPoint point(1, 1);
  ASSERT_NO_THROW(TCircle circle(&point, 1));
}

TEST(circle, can_throw_if_create_circle_with_negative_radius_0)
{
  TPoint point(1, 1);
  ASSERT_ANY_THROW(TCircle circle(&point, -1));
}

TEST(circle, can_create_circle_without_throws_2)
{
  ASSERT_NO_THROW(TCircle circle(1, 1, 1));
}

TEST(circle, can_throw_if_create_circle_with_negative_radius_1)
{
  ASSERT_ANY_THROW(TCircle circle(1, 1, -1));
}

TEST(circle, can_create_circle_without_throws_3)
{
  TCircle circle1(1, 1, 1);
  ASSERT_NO_THROW(TCircle circle(circle1));
}

TEST(circle, can_get_X_without_throws)
{
  TCircle circle(1, 1, 1);
  ASSERT_NO_THROW(circle.GetX());
}

TEST(circle, can_get_Y_without_throws)
{
  TCircle circle(1, 1, 1);
  ASSERT_NO_THROW(circle.GetY());
}

TEST(circle, can_get_R_without_throws)
{
  TCircle circle(1, 1, 1);
  ASSERT_NO_THROW(circle.GetR());
}

TEST(circle, can_get_X_correct)
{
  TCircle circle(1, 1, 1);
  EXPECT_EQ(circle.GetX(), 1);
}

TEST(circle, can_get_Y_correct)
{
  TCircle circle(1, 1, 1);
  EXPECT_EQ(circle.GetY(), 1);
}

TEST(circle, can_get_R_correct)
{
  TCircle circle(1, 1, 1);
  EXPECT_EQ(circle.GetR(), 1);
}

TEST(circle, can_set_X_without_throws)
{
  TCircle circle(1, 1, 1);
  ASSERT_NO_THROW(circle.SetX(2));
}

TEST(circle, can_set_Y_without_throws)
{
  TCircle circle(1, 1, 1);
  ASSERT_NO_THROW(circle.SetY(2));
}

TEST(circle, can_set_R_without_throws)
{
  TCircle circle(1, 1, 1);
  ASSERT_NO_THROW(circle.SetR(2));
}

TEST(circle, can_throw_if_set_negative_radius)
{
  TCircle circle(1, 1, 1);
  ASSERT_ANY_THROW(circle.SetR(-1));
}

TEST(circle, can_set_X_correct)
{
  TCircle circle(1, 1, 1);
  circle.SetX(2);
  EXPECT_EQ(circle.GetX(), 2);
}

TEST(circle, can_set_Y_correct)
{
  TCircle circle(1, 1, 1);
  circle.SetY(2);
  EXPECT_EQ(circle.GetY(), 2);
}

TEST(circle, can_set_R_correct)
{
  TCircle circle(1, 1, 1);
  circle.SetR(2);
  EXPECT_EQ(circle.GetR(), 2);
}