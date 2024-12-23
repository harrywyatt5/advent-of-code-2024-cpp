#pragma once

class SortedList {
    private:
        int* array;
        int size;
        void mergeSort(int left, int right);
        void merge(int left, int middle, int right);
    public:
        SortedList(int* array, int size);

        int* getArray() const {
            return this->array;
        }

        int getSize() const {
            return this->size;
        }

        ~SortedList() {
            delete[] array;
        }
};