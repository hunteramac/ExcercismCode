#include "pch.h";
#include "../ExcercismCode/troll_the_trolls.cpp"

using namespace hellmath;

namespace TrollTheTrolls {
	TEST(Dummy, AlwaysTrue) {
		EXPECT_TRUE(true);
	}

	TEST(DisplayPost, DontDisplayTrollPostsToUsers) {
		bool result = display_post(AccountStatus::troll, AccountStatus::user);
		EXPECT_FALSE(result);
	}
};