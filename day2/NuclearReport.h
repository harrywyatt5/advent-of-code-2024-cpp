#pragma once

class NuclearReport {
    private:
        static const int MAX_CHANGE; 
        int* levels;
        int count;
        bool areLevelsLinear() const;
        bool levelsHaveAceptableIncrease() const;
    public:
        void printReport() const;

        NuclearReport(int* levels, int count) {
            this->levels = levels;
            this->count = count;
        }

        bool isLevelSafe() const {
            return this->areLevelsLinear() && this->levelsHaveAceptableIncrease();
        }

        ~NuclearReport() {
            delete[] levels;
            levels = nullptr;
        }
};