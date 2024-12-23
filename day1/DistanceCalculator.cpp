#include "DistanceCalculator.h"
#include "SortedList.h"
#include <cstdlib>

int DistanceCalculator::getDistance() const {
    // Assume lists are the same length
    int listLength = this->firstList->getSize();
    int totalDistance = 0;

    int* firstArrRef = this->firstList->getArray();
    int* secondArrRef = this->secondList->getArray();

    for (int i = 0; i < listLength; i++) {
        totalDistance += abs(firstArrRef[i] - secondArrRef[i]);
    }

    return totalDistance;
}