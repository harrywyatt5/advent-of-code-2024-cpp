#include <cstdlib>
#include <iostream>
#include "NuclearReport.h"

const int NuclearReport::MAX_CHANGE = 3;

bool NuclearReport::areLevelsLinear() const {
    // LOok ahead at first two value and determine if increasing or not
    int firstVal = this->levels[0];
    int secondVal = this->levels[1];

    if (firstVal == secondVal) return false;

    bool isIncreasing = firstVal < secondVal;
    int prevVal = secondVal;

    for (int i = 2; i < this->count; i++) {
        if ((!isIncreasing && this->levels[i] >= prevVal) 
        || (isIncreasing && this->levels[i] <= prevVal)
        ) {
            return false;
        }

        prevVal = this->levels[i];
    }

    return true;
}

bool NuclearReport::levelsHaveAceptableIncrease() const {
    int prevValue = this->levels[0];

    for (int i = 1; i < this->count; i++) {
        if (abs(prevValue - this->levels[i]) > MAX_CHANGE) {
            return false;
        }

        prevValue = this->levels[i];
    }

    return true;
}

void NuclearReport::printReport() const {
    for (int i = 0; i < this->count; i++) {
        std::cout << levels[i] << " ";
    }

    std::cout << std::endl;
}