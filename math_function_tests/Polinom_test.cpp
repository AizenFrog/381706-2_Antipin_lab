#include <gtest.h>
#include "Polinom.h"

TEST(polinom, can_create_polinom)
{
  ASSERT_NO_THROW(Polinom A);
}

TEST(polinom, can_transformate_list_monoms_to_polinom)
{
  unsigned int B[]{ 3, 2, 1 };
  Monom C(3, B, 3.14);
  List<Monom> A;
  A.InstFirst(C);
  A.InstFirst(C);
  A.InstFirst(C);
  ASSERT_NO_THROW(Polinom P(A));
}

TEST(polinom, can_assign_polinom)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  Monom C(3, B, 3.14);
  P.InstFirst(C);
  P.InstFirst(C);
  Polinom Po;
  ASSERT_NO_THROW(Po = P);
}

TEST(polinom, can_throw_if_add_polinoms_with_different_lenght)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  Monom C(3, B, 3.14);
  P.InstFirst(C);
  P.InstFirst(C);
  Polinom Po;
  Po.InstFirst(C);
  ASSERT_ANY_THROW(P + Po);
}

TEST(polinom, can_add_polinoms_1)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  Monom C(3, B, 2);
  P.InstFirst(C);
  P.InstFirst(C);
  Polinom Po;
  Po.InstFirst(C);
  Po.InstFirst(C);
  Polinom rez;
  rez = P + Po;
  EXPECT_EQ(rez.GetValue(0).GetC(), 4);
  EXPECT_EQ(rez.GetValue(1).GetC(), 4);
}

TEST(polinom, can_add_polinoms_2)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  unsigned int A[]{ 1, 2, 3 };
  Monom C(3, B, 2);
  Monom D(3, A, 3);
  P.InstFirst(C);
  P.InstFirst(D);
  Polinom Po;
  Po.InstFirst(D);
  Po.InstFirst(C);
  Polinom rez;
  rez = P + Po;
  EXPECT_EQ(rez.GetValue(0).GetC(), 2);
  EXPECT_EQ(rez.GetValue(1).GetC(), 6);
  EXPECT_EQ(rez.GetValue(2).GetC(), 2);
}

TEST(polinom, can_throw_if_subtract_polinoms_with_different_lenght)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  Monom C(3, B, 3.14);
  P.InstFirst(C);
  P.InstFirst(C);
  Polinom Po;
  Po.InstFirst(C);
  ASSERT_ANY_THROW(P - Po);
}

TEST(polinom, can_subtract_polinoms_1)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  Monom C(3, B, 2);
  P.InstFirst(C);
  P.InstFirst(C);
  Polinom Po;
  Po.InstFirst(C);
  Po.InstFirst(C);
  Polinom rez;
  rez = P - Po;
  EXPECT_EQ(rez.GetValue(0).GetC(), 0);
  EXPECT_EQ(rez.GetValue(1).GetC(), 0);
}

TEST(polinom, can_subtract_polinoms_2)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  unsigned int A[]{ 1, 2, 3 };
  Monom C(3, B, 2);
  Monom D(3, A, 3);
  P.InstFirst(C);
  P.InstFirst(D);
  Polinom Po;
  Po.InstFirst(D);
  Po.InstFirst(C);
  Polinom rez;
  rez = P - Po;
  EXPECT_EQ(rez.GetValue(0).GetC(), -2);
  EXPECT_EQ(rez.GetValue(1).GetC(), 0);
  EXPECT_EQ(rez.GetValue(2).GetC(), 2);
}

TEST(polinom, can_multiply_polinoms)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  unsigned int A[]{ 1, 2, 3 };
  Monom C(3, B, 2);
  Monom D(3, A, 3);
  P.InstFirst(C);
  P.InstFirst(D);
  Polinom Po;
  Po.InstFirst(D);
  Po.InstFirst(C);
  Polinom rez;
  rez = P * Po;
  unsigned int rez_rower[]{ 4, 4, 4 };
  EXPECT_EQ(rez.GetValue(0).GetC(), 6);
  EXPECT_EQ(rez.GetValue(0).GetN(), 3);
  EXPECT_EQ(rez.GetValue(0).GetPower()[0], rez_rower[0]);
  EXPECT_EQ(rez.GetValue(0).GetPower()[1], rez_rower[1]);
  EXPECT_EQ(rez.GetValue(0).GetPower()[2], rez_rower[2]);
}

TEST(polinom, can_add_polinom_with_monom)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  unsigned int A[]{ 1, 2, 3 };
  Monom C(3, B, 2);
  Monom D(3, A, 3);
  P.InstFirst(C);
  P.InstFirst(C);
  ASSERT_NO_THROW(P += D);
}

TEST(polinom, can_add_polinom_with_monom_2)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  unsigned int A[]{ 1, 2, 3 };
  Monom C(3, B, 2);
  Monom D(3, A, 3);
  P.InstFirst(D);
  P.InstFirst(C);
  P += D;
  EXPECT_EQ(P.GetValue(1).GetC(), 6);
}

TEST(polinom, can_return_monom)
{
  Polinom P;
  unsigned int B[]{ 3, 2, 1 };
  Monom C(3, B, 2);
  P.InstFirst(C);
  P.InstFirst(C);
  EXPECT_EQ(P[1].GetC(), 2);
  EXPECT_EQ(P[1].GetN(), 3);
  EXPECT_EQ(P[1].GetPower()[0], B[0]);
  EXPECT_EQ(P[1].GetPower()[1], B[1]);
  EXPECT_EQ(P[1].GetPower()[2], B[2]);
}