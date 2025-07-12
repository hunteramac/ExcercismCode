#include "pch.h"

#include "../ExcercismCode/lasagna_master.h"

namespace LasagnaMaster{
TEST(Dummy, dummy1) {
	EXPECT_TRUE(true);
}

TEST(PreparationTime, canBeCalled) {
	std::vector<std::string> layers{ "sauce","noodles" };
	int estimateTime = lasagna_master::preparationTime(layers, 3);
	lasagna_master::preparationTime(layers);
}

TEST(PreparationTime, result1) {
	std::vector<std::string> layers{ "sauce","noodles" };
	int estimateTime = lasagna_master::preparationTime(layers, 3);
	EXPECT_EQ(estimateTime, 6);
}

}