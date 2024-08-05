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


TEST(MakingTheGrade, LetterGradeSpecialCase) {
	//higher then 100
	std::array<int, 4> expect100Spread({ 41, 56, 71, 86 });
	std::array<int, 4> expectLowSpread({ 41, 41, 41, 41 });

	EXPECT_EQ(
		letter_grades(1000),
		expect100Spread
	);

	//negative
	EXPECT_EQ(
		letter_grades(-1000),
		expectLowSpread
	);

	//zero
	EXPECT_EQ(
		letter_grades(0),
		expectLowSpread //can't remember/don't know if I canS how to initialize this with r value (no name)
	);
}
TEST(MakingTheGrade, LetterGrade) {
	
	std::array<int, 4> expect100Spread({ 41, 56, 71, 86 });
	EXPECT_EQ(
		letter_grades(100),
		expect100Spread
	);

	std::array<int, 4> expect88Spread({ 41, 53, 65, 77 });
	EXPECT_EQ(
		letter_grades(88),
		expect88Spread
	);
}

TEST(MakingTheGrade, StudentRanking_MethodCompile) {
	std::vector<int> StudentScores = { 0 };
	std::vector<std::string> StudentNames = { "Dummy" };
	student_ranking(StudentScores, StudentNames);
}

TEST(MakingTheGrade, StudentRanking_1Entry) {
	std::vector<int> StudentScores = { 80 };
	std::vector<std::string> StudentNames = { "Otto Bild" };
	EXPECT_EQ(
		student_ranking(StudentScores, StudentNames),
		std::vector<std::string>({
			"1 Otto Bild 80"
		})
	);
}

TEST(MakingTheGrade, StudentRanking_MultiEntry) {
	std::vector<int> StudentScores = { 80, 65};
	std::vector<std::string> StudentNames = { "Otto Bild" , "Samwise Gamgee"};
	EXPECT_EQ(
		student_ranking(StudentScores, StudentNames),
		std::vector<std::string>({
			"1 Otto Bild 80",
			"2 Samwise Gamgee 65"
			})
	);
}