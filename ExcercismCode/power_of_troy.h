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
		std::unique_ptr<power> own_power;
		std::unique_ptr<power> influenced_by;
	};
} //namespace troy