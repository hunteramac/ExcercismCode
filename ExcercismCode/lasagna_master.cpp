#include "lasagna_master.h"
#include "lasagna_master.h"
#include "lasagna_master.h"

namespace lasagna_master {

	const int NoodleLayerGrams = 50;
	const double SauceLayerLiters = 0.2;

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
				result.sauce += SauceLayerLiters;
			else if (layer == "noodles")
				result.noodles += NoodleLayerGrams;
		}

		return result;
	}

	void addSecretIngredient(std::vector<std::string>& toModify, const std::vector<std::string> completeList)
	{
	}

}  // namespace lasagna_master
