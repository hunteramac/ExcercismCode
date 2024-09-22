#include "pch.h"

// hotkey to trigger intellisense is ctrl space
#include "../ExcercismCode/interest_is_interesting.cpp"

//0, of tdd, get a test harness in place dummy passing test 
namespace InterestInteresting {
	TEST(InterestRate, NegativeBalance) {
		EXPECT_EQ(interest_rate(-1), 3.213);
	}

	TEST(InterestRate, posBracket1) {
		EXPECT_EQ(interest_rate(10), 0.5);
	}
}