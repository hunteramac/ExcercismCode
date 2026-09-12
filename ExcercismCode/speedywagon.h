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

    //enum class SensorEnvironment
    //{   
    //    Production,
    //    Test
    //};

    //// a global to disable some functionality in handling
    //// to make it easier to test with legacy code that can't easily be mocked.
    //SensorEnvironment sensorEnvironment = SensorEnvironment::Production;
    //int fakeUvIndexReturn = 0;

    /// <summary>
    /// Computes accumulated activity across an array of sensors.
    /// 
    /// Negative activity readings are discarded during the operation, user must run scans to check for negative readings using another method.
    /// Negative activity can still indicate something important (interference, sensor failure... etc)
    //  Unsigned int for activity from sensors isn't supported by the hardware
   /// </summary>
    /// <param name="sensorArray"></param>
    /// <param name="size"> 
    ///     Number of elements in the sensor array.
    ///     Blindly trusted by method - user must provide the correct size to prevent reading outside of memory.
    ///     Negative size causes no sensors to be proccessed.
    /// </param>
    /// <returns></returns>
    int activity_counter(const pillar_men_sensor* const sensorArray, int size);
    
    bool connection_check(pillar_men_sensor* sensor);

    bool alarm_control(pillar_men_sensor* sensor);

    bool uv_alarm(pillar_men_sensor* sensor);
}  // namespace speedywagon
