#include <iostream>

template <typename T>
int findIndex(T pivot, T* arr, std::size_t size) {
    for (std::size_t i = 0; i < size; i++) {
        if(arr[i] == pivot) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int partitionLomuto(T* arr, std::size_t size, T pivot) {
    std::size_t k = findIndex(pivot, arr, size);
    std::swap(arr[k], arr[size-1]);
    int pp = 0;
    for(std::size_t i = 0; i<size-1; i++) {
        if(arr[i] < pivot) {
            std::swap(arr[i], arr[pp]);
            pp++;
        }
    }
    std::swap(arr[pp], arr[size-1]);
    return pp;
}