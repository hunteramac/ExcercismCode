#include "pch.h"

#include "../ExcercismCode/ellens_alien_game.cpp"

namespace EllensAlienGame {
	TEST(Dummy, testHarnessWorks) {
		EXPECT_TRUE(true);
	}

	TEST(Constructor, canBeCalled) {
		// It can construct
		Alien testAlien(5, 2);
	}
}