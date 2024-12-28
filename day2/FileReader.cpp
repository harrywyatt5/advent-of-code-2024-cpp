#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "FileReader.h"
#include "NuclearReport.h"

NuclearReport* FileReader::getNextReport() {
    if (!std::getline(this->file, this->currentLine)) {
        return nullptr;
    }

    int count = 0;
    // True if we have seen a digit but not a space after it yet
    bool spaceFlag = false;
    for (int i = 0; i < this->currentLine.size(); i++) {
        if (isdigit(this->currentLine[i]) && !spaceFlag) {
            count++;
            spaceFlag = true;
        } else if (this->currentLine[i] == ' ') {
            spaceFlag = false;
        }
    }

    int startPointer = -1;
    int insertIndex = 0;
    int* levelsArr = new int[count];
    for (int i = 0; i < this->currentLine.size(); i++) {
        if (isdigit(this->currentLine[i]) && startPointer == -1) {
            startPointer = i;
        } else if (!isdigit(this->currentLine[i]) && startPointer != -1) {
            levelsArr[insertIndex] = stoi(this->currentLine.substr(startPointer, i));
            startPointer = -1;
            insertIndex++;
        }
    }

    if (startPointer != -1) {
        levelsArr[insertIndex] = stoi(this->currentLine.substr(startPointer, this->currentLine.size() - 1));
    }

    return new NuclearReport(levelsArr, count);
}
