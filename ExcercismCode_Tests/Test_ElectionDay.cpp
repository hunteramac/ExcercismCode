#include "pch.h"

#include "../ExcercismCode/election_day.cpp"

using namespace election;

namespace ElectionDay {
	TEST(Dummy, AlwaysTrue) {
		EXPECT_TRUE(true);
	}

	TEST(VoteCount, NumVotes1) {
		ElectionResult hamilton{ "Alex", 1804 };
		EXPECT_EQ(vote_count(hamilton), 1804);
	}

	TEST(IncrementVoteCount, IncrementByOne) {
		ElectionResult hamilton{ "Alex", 1804 };

		increment_vote_count(hamilton, 1);

		EXPECT_EQ(1805, vote_count(hamilton));

		increment_vote_count(hamilton, 3);

		EXPECT_EQ(1808, vote_count(hamilton));
	}

	TEST(DetermineResult, PresidentPedro) {
		ElectionResult sanchez{ "Pedro", 471 };
		ElectionResult wheatley{ "Summer", 340 };
		std::vector<ElectionResult> final_count{ sanchez, wheatley };

		ElectionResult& winner = determine_result(final_count);

		EXPECT_EQ(winner.name,"President Pedro");
	}

	// write a test capturing a different order, requiring tested function
	// to actually compare the votes to determine the winner
	TEST(DetermineResult, PresidentSummer) {
		ElectionResult sanchez{ "Pedro", 340 };
		ElectionResult wheatley{ "Summer", 471 };
		std::vector<ElectionResult> final_count{ sanchez, wheatley };

		ElectionResult& winner = determine_result(final_count);

		EXPECT_EQ(winner.name, "President Summer");
	}
};