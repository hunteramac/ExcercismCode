#pragma once

#include <string>
#include <vector>

namespace lasagna_master {

    struct amount {
        int noodles;
        double sauce;
    };

    int preparationTime(std::vector<std::string>layers, int averagePreparationTime = 2);


    amount quantities(std::vector<std::string>layers);

    void addSecretIngredient(std::vector<std::string> &toModify, const std::vector<std::string> &completeList);
    void addSecretIngredient(std::vector<std::string>& toModify, std::string secretIngredient);

    std::vector<double> scaleRecipe(std::vector<double> quantities, int portions);
    
}  // namespace lasagna_master
