#include "pch.h"

#include "../ExcercismCode/lasagna.cpp"

TEST(Lasagna, OvenTime) {
	EXPECT_EQ(ovenTime(), 40);
}

TEST(Lasagna, RemainingOvenTime_notInOven) {
	EXPECT_EQ(remainingOvenTime(0), 40);
}

TEST(Lasagna, RemainingOvenTime_10minIn) {
	EXPECT_EQ(remainingOvenTime(10), 30);
}

TEST(Lasagna, RemainingOvenTime_OverTime) {
	EXPECT_EQ(remainingOvenTime(41), 0);
}

TEST(Lasagna, PrepTime1) {
	EXPECT_EQ(preparationTime(2), 4);
}

TEST(Lasagna, PrepTime2) {
	EXPECT_EQ(preparationTime(10), 20);
}

TEST(Lasagna, ElapsedTime1) {
	EXPECT_EQ(elapsedTime(3, 20), 26);
}
