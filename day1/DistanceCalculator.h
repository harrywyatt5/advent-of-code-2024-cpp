#pragma once
#include "SortedList.h"

class DistanceCalculator {
    private:
        SortedList* firstList;
        SortedList* secondList;
    public:
        int getDistance() const;

        DistanceCalculator(SortedList* first, SortedList* second) {
            this->firstList = first;
            this->secondList = second; 
        }

        ~DistanceCalculator() {
            delete firstList;
            delete secondList;
        }
};