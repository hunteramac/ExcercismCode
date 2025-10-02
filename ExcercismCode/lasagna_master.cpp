#include "lasagna_master.h"
#include "lasagna_master.h"
#include "lasagna_master.h"
#include <algorithm>

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

	void addSecretIngredient(std::vector<std::string>& toModify, const std::vector<std::string>& completeList)
	{
		// The end of the input list should be replaced with the secret ingredient.
		// The end of the complete list has the secret ingredient.
		//toModify[toModify.size()] = completeList.end();
		if(!toModify.empty())
			toModify.back() = completeList.back();
	}

	void addSecretIngredient(std::vector<std::string>& toModify, std::string secretIngredient)
	{
		if (!toModify.empty())
			toModify.back() = secretIngredient;
	}

	std::vector<double> scaleRecipe(std::vector<double> quantities, int portions)
	{
		std::transform(quantities.begin(), quantities.end(), quantities.begin(), [portions](double v) { return v * portions / 2; });
		//auto result = quantities | std::views::transform([](double v) { return v * 1 / 2; });
			
		return quantities;
	}

}  // namespace lasagna_master
