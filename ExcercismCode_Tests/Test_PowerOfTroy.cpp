#include "pch.h"

#include "../ExcercismCode/power_of_troy.h"

namespace PowerOfTroy
{
TEST(Humans, CanBeInstantiated)
{
	troy::human mindy_mccready{};
}

TEST(Humans, PossessArtifacts)
{
	troy::human mindy_mccready{};
	EXPECT_EQ(mindy_mccready.possession, nullptr);

	troy::artifact holyGrail{"The Holy Grail"};
	mindy_mccready.possession = std::make_unique<troy::artifact>(holyGrail);

	EXPECT_EQ(mindy_mccready.possession.get()->name, "The Holy Grail");
}

} //namespace PowerOfTroy