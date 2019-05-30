#include <gtest.h>
#include "Elem.h"

TEST(element, can_create_element_without_throws_0)
{
  ASSERT_NO_THROW(TElem<int> elem);
}

TEST(element, can_create_element_without_throws_1)
{
  String key("sto");
  ASSERT_NO_THROW(TElem<int> elem(100, key));
}

TEST(element, can_assign_elements_without_throws)
{
  String key("k");
  TElem<int> elem1(100, key);
  TElem<int> elem2;
  ASSERT_NO_THROW(elem2 = elem1);
}

TEST(element, can_assign_elements_correct)
{
  String key("k");
  TElem<int> elem1(100, key);
  TElem<int> elem2;
  elem2 = elem1;
  EXPECT_EQ(elem1.GetData(), elem2.GetData());
  EXPECT_EQ(elem1.GetKey(), elem2.GetKey());
}

TEST(element, can_get_data_without_throws)
{
	String key("k");
	TElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.GetData());
}

TEST(element, can_get_data_correct)
{
	String key("k");
	TElem<int> elem(100, key);
	EXPECT_EQ(elem.GetData(), 100);
}

TEST(element, can_set_data_without_throws)
{
	String key("k");
	TElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.SetData(200));
}

TEST(element, can_set_data_correct)
{
	String key("k");
	TElem<int> elem(100, key);
	elem.SetData(200);
	EXPECT_EQ(elem.GetData(), 200);
}

TEST(element, can_set_key_without_throws)
{
	String key("k");
	String key1("key");
	TElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.SetKey(key1));
}

TEST(element, can_set_key_correct)
{
	String key("k");
	String key1("key");
	TElem<int> elem(100, key);
	elem.SetKey(key1);
	EXPECT_EQ(elem.GetKey(), key1);
}

TEST(element, can_compare_elements_without_throws_0)
{
	String key1("key1");
	String key2("key2");
	TElem<int> elem1(100, key1);
	TElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 == elem2);
}

TEST(element, can_compare_elements_without_throws_1)
{
	String key1("key1");
	String key2("key1");
	TElem<int> elem1(100, key1);
	TElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 == elem2);
}

TEST(element, can_compare_elements_correct_0)
{
	String key1("key1");
	String key2("key1");
	TElem<int> elem1(100, key1);
	TElem<int> elem2(100, key2);
	EXPECT_EQ(elem1 == elem2, 1);
}

TEST(element, can_compare_elements_without_throws_0_0)
{
	String key1("key1");
	String key2("key2");
	TElem<int> elem1(100, key1);
	TElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 != elem2);
}

TEST(element, can_compare_elements_without_throws_1_1)
{
	String key1("key1");
	String key2("key1");
	TElem<int> elem1(100, key1);
	TElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 != elem2);
}

TEST(element, can_compare_elements_correct_0_1)
{
	String key1("key1");
	String key2("key2");
	TElem<int> elem1(100, key1);
	TElem<int> elem2(100, key2);
	EXPECT_EQ(elem1 != elem2 , 1);
}

TEST(hash_element, can_create_element_without_throws_0)
{
	ASSERT_NO_THROW(THashElem<int> elem);
}

TEST(hash_element, can_create_element_without_throws_1)
{
	String key("sto");
	ASSERT_NO_THROW(THashElem<int> elem(100, key));
}

TEST(hash_element, can_assign_elements_without_throws)
{
	String key("k");
	THashElem<int> elem1(100, key);
	THashElem<int> elem2;
	ASSERT_NO_THROW(elem2 = elem1);
}

TEST(hash_element, can_assign_elements_correct)
{
	String key("k");
	THashElem<int> elem1(100, key);
	THashElem<int> elem2;
	elem2 = elem1;
	EXPECT_EQ(elem1.GetData(), elem2.GetData());
	EXPECT_EQ(elem1.GetKey(), elem2.GetKey());
}

TEST(hash_element, can_get_data_without_throws)
{
	String key("k");
	THashElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.GetData());
}

TEST(hash_element, can_get_data_correct)
{
	String key("k");
	THashElem<int> elem(100, key);
	EXPECT_EQ(elem.GetData(), 100);
}

TEST(hash_element, can_set_data_without_throws)
{
	String key("k");
	THashElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.SetData(200));
}

TEST(hash_element, can_set_data_correct)
{
	String key("k");
	THashElem<int> elem(100, key);
	elem.SetData(200);
	EXPECT_EQ(elem.GetData(), 200);
}

TEST(hash_element, can_set_key_without_throws)
{
	String key("k");
	String key1("key");
	THashElem<int> elem(100, key);
	ASSERT_NO_THROW(elem.SetKey(key1));
}

TEST(hash_element, can_set_key_correct)
{
	String key("k");
	String key1("key");
	THashElem<int> elem(100, key);
	elem.SetKey(key1);
	EXPECT_EQ(elem.GetKey(), key1);
}

TEST(hash_element, can_compare_elements_without_throws_0)
{
	String key1("key1");
	String key2("key2");
	THashElem<int> elem1(100, key1);
	THashElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 == elem2);
}

TEST(hash_element, can_compare_elements_without_throws_1)
{
	String key1("key1");
	String key2("key1");
	THashElem<int> elem1(100, key1);
	THashElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 == elem2);
}

TEST(hash_element, can_compare_elements_correct_0)
{
	String key1("key1");
	String key2("key1");
	TElem<int> elem1(100, key1);
	TElem<int> elem2(100, key2);
	EXPECT_EQ(elem1 == elem2, 1);
}

TEST(hash_element, can_compare_elements_without_throws_0_0)
{
	String key1("key1");
	String key2("key2");
	THashElem<int> elem1(100, key1);
	THashElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 != elem2);
}

TEST(hash_element, can_compare_elements_without_throws_1_1)
{
	String key1("key1");
	String key2("key1");
	THashElem<int> elem1(100, key1);
	THashElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1 != elem2);
}

TEST(hash_element, can_compare_elements_correct_0_1)
{
	String key1("key1");
	String key2("key2");
	THashElem<int> elem1(100, key1);
	THashElem<int> elem2(100, key2);
	EXPECT_EQ(elem1 != elem2, 1);
}

TEST(hash_element, can_create_elem_with_next_element_without_throws)
{
	String key1("key1");
	String key2("key2");
	THashElem<int> elem1(100, key1);
	ASSERT_NO_THROW(THashElem<int> elem2(100, key2, &elem1));
}

TEST(hash_element, can_set_next_element_without_throws)
{
	String key1("key1");
	String key2("key2");
	THashElem<int> elem1(100, key1);
	THashElem<int> elem2(100, key2);
	ASSERT_NO_THROW(elem1.SetNext(&elem2));
}

TEST(hash_element, can_get_next_element_correct)
{
	String key1("key1");
	String key2("key2");
	THashElem<int> elem1(100, key1);
	THashElem<int> elem2(100, key2, &elem1);
	EXPECT_EQ(*elem2.GetNext() == elem1, 1);
}

TEST(hash_element, can_get_next_element_correct_1)
{
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	THashElem<int> elem1(100, key1);
	THashElem<int> elem2(100, key2, &elem1);
	THashElem<int> elem3(100, key3, &elem2);
	THashElem<int> elem4(100, key4, &elem3);
	EXPECT_EQ(*elem2.GetNext() == elem1, 1);
}