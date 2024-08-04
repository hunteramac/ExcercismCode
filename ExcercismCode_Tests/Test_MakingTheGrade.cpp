#include "pch.h"
#include "../ExcercismCode/making_the_grade.cpp"


TEST(MakingTheGrade, RoundDownScores_Simple) {
	//arrange
	std::vector<double> Input = { 0.0 };
	std::vector<int> Expected_Output = { 0 };
	
	//assert
	EXPECT_EQ(
		round_down_scores(Input),
		Expected_Output
	);
}

TEST(MakingTheGrade, RoundDownScores_1) {
	//arrange
	std::vector<double> Input = { 75.5 , 99.99};
	std::vector<int> Expected_Output = { 75, 99 };

	//assert
	EXPECT_EQ(
		round_down_scores(Input),
		Expected_Output
	);
}

TEST(MakingTheGrade, RoundDownScores_2) {
	//arrange
	std::vector<double> Input = { 15.3333, 5.0001, 100.5};
	std::vector<int> Expected_Output = { 15, 5 , 100 };

	//assert
	EXPECT_EQ(
		round_down_scores(Input),
		Expected_Output
	);
}

TEST(MakingTheGrade, CountFailedStudents_1) {
	std::vector<int> Input = { 25, 40, 90 };

	EXPECT_EQ(count_failed_students(Input), 2);
}

//greater then 40 to pass
TEST(MakingTheGrade, CountFailedStudents_2) {
	std::vector<int> Input = { 39, 25, 40, 90 };

	EXPECT_EQ(count_failed_students(Input), 3);
}

TEST(MakingTheGrade, AboveThreshold_1) {
	std::vector<int> Input = { };

	EXPECT_EQ(above_threshold(Input, 0), std::vector<int> {});
}

TEST(MakingTheGrade, AboveThreshold_2) {
	std::vector<int> Input = {100};

	EXPECT_EQ(above_threshold(Input, 0), std::vector<int> {100});
}

TEST(MakingTheGrade, AboveThreshold_3) {
	std::vector<int> Input = { 50, 100, 60 , 80, 75};
	std::vector<int> ExpectedResult = { 100, 80, 75 };

	EXPECT_EQ(above_threshold(Input, 75), ExpectedResult);
}