#include <iostream>
#include <string>
#include "FileReader.h"
#include "NuclearReport.h"

int main() {
    std::string fileLocation = "input.txt";
    FileReader myFileReader(fileLocation);

    NuclearReport* nextReport = myFileReader.getNextReport();
    int count = 0;
    while (nextReport != nullptr) {
        if (nextReport->isLevelSafe()) {
            count++;
        }

        nextReport->printReport();

        delete nextReport;
        nextReport = myFileReader.getNextReport();
    }

    std::cout << "The number of safe reports are " << count << std::endl; 
}