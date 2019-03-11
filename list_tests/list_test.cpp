#include <gtest.h>
#include "List.h"

TEST(List, can_create_list_without_throws)
{
  ASSERT_NO_THROW(List<int> A);
}

TEST(List, can_return_true_if_list_is_empty)
{
  List<int> A;
  EXPECT_EQ(A.IsEmpty(), 1);
}

TEST(List, can_return_false_if_list_is_not_empty)
{
  List<int> A;
  A.InstFirst(5);
  EXPECT_EQ(A.IsEmpty(), 0);
}

TEST(List, can_return_wright_value)
{
  List<int> A;
  A.InstFirst(5);
  EXPECT_EQ(A.GetValue(0), 5);
}

TEST(List, can_return_list_lenght)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(5);
  A.InstFirst(5);
  EXPECT_EQ(A.GetListLen(), 3);
}

TEST(List, can_instal_first_slot)
{
  List<int> A;
  ASSERT_NO_THROW(A.InstFirst(5));
}

TEST(List, can_throw_if_delete_first_item_in_empty_list)
{
  List<int> A;
  ASSERT_ANY_THROW(A.DelFirst());
}

TEST(List, can_delete_first_item)
{
  List<int> A;
  A.InstFirst(5);
  A.DelFirst();
  EXPECT_EQ(1, A.IsEmpty());
}

TEST(List, can_instal_last_slot_without_throw)
{
  List<int> A;
  ASSERT_NO_THROW(A.InstLast(5));
}

TEST(List, can_instal_last_slot)
{
  List<int> A;
  A.InstFirst(10);
  ASSERT_NO_THROW(A.InstLast(5));
}

TEST(List, can_throw_if_instal_in_custom_slot_out_of_range)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  ASSERT_ANY_THROW(A.InstCustom(3, 15));
}

TEST(List, can_instal_in_custom_slot_if_nomber_is_0)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  ASSERT_NO_THROW(A.InstCustom(0, 15));
}

TEST(List, can_instal_in_custom_slot)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  ASSERT_NO_THROW(A.InstCustom(1, 15));
}

TEST(List, can_instal_in_last_custom_slot)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  ASSERT_NO_THROW(A.InstCustom(2, 15));
}

TEST(List, can_return_a_custom_item)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(1, 15);
  EXPECT_EQ(A.GetValue(1), 15);
}

TEST(List, can_return_custom_item_if_nomber_is_0)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(0, 15);
  EXPECT_EQ(A.GetValue(0), 15);
}

TEST(List, can_return_a_last_custom_item)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(2, 15);
  EXPECT_EQ(A.GetValue(2), 15);
}

TEST(List, can_throw_if_delete_custom_item_out_of_range)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(0, 15);
  ASSERT_ANY_THROW(A.DelCustom(3));
}

TEST(List, can_throw_if_delete_custom_item_in_empty_list)
{
  List<int> A;
  ASSERT_ANY_THROW(A.DelCustom(3));
}

TEST(List, can_throw_if_delete_custom_0)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(0, 15);
  ASSERT_NO_THROW(A.DelCustom(0));
}

TEST(List, can_throw_if_delete_custom_item_0_1)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(0, 15);
  A.DelCustom(0);
  EXPECT_EQ(10, A.GetValue(0));
}

TEST(List, can_throw_if_delete_custom)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(0, 15);
  ASSERT_NO_THROW(A.DelCustom(1));
}

TEST(List, can_throw_if_delete_custom_item_1)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(0, 15);
  A.DelCustom(1);
  EXPECT_EQ(5, A.GetValue(1));
}

TEST(List, can_throw_if_delete_custom_last)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(0, 15);
  ASSERT_NO_THROW(A.DelCustom(2));
}

TEST(List, can_throw_if_delete_custom_item_last_1)
{
  List<int> A;
  A.InstFirst(5);
  A.InstFirst(10);
  A.InstCustom(0, 15);
  A.DelCustom(2);
  ASSERT_ANY_THROW(A.GetValue(2));
}