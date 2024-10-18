#include "pch.h"

#include "../ExcercismCode/ellens_alien_game.cpp"
using namespace targets;

namespace EllensAlienGame {
TEST(Dummy, testHarnessWorks) {
	EXPECT_TRUE(true);
}

TEST(Constructor, canBeCalled) {
	// It can construct
	Alien testAlien(5, 2);
}

TEST(Coordinates, canBeAccessed) {
	Alien testAlien(5, 2);

	EXPECT_EQ(5, testAlien.x_coordinate);
	EXPECT_EQ(2, testAlien.y_coordinate);
}

TEST(Health, canBeAccessed) {
	Alien testAlien(5, 2);

	// ACT
	int result = testAlien.get_health();

	EXPECT_EQ(result, 3);
}

//fixture to construct an alien?

TEST(Hit, DecrementsHealthByOne) {
	// ARRANGE
	Alien testAlien(5, 2);
	int prevHealth = testAlien.get_health();

	//ACT
	testAlien.hit();
	int newHealth = testAlien.get_health();

	// ASSERT
	EXPECT_EQ(newHealth, prevHealth - 1);
}

TEST(IsAlive, onAlienConstruct)
{
	Alien testAlien(5, 2);
	EXPECT_TRUE(testAlien.is_alive());
}

TEST(IsAlive, onAlienHit3x)
{
	Alien testAlien(5, 2);

	// defn efficent way to itterate some number times
	//post increment essential here, otherwise only executes twice
	for (auto _ = 3; _--;) testAlien.hit();
	//for (int i = 0; i < 3; ++i) {
	//	testAlien.hit();
	//}

	EXPECT_EQ(testAlien.get_health(), 0);
	EXPECT_FALSE(testAlien.is_alive());
}

}