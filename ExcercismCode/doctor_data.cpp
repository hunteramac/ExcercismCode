#include "doctor_data.h"

heaven::Vessel::Vessel(std::string name, int identification, star_map::System system)
{
	this->name = name;
	current_system = system;
	generation = identification;
	busters = 0;
}

// creates temporary object
heaven::Vessel heaven::Vessel::replicate(std::string name) const
{
	return Vessel(name, generation+1, current_system);
}

void heaven::Vessel::make_buster()
{
	++busters;
}

bool heaven::Vessel::shoot_buster()
{
	if (busters > 0)
	{
		--busters;
		return true;
	}
	else
	{
		return false;
	}
}

std::string heaven::get_older_bob(Vessel v1, Vessel v2)
{
	if (v1.generation <= v2.generation)
		return v1.name;
	else
		return v2.name;
}

bool heaven::in_the_same_system(Vessel v1, Vessel v2)
{
	return v1.current_system == v2.current_system;
}
