#include <gtest.h>
#include "Triangle.h"

TEST(triangle, can_create_triangle_without_throws_0)
{
  ASSERT_NO_THROW(TTriangle triangle);
}

TEST(triangle, can_create_triangle_without_throws_1)
{
  TPoint point1(1, 1), point2(2, 2), point3(3, 1);
  ASSERT_NO_THROW(TTriangle triangle(&point1, &point2, &point3));
}

TEST(triangle, can_throw_if_create_triangle_with_eqil_points_0)
{
  TPoint point(1, 1), point2(2, 2), point3(3, 3);
  ASSERT_ANY_THROW(TTriangle triangle(&point, &point2, &point3));
}

TEST(triangle, can_create_triangle_without_throws_2)
{
  ASSERT_NO_THROW(TTriangle triangle(1, 1, 2, 2, 3, 1));
}

TEST(triangle, can_throw_if_create_triangle_with_eqil_points)
{
  ASSERT_ANY_THROW(TTriangle triangle(1, 1, 2, 2, 3, 3));
}

TEST(triangle, can_create_triangle_without_throws_3)
{
  TTriangle triangle1(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(TTriangle triangle(triangle1));
}

TEST(triangle, can_get_A_X_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.GetXA());
}

TEST(triangle, can_get_A_Y_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.GetYA());
}

TEST(triangle, can_get_B_X_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.GetXB());
}

TEST(triangle, can_get_B_Y_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.GetYB());
}

TEST(triangle, can_get_C_X_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.GetXC());
}

TEST(triangle, can_get_C_Y_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.GetYC());
}

TEST(triangle, can_get_A_X_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  EXPECT_EQ(triangle.GetXA(), 1);
}

TEST(triangle, can_get_A_Y_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  EXPECT_EQ(triangle.GetYA(), 1);
}

TEST(triangle, can_get_B_X_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  EXPECT_EQ(triangle.GetXB(), 2);
}

TEST(triangle, can_get_B_Y_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  EXPECT_EQ(triangle.GetYB(), 2);
}

TEST(triangle, can_get_C_X_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  EXPECT_EQ(triangle.GetXC(), 3);
}

TEST(triangle, can_get_C_Y_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  EXPECT_EQ(triangle.GetYC(), 1);
}

TEST(triangle, can_set_A_X_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.SetXA(2));
}

TEST(triangle, can_throw_if_set_equil_A_X)
{
  TTriangle triangle(2, 1, 2, 2, 3, 3);
  ASSERT_ANY_THROW(triangle.SetXA(1));
}

TEST(triangle, can_set_A_Y_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.SetYA(2));
}

TEST(triangle, can_throw_if_set_equil_A_Y)
{
  TTriangle triangle(1, 2, 2, 2, 3, 3);
  ASSERT_ANY_THROW(triangle.SetYA(1));
}

TEST(triangle, can_set_B_X_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.SetXB(1));
}

TEST(triangle, can_throw_if_set_equil_B_X)
{
  TTriangle triangle(1, 1, 1, 2, 3, 3);
  ASSERT_ANY_THROW(triangle.SetXB(2));
}

TEST(triangle, can_set_B_Y_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.SetYB(1));
}

TEST(triangle, can_throw_if_set_equil_B_Y)
{
  TTriangle triangle(1, 1, 2, 1, 3, 3);
  ASSERT_ANY_THROW(triangle.SetYB(2));
}

TEST(triangle, can_set_C_X_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.SetXC(2));
}

TEST(triangle, can_throw_if_set_equil_C_X)
{
  TTriangle triangle(1, 1, 2, 2, 1, 3);
  ASSERT_ANY_THROW(triangle.SetXC(3));
}

TEST(triangle, can_set_C_Y_without_throws)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_NO_THROW(triangle.SetYC(2));
}

TEST(triangle, can_throw_if_set_equil_C_Y)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  ASSERT_ANY_THROW(triangle.SetYC(3));
}

TEST(triangle, can_set_A_X_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  triangle.SetXA(2);
  EXPECT_EQ(triangle.GetXA(), 2);
}

TEST(triangle, can_set_A_Y_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  triangle.SetYA(2);
  EXPECT_EQ(triangle.GetYA(), 2);
}

TEST(triangle, can_set_B_X_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  triangle.SetXB(1);
  EXPECT_EQ(triangle.GetXB(), 1);
}

TEST(triangle, can_set_B_Y_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  triangle.SetYB(1);
  EXPECT_EQ(triangle.GetYB(), 1);
}

TEST(triangle, can_set_C_X_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  triangle.SetXC(2);
  EXPECT_EQ(triangle.GetXC(), 2);
}

TEST(triangle, can_set_C_Y_correct)
{
  TTriangle triangle(1, 1, 2, 2, 3, 1);
  triangle.SetYC(2);
  EXPECT_EQ(triangle.GetYC(), 2);
}