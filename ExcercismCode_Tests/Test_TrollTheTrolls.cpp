#include "pch.h";
#include "../ExcercismCode/troll_the_trolls.cpp"

using namespace hellmath;

namespace TrollTheTrolls {
	TEST(Dummy, AlwaysTrue) {
		EXPECT_TRUE(true);
	}

	TEST(DisplayPost, DontDisplayTrollPostsToUsers) {
		EXPECT_FALSE(display_post(AccountStatus::troll, AccountStatus::user));
	}

	TEST(DisplayPost, DisplayNonTrollPostsToAll) {

		// For all non troll accounts
		for (int i = 0; i < static_cast<int>(AccountStatus::END); ++i) {
			if (static_cast<AccountStatus>(i) != AccountStatus::troll) {
				AccountStatus curUserTypeNoTrolls = static_cast<AccountStatus>(i);

				// Check can display posts of these accounts to all users
				for (int j = 0; j < static_cast<int>(AccountStatus::END); ++j) {
					AccountStatus curUserType = static_cast<AccountStatus>(j);
					EXPECT_TRUE(display_post(curUserTypeNoTrolls, curUserType));
				}
			}		
		}
	}

	TEST(DisplayPost, OnlyTrollsSeeTrollPosts) {
		//Itterate over the enum
		for (int i = 0; i < static_cast<int>(AccountStatus::END); ++i) {
			AccountStatus curUserType = static_cast<AccountStatus>(i);
			if (curUserType == AccountStatus::troll)
				EXPECT_TRUE(display_post(AccountStatus::troll, curUserType));
			else
				EXPECT_FALSE(display_post(AccountStatus::troll, curUserType));
		}
	}

	TEST(PermissionCheck, call) {
		permission_check(Action::remove, AccountStatus::troll);
	}

	TEST(PermissionCheck, AllUsersCanReadPosts) {
		for (int i = 0; i < static_cast<int>(AccountStatus::END); ++i)
			EXPECT_TRUE(permission_check(Action::read, static_cast<AccountStatus>(i)));
	}

	TEST(PermissionCheck, AllUsersButGuestsCanWrite) {
		for (int i = 0; i < static_cast<int>(AccountStatus::END); ++i){
			AccountStatus user = static_cast<AccountStatus>(i);
			if (user == AccountStatus::guest)
				EXPECT_FALSE(permission_check(Action::write, user));
			else
				EXPECT_TRUE(permission_check(Action::write, user));
		}
	}

	TEST(PermissionCheck, OnlyModeratorsCanRemovePosts) {
		for (int i = 0; i < static_cast<int>(AccountStatus::END); ++i){
			AccountStatus user = static_cast<AccountStatus>(i);
			if (user == AccountStatus::mod)
				EXPECT_TRUE(permission_check(Action::remove, user));
			else
				EXPECT_FALSE(permission_check(Action::remove, user));
		}
	}
	TEST(ValidPlayerCombination, GuestPairingInvalid) {
		for (int i = 0; i < static_cast<int>(AccountStatus::END); ++i) {
			AccountStatus curUser = static_cast<AccountStatus>(i);
			EXPECT_FALSE(
				valid_player_combination(
					curUser,
					AccountStatus::guest
			));
			EXPECT_FALSE(
				valid_player_combination(
					AccountStatus::guest,
					curUser
			));
		}
	}

	TEST(ValidPlayerCombination, TrollPairingValidOnlyWithOtherTrolls){
		EXPECT_TRUE(
			valid_player_combination(
				AccountStatus::troll, 
				AccountStatus::troll
		));

		for (int i = 0; i < static_cast<int>(AccountStatus::END); ++i) {
			AccountStatus curUser = static_cast<AccountStatus>(i);
			if (curUser == AccountStatus::troll)
				break;

			EXPECT_FALSE(
				valid_player_combination(
					AccountStatus::troll,
					curUser
				)
			);
			EXPECT_FALSE(
				valid_player_combination(
					curUser, 
					AccountStatus::troll
				)
			);
		}
	}

	TEST(HasPriority, UserHasPriorityOverTroll)
	{
		EXPECT_TRUE
		(
			has_priority(AccountStatus::user, AccountStatus::troll)
		);
	}

	TEST(HasPriority, GuestDoesntHavePriorityOverMod)
	{
		EXPECT_FALSE
		(
			has_priority(AccountStatus::guest, AccountStatus::mod)
		);
	}

	TEST(HasPriority, EqualUserTypesStrictlyHigher)
	{
		EXPECT_FALSE
		(
			has_priority(AccountStatus::mod, AccountStatus::mod)
		);

		EXPECT_FALSE
		(
			has_priority(AccountStatus::user, AccountStatus::user)
		);

		EXPECT_FALSE
		(
			has_priority(AccountStatus::guest, AccountStatus::guest)
		);

		EXPECT_FALSE
		(
			has_priority(AccountStatus::troll, AccountStatus::troll)
		);
	}

	TEST(HasPriority, ModHasPriorityOverUser)
	{
		EXPECT_TRUE
		(
			has_priority(AccountStatus::mod, AccountStatus::user)
		);
	}

	TEST(HasPriority, UserHasPriorityOverGuest)
	{
		EXPECT_TRUE
		(
			has_priority(AccountStatus::user, AccountStatus::guest)
		);
	}

	TEST(HasPriority, GuestDoesntHavePriorityUser)
	{
		EXPECT_FALSE
		(
			has_priority(AccountStatus::guest, AccountStatus::user)
		);
	}
};