#include "pch.h";
#include "../ExcercismCode/troll_the_trolls.cpp"

using namespace hellmath;

namespace TrollTheTrolls {

	std::vector<AccountStatus> allUserTypes = {
		AccountStatus::troll,
		AccountStatus::guest,
		AccountStatus::user,
		AccountStatus::mod
	};
	TEST(Dummy, AlwaysTrue) {
		EXPECT_TRUE(true);
	}

	TEST(DisplayPost, DontDisplayTrollPostsToUsers) {
		EXPECT_FALSE(display_post(AccountStatus::troll, AccountStatus::user));
	}

	TEST(DisplayPost, DisplayNonTrollPostsToAll) {
		// How can we paramterize this test?
		std::vector<AccountStatus> noTrolls = {
			AccountStatus::guest,
			AccountStatus::user,
			AccountStatus::mod
		};

		for( auto curTypeNoTrolls : noTrolls)
			for (auto curType: allUserTypes)
				EXPECT_TRUE(display_post(curTypeNoTrolls, curType));
	}

	TEST(DisplayPost, OnlyTrollsSeeTrollPosts) {
		// in C++ there appears to not currently be a good way to itterate over an Enum'S possible values
		// therefore, we must make do in these tests with arrays that will become out of date if new
		// entries to the enum are added.
		std::vector<AccountStatus> Types = {
			AccountStatus::guest,
			AccountStatus::user,
			AccountStatus::mod
		};

		EXPECT_TRUE(display_post(AccountStatus::troll, AccountStatus::troll));

		for (auto curType : Types) {
			EXPECT_FALSE(display_post(AccountStatus::troll, curType));
		}
	}

	TEST(PermissionCheck, call) {
		permission_check(Action::remove, AccountStatus::troll);
	}

	TEST(PermissionCheck, AllUsersCanReadPosts) {
		for(auto user : allUserTypes)
			EXPECT_TRUE(permission_check(Action::read, user));
	}

	TEST(PermissionCheck, AllUsersButGuestsCanWrite) {
		for (auto user : allUserTypes)
			if (user == AccountStatus::guest)
				EXPECT_FALSE(permission_check(Action::write, user));
			else
				EXPECT_TRUE(permission_check(Action::write, user));
	}

	TEST(PermissionCheck, OnlyModeratorsCanRemovePosts) {
		for (auto user : allUserTypes) {
			if (user == AccountStatus::mod)
				EXPECT_TRUE(permission_check(Action::remove, user));
			else
				EXPECT_FALSE(permission_check(Action::remove, user));
		}
	}
	TEST(ValidPlayerCombination, call) {
		valid_player_combination(AccountStatus::troll, AccountStatus::guest);
	}
};