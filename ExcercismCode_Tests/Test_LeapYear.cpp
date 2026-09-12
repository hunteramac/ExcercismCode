//#include "pch.h" //#include "gtest/gtest.h"
//#include "../ExcercismCode/leap.h"
//
//namespace LeapYear{
//
//struct LeapYearTest
//{
//	int year;
//	bool isLeapYear;
//};
//	
//class ParamLeapYear : public ::testing::TestWithParam<LeapYearTest>{};
//
//TEST_P(ParamLeapYear, ChecksLeapYear)
//{
//	const auto& testYear = GetParam();
//	bool result = leap::is_leap_year(testYear.year);
//	EXPECT_EQ(result, testYear.isLeapYear);
//}
//
//INSTANTIATE_TEST_CASE_P(
//	LeapTestsParam,
//	ParamLeapYear,
//	::testing::Values(
//		LeapYearTest{ 2015, false }, // not divisible by 4
//		LeapYearTest{ 2016, true }, // divisible by 4
//		LeapYearTest{ 2000, true }, // divisible by 4 and 400
//		LeapYearTest{ 1997, false }, // not divisible by 4
//		LeapYearTest{ 1900, false } //not divisible by 400
//	)
//);
//
//TEST(LeapYearBadData, passZero)
//{
//	leap::is_leap_year(0);
//}
//
//TEST(LeapYearBadData, negative)
//{
//	leap::is_leap_year(-100);
//}
//}