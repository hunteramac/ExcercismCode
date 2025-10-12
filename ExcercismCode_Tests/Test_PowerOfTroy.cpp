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

TEST(GiveNewArtifact, CanGiveArtifact)
{
	troy::human hadrian_marlowe{};
	troy::give_new_artifact(hadrian_marlowe, "Adamantine arm");

	EXPECT_EQ(hadrian_marlowe.possession->name, "Adamantine arm");
}

TEST(ExchangeArtifacts, CanExchange)
{
	troy::human valeros{};
	troy::give_new_artifact(valeros, "Headband of intellect");
	troy::human ezren{};
	troy::give_new_artifact(ezren, "Flame tongue longsword");

	troy::exchange_artifacts(valeros.possession, ezren.possession);

	EXPECT_EQ(valeros.possession->name, "Flame tongue longsword");
	EXPECT_EQ(ezren.possession->name, "Headband of intellect");
}

TEST(ManifestPower, manifests)
{
	troy::human patience_kys{};
	troy::manifest_power(patience_kys, "telekinesis");
	EXPECT_EQ(patience_kys.own_power->effect, "telekinesis");
}

} //namespace PowerOfTroy