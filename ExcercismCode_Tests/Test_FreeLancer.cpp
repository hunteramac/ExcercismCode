#include "pch.h"

#include "../ExcercismCode/freelancer_rates.cpp"

TEST(FreeLancer, DailyRate1) {
	EXPECT_EQ(daily_rate(60), 480);
}

TEST(FreeLancer, ApplyDiscount1) {
	EXPECT_EQ(apply_discount(10,1), 9);
}

TEST(FreeLancer, ApplyDiscount_notNegative) {
	EXPECT_EQ(apply_discount(10, 15), 0);
}
