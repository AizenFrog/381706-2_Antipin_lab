#include <gtest.h>
#include "List_Item.h"

TEST(List_Item, can_create_list_item)
{
  ASSERT_NO_THROW(TDatLink<int> li(10, NULL));
}

TEST(List_Item, can_link_2_list_items)
{
  TDatLink<int> li_1(10, NULL);
  ASSERT_NO_THROW(TDatLink<int> li_2(10, &li_1));
}

TEST(List_Item, can_set_mem_without_any_throw)
{
  TDatLink<int> li(10, NULL);
  ASSERT_NO_THROW(li.SetMem(15));
}

TEST(List_Item, can_get_mem_without_any_throw)
{
  TDatLink<int> li(10, NULL);
  ASSERT_NO_THROW(li.GetMem());
}

TEST(List_Item, can_get_right_mem)
{
  TDatLink<int> li(10, NULL);
  EXPECT_EQ(10, li.GetMem());
}

TEST(List_Item, can_set_item_and_return_it_right)
{
  TDatLink<int> li(10, NULL);
  li.SetMem(15);
  EXPECT_EQ(15, li.GetMem());
}

TEST(List_Item, can_right_set_TDatLink)
{
  TDatLink<int> li_1(10, NULL);
  TDatLink<int> li_2(5, NULL);
  ASSERT_NO_THROW(li_2.Set_m(&li_1));
}

TEST(List_Item, can_set_right_TDatLink)
{
  TDatLink<int> li_1(10, NULL);
  TDatLink<int> li_2(5, NULL);
  li_2.Set_m(&li_1);
  EXPECT_EQ(&li_1, li_2.GetNextLink());
}