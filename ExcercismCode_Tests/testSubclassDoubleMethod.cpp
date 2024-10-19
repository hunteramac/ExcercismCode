#include "pch.h"

#include "../ExcercismCode/testDerivativeClass.h"

//#include "../ExcercismCode/pretendMFCClass.h"

namespace testSubclassMethod{

TEST(SubclassDoubleMethod, harnessWorks) {
	//testDerivativeClass* tempClass = new testDerivativeClass();
	
	testDerivativeClass* tempClass = new testDerivativeClass();

	int result = tempClass->SetText();

	EXPECT_EQ(result, 2);
	//tempClass->dummy();

	//int result = tempClass->set
	//EXPECT_EQ(tempClass().SetText, 2);
	//EXPECT_TRUE(false);
}

}