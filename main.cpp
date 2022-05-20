#include <iostream>
#include <cstdlib>

#include "change.hpp"


int main(int argc, char *argv[]){

    int inputMoney;
    if (argc != 2){
        std::cout<<"Must provide inputMoney to make as <bin> <inputMoney>. Using default (inputMoney == 200)"<<std::endl;
        inputMoney = 200;
    }
    else {
        inputMoney = atoi(argv[1]);
    }
    Change change(inputMoney);

    std::cout<<"result: "<<change.result_<<std::endl;
}