#include "speedywagon.h"

namespace speedywagon {


    /// <summary>
    /// Appears to finds differences (outliers) in the data and computes a sum based on that.
    /// </summary>
    /// <param name="data_array"></param>
    /// <returns></returns>
    int uv_light_heuristic(std::vector<int>* data_array) {
        //if (sensorEnvironment == SensorEnvironment::Test)
        //{
        //    // Testing override
        //    return fakeUvIndexReturn;
        //}
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

    // Enter your code below:
    int activity_counter(const pillar_men_sensor* const sensorArray, int size)
    {
        if (!sensorArray)
            return 0;

        if (size < 0)
            return 0;

        unsigned int activityCounter = 0;
        for (int i = 0; i<size; ++i)
        {
            // given legacy sensors can have 'negative' activity reports
            // and unsigned int doesn't appear to be supported.
            // 
            // choice between:
            // 1. discarding the reading <- current safest option. 
            //      User needs to know about this to perform 'bad reading' via other methods in case these readings matter.
            //      Ex Detect Pillar men intrusions have taking control of a remote sensor on the network / bad readings from interference. etc 
            // 2. adding absoloute value - seems incorrect. A negative reading is not going to mean what a positive reading means ever.
            // 3. summing the negative activity with positive - Danger! Pillar men might exploit this to mask their attacks 
            //  Eg zero activity reported to control when one sensor had activity and other had negative activity.
            if(sensorArray[i].activity > 0)
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
        if (sensor)
        {
            return uv_light_heuristic(&sensor->data) > sensor->activity;
        }
        
        return false;
    }

}  // namespace speedywagon
