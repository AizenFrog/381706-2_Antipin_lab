#include <gtest.h>
#include "HashTable.h"

TEST(hashtables, can_create_hash_table_without_throws_0)
{
	ASSERT_NO_THROW(THashTable<int> table);
}

TEST(hashtables, can_create_hash_table_without_throws_1)
{
	ASSERT_NO_THROW(THashTable<int> table(10));
}

TEST(hashtables, can_add_element_to_hash_table_without_throws_0)
{
	THashTable<int> table(100);
	String key("a");
	TElem<int> elem(10, key);
	ASSERT_NO_THROW(table.Add(elem));
}

TEST(hashtables, can_add_element_to_hash_table_with_resize_without_throws_0)
{
	THashTable<int> table(3);
	String key1("a");
	TElem<int> elem1(10, key1);
	ASSERT_NO_THROW(table.Add(elem1));
}

TEST(hashtables, can_add_element_to_hash_table_correct_0)
{
	THashTable<int> table(5);
	String key("a");
	TElem<int> elem(10, key);
	table.Add(elem);
	EXPECT_EQ(table.Search(key), 10);
}

TEST(hashtables, can_add_element_to_hash_table_without_throws_1)
{
	THashTable<int> table(100);
	String key("a");
	ASSERT_NO_THROW(table.Add(key, 10));
}

TEST(hashtables, can_add_element_to_hash_table_with_resize_without_throws_1)
{
	THashTable<int> table(3);
	String key("a");
	ASSERT_NO_THROW(table.Add(key, 10));
}

TEST(hashtables, can_add_element_to_hash_table_correct_1)
{
	THashTable<int> table(5);
	String key("a");
	table.Add(key, 10);
	EXPECT_EQ(table.Search(key), 10);
}

TEST(hashtables, can_return_current_count_without_throws_0)
{
	THashTable<int> table(5);
	ASSERT_NO_THROW(table.GetCount());
}

TEST(hashtables, can_return_current_count_correct_0)
{
	THashTable<int> table(5);
	EXPECT_EQ(0, table.GetCount());
}

TEST(hashtables, can_return_current_count_without_throws_1)
{
	THashTable<int> table(5);
	String key("a");
	table.Add(key, 10);
	ASSERT_NO_THROW(table.GetCount());
}

TEST(hashtables, can_return_current_count_correct_1)
{
	THashTable<int> table(5);
	String key("a");
	table.Add(key, 10);
	EXPECT_EQ(1, table.GetCount());
}

TEST(hashtables, can_delete_element_from_hash_table_without_throws_0)
{
	THashTable<int> table(100);
	String key("a");
	TElem<int> elem(10, key);
	table.Add(elem);
	ASSERT_NO_THROW(table.Del(key));
}

TEST(hashtables, can_delete_element_from_hash_table_without_throws_1)
{
	THashTable<int> table(100);
	String key("a");
	TElem<int> elem(10, key);
	table.Add(elem);
	EXPECT_EQ(table.Del(key), 1);
}

TEST(hashtables, can_delete_element_from_hash_table_without_throws_2)
{
	THashTable<int> table(100);
	String key("a");
	String key1("b");
	TElem<int> elem(10, key);
	table.Add(elem);
	EXPECT_EQ(table.Del(key1), 0);
}

TEST(hashtables, can_delete_element_from_hash_table_correct_0)
{
	THashTable<int> table(5);
	String key("a");
	TElem<int> elem(10, key);
	table.Add(elem);
	table.Del(key);
	EXPECT_EQ(table.Search(key), 0);
}

TEST(hashtables, can_add_element_to_hash_table_correct_2)
{
	THashTable<int> table(5);
	String key("a");
	String key1("b");
	String key2("c");
	String key3("d");
	String key4("ab");
	table.Add(key, 10);
	table.Add(key1, 15);
	table.Add(key2, 20);
	table.Add(key3, 25);
	table.Add(key4, 30);
	EXPECT_EQ(table.Search(key2), 20);
}

TEST(hashtables, can_overcome_the_conflict_0)
{
	THashTable<int> table(5);
	String key1("ab");
	String key2("Ar");
	table.Add(key1, 15);
	table.Add(key2, 20);
	ASSERT_NO_THROW(table.Search(key2));
}

TEST(hashtables, can_overcome_the_conflict_1)
{
	THashTable<int> table(5);
	String key1("ab");
	String key2("Ar");
	String key3("Bq");
	String key4("sv");
	table.Add(key1, 15);
	table.Add(key2, 20);
	table.Add(key3, 25);
	table.Add(key4, 30);
	ASSERT_NO_THROW(table.Search(key2));
}

TEST(hashtables, can_overcome_the_conflict_correct_0)
{
	THashTable<int> table(5);
	String key1("ab");
	String key2("Ar");
	table.Add(key1, 15);
	table.Add(key2, 20);
	EXPECT_EQ(table.Search(key2), 20);
}

TEST(hashtables, can_overcome_the_conflict_correct_1)
{
	THashTable<int> table(5);
	String key1("ab");
	String key2("Ar");
	String key3("Bq");
	String key4("sv");
	table.Add(key1, 15);
	table.Add(key2, 20);
	table.Add(key3, 25);
	table.Add(key4, 30);
	EXPECT_EQ(table.Search(key3), 25);
}

TEST(hashtables, can_return_false_if_nomber_is_simple)
{
	THashTable<int> table(5);
	EXPECT_EQ(table.IsSimple(156), false);
}

TEST(hashtables, can_return_true_if_nomber_is_simple)
{
	THashTable<int> table(5);
	EXPECT_EQ(table.IsSimple(157), true);
}

TEST(hashtables_1, can_create_hash_table_without_throws_0)
{
	ASSERT_NO_THROW(THashTable_1<int> table);
}

TEST(hashtables_1, can_create_hash_table_without_throws_1)
{
	ASSERT_NO_THROW(THashTable_1<int> table(10));
}

TEST(hashtables_1, can_add_element_to_hash_table_without_throws_0)
{
	THashTable_1<int> table(100);
	String key("a");
	THashElem<int> elem(10, key);
	ASSERT_NO_THROW(table.Add(elem));
}

TEST(hashtables_1, can_add_element_to_hash_table_with_resize_without_throws_0)
{
	THashTable_1<int> table(3);
	String key1("a");
	THashElem<int> elem1(10, key1);
	ASSERT_NO_THROW(table.Add(elem1));
}

TEST(hashtables_1, can_add_element_to_hash_table_correct_0)
{
	THashTable_1<int> table(5);
	String key("a");
	THashElem<int> elem(10, key);
	table.Add(elem);
	EXPECT_EQ(table.Search(key), 10);
}

TEST(hashtables_1, can_add_element_to_hash_table_without_throws_1)
{
	THashTable_1<int> table(100);
	String key("a");
	ASSERT_NO_THROW(table.Add(key, 10));
}

TEST(hashtables_1, can_add_element_to_hash_table_with_resize_without_throws_1)
{
	THashTable_1<int> table(3);
	String key("a");
	ASSERT_NO_THROW(table.Add(key, 10));
}

TEST(hashtables_1, can_add_element_to_hash_table_correct_1)
{
	THashTable_1<int> table(5);
	String key("a");
	table.Add(key, 10);
	EXPECT_EQ(table.Search(key), 10);
}

TEST(hashtables_1, can_return_current_count_without_throws_0)
{
	THashTable_1<int> table(5);
	ASSERT_NO_THROW(table.GetCount());
}

TEST(hashtables_1, can_return_current_count_correct_0)
{
	THashTable_1<int> table(5);
	EXPECT_EQ(0, table.GetCount());
}

TEST(hashtables_1, can_return_current_count_without_throws_1)
{
	THashTable_1<int> table(5);
	String key("a");
	table.Add(key, 10);
	ASSERT_NO_THROW(table.GetCount());
}

TEST(hashtables_1, can_return_current_count_correct_1)
{
	THashTable_1<int> table(5);
	String key("a");
	table.Add(key, 10);
	EXPECT_EQ(1, table.GetCount());
}

TEST(hashtables_1, can_delete_element_from_hash_table_without_throws_0)
{
	THashTable_1<int> table(100);
	String key("a");
	THashElem<int> elem(10, key);
	table.Add(elem);
	ASSERT_NO_THROW(table.Del(key));
}

TEST(hashtables_1, can_delete_element_from_hash_table_without_throws_1)
{
	THashTable_1<int> table(100);
	String key("a");
	THashElem<int> elem(10, key);
	table.Add(elem);
	EXPECT_EQ(table.Del(key), 1);
}

TEST(hashtables_1, can_delete_element_from_hash_table_without_throws_2)
{
	THashTable_1<int> table(100);
	String key("a");
	String key1("b");
	THashElem<int> elem(10, key);
	table.Add(elem);
	EXPECT_EQ(table.Del(key1), 0);
}

TEST(hashtables_1, can_delete_element_from_hash_table_correct_0)
{
	THashTable_1<int> table(5);
	String key("a");
	THashElem<int> elem(10, key);
	table.Add(elem);
	table.Del(key);
	EXPECT_EQ(table.Search(key), 0);
}

TEST(hashtables_1, can_add_element_to_hash_table_correct_2)
{
	THashTable_1<int> table(5);
	String key("a");
	String key1("b");
	String key2("c");
	String key3("d");
	String key4("ab");
	table.Add(key, 10);
	table.Add(key1, 15);
	table.Add(key2, 20);
	table.Add(key3, 25);
	table.Add(key4, 30);
	EXPECT_EQ(table.Search(key2), 20);
}

TEST(hashtables_1, can_overcome_the_conflict_0)
{
	THashTable_1<int> table(5);
	String key1("ab");
	String key2("Ar");
	table.Add(key1, 15);
	table.Add(key2, 20);
	ASSERT_NO_THROW(table.Search(key2));
}

TEST(hashtables_1, can_overcome_the_conflict_1)
{
	THashTable_1<int> table(5);
	String key1("ab");
	String key2("Ar");
	String key3("Bq");
	String key4("sv");
	table.Add(key1, 15);
	table.Add(key2, 20);
	table.Add(key3, 25);
	table.Add(key4, 30);
	ASSERT_NO_THROW(table.Search(key2));
}

TEST(hashtables_1, can_overcome_the_conflict_correct_0)
{
	THashTable_1<int> table(5);
	String key1("ab");
	String key2("Ar");
	table.Add(key1, 15);
	table.Add(key2, 20);
	EXPECT_EQ(table.Search(key2), 20);
}

TEST(hashtables_1, can_overcome_the_conflict_correct_1)
{
	THashTable_1<int> table(5);
	String key1("ab");
	String key2("Ar");
	String key3("Bq");
	String key4("sv");
	table.Add(key1, 15);
	table.Add(key2, 20);
	table.Add(key3, 25);
	table.Add(key4, 30);
	EXPECT_EQ(table.Search(key3), 25);
}

TEST(hashtables_1, can_delete_element_from_hash_table_correct_1)
{
	THashTable_1<int> table(5);
	String key1("ab");
	String key2("Ar");
	String key3("Bq");
	String key4("sv");
	table.Add(key1, 15);
	table.Add(key2, 20);
	table.Add(key3, 25);
	table.Add(key4, 30);
	table.Del(key3);
	EXPECT_EQ(table.Search(key3), 0);
}

TEST(hashtables_1, can_delete_element_from_hash_table_correct_2)
{
	THashTable_1<int> table(5);
	String key1("ab");
	String key2("Ar");
	String key3("Bq");
	String key4("sv");
	table.Add(key1, 15);
	table.Add(key2, 20);
	table.Add(key3, 25);
	table.Add(key4, 30);
	table.Del(key2);
	EXPECT_EQ(table.Search(key2), 0);
}

TEST(hashtables_1, can_delete_element_from_hash_table_correct_3)
{
	THashTable_1<int> table(5);
	String key1("ab");
	String key2("Ar");
	String key3("Bq");
	String key4("sv");
	table.Add(key1, 15);
	table.Add(key2, 20);
	table.Add(key3, 25);
	table.Add(key4, 30);
	table.Del(key1);
	EXPECT_EQ(table.Search(key1), 0);
}