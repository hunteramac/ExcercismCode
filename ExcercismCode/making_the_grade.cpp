#include <vector>
#include <array>
#include <string>

std::vector<int> round_down_scores(const std::vector<double> studentScores) {
	//casting is truncation
	return std::vector<int>(studentScores.begin(), studentScores.end());
}

int count_failed_students(const std::vector<int> studentScores) {
	int count = 0;

	for (auto studentScore : studentScores)
		if (studentScore <= 40) count++;

	return count;
}

std::vector<int> above_threshold(const std::vector<int> studentScores, const int threshold) {
	std::vector<int> aboveThreshold;

	for (auto studentScore : studentScores)
		if (studentScore >= threshold)
			aboveThreshold.push_back(studentScore);
	return aboveThreshold;
}

#include <cmath>

std::array<int, 4> letter_grades(const int highestScore) {
	int wHighestScore = highestScore;

	std::array<int, 4> letterGradeThresholds({41,41,41,41});

	if (wHighestScore > 100) {
		wHighestScore = 100;
	}
	else if (wHighestScore < 0) {
		wHighestScore = 0;
	}

	int diff = (wHighestScore - 40)/4;
	if (diff < 0) {
		diff = 0;
	}

	for (int i = 0; i < letterGradeThresholds.size(); i++) {
		letterGradeThresholds[i] += diff * i;
	}

	return letterGradeThresholds;
}

// We only use this in student ranking function at the moment
struct StudentScore {
	int studentScore;
	std::string studentName;
};

//#include <ranges>
#include <algorithm>
//unless you have ranges, simplest is just

/// <summary>
/// Produces set of student rankings in descending order.
/// </summary>
/// <param name="studentScores"> No order required </param>
/// <param name="studentNames"> Expected to be in order matching the score. </param> 
/// <returns>vector holding string representation of student ranking, in descending order</returns>
std::vector<std::string> student_ranking(std::vector<int> studentScores, std::vector<std::string> studentNames) {
	//probably should do something if user provides uneven vectors? do best given what we can
	//this will prevent an out of bounds occuring
	int minSize = (studentScores.size() < studentNames.size()) ? studentScores.size() : studentNames.size();

	//zip the scores
	
	std::vector<StudentScore> StudentScores;
	for (int i = 0; i < minSize; ++i) {
		StudentScore tempScore;
		tempScore.studentName = studentNames[i];
		tempScore.studentScore = studentScores[i];

		StudentScores.push_back(tempScore);
	}
	
	//sort them descending order
	std::sort(StudentScores.begin(), StudentScores.end(), [](StudentScore a, StudentScore b) { return a.studentScore > b.studentScore; });

	//make display vector
	std::vector<std::string> DisplayStudentRankings;
	for (int i = 0; i < minSize; ++i) {
		DisplayStudentRankings.push_back(
			std::to_string(i+1) + ". " + StudentScores[i].studentName + ": " + std::to_string(StudentScores[i].studentScore)
		);
	}
	
	return DisplayStudentRankings;
}

std::string perfect_score(std::vector<int> studentScores, std::vector<std::string> studentNames){
	for (int i = 0; i < studentScores.size(); ++i) {
		if (studentScores[i] == 100) {
			return studentNames[i];
		}
	}
	return "";
}