#include <gtest.h>
#include <SeeTable.h>

TEST(seetables, can_create_table_without_throws)
{
	ASSERT_NO_THROW(TTable<int> table(5));
}