#include <gtest/gtest.h>

#include "change.hpp"

// g++ test.cpp -lgtest -lgtest_main -lpthread


TEST(change, changeIn1p)
{
    int moneyInPence = 1;
    Change change(moneyInPence);

    auto waysOfMakingChange = change.findWaysToMakeChange(moneyInPence, change.coins_, 0);

    EXPECT_EQ(waysOfMakingChange, 1);
}


TEST(change, changeIn2p)
{
    int moneyInPence = 2;
    Change change(moneyInPence);
    change.findWaysToMakeChange(moneyInPence, change.coins_, 0);

    ASSERT_EQ(change.result_, 2);
}


TEST(change, changeIn5p)
{
    int moneyInPence = 5;
    Change change(moneyInPence);

    change.findWaysToMakeChange(moneyInPence, change.coins_, 0);

    // 5p = 5p, 2x2p + 1p, 2p + 3x1p, 5x1p
    ASSERT_EQ(change.result_, 4);
}


TEST(change, changeIn7p)
{
    int moneyInPence = 7;
    Change change(moneyInPence);

    change.findWaysToMakeChange(moneyInPence, change.coins_, 0);
    
    // 5+2, 5+1s, 2+2+2+1, 2+2+1s, 2+1s, 1s
    ASSERT_EQ(change.result_, 6);
}


//run all tests 
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
