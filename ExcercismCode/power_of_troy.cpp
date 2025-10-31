#include "power_of_troy.h"

namespace troy {

	void give_new_artifact(human& possessor, std::string artifact)
	{
		auto tempArtifact = troy::artifact{};
		tempArtifact.name = artifact;
		possessor.possession = std::make_unique<troy::artifact>(tempArtifact);
		// can't use designated initializers with excercism tests
		//possessor.possession = std::make_unique<troy::artifact>(troy::artifact{ .name = artifact });
	}

	void exchange_artifacts(std::unique_ptr<artifact>& a, std::unique_ptr<artifact>& b)
	{
		a.swap(b);
	}

	void manifest_power(human& manifestor, std::string power)
	{
		auto tempPower = troy::power{};
		tempPower.effect = power;
		manifestor.own_power = std::make_unique<troy::power>(tempPower);

		//manifestor.own_power = std::make_unique<troy::power>(troy::power{ .effect = power });
	}
	void use_power(human& user, human& target)
	{
		target.influenced_by = user.own_power;
;	}
	int power_intensity(human& powered)
	{
		return powered.own_power.use_count();
	}
}  // namespace troy