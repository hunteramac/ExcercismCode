#include <vector>

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