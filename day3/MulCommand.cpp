#include "MulCommand.h"
#include <iostream>
#include <stdexcept>

void MulCommand::setParameter(int* parameters, int count) {
    if (count != 2) {
        std::cout << "2 parameters are required" << std::endl;
        throw new std::runtime_error("2 parameters are required");
    }

    this->firstNum = parameters[0];
    this->secondNum = parameters[1];
}

int MulCommand::resolve() const {
    return this->firstNum * this->secondNum;
}