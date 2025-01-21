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
};