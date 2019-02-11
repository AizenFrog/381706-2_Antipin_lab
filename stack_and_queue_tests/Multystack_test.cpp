#include <gtest.h>
#include "Multystack.h"

TEST(Multistack, can_create_multystack_with_positive_len)
{
	ASSERT_NO_THROW(Multistack<int> M(5, 20));
}

TEST(Multistack, can_throw_if_create_multystack_with_negative_len)
{
	ASSERT_ANY_THROW(Multistack<int> M(-1, -2));
}

TEST(Multistack, can_throw_if_create_multystack_with_more_counts_than_len)
{
	ASSERT_ANY_THROW(Multistack<int> M(10, 5));
}

TEST(Multistack, can_create_multistack_using_other_multistack)
{
  Multistack<int> M(5, 20);
  ASSERT_NO_THROW(Multistack<int> B(M));
}

TEST(Multistack, can_put_item_into_stack_without_throws)
{
  Multistack<int> M(3, 5);
  ASSERT_NO_THROW(M.Put(0, 10));
}

TEST(Multistack, can_get_item_from_stack_without_throws)
{
  Multistack<int> M(3, 5);
  M.Put(0, 10);
  ASSERT_NO_THROW(M.Get(0));
}

TEST(Multistack, can_put_item_into_stack)
{
	Multistack<int> M(3, 5);
	M.Put(0, 10);
    M.Put(0, 10);
    M.Put(0, 10);
    int m = M.Get(0);
	EXPECT_EQ(10, m);
}

TEST(Multistack, can_put_item_into_full_stack_with_resise_without_throws_0)
{
  Multistack<int> M(3, 5);
  M.Put(2, 10);
  ASSERT_NO_THROW(M.Put(2, 10));
}

TEST(Multistack, can_put_item_into_full_stack_with_resise_without_throws)
{
  Multistack<int> M(3, 5);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(0, 10);
  ASSERT_NO_THROW(M.Put(0, 10));
}

TEST(Multistack, can_put_item_into_full_stack_with_resise_without_throws_2)
{
  Multistack<int> M(3, 10);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(1, 10);
  M.Put(1, 10);
  ASSERT_NO_THROW(M.Put(1, 10));
}

TEST(Multistack, can_put_item_into_stack_with_resise_without_throws_3)
{
  Multistack<int> M(3, 7);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(1, 10);
  M.Put(1, 10);
  ASSERT_NO_THROW(M.Put(2, 10));
}

TEST(Multistack, can_get_item_from_full_stack_with_resise_without_throws)
{
  Multistack<int> M(3, 7);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(0, 10);
  M.Put(1, 10);
  M.Put(1, 10);
  M.Put(2, 10);
  ASSERT_NO_THROW(M.Get(0));
}

TEST(Multistack, can_get_item_from_stack)
{
	Multistack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	EXPECT_EQ(5, M.Get(0));
}

TEST(Multistack, can_messege_if_stack_is_full)
{
	Multistack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	EXPECT_EQ(1, M.IsFull(0));
}

TEST(Multistack, can_messege_if_stack_is_empty)
{
	Multistack<int> M(3, 5);
	EXPECT_EQ(1, M.IsEmpty(0));
}

//#define PUBLICMETHODS
#ifdef PUBLICMETHODS
TEST(Multistack, can_calculate_free_memory_in_all_stacks)
{
	Multistack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	EXPECT_EQ(3, M.CalcFree());
}

TEST(Multistack, can_resize1_free_memory_in_all_stacks)
{
	Multistack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	EXPECT_EQ(1, M.Resize(0));
}

TEST(Multistack, can_resize2_free_memory_in_all_stacks)
{
	Multistack<int> M(3, 10);
	M.Put(1, 10);
	M.Put(1, 8);
	M.Put(1, 5);
	EXPECT_EQ(1, M.Resize(1));
}

TEST(Multistack, can_resize_if_no_free_memory_in_all_stacks)
{
	Multistack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	M.Put(1, 3);
	M.Put(2, 1);
	EXPECT_EQ(0, M.Resize(0));
}

TEST(Multistack, can_resize_if_have_1_slot_free_memory)
{
	Multistack<int> M(3, 5);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 5);
	M.Put(2, 1);
	EXPECT_EQ(1, M.Resize(0));
}

TEST(Multistack, can_resize_and_return_item)
{
	Multistack<int> M(3, 6);
	M.Put(0, 10);
	M.Put(0, 8);
	M.Put(0, 1);
	EXPECT_EQ(1, M.Get(0));
	//ASSERT_NO_THROW(M.Get(0));
}

#endif