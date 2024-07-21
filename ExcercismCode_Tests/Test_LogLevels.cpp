#include "pch.h"

#include "../ExcercismCode/log_levels.cpp"

//[<LEVEL>]: <MESSAGE>
//INFO
//WARNING
//ERROR
TEST(Ex_LogLevels, T1) {
	std::string line = "[INFO]: hello world";
	EXPECT_EQ(log_line::message(line),"hello world");
}