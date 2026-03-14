#include "pch.h"

#include "../ExcercismCode/speedywagon.h"


static int calledXTimes = 0;
static std::vector<int>* data_array_input = nullptr;
static int mockOut = 0;

int uv_light_heuristic(std::vector<int>* data_array)
{
	data_array_input = data_array;
	calledXTimes++;
	return mockOut;
}


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

TEST(AlarmControl, ActiveSensor)
{
	speedywagon::pillar_men_sensor db{ 1, "Mars", {7,7,7} };
	speedywagon::pillar_men_sensor db2{ 9008, "Mars", {7,7,7} };

	EXPECT_TRUE(speedywagon::alarm_control(&db));
	EXPECT_TRUE(speedywagon::alarm_control(&db2));
}

TEST(AlarmControl, NullptrDoesntCrash)
{
	speedywagon::pillar_men_sensor db;

	EXPECT_FALSE(speedywagon::alarm_control(nullptr));
}

TEST(AlarmControl, ZeroActivity)
{
	speedywagon::pillar_men_sensor db{ 0, "Mars", {1,2,3} };

	EXPECT_FALSE(speedywagon::alarm_control(&db));
}
TEST(UvAlarm, canCall)
{
	speedywagon::pillar_men_sensor db{ 0, "Mars", {1,2,3} };
	speedywagon::uv_alarm(&db);
}
TEST(UvAlarm, NullPtr)
{
	EXPECT_FALSE(speedywagon::uv_alarm(nullptr));
}
TEST(UvAlarm, LightHeuristicGreaterThanSensorAcitivityLevel)
{
	speedywagon::pillar_men_sensor db{ 0, "Mars", {1,2,3} };
	speedywagon::uv_alarm(&db);
	EXPECT_EQ(calledXTimes, 1);
	//EXPECT_EQ(data_array_input,&db.data);
}

};