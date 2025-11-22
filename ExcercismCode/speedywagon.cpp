#include "speedywagon.h"

namespace speedywagon {

    // Enter your code below:

    int activity_counter(const pillar_men_sensor* const sensorArray, int size)
    {
        int activityCounter = 0;
        for (int i = 0; i<size; ++i)
        {
            activityCounter += sensorArray[i].activity;
        }
        return activityCounter;
    }

    // Please don't change the interface of the uv_light_heuristic function
    int uv_light_heuristic(std::vector<int>* data_array) {
        double avg{};
        for (auto element : *data_array) {
            avg += element;
        }
        avg /= data_array->size();
        int uv_index{};
        for (auto element : *data_array) {
            if (element > avg) ++uv_index;
        }
        return uv_index;
    }

    bool connection_check(pillar_men_sensor* sensor)
    {
        return sensor;
    }

}  // namespace speedywagon
