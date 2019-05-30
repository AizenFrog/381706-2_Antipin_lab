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

TEST(sorttables, can_search_element_to_sort_table_without_throws_0)
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
	table.Add(elem4);
	ASSERT_NO_THROW(table.Search(key3));
}

TEST(sorttables, can_search_element_to_sort_table_without_throws_1)
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
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	ASSERT_NO_THROW(table.Search(key4));
}

TEST(sorttables, can_search_element_to_sort_table_correct)
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
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	table.Add(elem4);
	EXPECT_EQ(table.Search(key3) == elem3, 1);
}

TEST(sorttables, can_add_element_to_sort_table_without_throws_0_1)
{
	TSortTable<int> table(5);
	ASSERT_NO_THROW(table.Add(10));
}

TEST(sorttables, can_add_element_to_sort_table_without_throws_0_2)
{
	TSortTable<int> table(5);
	String key("key");
	TElem<int> elem(10, key);
	table.Add(elem);
	ASSERT_NO_THROW(table.Add(25));
}

TEST(sorttables, can_add_element_to_sort_table_without_throws_1_1)
{
	TSortTable<int> table(5);
	String tmp = table.Add(25);
	EXPECT_EQ(tmp.GetArrChar()[0], 'F');
	EXPECT_EQ(tmp.GetArrChar()[2], 'r');
	EXPECT_EQ(tmp.GetArrChar()[4], 't');
	EXPECT_EQ(tmp.GetArrChar()[6], 'K');
	EXPECT_EQ(tmp.GetArrChar()[8], 'y');
}

TEST(sorttables, can_add_element_to_sort_table_with_resize_without_throws_0_1)
{
	TSortTable<int> table(3);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(10, key2);
	TElem<int> elem3(10, key3);
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	ASSERT_NO_THROW(table.Add(25));
}

TEST(sorttables, can_add_element_to_sort_table_with_resize_without_throws_1_correct)
{
	TSortTable<int> table(3);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(10, key2);
	TElem<int> elem3(10, key3);
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	String tmp = table.Add(25);
	EXPECT_EQ(table.Search(tmp).GetData(), 25);
}

TEST(sorttables, cad_delete_element_in_sort_table_without_throws_0)
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
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	table.Add(elem4);
	ASSERT_NO_THROW(table.Del(elem3));
}

TEST(sorttables, cad_delete_element_in_sort_table_without_throws_1)
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
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	table.Add(elem4);
	ASSERT_NO_THROW(table.Del(key3));
}

TEST(sorttables, cad_throw_if_count_of_elements_in_sort_table_is_zero_0)
{
	TSortTable<int> table(3);
	String key3("key3");
	TElem<int> elem3(10, key3);
	EXPECT_EQ(table.Del(elem3), 0);
}

TEST(sorttables, cad_throw_if_count_of_elements_in_sort_table_is_zero_1)
{
	TSortTable<int> table(3);
	String key3("key3");
	EXPECT_EQ(table.Del(key3), 0);
}

TEST(sorttables, cad_delete_element_in_sort_table_without_throws_2)
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
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	table.Add(elem4);
	EXPECT_EQ(table.Del(elem3), 1);
}

TEST(sorttables, cad_delete_element_in_sort_table_without_throws_3)
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
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	table.Add(elem4);
	EXPECT_EQ(table.Del(key3), 1);
}

TEST(sorttables, cad_delete_element_in_sort_table_correct_0)
{
	TSortTable<int> table(3);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	table.Add(elem4);
	table.Del(elem2);
	EXPECT_EQ(table[key3], 20);
}

TEST(sorttables, cad_delete_element_in_sort_table_correct_1)
{
	TSortTable<int> table(3);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	table.Add(elem4);
	table.Del(key2);
	EXPECT_EQ(table[key3], 20);
}

TEST(sorttables, cad_delete_element_in_sort_table_correct_2)
{
	TSortTable<int> table(3);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	table.Add(elem4);
	table.Del(elem2);
	EXPECT_EQ(table[key2] == 0, 1);
}

TEST(sorttables, cad_delete_element_in_sort_table_correct_3)
{
	TSortTable<int> table(3);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	table.Add(elem1);
	table.Add(elem2);
	table.Add(elem3);
	table.Add(elem4);
	table.Del(key2);
	EXPECT_EQ(table[key2] == 0, 1);
}

TEST(sorttables, can_sort_seetable_by_insert_sort_without_throws_0)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem6);
	table.Add(elem5);
	ASSERT_NO_THROW(TSortTable<int>::InsertSort(table));
}

TEST(sorttables, can_sort_seetable_by_insert_sort_correct_0)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem6);
	table.Add(elem5);
	TSortTable<int>::InsertSort(table);
	EXPECT_EQ(table.Search(key6) == elem6, 1);
}

TEST(sorttables, can_sort_seetable_by_insert_sort_correct)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem5);
	TSortTable<int>::InsertSort(table);
	EXPECT_EQ(table.Search(key5) == elem5, 1);
}

TEST(sorttables, can_sort_seetable_by_merge_sort_without_throws_0)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem6);
	table.Add(elem5);
	ASSERT_NO_THROW(TSortTable<int>::MergeSort(table, table.GetCount(), 0));
}

TEST(sorttables, can_sort_seetable_by_merge_sort_correct_0)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem6);
	table.Add(elem5);
	TSortTable<int>::MergeSort(table, table.GetCount(), 0);
	EXPECT_EQ(table.Search(key6) == elem6, 1);
}

TEST(sorttables, can_sort_seetable_by_merge_sort_correct_1)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem5);
	TSortTable<int>::MergeSort(table, table.GetCount(), 0);
	EXPECT_EQ(table.Search(key5) == elem5, 1);
}

TEST(sorttables, can_sort_seetable_by_quick_sort_without_throws_0)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem6);
	table.Add(elem5);
	ASSERT_NO_THROW(TSortTable<int>::QuickSort(table, 0, table.GetCount() - 1));
}

TEST(sorttables, can_sort_seetable_by_quick_sort_correct_0)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem6);
	table.Add(elem5);
	TSortTable<int>::QuickSort(table, 0, table.GetCount() - 1);
	EXPECT_EQ(table.Search(key6) == elem6, 1);
}

TEST(sorttables, can_sort_seetable_by_quick_sort_correct_1)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem5);
	TSortTable<int>::QuickSort(table, 0, table.GetCount() - 1);
	EXPECT_EQ(table.Search(key5) == elem5, 1);
}

TEST(sorttables, can_create_sort_table_using_seetable_insert_sort)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem6);
	table.Add(elem5);
	table.Add(elem6);
	ASSERT_NO_THROW(TSortTable<int> tmp(table, INSERT_SORT));
}

TEST(sorttables, can_create_sort_table_using_seetable_merge_sort)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem6);
	table.Add(elem5);
	table.Add(elem6);
	ASSERT_NO_THROW(TSortTable<int> tmp(table, MERGE_SORT));
}

TEST(sorttables, can_create_sort_table_using_seetable_quick_sort)
{
	TTable<int> table(5);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	table.Add(elem4);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem3);
	table.Add(elem6);
	table.Add(elem5);
	table.Add(elem6);
	ASSERT_NO_THROW(TSortTable<int> tmp(table, QUICK_SORT));
}