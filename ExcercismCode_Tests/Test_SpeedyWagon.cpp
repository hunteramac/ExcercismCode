#include "pch.h"

#include "../ExcercismCode/speedywagon.h"
TEST(CheckSensorConnection, canCall)
{
	speedywagon::pillar_men_sensor* sensor{ nullptr };
	EXPECT_FALSE(speedywagon::connection_check(sensor));
}