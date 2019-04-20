#include <gtest.h>
#include "Point.h"

TEST(point, can_create_point_without_throws_0)
{
  ASSERT_NO_THROW(TPoint point);
}

TEST(point, can_create_point_without_throws_1)
{
  ASSERT_NO_THROW(TPoint point(1, 1));
}

TEST(point, can_create_point_without_throws_2)
{
  TPoint p1(1, 1);
  ASSERT_NO_THROW(TPoint point(p1));
}

TEST(point, can_set_X_without_throws)
{
  TPoint point;
  ASSERT_NO_THROW(point.SetX(1));
}

TEST(point, can_set_Y_without_throws)
{
  TPoint point;
  ASSERT_NO_THROW(point.SetY(1));
}

TEST(point, can_get_X_without_throws)
{
  TPoint point(1, 1);
  ASSERT_NO_THROW(point.GetX());
}

TEST(point, can_get_Y_without_throws)
{
  TPoint point(1, 1);
  ASSERT_NO_THROW(point.GetY());
}

TEST(point, can_get_X)
{
  TPoint point(1, 1);
  EXPECT_EQ(1, point.GetX());
}

TEST(point, can_get_Y)
{
  TPoint point(1, 1);
  EXPECT_EQ(1, point.GetY());
}

TEST(point, can_return_true_if_points_are_equil)
{
  TPoint point(1, 1);
  TPoint point1(1, 1);
  EXPECT_EQ(1, point == point1);
}

TEST(point, can_return_false_if_points_are_not_equil)
{
  TPoint point(1, 1);
  TPoint point1(1, 2);
  EXPECT_EQ(0, point == point1);
}

TEST(point, can_return_true_if_points_are_not_equil)
{
  TPoint point(1, 1);
  TPoint point1(2, 1);
  EXPECT_EQ(1, point != point1);
}

TEST(point, can_return_false_if_points_are_equil)
{
  TPoint point(1, 1);
  TPoint point1(1, 1);
  EXPECT_EQ(0, point != point1);
}