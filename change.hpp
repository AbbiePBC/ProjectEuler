#include <vector>
#include <iostream>

class Change {

    public:
        int result_ = 0;
        int input_ = 0;
        std::vector<int> coins_;

    Change(int moneyInPence) {
        int input_ = moneyInPence;
        coins_ = chooseCoinsToUse(input_);
    }

    std::vector<int> chooseCoinsToUse(int &moneyInPence){
        std::vector<int> coins = {200, 100, 50, 20, 10, 5, 2, 1};

        while (coins.at(0) > moneyInPence){
            coins.erase(coins.begin());
        }
        return coins;
    }


    void printSet(std::vector<int> vec){
        std::cout<<"one set of coins: "<<std::endl;
        for (auto &v: vec){
            std::cout<<v<<" ";
        }
        std::cout<<std::endl;
    }
    

    int findWaysToMakeChange(int moneyInPence, std::vector<int> coins, int coin_idx) {
        std::cout<<"finding change for "<<moneyInPence<<" starting with "<<coins.at(coin_idx)<<"p."<<std::endl;
       // input: target amount
       // until no longer possible, subtract coin value then find next target amount, without that coin.
        if (coin_idx >= coins.size()){
            return result_;
        }

        if (coins.at(coin_idx) == 1){
            result_ ++;
            return result_;
        }

        while(moneyInPence > coins.at(coin_idx)){
            int nextCoinIdx = coin_idx + 1;
            moneyInPence -= coins.at(coin_idx);
            findWaysToMakeChange(moneyInPence, coins, nextCoinIdx);
            
        }
        if (moneyInPence - coins.at(coin_idx) == 0){
            findWaysToMakeChange(input_, coins, ++coin_idx);
            result_ ++;
        }
        return result_;
    }
    
};
