#include "pch.h"

#include "../ExcercismCode/testClass.h"

TEST(TestThrow, IndexNull) {
	testClass* myVar = NULL;

	try {

	}

	//Why doesnt this crash?
	EXPECT_EQ(5,myVar->getNum());
}