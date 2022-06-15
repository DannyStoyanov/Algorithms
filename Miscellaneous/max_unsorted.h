#include <iostream>

int max_unsorted(int* arr, std::size_t size) {
    if (size <= 0) {
        return -1;
    }
    int max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int max_unsorted_rec(int* arr, std::size_t size) {
    if (size == 0) {
        return INT_MIN;
    }
    int max = max_unsorted_rec(arr, size-1);
    if (max < arr[size-1]) {
        max = arr[size-1];
    }
    return max;
}