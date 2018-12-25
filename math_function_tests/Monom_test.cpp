#include <gtest.h>
#include "Monom.h"

TEST(monom, can_create_monom)
{
	unsigned int B[]{3, 2, 1};
	/*for (int i = 0; i < 3; i++)
		B[i] = i;*/
	ASSERT_NO_THROW(Monom A(3, B, 3.14));
}