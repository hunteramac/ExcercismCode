#include "pch.h"

#include "../ExcercismCode/testClass.h"

#include <string>
TEST(TestThrow, IndexNull) {
	int testInt = 4;

	double newNum = static_cast<double>(testInt);
	
	std::string temp = "hello world";

	//const char* testCharStar = const_cast<char*>(temp);
	//const char* testCharStar = static_cast<char*>(temp);


	EXPECT_TRUE(true);

	//testClass* myVar = NULL;

	//try {

	//}
	//catch (...) {
	//	//Why doesnt this crash?
	//	EXPECT_EQ(5, myVar->getNum());
	//}
}