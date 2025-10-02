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
	};
} //namespace troy