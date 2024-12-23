#include <fstream>
#include <string>
#include "DistanceCalculator.h"

class FileReader {
    private:
        std::ifstream stream;
    public:
        FileReader(std::string filename) {
            stream = std::ifstream(filename);
        }

        DistanceCalculator* getDistanceCalculator();

        ~FileReader() {
            if (stream.is_open()) {
                stream.close();
            }
        }
};