#include "pch.h"

// hotkey to trigger intellisense is ctrl space
#include "../ExcercismCode/interest_is_interesting.cpp"

//0, of tdd, get a test harness in place dummy passing test 
namespace InterestInteresting {
	TEST(InterestRate, NegativeBalance) {
		EXPECT_EQ(interest_rate(-1), 3.213);
	}

	TEST(InterestRate, posBracket1) {
		EXPECT_EQ(interest_rate(0), 0.5);
		EXPECT_EQ(interest_rate(999), 0.5);
	}

	TEST(InterestRate, posB2) {
		EXPECT_EQ(interest_rate(1000), 1.621);
		EXPECT_EQ(interest_rate(4999), 1.621);
	}

	TEST(InterestRate, posB3) {
		EXPECT_EQ(interest_rate(5000), 2.475);
	}

	TEST(YearlyInterest, yearly1) {
		EXPECT_EQ(yearly_interest(200), 1);
	}

	TEST(AnnualBalanceUpdate, update1){
		EXPECT_EQ(annual_balance_update(200), 201);
	}
}