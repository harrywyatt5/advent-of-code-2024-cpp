#include <iostream>
#include "SortedList.h"
#include "DistanceCalculator.h"
#include "FileReader.h"

int main() {
    FileReader myFileReader("input.txt");
    DistanceCalculator* calculator = myFileReader.getDistanceCalculator();

    std::cout << calculator->getDistance() << std::endl;
}