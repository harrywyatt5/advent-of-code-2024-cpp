#include "CommandInterpreter.h"
#include "ICommand.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool CommandInterpreter::hasCommandStr() {
    for (int i = 0; i < this->commandStr.size(); i++) {
        this->currentChar = this->fileStream.get();

        if (this->fileStream.eof() || this->currentChar != this->commandStr[i]) {
            return false;
        }
    }

    return true;
}

CommandInterpreter::CommandInterpreter(std::string fileName, std::string commandStr, int maxParameters) {
    this->fileStream = std::ifstream(fileName);
    this->commandStr = commandStr;
    this->maxParameters = maxParameters;
    this->currentChar = ' ';
}

std::string* CommandInterpreter::getCommandArgs() {
    // Next character must be a bracket
    this->currentChar = this->fileStream.get();

    if (this->currentChar != '(') {
        return nullptr;
    }

    std::vector<char> newString;
    this->currentChar = this->fileStream.get();
    while (this->currentChar != ')') {
        if (this->fileStream.eof() || ((this->currentChar < 48 || this->currentChar > 57) && this->currentChar != ',')) {
            std::cout << "We saw " << this->currentChar << ", returning nullptr" << std::endl;
            return nullptr;
        }

        newString.push_back(this->currentChar);
        this->currentChar = this->fileStream.get();
    }

    return new std::string(newString.begin(), newString.end());
}

int* CommandInterpreter::createArgsFromStr(std::string& str) {
    std::cout << "The string is " << str << std::endl;
    int* args = new int[this->maxParameters];

    int startPos = 0;
    int currentArgsInsert = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ',' || i == str.size() - 1) {
            try {
                int endPos = i == str.size() - 1 ? i + 1 : i;
                args[currentArgsInsert] = std::stoi(str.substr(startPos, endPos - startPos));
                startPos = i + 1;
                currentArgsInsert++;
            } catch (std::invalid_argument exception) {
                // This command is corrupted
                std::cout << "Command is corrupted" << std::endl;
                delete[] args;

                return nullptr;
            }
        }

        if (currentArgsInsert > this->maxParameters) {
            std::cout << "More args than expected" << std::endl;
            delete[] args;
            
            return nullptr;
        }
    }


    if (currentArgsInsert < this->maxParameters) {
        std::cout << "Less args than expected" << std::endl;
        delete[] args;

        return nullptr;
    }

    for (int i = 0; i < this->maxParameters; i++) {
        std::cout << "Number " << args[i] << "; ";
    }
    std::cout << std::endl;

    return args;
}

bool CommandInterpreter::getNextCommand(ICommand* commandToFill) {
    while (!this->fileStream.eof()) {
        if (!this->hasCommandStr()) {
            continue;
        }

        std::string* cmdArgs = this->getCommandArgs();
        // If we've not got a nullptr
        if (cmdArgs == nullptr) {
            continue;
        }

        int len = this->maxParameters;
        int* argsArr = this->createArgsFromStr(*cmdArgs);

        if (argsArr == nullptr) {
            delete cmdArgs;
            continue;
        }

        commandToFill->setParameter(argsArr, len);
        delete cmdArgs;
        return true;
    }

    // Return false if there are no more commands
    return false;
}