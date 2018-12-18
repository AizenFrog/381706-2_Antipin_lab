#include <gtest.h>
#include "Multystack.h"

TEST(Multystack, can_create_multystack_with_positive_len)
{
	ASSERT_NO_THROW(Multystack<int> M(5, 20));
}

TEST(Multystack, can_throw_if_create_multystack_with_negative_len)
{
	ASSERT_ANY_THROW(Multystack<int> M(-1, -2));
}

TEST(Multystack, can_throw_if_create_multystack_with_more_counts_than_len)
{
	ASSERT_ANY_THROW(Multystack<int> M(10, 5));
}

TEST(Multystack, can_put_item_into_stack)
{
	Multystack<int> M(3, 5);
	M.Put(0, 10);
	EXPECT_EQ(10, M.Get(0));
}

TEST(Multystack, can_get_item_from_stack)
{
	Multystack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	EXPECT_EQ(5, M.Get(0));
}

TEST(Multystack, can_messege_if_stack_is_full)
{
	Multystack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	EXPECT_EQ(1, M.IsFull(0));
}

TEST(Multystack, can_messege_if_stack_is_empty)
{
	Multystack<int> M(3, 5);
	EXPECT_EQ(1, M.IsEmpty(0));
}

//#define PUBLICMETHODS
#ifdef PUBLICMETHODS
TEST(Multystack, can_calculate_free_memory_in_all_stacks)
{
	Multystack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	EXPECT_EQ(3, M.CalcFree());
}

TEST(Multystack, can_resize1_free_memory_in_all_stacks)
{
	Multystack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	EXPECT_EQ(1, M.Resize(0));
}

TEST(Multystack, can_resize2_free_memory_in_all_stacks)
{
	Multystack<int> M(3, 10);
	M.Put(1, 10);
	M.Put(1, 8);
	M.Put(1, 5);
	EXPECT_EQ(1, M.Resize(1));
}

TEST(Multystack, can_resize_if_no_free_memory_in_all_stacks)
{
	Multystack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	M.Put(1, 3);
	M.Put(2, 1);
	EXPECT_EQ(0, M.Resize(0));
}

TEST(Multystack, can_resize_if_have_1_slot_free_memory)
{
	Multystack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	M.Put(2, 1);
	EXPECT_EQ(1, M.Resize(0));
}

TEST(Multystack, can_resize_and_return_item)
{
	Multystack<int> M(3, 6);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 1);
	EXPECT_EQ(1, M.Get(0));
	//ASSERT_NO_THROW(M.Get(0));
}

#endif