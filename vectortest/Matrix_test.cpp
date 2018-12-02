#include <gtest.h>
#include "Matrix.h"

TEST(Matrix, can_create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(Matrix<int> bf(-3));
}

TEST(Matrix, can_create_matrix_with_positive_size)
{
	ASSERT_NO_THROW(Matrix<int> bf(3));
}

TEST(Matrix, can_assign_matrix)
{
	Matrix<int> bf(2), bp(2);
	bf[0][0] = 1;
	bf[0][1] = 2;
	bf[1][1] = 3;
	bp = bf;
	EXPECT_EQ(1, bf[0][0]);
	EXPECT_EQ(2, bf[0][1]);
	EXPECT_EQ(3, bf[1][1]);
}

TEST(Matrix, can_compare_matrixs)
{
	Matrix<int> bf(2), bp(2);
	bf[0][0] = 5;
	bf[0][1] = 3;
	bf[1][1] = 1;
	bp = bf;
	EXPECT_EQ(1, bf == bp);
}

TEST(Matrix, can_compare_different_matrixs)
{
	Matrix<int> bf(2), bp(0);
	bf[0][0] = 5;
	bf[0][1] = 3;
	bf[1][1] = 1;
	EXPECT_EQ(0, bf == bp);
}

TEST(Matrix, can_add_matrixs)
{
	Matrix<int> bf(2), bp(2), bd(2);
	bf[0][0] = 5;
	bf[0][1] = 3;
	bf[1][1] = 1;
	bp = bf;
	bd = bp + bf;
	EXPECT_EQ(10, bd[0][0]);
	EXPECT_EQ(6, bd[0][1]);
	EXPECT_EQ(2, bd[1][1]);
}

TEST(Matrix, can_throw_if_add_matrixs_with_different_lenght)
{
	Matrix<int> bf(2), bp(3);
	ASSERT_ANY_THROW(bf + bp);
}

TEST(Matrix, can_subtract_matrixs)
{
	Matrix<int> bf(2), bp(2), bd(2);
	bf[0][0] = 5;
	bf[0][1] = 3;
	bf[1][1] = 1;
	bp[0][0] = 3;
	bp[0][1] = 2;
	bp[1][1] = 1;
	bd = bf - bp;
	EXPECT_EQ(2, bd[0][0]);
	EXPECT_EQ(1, bd[0][1]);
	EXPECT_EQ(0, bd[1][1]);
}

TEST(Matrix, can_throw_if_subtract_matrixs_with_different_lenght)
{
	Matrix<int> bf(2), bp(3);
	ASSERT_ANY_THROW(bf - bp);
}

TEST(Matrix, can_multiply_matrixs)
{
	Matrix<int> bf(2), bp(2), bd(2);
	bf[0][0] = 5;
	bf[0][1] = 3;
	bf[1][1] = 1;
	bp[0][0] = 3;
	bp[0][1] = 2;
	bp[1][1] = 1;
	bd = bf * bp;
	EXPECT_EQ(15, bd[0][0]);
	EXPECT_EQ(13, bd[0][1]);
	EXPECT_EQ(1, bd[1][1]);
}