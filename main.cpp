#include <iostream>

#include "change.hpp"


int main(int argc, char *argv[]){

    int inputMoney = 1;

    Change change(inputMoney);

    change.findWaysToMakeChange(inputMoney, change.coins_, 0);
    std::cout<<"result: "<<change.result_;
}