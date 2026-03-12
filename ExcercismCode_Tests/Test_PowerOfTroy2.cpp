#include "pch.h"


namespace PowerOfTroy2
{
	TEST(dummy, dummy1) {
		//make a shared ptr
		std::unique_ptr<std::string> testPtr = std::make_unique<std::string>("helloWorld");
		
		std::string expectation = "helloWorld";
		std::string result = "helloWorld";

		EXPECT_EQ(result, expectation);

		//EXPECT_EQ(testPtr.get()->c_str(), expectation.c_str());

		//testPtr.release();
		//EXPECT_FALSE(testPtr.get());
	}
}