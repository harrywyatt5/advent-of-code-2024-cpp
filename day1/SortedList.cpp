#include "SortedList.h"

SortedList::SortedList(int* array, int size) {
    this->array = array;
    this->size = size;
    this->mergeSort(0, size - 1);
}

void SortedList::mergeSort(int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;

        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        merge(left, middle, right);
    }
}

void SortedList::merge(int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = this->array[left + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = this->array[middle + 1 + i];
    }

    int leftArrIndex = 0;
    int rightArrIndex = 0;
    int mergeIndex = left;

    while (leftArrIndex < leftSize && rightArrIndex < rightSize) {
        if (leftArr[leftArrIndex] <= rightArr[rightArrIndex]) {
            this->array[mergeIndex] = leftArr[leftArrIndex];
            leftArrIndex++;
        } else {
            this->array[mergeIndex] = rightArr[rightArrIndex];
            rightArrIndex++;
        }

        mergeIndex++;
    }

    while (leftArrIndex < leftSize) {
        this->array[mergeIndex] = leftArr[leftArrIndex];
        leftArrIndex++;
        mergeIndex++;
    }

    while (rightArrIndex < rightSize) {
        this->array[mergeIndex] = rightArr[rightArrIndex];
        rightArrIndex++;
        mergeIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}