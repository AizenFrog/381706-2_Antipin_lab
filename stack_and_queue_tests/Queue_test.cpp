#include <gtest.h>
#include "Queue.h"

TEST(Queue, can_create_queue_with_positive_len)
{
  ASSERT_NO_THROW(Queue<int> A(5));
}

TEST(Queue, can_create_queue_with_negative_len)
{
  ASSERT_ANY_THROW(Queue<int> A(-2));
}

TEST(Queue, can_put_item)
{
  Queue<int> A(3);
  A.Put(10);
  A.Put(5);
  EXPECT_EQ(10, A.Get());
}

TEST(Queue, can_throw_when_put_item_in_full_queue)
{
  Queue<int> A(3);
  A.Put(10);
  A.Put(5);
  A.Put(1);
  ASSERT_ANY_THROW(A.Put(3));
}

TEST(Queue, can_get_item)
{
  Queue<int> A(3);
  A.Put(10);
  A.Put(5);
  A.Put(2);
  EXPECT_EQ(10, A.Get());
}

TEST(Queue, can_get_without_delete_item)
{
  Queue<int> A(3);
  A.Put(10);
  A.Put(5);
  A.Put(2);
  EXPECT_EQ(10, A.GetWithoutDelete());
  EXPECT_EQ(10, A.GetWithoutDelete());
}

TEST(Queue, custom_put_and_get_item)
{
  Queue<int> A(3);
  A.Put(10);
  A.Put(5);
  A.Put(2);
  A.Get();
  A.Put(15);
  A.Get();
  EXPECT_EQ(2, A.Get());
  EXPECT_EQ(15, A.Get());
}

TEST(Queue, can_throw_when_get_item_in_empty_queue)
{
  Queue<int> A(3);
  ASSERT_ANY_THROW(A.Get());
}

TEST(Queue, can_report_if_queue_is_full)
{
  Queue<int> A(3);
  A.Put(10);
  A.Put(5);
  A.Put(2);
  EXPECT_EQ(1, A.IsFull());
}

TEST(Queue, can_report_if_queue_is_not_full)
{
  Queue<int> A(3);
  A.Put(10);
  EXPECT_EQ(0, A.IsFull());
}

TEST(Queue, can_report_if_queue_is_empty)
{
  Queue<int> A(3);
  EXPECT_EQ(1, A.IsEmpty());
}

TEST(Queue, can_report_if_queue_is_not_empty)
{
  Queue<int> A(3);
  A.Put(10);
  EXPECT_EQ(0, A.IsEmpty());
}