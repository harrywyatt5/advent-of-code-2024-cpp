#include "FileReader.h"
#include "DistanceCalculator.h"
#include <fstream>
#include <string>
#include <iostream>

DistanceCalculator* FileReader::getDistanceCalculator() {
    // Get how many lines there are
    std::string currentLine;
    int count = 0;

    // This is basically only to get rid of problematic empty lines or eofs, we don't valid the file at all
    // and could result in a really corrupted calculation if the file is incorrect
    while (std::getline(this->stream, currentLine)) {
        try {
            std::stoi(currentLine);
            count++;
        } catch (std::invalid_argument err) {
            continue;
        }
    }

    int* firstArr = new int[count];
    int* secondArr = new int[count];
    int arrPointer = 0;
    std::string firstNum;
    std::string secondNum; 
    this->stream.clear();
    this->stream.seekg(0);

    while (std::getline(this->stream, currentLine)) {
        int lineLength = currentLine.size();

        // Find the space
        int endStr1 = 0;
        int startStr2 = 0;
        for (int i = 0; i < lineLength; i++) {
            if (currentLine[i] == ' ' && endStr1 == 0) {
                endStr1 = i;
            } else if (currentLine[i] != ' ' && endStr1 != 0) {
                startStr2 = i;
                break;
            }
        }

        firstNum = currentLine.substr(0, endStr1);
        secondNum = currentLine.substr(startStr2);
        firstArr[arrPointer] = std::stoi(firstNum);
        secondArr[arrPointer] = std::stoi(secondNum);
        arrPointer++;
    }

    return new DistanceCalculator(new SortedList(firstArr, count), new SortedList(secondArr, count));
}