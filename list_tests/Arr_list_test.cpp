#include "Arr_List.h"
#include <gtest.h>

TEST(arr_list, can_create_array_list)
{
  ASSERT_NO_THROW(ArrList<int> A(5));
}

TEST(arr_list, can_throw_if_create_array_list_with_negative_size)
{
  ASSERT_ANY_THROW(ArrList<int> A(-5));
}

TEST(arr_list, can_report_if_array_list_is_empty)
{
  ArrList<int> A(5);
  EXPECT_EQ(A.IsEmpty(), 1);
}

TEST(arr_list, can_report_if_array_list_is_not_empty)
{
  ArrList<int> A(5);
  A.PutEnd(100);
  EXPECT_EQ(A.IsEmpty(), 0);
}

TEST(arr_list, can_report_if_array_list_is_full)
{
  ArrList<int> A(5);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutEnd(100);
  EXPECT_EQ(A.IsFull(), 1);
}

TEST(arr_list, can_report_if_array_list_is_not_full)
{
  ArrList<int> A(5);
  A.PutEnd(100);
  EXPECT_EQ(A.IsFull(), 0);
}

TEST(arr_list, can_put_element_to_start_of_array_list)
{
  ArrList<int> A(5);
  ASSERT_NO_THROW(A.PutStart(100));
}

TEST(arr_list, can_throw_if_put_element_to_start_of_full_array_list)
{
  ArrList<int> A(5);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutEnd(100);
  ASSERT_ANY_THROW(A.PutStart(100));
}

TEST(arr_list, can_return_element_from_start_of_array_list)
{
  ArrList<int> A(5);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutStart(50);
  EXPECT_EQ(A.GetStart(), 50);
}

TEST(arr_list, can_throw_if_put_element_from_start_of_empty_array_list)
{
  ArrList<int> A(5);
  ASSERT_ANY_THROW(A.GetStart());
}

TEST(arr_list, can_put_element_to_the_end_of_array_list)
{
  ArrList<int> A(5);
  ASSERT_NO_THROW(A.PutEnd(100));
}

TEST(arr_list, can_throw_if_put_element_to_the_end_of_full_array_list)
{
  ArrList<int> A(5);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutEnd(100);
  A.PutEnd(100);
  ASSERT_ANY_THROW(A.PutEnd(100));
}

TEST(arr_list, can_return_element_from_the_end_of_array_list)
{
  ArrList<int> A(5);
  A.PutStart(100);
  A.PutStart(100);
  A.PutEnd(50);
  EXPECT_EQ(A.GetEnd(), 50);
}

TEST(arr_list, can_throw_if_put_element_from_the_end_of_empty_array_list)
{
  ArrList<int> A(5);
  ASSERT_ANY_THROW(A.GetEnd());
}

