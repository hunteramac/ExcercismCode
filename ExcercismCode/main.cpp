#ifdef WITH_AUTOMATION_TESTS
#include <gtest/gtest.h>

int RunAllGoogleTests()
{
    int argc = 0;
    char** argv = nullptr;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

int main() {
    RunAllGoogleTests();
}
#else
int main() {
    //dummy
}

#endif