#include "Vector.h"
#include <gtest.h>

TEST(Vector, can_create_vector_with_positive_lenght)
{
	ASSERT_NO_THROW(Vector<int> bf(3));
}

TEST(Vector, can_throw_when_create_vector_with_zero_lenght)
{
	ASSERT_ANY_THROW(Vector<int> bf(0));
}

TEST(Vector, can_return_vector_size)
{
	Vector<int> bf(3);
	EXPECT_EQ(3, bf.GetSize());
}

TEST(Vector, can_return_element_with_negative_or_more_sise_index)
{
	Vector<int> bf(3);
	ASSERT_ANY_THROW(bf.GetValue(3));
}

TEST(Vector, can_return_element_with_normal_index)
{
	Vector<int> bf(3);
	ASSERT_NO_THROW(bf.GetValue(2));
}

TEST(Vector, can_return_i_element)
{
	Vector<int> bf(3);
	bf[1] = 4;
	EXPECT_EQ(4, bf[1]);
}

TEST(Vector, can_assign_vector)
{
	Vector<int> bf(2) , bp(2);
	bf[0] = 5;
	bp = bf;
	EXPECT_EQ(5, bp[0]);
}

TEST(Vector, can_compare_vectors)
{
	Vector<int> bf(2), bp(2);
	bf[1] = 5;
	bf[0] = 3;
	bp = bf;
	EXPECT_EQ(1, bf == bp);
}

TEST(Vector, can_compare_different_vectors)
{
	Vector<int> bf(2), bp(3);
	bf[1] = 5;
	bf[0] = 3;
	EXPECT_EQ(0, bf == bp);
}

TEST(Vector, can_compare_different_vectors_with_not_equal_operator)
{
	Vector<int> bf(2), bp(2);
	bf[1] = 5;
	bf[0] = 3;
	bp[0] = 2;
	EXPECT_EQ(1, bf != bp);
}

TEST(Vector, can_compare_vectorswith_different_lenght_with_not_equal_operator)
{
	Vector<int> bf(2), bp(3);
	bf[1] = 5;
	bf[0] = 3;
	bp[0] = 3;
	bp[1] = 5;
	EXPECT_EQ(1, bf != bp);
}

TEST(Vector, can_add_vectors)
{
	Vector<int> bf(2), bp(2), bd(2);
	for (int i = 0; i < 2; i++)
		bp[i] = bf[i] = i + 1;
	bd = bp + bf;
	EXPECT_EQ(2, bd[0]);
	EXPECT_EQ(4, bd[1]);
}

TEST(Vector, can_subtract_vectors)
{
	Vector<int> bf(2), bp(2), bd(2);
	for (int i = 0; i < 2; i++)
		bp[i] = bf[i] = i + 1;
	bd = bp - bf;
	EXPECT_EQ(0, bd[0]);
	EXPECT_EQ(0, bd[1]);
}

TEST(Vector, can_conduct_vector_multiplication)
{
	Vector<int> bf(2), bp(2);
	for (int i = 0; i < 2; i++)
		bp[i] = bf[i] = i + 1;
	EXPECT_EQ(5, bf * bp);
}

TEST(Vector, can_throw_when_vector_multiplication_with_different_lenght)
{
	Vector<int> bf(2), bp(3);
	for (int i = 0; i < 2; i++)
		bp[i] = bf[i] = i + 1;
	ASSERT_ANY_THROW(bf * bp);
}

TEST(Vector, can_add_scalar_to_vector)
{
	Vector<int> bf(2);
	for (int i = 0; i < 2; i++)
		bf[i] = i + 1;
	bf = bf + 5;
	EXPECT_EQ(6, bf[0]);
	EXPECT_EQ(7, bf[1]);
}

TEST(Vector, can_subtract_scalar_to_vector)
{
	Vector<int> bf(2);
	for (int i = 0; i < 2; i++)
		bf[i] = i + 1;
	bf = bf - 5;
	EXPECT_EQ(-4, bf[0]);
	EXPECT_EQ(-3, bf[1]);
}

TEST(Vector, can_multiply_scalar_to_vector)
{
	Vector<int> bf(2);
	for (int i = 0; i < 2; i++)
		bf[i] = i + 1;
	bf = bf * 5;
	EXPECT_EQ(5, bf[0]);
	EXPECT_EQ(10, bf[1]);
}