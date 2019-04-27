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

TEST(sorttables, can_add_element_to_sort_table_without_throws)
{
	TSortTable<int> table(10);
	String key("key");
	TElem<int> elem(10, key);
	table.Add(elem);
}

TEST(sorttables, can_add_element_to_sort_table_without_throws_1)
{
	TSortTable<int> table(5);
	String key("key");
	TElem<int> elem(10, key);
	EXPECT_EQ(table.Add(elem), 1);
}

TEST(sorttables, can_add_element_to_sort_table_with_resize_without_throws_0)
{
	TSortTable<int> table(3);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(10, key2);
	TElem<int> elem3(10, key3);
	TElem<int> elem4(5, key4);
	table.Add(elem3);
	table.Add(elem1);
	table.Add(elem2);
	ASSERT_NO_THROW(table.Add(elem4));
}

TEST(sorttables, can_add_element_to_sort_table_with_resize_without_throws_1)
{
	TSortTable<int> table(3);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(10, key2);
	TElem<int> elem3(10, key3);
	TElem<int> elem4(5, key4);
	table.Add(elem3);
	table.Add(elem1);
	table.Add(elem2);
	EXPECT_EQ(table.Add(elem4), 1);
}

TEST(sorttables, can_add_element_to_sort_table_correct)
{
	TSortTable<int> table(5);
	String key("key");
	TElem<int> elem(10, key);
	table.Add(elem);
	EXPECT_EQ(table[key], 10);
}