#include "Stack_on_List.h"
#include <gtest.h>

TEST(StackList, can_create_stack_list)
{
	ASSERT_NO_THROW(tStackList<int> A);
}

TEST(StackList, can_put_it_empty_stack_list)
{
	tStackList<int> A;
	ASSERT_NO_THROW(A.Put(10));
}

TEST(StackList, can_put_stack_list)
{
	tStackList<int> A;
	A.Put(20);
	A.Put(15);
	ASSERT_NO_THROW(A.Put(10));
}

TEST(StackList, can_return_false_if_stack_is_not_empty)
{
	tStackList<int> A;
	A.Put(20);
	A.Put(15);
	EXPECT_EQ(0, A.IsEmpty());
}

TEST(StackList, can_return_true_if_stack_is_empty)
{
	tStackList<int> A;
	EXPECT_EQ(1, A.IsEmpty());
}

TEST(StackList, can_throw_if_get_item_from_empty_stack_list)
{
	tStackList<int> A;
	ASSERT_ANY_THROW(A.Get());
}

TEST(StackList, can_return_list_lenght)
{
	tStackList<int> A;
	EXPECT_EQ(A.GetLen(), 0);
}

TEST(StackList, can_return_stack_item_1)
{
	tStackList<int> A;
	A.Put(20);
	ASSERT_NO_THROW(A.Get());
}

TEST(StackList, can_return_stack_item)
{
	tStackList<int> A;
	A.Put(20);
	A.Put(15);
	ASSERT_NO_THROW(A.Get());
}

TEST(StackList, can_right_return_stack_item)
{
	tStackList<int> A;
	A.Put(20);
	A.Put(15);
	EXPECT_EQ(A.Get(), 15);
}

TEST(StackList, can_right_put_and_return_stack_item)
{
	tStackList<int> A;
	A.Put(20);
	A.Put(15);
	A.Get();
	A.Put(25);
	EXPECT_EQ(A.Get(), 25);
	EXPECT_EQ(A.Get(), 20);
}