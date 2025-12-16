#ifdef WITH_AUTOMATION_TESTS
#include <gtest/gtest.h>
#include "../lasagna_master.h"

TEST(MyLegacyTest, PassingTest)
{
	EXPECT_TRUE(false);
}

TEST(MyLegacyTest, FailingTest)
{
	EXPECT_TRUE(true);
}

TEST(MyLegacyTest, CanCall)
{
	std::vector<std::string>layers;
	lasagna_master::preparationTime(layers);
}

//#include <assert.h>
//void RunTests()
//{
//	assert(true);
//}
#endif
