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

std::vector<std::string> student_ranking(std::vector<int> studentScores, std::vector<std::string> studentNames) {
	std::vector<std::string> StudentRankings;
	StudentRankings.push_back(
		"1 " + studentNames[0] + " " + std::to_string(studentScores[0])
	);
	return StudentRankings;
}