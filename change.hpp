#include <vector>
#include <iostream>

class Change {

    private:
        int input_;
        std::vector<int> coins_;

    public:
        int result_ = 0;

    Change(int moneyInPence);

    const int findWaysToMakeChange(const int &moneyInPence, std::vector<int> coins, int coin_idx);
    
};
