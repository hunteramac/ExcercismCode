#include "pch.h"

#include "../ExcercismCode/lasagna.cpp"

TEST(Lasagna, OvenTime) {
	EXPECT_EQ(ovenTime(), 40);
}