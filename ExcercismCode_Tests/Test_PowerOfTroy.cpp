#include "pch.h"

#include "../ExcercismCode/power_of_troy.h"

namespace PowerOfTroy
{
TEST(Humans, CanBeInstantiated)
{
	troy::human mindy_mccready{};
}

TEST(Humans, CanPossessArtifacts)
{
	troy::human mindy_mccready{};
	EXPECT_EQ(mindy_mccready.possession, nullptr);

	troy::artifact holyGrail{"The Holy Grail"};
	mindy_mccready.possession = std::make_unique<troy::artifact>(holyGrail);

	EXPECT_EQ(mindy_mccready.possession.get()->name, "The Holy Grail");
}

TEST(Humans, CanHavePowers)
{
	troy::human stephanie_edgley{};
	EXPECT_EQ(stephanie_edgley.own_power, nullptr);

	troy::power elementalist{.effect="Element control"};

	troy::human valkyrie_cain{.own_power = std::make_unique<troy::power>(elementalist)};

	EXPECT_EQ(valkyrie_cain.own_power.get()->effect, "Element control");
}

TEST(Humans, CanBeInfluencedByPowers)
{
	troy::power infernal{ .effect = "Hell fire" };
	troy::human Mizora{.own_power = std::make_unique<troy::power>(infernal)};

	troy::human wyll_ravengaurd{.influenced_by = std::make_unique<troy::power>(infernal)};
	
	EXPECT_EQ(wyll_ravengaurd.influenced_by.get()->effect, "Hell fire");
}

} //namespace PowerOfTroy