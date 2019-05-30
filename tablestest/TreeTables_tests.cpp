#include <gtest.h>
#include "TreeTable.h"

TEST(tree_table, can_create_tree_table_without_throws)
{
	ASSERT_NO_THROW(TTreeTable<int> table);
}

TEST(tree_table, can_return_tree_table_count_without_throws)
{
	TTreeTable<int> table;
	ASSERT_NO_THROW(table.GetCount());
}

TEST(tree_table, can_return_tree_table_count_correct_0)
{
	TTreeTable<int> table;
	EXPECT_EQ(table.GetCount(), 0);
}

TEST(tree_table, can_return_tree_table_node_without_throws)
{
	TTreeTable<int> table;
	ASSERT_NO_THROW(table.GetNode());
}

TEST(tree_table, can_return_tree_table_node_correct_0)
{
	TTreeTable<int> table;
	EXPECT_EQ(table.GetNode() == NULL, 1);
}

TEST(tree_table, can_add_element_to_tree_table_without_throws_0)
{
	TTreeTable<int> table;
	String key("key1");
	TTreeElem<int> elem(10, key);
	ASSERT_NO_THROW(table.Add(elem));
}

TEST(tree_table, can_return_tree_table_count_without_throws_1)
{
	TTreeTable<int> table;
	String key("key1");
	TTreeElem<int> elem(10, key);
	table.Add(elem);
	ASSERT_NO_THROW(table.GetCount());
}

TEST(tree_table, can_return_tree_table_count_correct_1)
{
	TTreeTable<int> table;
	String key("key1");
	TTreeElem<int> elem(10, key);
	table.Add(elem);
	EXPECT_EQ(table.GetCount(), 1);
}

TEST(tree_table, can_return_tree_table_node_without_throws_1)
{
	TTreeTable<int> table;
	String key("key1");
	TTreeElem<int> elem(10, key);
	table.Add(elem);
	ASSERT_NO_THROW(table.GetNode());
}

TEST(tree_table, can_return_tree_table_node_correct_1)
{
	TTreeTable<int> table;
	String key("key1");
	TTreeElem<int> elem(10, key);
	TTreeElem<int>* tmp = table.Add(elem);
	EXPECT_EQ(table.GetNode() == tmp, 1);
}

TEST(tree_table, can_add_elem_to_tree_table_correct_1)
{
	TTreeTable<int> table;
	String key1("key1");
	TTreeElem<int> elem1(10, key1);
	String key2("key2");
	TTreeElem<int> elem2(10, key2);
	table.Add(elem1);
	ASSERT_NO_THROW(table.Add(elem2));
}

TEST(tree_table, can_delete_elem_from_tree_table_correct_0)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	TTreeElem<int>* tmp;
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	tmp = table.Add(elem5);
	table.Add(elem4);
	table.Add(elem6);
	ASSERT_NO_THROW(table.Del(*tmp));
}

TEST(tree_table, can_delete_elem_from_tree_table_correct_1)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	TTreeElem<int>* tmp;
	table.Add(elem3);
	tmp = table.Add(elem2);
	table.Add(elem1);
	table.Add(elem5);
	table.Add(elem4);
	table.Add(elem6);
	ASSERT_NO_THROW(table.Del(*tmp));
}

TEST(tree_table, can_delete_elem_from_tree_table_correct_2)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	TTreeElem<int>* tmp;
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	tmp = table.Add(elem4);
	table.Add(elem5);
	table.Add(elem6);
	ASSERT_NO_THROW(table.Del(*tmp));
}

TEST(tree_table, can_delete_elem_from_tree_table_correct_3)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	TTreeElem<int>* tmp;
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem4);
	tmp = table.Add(elem5);
	table.Add(elem6);
	//tmp = &elem5;
	ASSERT_NO_THROW(table.Del(*tmp));
}

TEST(tree_table, can_delete_elem_from_tree_table_correct_4)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	String key7("key7");
	String key8("key8");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	TTreeElem<int> elem7(10, key7);
	TTreeElem<int> elem8(10, key8);
	TTreeElem<int>* tmp;
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	tmp = table.Add(elem5);
	table.Add(elem4);
	table.Add(elem7);
	table.Add(elem6);
	table.Add(elem8);
	//tmp = &elem5;
	ASSERT_NO_THROW(table.Del(*tmp));
}

TEST(tree_table, can_delete_elem_from_tree_table_by_key_correct_0)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem5);
	table.Add(elem4);
	table.Add(elem6);
	ASSERT_NO_THROW(table.Del(key5));
}

TEST(tree_table, can_delete_elem_from_tree_table_by_key_correct_1)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem5);
	table.Add(elem4);
	table.Add(elem6);
	ASSERT_NO_THROW(table.Del(key6));
}

TEST(tree_table, can_search_elem_in_tree_table_by_key_without_throws_0)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem5);
	table.Add(elem4);
	table.Add(elem6);
	ASSERT_NO_THROW(table.Search(key1));
}

TEST(tree_table, can_search_elem_in_tree_table_by_key_without_throws_1)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem5);
	table.Add(elem4);
	table.Add(elem6);
	ASSERT_NO_THROW(table.Search(key4));
}

TEST(tree_table, can_search_elem_in_tree_table_by_key_correct_0)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem5);
	table.Add(elem4);
	table.Add(elem6);
	EXPECT_EQ(table.Search(key4) == elem4, 1);
}

TEST(tree_table, can_search_elem_in_tree_table_by_key_without_throws_2)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(10, key6);
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem5);
	table.Add(elem4);
	//table.Add(elem6);
	ASSERT_NO_THROW(table.Search(key6));
}

TEST(tree_table, can_get_data_elem_in_tree_table_by_key_without_throws_0)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(15, key6);
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem5);
	table.Add(elem4);
	table.Add(elem6);
	ASSERT_NO_THROW(table[key6]);
}

TEST(tree_table, can_get_data_elem_in_tree_table_by_key_correct)
{
	TTreeTable<int> table;
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	TTreeElem<int> elem1(10, key1);
	TTreeElem<int> elem2(10, key2);
	TTreeElem<int> elem3(10, key3);
	TTreeElem<int> elem4(10, key4);
	TTreeElem<int> elem5(10, key5);
	TTreeElem<int> elem6(15, key6);
	table.Add(elem3);
	table.Add(elem2);
	table.Add(elem1);
	table.Add(elem5);
	table.Add(elem4);
	table.Add(elem6);
	EXPECT_EQ(table[key6], 15);
}