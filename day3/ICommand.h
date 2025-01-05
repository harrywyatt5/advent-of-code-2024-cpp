#pragma once

class ICommand {
    public:
        virtual void setParameter(int* parameters, int count) = 0;
        virtual int resolve() const = 0;
};