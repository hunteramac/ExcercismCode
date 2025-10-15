#include "power_of_troy.h"

namespace troy {

	void give_new_artifact(human& possessor, std::string artifact)
	{
		possessor.possession = std::make_unique<troy::artifact>(troy::artifact{ .name = artifact });
	}

	void exchange_artifacts(std::unique_ptr<artifact>& a, std::unique_ptr<artifact>& b)
	{
		a.swap(b);
	}

	void manifest_power(human& manifestor, std::string power)
	{
		manifestor.own_power = std::make_unique<troy::power>(troy::power{ .effect = power });
	}
	void use_power(human& user, human& target)
	{
		target.influenced_by = user.own_power;
;	}
}  // namespace troy