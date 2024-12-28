#pragma once
#include <fstream>
#include <string>
#include "NuclearReport.h"

class FileReader {
    private:
        std::ifstream file;
        std::string currentLine;
    public:
        FileReader(std::string location) {
            file = std::ifstream(location);
        }
        NuclearReport* getNextReport();
        ~FileReader() {
            if (file.is_open()) {
                file.close();
            }
        }
};