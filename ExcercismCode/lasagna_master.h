#pragma once

#include <string>
#include <vector>

namespace lasagna_master {

    struct amount {
        int noodles;
        double sauce;
    };

    int preparationTime(std::vector<std::string>layers, int averagePreparationTime = 2);

}  // namespace lasagna_master
