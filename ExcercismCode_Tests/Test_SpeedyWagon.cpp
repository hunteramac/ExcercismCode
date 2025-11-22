#include "pch.h"

#include "../ExcercismCode/speedywagon.h"

namespace SpeedyWagon {


TEST(CheckSensorConnection, DisconnectedSensor)
{
	speedywagon::pillar_men_sensor* sensor{ nullptr };
	EXPECT_FALSE(speedywagon::connection_check(sensor));
}

TEST(CheckSensorConnection, ConnectedSensor)
{
	speedywagon::pillar_men_sensor* sensor = new speedywagon::pillar_men_sensor();
	EXPECT_TRUE(speedywagon::connection_check(sensor));
}

TEST(ActivityCounter, getsCount1)
{
	speedywagon::pillar_men_sensor sensor_array[3] =
	{ {0}, {101}, {22} };

	EXPECT_EQ(speedywagon::activity_counter(sensor_array, 3), 123);
}

TEST(ActivityCounter, getsCount2)
{
	speedywagon::pillar_men_sensor sensor_array[5] =
	{ {0}, {1}, {3}, {80} };

	EXPECT_EQ(speedywagon::activity_counter(sensor_array, 5), 84);
}

};