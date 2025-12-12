#include "speedywagon.h"
#include "speedywagonUtils.h"

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

    bool connection_check(pillar_men_sensor* sensor)
    {
        return sensor;
    }

    bool alarm_control(pillar_men_sensor* sensor)
    {
        if (!connection_check(sensor))
            return false;

        if(sensor->activity > 0)
            return true;

        return false;
    }

    bool uv_alarm(pillar_men_sensor* sensor)
    {
        uv_light_heuristic(&sensor->data);
        return false;
    }

}  // namespace speedywagon
