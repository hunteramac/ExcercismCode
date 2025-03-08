
#include <string>

namespace star_map
{

	enum class System {
		Sol,
		BetaHydri,
		AlphaCentauri,
		DeltaEridani,
		EpsilonEridani,
		Omicron2Eridani
	};

}

namespace heaven
{
	class Vessel 
	{
	public:
		
		std::string name;
		
		Vessel(std::string name, int identification, star_map::System system = star_map::System::Sol);

		star_map::System current_system;

		int generation;

		Vessel replicate(std::string name) const;

		int busters;

		void make_buster();

		bool shoot_buster();
	};

	std::string get_older_bob(Vessel v1, Vessel v2);

	bool in_the_same_system(Vessel v1, Vessel v2);

}

