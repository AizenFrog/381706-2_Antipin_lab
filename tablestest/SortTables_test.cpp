#include <gtest.h>
#include "SortTable.h"

TEST(sorttables, can_create_sort_table_without_throws)
{
	ASSERT_NO_THROW(TSortTable<int> table);
}

TEST(sorttables, can_creaate_sort_table_with_some_size_without_throws)
{
	ASSERT_NO_THROW(TSortTable<int> table(10));
}