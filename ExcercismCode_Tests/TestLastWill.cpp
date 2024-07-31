#include "pch.h"

#include "../ExcercismCode/last_will.cpp"

//Turns out, this code is not really testable... not in meaningful way
// hard dependenices cannot be mocked.
TEST(LastWill, dummy) {
	EXPECT_EQ(estate_executor::assemble_account_number(1),1);
}
