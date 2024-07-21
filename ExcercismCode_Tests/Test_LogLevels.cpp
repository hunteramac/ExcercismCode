#include "pch.h"

#include "../ExcercismCode/log_levels.cpp"

//[<LEVEL>]: <MESSAGE>
//INFO
//WARNING
//ERROR
TEST(Ex_LogLevels, message_1) {
	std::string line = "[INFO]: hello world";
	EXPECT_EQ(log_line::message(line),"hello world");
}

TEST(Ex_LogLevels, message_2) {
	std::string line = "[INFO]: good bye world";
	EXPECT_EQ(log_line::message(line), "good bye world");
}

TEST(Ex_LogLevels, log_level_1) {
	std::string line = "[INFO]: good bye world";
	EXPECT_EQ(log_line::log_level(line), "INFO");
}

TEST(Ex_LogLevels, reformat_1) {
	std::string line = "[INFO]: good bye world";
	EXPECT_EQ(log_line::reformat(line), "good bye world (INFO)");
}