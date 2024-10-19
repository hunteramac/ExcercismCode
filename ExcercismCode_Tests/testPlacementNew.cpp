#include "pch.h"

TEST(PlacementNew, Test1) {
	// https://stackoverflow.com/questions/222557/what-uses-are-there-for-placement-new

	//example of using placement
	// placement new allows you to construct an object in memory that's allready allocated

	// key features
	// - no danger of mem allocation failure -> preallocated
	// - constructing an object in preallocated buffer takes less time


	// 1. preallocate some memory somewhere else
	// For example, in a NON critical section of the code
	char *buf = new char[sizeof(std::string)];

	// 2. Placement new
	// construct in place using the buffer
	std::string* p = new (buf) std::string("hi");

	// ordinary heap allocation
	std::string* q = new std::string("hi");

	// https://www.stroustrup.com/bs_faq2.html#placement-delete
	// placement delete

	EXPECT_TRUE(true);
}