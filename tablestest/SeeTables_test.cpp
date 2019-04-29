#include <gtest.h>
#include <SeeTable.h>

TEST(seetables, can_create_table_without_throws_0)
{
	ASSERT_NO_THROW(TTable<double> table);
}

TEST(seetables, can_create_table_without_throws_1)
{
	ASSERT_NO_THROW(TTable<int> table(10));
}

TEST(seetables, can_add_element_without_throws_0)
{
	TTable<int> table(5);
	String key("key");
	TElem<int> elem(10, key);
	ASSERT_NO_THROW(table.Add(elem));
}

TEST(seetables, can_add_element_without_throws_1)
{
	TTable<int> table(5);
	String key("key");
	TElem<int> elem(10, key);
	EXPECT_EQ(table.Add(elem), 1);
}

TEST(seetables, can_add_element_with_resize_without_throws_0)
{
	TTable<int> table(3);
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
	ASSERT_NO_THROW(table.Add(elem4));
}

TEST(seetables, can_add_element_with_resize_without_throws_1)
{
	TTable<int> table(3);
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
	EXPECT_EQ(table.Add(elem4), 1);
}

TEST(seetables, can_add_element_correct)
{
	TTable<int> table(5);
	String key("key");
	TElem<int> elem(10, key);
	table.Add(elem);
	EXPECT_EQ(table[key], 10);
}

TEST(seetables, can_search_element_without_throws_0)
{
	TTable<int> table(3);
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
	ASSERT_NO_THROW(table.Search(key3));
}

TEST(seetables, can_search_element_without_throws_1)
{
	TTable<int> table(3);
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

TEST(seetables, can_search_element_correct)
{
	TTable<int> table(3);
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

TEST(seetables, can_add_element_without_throws_0_1)
{
	TTable<int> table(5);
	ASSERT_NO_THROW(table.Add(10));
}

TEST(seetables, can_add_element_without_throws_0_2)
{
	TTable<int> table(5);
	String key("key");
	TElem<int> elem(10, key);
	table.Add(elem);
	ASSERT_NO_THROW(table.Add(25));
}

TEST(seetables, can_add_element_without_throws_1_1)
{
	TTable<int> table(5);
	String tmp = table.Add(25);
	EXPECT_EQ(tmp.GetArrChar()[0], 'F');
	EXPECT_EQ(tmp.GetArrChar()[2], 'r');
	EXPECT_EQ(tmp.GetArrChar()[4], 't');
	EXPECT_EQ(tmp.GetArrChar()[6], 'K');
	EXPECT_EQ(tmp.GetArrChar()[8], 'y');
}

TEST(seetables, can_add_element_with_resize_without_throws_0_1)
{
	TTable<int> table(3);
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

TEST(seetables, can_add_element_with_resize_without_throws_1_correct)
{
	TTable<int> table(3);
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

TEST(seetables, cad_delete_element_without_throws_0)
{
	TTable<int> table(3);
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

TEST(seetables, cad_delete_element_without_throws_1)
{
	TTable<int> table(3);
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

TEST(seetables, cad_throw_if_count_is_zero_0)
{
	TTable<int> table(3);
	String key3("key3");
	TElem<int> elem3(10, key3);
	EXPECT_EQ(table.Del(elem3), 0);
}

TEST(seetables, cad_throw_if_count_is_zero_1)
{
	TTable<int> table(3);
	String key3("key3");
	EXPECT_EQ(table.Del(key3), 0);
}

TEST(seetables, cad_delete_element_without_throws_2)
{
	TTable<int> table(3);
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

TEST(seetables, cad_delete_element_without_throws_3)
{
	TTable<int> table(3);
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

TEST(seetables, cad_delete_element_correct_0)
{
	TTable<int> table(3);
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

TEST(seetables, cad_delete_element_correct_1)
{
	TTable<int> table(3);
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

TEST(seetables, cad_delete_element_correct_2)
{
	TTable<int> table(3);
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

TEST(seetables, cad_delete_element_correct_3)
{
	TTable<int> table(3);
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