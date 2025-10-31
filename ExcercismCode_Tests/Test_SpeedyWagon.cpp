#include "pch.h"

#include "../ExcercismCode/speedywagon.h"
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