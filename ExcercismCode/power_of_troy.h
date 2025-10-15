#pragma once

# include <string>
#include <memory>

namespace troy
{
	struct artifact {
		std::string name;
	};

	struct power {
		std::string effect;
	};

	struct human {
		std::unique_ptr<artifact> possession;
		std::shared_ptr<power> own_power;
		std::shared_ptr<power> influenced_by;
	};

	void give_new_artifact(human& possessor, std::string artifact);
	void exchange_artifacts(std::unique_ptr<artifact>& a, std::unique_ptr<artifact>& b);
	void manifest_power(human& manifestor, std::string power);
	void use_power(human& user, human& target);
} //namespace troy