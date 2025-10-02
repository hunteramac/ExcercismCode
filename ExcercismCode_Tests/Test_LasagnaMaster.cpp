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

TEST(AddScecretIngredient, IsCallable)
{
	std::vector<std::string> ingredientsList = { "noodles","sauce","?"};
	std::vector<std::string> secretList = { "noodles","sauce","kampot pepper" };


	lasagna_master::addSecretIngredient(ingredientsList, secretList);
}

TEST(AddScecretIngredient, AddsSecretIngredient1)
{
	std::vector<std::string> ingredientsList = { "noodles","sauce","?" };
	std::vector<std::string> secretList = { "noodles","sauce","kampot pepper" };


	lasagna_master::addSecretIngredient(ingredientsList, secretList);

	EXPECT_EQ(ingredientsList, secretList);
}

TEST(AddScecretIngredient, AddsSecretIngredientWhenListsAreDifferent)
{
	std::vector<std::string> ingredientsList = { "noodles","meat","sauce","mozzerella","?"};
	std::vector<std::string> secretList = { "noodles","sauce","kampot pepper" };


	lasagna_master::addSecretIngredient(ingredientsList, secretList);

	std::vector<std::string> expectList = { "noodles","meat","sauce","mozzerella","kampot pepper" };
	EXPECT_EQ(ingredientsList, expectList);
}

TEST(AddScecretIngredient, DoesntCrashIfUserProvidedEmptyToReplaceList)
{
	std::vector<std::string> ingredientsList = {};
	std::vector<std::string> secretList = { "noodles","sauce","kampot pepper" };

	lasagna_master::addSecretIngredient(ingredientsList, secretList);
}

TEST(ScaleRecipe, CanBeCalled)
{
	std::vector<double> quantities{ 1.2,3.6,10.5 };
	lasagna_master::scaleRecipe(quantities, 4);
}

TEST(ScaleRecipe, ScalesQuantities1)
{
	std::vector<double> quantities{ 1.2,3.6,10.5 };
	std::vector<double> expectedAmounts{ 2.4, 7.2, 21 };
	EXPECT_EQ(expectedAmounts, lasagna_master::scaleRecipe(quantities, 4));
}

TEST(AddSecretIngredientSecret, AddsToEnd)
{
	std::vector<std::string> myList{ "noodles", "meat", "sauce", "mozzarella", "?" };
	std::string secretIngredient{ "spice melange" };
	lasagna_master::addSecretIngredient(myList, secretIngredient);

	std::vector<std::string> expectList{ "noodles", "meat", "sauce", "mozzarella", "spice melange" };
	EXPECT_EQ(myList, expectList);
}

}