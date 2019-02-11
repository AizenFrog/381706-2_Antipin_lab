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

//#define TIMECHECK
#ifdef TIMECHECK

TEST(Multistack, resize_time_check_with_100000)
{
  Multistack<int> M(160, 100000);
  for (int i = 0; i < 100000; i++)
  {
    int j = 0;
    if (i % 1000 == 0)
      j++;
    M.Put(j, i);
   
  }
  M.GetResizeCount();
}

TEST(Multistack, resize_time_check_with_1000000)
{
  Multistack<int> M(160, 1000000);
  for (int i = 0; i < 1000000; i++)
  {
    int j = 0;
    if (i % 10000 == 0)
      j++;
    M.Put(j, i);

  }
  M.GetResizeCount();
}

TEST(Multistack, resize_time_check_with_10000000)
{
  Multistack<int> M(160, 10000000);
  for (int i = 0; i < 10000000; i++)
  {
    int j = 0;
    if (i % 100000 == 0)
      j++;
    M.Put(j, i);

  }
  M.GetResizeCount();
}

#endif