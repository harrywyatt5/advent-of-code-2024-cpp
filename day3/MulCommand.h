#pragma once
#include "ICommand.h"

class MulCommand : public ICommand {
    private:
        int firstNum;
        int secondNum;
    public:
        MulCommand() {
            this->firstNum = 0;
            this->secondNum = 0;
        }
        void setParameter(int* parameters, int count);
        int resolve() const;
};