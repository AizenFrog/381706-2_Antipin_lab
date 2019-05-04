#include <gtest.h>
#include "Elem.h"

TEST(tree_elem, can_create_tree_elem_without_throws_0)
{
	ASSERT_NO_THROW(TTreeElem<int> elem);
}

TEST(tree_elem, can_create_tree_elem_without_throws_1)
{
	String key("sto");
	ASSERT_NO_THROW(TTreeElem<int> elem(100, key));
}

TEST(tree_elem, can_create_tree_elem_without_throws_2)
{
	String key("sto");
	ASSERT_NO_THROW(TTreeElem<int> elem(100, key, NULL, NULL, NULL));
}

TEST(tree_elem, can_create_tree_elem_without_throws_3)
{
	String key("sto");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	ASSERT_NO_THROW(TTreeElem<int> elem(100, key, &elem1, &elem1, &elem1));
}

TEST(tree_elem, can_assign_tree_elem_without_throws)
{
	String key("k");
	TTreeElem<int> elem1(100, key);
	TTreeElem<int> elem2;
	ASSERT_NO_THROW(elem2 = elem1);
}

TEST(tree_elem, can_assign_elements_correct)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem(100, key1);
	TTreeElem<int> elem1(100, key, &elem, &elem, &elem);
	TTreeElem<int> elem2;
	elem2 = elem1;
	EXPECT_EQ(elem1.GetData(), elem2.GetData());
	EXPECT_EQ(elem1.GetKey(), elem2.GetKey());
	EXPECT_EQ(elem1.GetLeft(), elem2.GetLeft());
	EXPECT_EQ(elem1.GetParent(), elem2.GetParent());
	EXPECT_EQ(elem1.GetRight(), elem2.GetRight());
}

TEST(tree_elem, can_get_data_without_throws)
{
	String key("k");
	TTreeElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.GetData());
}

TEST(tree_elem, can_get_data_correct)
{
	String key("k");
	TTreeElem<int> elem(100, key);
	EXPECT_EQ(elem.GetData(), 100);
}

TEST(tree_elem, can_set_data_without_throws)
{
	String key("k");
	TTreeElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.SetData(200));
}

TEST(tree_elem, can_set_data_correct)
{
	String key("k");
	TTreeElem<int> elem(100, key);
	elem.SetData(200);
	EXPECT_EQ(elem.GetData(), 200);
}

TEST(tree_elem, can_get_left_without_throws)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key, &elem1);
	ASSERT_NO_THROW(elem.GetLeft());
}

TEST(tree_elem, can_get_left_correct)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key, &elem1);
	EXPECT_EQ(elem.GetLeft() == &elem1, 1);
}

TEST(tree_elem, can_set_left_without_throws)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.SetLeft(&elem1));
}

TEST(tree_elem, can_set_left_correct)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key);
	elem.SetLeft(&elem1);
	EXPECT_EQ(elem.GetLeft() == &elem1, 1);
}

TEST(tree_elem, can_get_right_without_throws)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key, NULL, &elem1);
	ASSERT_NO_THROW(elem.GetRight());
}

TEST(tree_elem, can_get_right_correct)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key, NULL, &elem1);
	EXPECT_EQ(elem.GetRight() == &elem1, 1);
}

TEST(tree_elem, can_set_right_without_throws)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.SetRight(&elem1));
}

TEST(tree_elem, can_set_right_correct)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key);
	elem.SetRight(&elem1);
	EXPECT_EQ(elem.GetRight() == &elem1, 1);
}

TEST(tree_elem, can_get_parent_without_throws)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key, NULL, NULL, &elem1);
	ASSERT_NO_THROW(elem.GetParent());
}

TEST(tree_elem, can_get_parent_correct)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key, NULL, NULL, &elem1);
	EXPECT_EQ(elem.GetParent() == &elem1, 1);
}

TEST(tree_elem, can_set_parent_without_throws)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.SetParent(&elem1));
}

TEST(tree_elem, can_set_parent_correct)
{
	String key("k");
	String key1("pro100");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem(100, key);
	elem.SetParent(&elem1);
	EXPECT_EQ(elem.GetParent() == &elem1, 1);
}

TEST(tree_elem, can_set_key_without_throws)
{
	String key("k");
	String key1("key");
	TTreeElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.SetKey(key1));
}

TEST(tree_elem, can_set_key_correct)
{
	String key("k");
	String key1("key");
	TTreeElem<int> elem(100, key);
	elem.SetKey(key1);
	EXPECT_EQ(elem.GetKey(), key1);
}

TEST(tree_elem, can_compare_elements_without_throws_0)
{
	String key1("key1");
	String key2("key2");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 == elem2);
}

TEST(tree_elem, can_compare_elements_without_throws_1)
{
	String key1("key1");
	String key2("key1");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 == elem2);
}

TEST(tree_elem, can_compare_elements_correct_0)
{
	String key1("key1");
	String key2("key1");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem2(100, key2);
	EXPECT_EQ(elem1 == elem2, 1);
}

TEST(tree_elem, can_compare_elements_without_throws_0_0)
{
	String key1("key1");
	String key2("key2");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 != elem2);
}

TEST(tree_elem, can_compare_elements_without_throws_1_1)
{
	String key1("key1");
	String key2("key1");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 != elem2);
}

TEST(tree_elem, can_compare_elements_correct_0_1)
{
	String key1("key1");
	String key2("key2");
	TTreeElem<int> elem1(100, key1);
	TTreeElem<int> elem2(100, key2);
	EXPECT_EQ(elem1 != elem2, 1);
}