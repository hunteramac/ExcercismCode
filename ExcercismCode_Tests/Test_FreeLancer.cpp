#include "pch.h"

#include "../ExcercismCode/freelancer_rates.cpp"

TEST(FreeLancer, DailyRate1) {
	EXPECT_EQ(daily_rate(60), 480);
}

TEST(FreeLancer, ApplyDiscount1) {
	EXPECT_EQ(apply_discount(10,10), 9);
}

TEST(FreeLancer, ApplyDiscount2) {
	EXPECT_EQ(apply_discount(10, 50), 5);
}

TEST(FreeLancer, ApplyDiscount3) {
	EXPECT_EQ(apply_discount(10, 49), 5.1);
}

TEST(FreeLancer, ApplyDiscount_notNegative) {
	EXPECT_EQ(apply_discount(10, 215), 0);
}

TEST(FreeLancer, MonthlyRate1) {
	EXPECT_EQ(monthly_rate(77,10.5), 12130);
}

TEST(FreeLancer, MonthlyRate2_edgecase_0) {
	EXPECT_EQ(monthly_rate(0, 0), 0);
}

TEST(FreeLancer, MonthlyRate2_edgecase_negative_input) {
	EXPECT_EQ(monthly_rate(-20, -10), 0);
}

//monthly_rate()
// it should
// round up
TEST(FreeLancer, MonthlyRate_RoundsUp1) {
	EXPECT_EQ(monthly_rate(62.8, 0), 11'053);
}

TEST(FreeLancer, DaysInBudget_NoBudget) {
	EXPECT_EQ(days_in_budget(0,10,0), 0);
}

TEST(FreeLancer, DaysInBudget_EvenSmallBudget) {
	EXPECT_EQ(days_in_budget(100, 10, 0), 1);
}

TEST(FreeLancer, DaysInBudget_excerCase) {
	EXPECT_EQ(days_in_budget(20'000, 80, 11), 35);
}

//write a boundary test for days_in_budget
TEST(FreeLancer, DaysInBudget_negativeBudget) {
	EXPECT_EQ(days_in_budget(-80, 80, 0), 0);
}

TEST(FreeLancer, DaysInBudget_BoundaryDaysMoreBudget) {
	//assumes 8hr days
	EXPECT_EQ(days_in_budget(79.9, 10, 0), 0);
	EXPECT_EQ(days_in_budget(80, 10, 0), 1);
}