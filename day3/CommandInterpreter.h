#pragma once
#include <string>
#include <fstream>
#include "ICommand.h"

class CommandInterpreter {
    private:
        std::ifstream fileStream;
        std::string commandStr;
        int maxParameters;
        char currentChar;
        bool hasCommandStr();
        std::string* getCommandArgs();
        int* createArgsFromStr(std::string& str);
    public:
        CommandInterpreter(std::string fileName, std::string commandStr, int maxParameters);
        bool getNextCommand(ICommand* commandToFill);
};