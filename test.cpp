#include <gtest/gtest.h>

#include "change.hpp"

// g++ test.cpp -lgtest -lgtest_main -lpthread
//int findWaysToMakeChange(int moneyInPence, std::vetor<int> coins, int coin_idx,  int &ways) {


TEST(change, correctCoinsChosen)
{
    int moneyInPence = 99;
    Change change(moneyInPence);
    std::vector<int> expectedChange = {50, 20, 10, 5, 2, 1};

    for (int i = 0; i < expectedChange.size(); i ++){
        EXPECT_EQ(expectedChange.at(i), change.coins_.at(i));
    }

}



TEST(change, changeIn1p)
{
    //SpyChange spy();

    int moneyInPence = 1;
    Change change(moneyInPence);
    auto waysOfMakingChange = change.findWaysToMakeChange(moneyInPence, change.coins_, 0);
    

    EXPECT_EQ(waysOfMakingChange, 1);
    //EXPECT_EQ(spy().times, 1);
    
}

TEST(change, changeIn2p)
{
    int moneyInPence = 2;
    Change change(moneyInPence);

    std::vector<int> soln;
    change.findWaysToMakeChange(moneyInPence, change.coins_, 0);
    auto waysOfMakingChange = change.result_;

    ASSERT_EQ(waysOfMakingChange, 2);
}

TEST(change, changeIn5p)
{
    int moneyInPence = 5;
    Change change(moneyInPence);
    
    std::vector<int> soln;
    change.findWaysToMakeChange(moneyInPence, change.coins_, 0);

    auto waysOfMakingChange = change.result_;

    // 5p = 5p, 2x2p + 1p, 2p + 3x1p, 5x1p
    ASSERT_EQ(waysOfMakingChange, 4);
}

// TEST(change, changeIn7p)
// {
//     int moneyInPence = 7;
//     Change change(moneyInPence);

//     std::vector<int> soln;
//     change.findWaysToMakeChange(moneyInPence, change.coins_, 0, soln);

//     auto waysOfMakingChange = change.result_;

//     ASSERT_EQ(waysOfMakingChange, 5);
// }


//run all tests 
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
