
#include <string>

namespace star_map
{

	enum class System {
		BetaHydri,
		EpsilonEridani
	};

}

namespace heaven
{

class Vessel 
{
public:
	Vessel(std::string name, int identification, star_map::System system = star_map::System::BetaHydri);
};

}

