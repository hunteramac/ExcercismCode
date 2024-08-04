#include "pch.h"

#include "../ExcercismCode/pacman_rules.cpp"

//is there a way to group tests by method?
TEST(Pacman, CanEatGhost) {
	//it should
	//return true if power pellet and ghost contact
	EXPECT_EQ(
		can_eat_ghost(true,true),
		true
	);

	//how do we parameterize this test?
	//return false in all other cases
	EXPECT_EQ(
		can_eat_ghost(false, true),
		false
	);
	EXPECT_EQ(
		can_eat_ghost(false, false),
		false
	);
	EXPECT_EQ(
		can_eat_ghost(true, false),
		false
	);
}

TEST(Pacman, Scored1) {
	EXPECT_EQ(
		scored(false, false),
		false
	);

	EXPECT_EQ(
		scored(true, false),
		true
	);

	EXPECT_EQ(
		scored(false, true),
		true
	);

	EXPECT_EQ(
		scored(true, true),
		true
	);
}

TEST(Pacman, Lost) {
	

	EXPECT_EQ(lost(false, false), false);

	EXPECT_EQ(
		lost(false, true),
		true
	);

	EXPECT_EQ(lost(true, false),false);
	EXPECT_EQ(lost(true, true), false);
}

TEST(Pacman, Win) {
	//enumerating all combinations like this is not particularly efficent
	
	//can see input boundaries (to avoid enumerating all cases)
	//power pellet + eaten all dots enables contact ghost true to not = false
	EXPECT_EQ(
		won(true, true, true),
		true
	);

	EXPECT_EQ(
		won(true, true, false),
		true
	);

	// eatenalldots true doesnt win vs true contact ghost, unless powerpellet
	EXPECT_EQ(
		won(true, false, true),
		false
	);

	//clearly see eatenAllDots wins out -> sample single point randomly. paramemterize
	EXPECT_EQ(
		won(false, true, true),
		false
	);

	EXPECT_EQ(
		won(false, true, false),
		false
	);

	EXPECT_EQ(
		won(false, false, true),
		false
	);

	EXPECT_EQ(
		won(false, false, false),
		false
	);
	//
}