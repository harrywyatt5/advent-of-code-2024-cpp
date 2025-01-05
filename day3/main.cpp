#include <iostream>
#include <vector>
#include "CommandInterpreter.h"
#include "MulCommand.h"
#include "ICommand.h"

int main() {
    CommandInterpreter interpreter("input.txt", "mul", 2);
    std::vector<MulCommand> instructionVector;
    MulCommand* mulCommand = new MulCommand();

    while (interpreter.getNextCommand((ICommand*)mulCommand)) {
        instructionVector.push_back(*mulCommand);

        delete mulCommand;
        mulCommand = new MulCommand();
   }

    delete mulCommand;
    mulCommand = nullptr;
    int result = 0;

    for (int i = 0; i < instructionVector.size(); i++) {
        result += instructionVector[i].resolve();
    }
    
    std::cout << "Vector count: " << instructionVector.size() << std::endl;
    std::cout << "The result is: " << result << std::endl;
    return 0;
}