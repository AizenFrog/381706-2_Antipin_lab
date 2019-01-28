#include <gtest.h>
#include "Monom.h"

TEST(monom, can_create_monom)
{
  unsigned int B[]{ 3, 2, 1 };
  ASSERT_NO_THROW(Monom A(3, B, 3.14));
}

TEST(monom, can_get_monom_size)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  EXPECT_EQ(A.GetN(), 3);
}

TEST(monom, can_get_monom_coefficient)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  EXPECT_EQ(A.GetC(), 3.14);
}

TEST(monom, can_get_monom_power)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  EXPECT_EQ(A.GetPower()[0], B[0]);
  EXPECT_EQ(A.GetPower()[1], B[1]);
  EXPECT_EQ(A.GetPower()[2], B[2]);
}

TEST(monom, can_throw_if_set_new_negetive_size)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  ASSERT_ANY_THROW(A.SetN(-1));
}

TEST(monom, can_set_new_size_without_throws)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  ASSERT_NO_THROW(A.SetN(4));
}

TEST(monom, can_set_new_size)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  A.SetN(4);
  EXPECT_EQ(A.GetN(), 4);
}

TEST(monom, can_set_new_coefficient_without_throws)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  ASSERT_NO_THROW(A.SetC(6.28));
}

TEST(monom, can_set_new_coefficient)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  A.SetC(6.28);
  EXPECT_EQ(A.GetC(), 6.28);
}

TEST(monom, can_set_new_power_without_throws)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3 };
  Monom A(3, B, 3.14);
  ASSERT_NO_THROW(A.SetPower(C));
}

TEST(monom, can_throw_if_set_new_power_with_negative_element)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, -2, 3 };
  Monom A(3, B, 3.14);
  ASSERT_NO_THROW(A.SetPower(C));
}

TEST(monom, can_set_new_power)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3 };
  Monom A(3, B, 3.14);
  A.SetPower(C);
  EXPECT_EQ(A.GetPower()[0], C[0]);
  EXPECT_EQ(A.GetPower()[1], C[1]);
  EXPECT_EQ(A.GetPower()[2], C[2]);
}

TEST(monom, can_assign_monom_to_yourself_without_throws)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  ASSERT_NO_THROW(A = A);
}

TEST(monom, can_assign_monom_to_yourself)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  A = A;
  EXPECT_EQ(A.GetC(), 3.14);
  EXPECT_EQ(A.GetN(), 3);
  EXPECT_EQ(A.GetPower()[0], B[0]);
  EXPECT_EQ(A.GetPower()[1], B[1]);
  EXPECT_EQ(A.GetPower()[2], B[2]);
}

TEST(monom, can_assign_without_throws)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3 };
  Monom A(3, B, 3.14);
  Monom D(3, C, 5);
  ASSERT_NO_THROW(A = D);
}

TEST(monom, can_assign_monoms)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3 };
  Monom A(3, B, 3.14);
  Monom D(3, C, 5);
  A = D;
  EXPECT_EQ(A.GetC(), 5);
  EXPECT_EQ(A.GetN(), 3);
  EXPECT_EQ(A.GetPower()[0], C[0]);
  EXPECT_EQ(A.GetPower()[1], C[1]);
  EXPECT_EQ(A.GetPower()[2], C[2]);
}

TEST(monom, can_add_monoms_with_different_size)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3, 4 };
  Monom A(3, B, 3.14);
  Monom D(4, C, 5);
  ASSERT_ANY_THROW(A + D);
}

TEST(monom, can_add_monoms_with_different_power)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3,};
  Monom A(3, B, 3.14);
  Monom D(3, C, 5);
  ASSERT_ANY_THROW(A + D);
}

TEST(monom, can_add_monoms)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  Monom D(3, C, 5);
  A = A + D;
  EXPECT_EQ(A.GetC(), 8.14);
  EXPECT_EQ(A.GetN(), 3);
  EXPECT_EQ(A.GetPower()[0], C[0]);
  EXPECT_EQ(A.GetPower()[1], C[1]);
  EXPECT_EQ(A.GetPower()[2], C[2]);
}

TEST(monom, can_subtract_monoms_with_different_size)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3, 4 };
  Monom A(3, B, 3.14);
  Monom D(4, C, 5);
  ASSERT_ANY_THROW(A - D);
}

TEST(monom, can_subtract_monoms_with_different_power)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3, };
  Monom A(3, B, 3.14);
  Monom D(3, C, 5);
  ASSERT_ANY_THROW(A - D);
}

TEST(monom, can_subtract_monoms)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 3);
  Monom D(3, C, 5);
  A = D - A;
  EXPECT_EQ(A.GetC(), 2);
  EXPECT_EQ(A.GetN(), 3);
  EXPECT_EQ(A.GetPower()[0], C[0]);
  EXPECT_EQ(A.GetPower()[1], C[1]);
  EXPECT_EQ(A.GetPower()[2], C[2]);
}

TEST(monom, can_multiply_monoms_with_different_size)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3, 4 };
  Monom A(3, B, 3.14);
  Monom D(4, C, 5);
  ASSERT_ANY_THROW(A * D);
}

TEST(monom, can_multiply_monoms)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 3, 5 };
  unsigned int E[]{ 4, 5, 6 };
  Monom A(3, B, 3);
  Monom D(3, C, 5);
  A = A * D;
  EXPECT_EQ(A.GetC(), 15);
  EXPECT_EQ(A.GetN(), 3);
  EXPECT_EQ(A.GetPower()[0], E[0]);
  EXPECT_EQ(A.GetPower()[1], E[1]);
  EXPECT_EQ(A.GetPower()[2], E[2]);
}

TEST(monom, can_compare_monoms_with_different_size)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3, 4 };
  Monom A(3, B, 3.14);
  Monom D(4, C, 5);
  ASSERT_ANY_THROW(A == D);
}

TEST(monom, can_compare_monoms_1)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3 };
  Monom A(3, B, 3.14);
  Monom D(3, C, 5);
  EXPECT_EQ(A == D, 0);
}

TEST(monom, can_compare_monoms_2)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  Monom D(3, C, 5);
  EXPECT_EQ(A == D, 0);
}

TEST(monom, can_compare_monoms_3)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 5);
  Monom D(3, C, 5);
  EXPECT_EQ(A == D, 1);
}

TEST(monom, can_compare_more_monoms_with_defferent_size)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3, 4};
  Monom A(3, B, 3.14);
  Monom D(4, C, 5);
  ASSERT_ANY_THROW(A > D);
}

TEST(monom, can_compare_more_monoms_1)
{
  unsigned int B[]{ 1, 2, 3 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  Monom D(3, C, 5);
  EXPECT_EQ(A > D, 0);
}

TEST(monom, can_compare_more_monoms_2)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 3);
  Monom D(3, C, 5);
  EXPECT_EQ(A > D, 0);
}

TEST(monom, can_compare_more_monoms_3)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 6);
  Monom D(3, C, 5);
  EXPECT_EQ(A > D, 1);
}

TEST(monom, can_compare_more_monoms_4)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3 };
  Monom A(3, B, 3);
  Monom D(3, C, 5);
  EXPECT_EQ(A > D, 1);
}

TEST(monom, can_compare_less_monoms_with_defferent_size)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 1, 2, 3, 4 };
  Monom A(3, B, 3.14);
  Monom D(4, C, 5);
  ASSERT_ANY_THROW(A < D);
}

TEST(monom, can_compare_less_monoms_1)
{
  unsigned int B[]{ 1, 2, 3 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 3.14);
  Monom D(3, C, 5);
  EXPECT_EQ(D < A, 0);
}

TEST(monom, can_compare_less_monoms_2)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 3);
  Monom D(3, C, 5);
  EXPECT_EQ(D < A, 0);
}

TEST(monom, can_compare_less_monoms_3)
{
  unsigned int B[]{ 3, 2, 1 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 4);
  Monom D(3, C, 5);
  EXPECT_EQ(A < D, 1);
}

TEST(monom, can_compare_less_monoms_4)
{
  unsigned int B[]{ 1, 2, 3 };
  unsigned int C[]{ 3, 2, 1 };
  Monom A(3, B, 3);
  Monom D(3, C, 5);
  EXPECT_EQ(A < D, 1);
}