#include "lasagna_master.h"
#include "lasagna_master.h"

namespace lasagna_master {

	// TODO: add your solution here

	int preparationTime(std::vector<std::string> layers, int averagePreparationTime)
	{
		return static_cast<int>(layers.size()) * averagePreparationTime;
	}

	amount quantities(std::vector<std::string> layers)
	{
		amount result = { 0,0 };

		for (std::string layer : layers)
		{
			if (layer == "sauce")
				result.sauce += 0.2;
			else if (layer == "noodles")
				result.noodles += 50;
		}

		return result;
	}

}  // namespace lasagna_master
