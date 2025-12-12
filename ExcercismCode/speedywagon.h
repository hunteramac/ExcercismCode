#pragma once
#pragma once

#include <string>
#include <vector>

namespace speedywagon {

    struct pillar_men_sensor {
        int activity{};
        std::string location{};
        std::vector<int> data{};
    };

    int activity_counter(const pillar_men_sensor* const sensorArray, int size);
    
    bool connection_check(pillar_men_sensor* sensor);

    bool alarm_control(pillar_men_sensor* sensor);

    bool uv_alarm(pillar_men_sensor* sensor);
}  // namespace speedywagon
