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
};