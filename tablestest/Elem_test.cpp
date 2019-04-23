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
	//std::cout << elem;
}