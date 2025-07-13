#include "pch.h"

#include "../ExcercismCode/lasagna_master.h"

namespace LasagnaMaster{
TEST(PreparationTime, IsCallable) {
	std::vector<std::string> layers{ "sauce","noodles" };
	int estimateTime = lasagna_master::preparationTime(layers, 3);
	lasagna_master::preparationTime(layers);
}

TEST(PreparationTime, TakesInSpecificLayerPrepTime) {
	std::vector<std::string> layers{ "sauce","noodles" };
	int estimateTime = lasagna_master::preparationTime(layers, 3);
	EXPECT_EQ(estimateTime, 6);
}

TEST(Quantities, IsCallable)
{
	std::vector<std::string> layers{ "sauce","noodles" };
	lasagna_master::amount result = lasagna_master::quantities(layers);
}

TEST(Quantities, DeterminesAmountNeededInSimpleCase)
{
	std::vector<std::string> layers{ "sauce","noodles" };
	lasagna_master::amount result = lasagna_master::quantities(layers);
	EXPECT_EQ(result.noodles, 50);
	EXPECT_EQ(result.sauce, 0.2);
}

TEST(Quantities, DeterminesAmountNeededWithMultipleLayers)
{
	lasagna_master::amount needed{ 
		lasagna_master::quantities(
			{"sauce", "noodles", "sauce", "meat", "mozzarella", "noodles"}
		)
	};
	EXPECT_EQ(needed.noodles, 100);
	EXPECT_EQ(needed.sauce, 0.4);
}

}