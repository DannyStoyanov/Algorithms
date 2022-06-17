#include <iostream>
#include "mergeSort.h"

template <typename T>
bool uniqueElements(T arr[], std::size_t size) {
    mergeSort<T>(arr, size);
    for (std::size_t i = 1; i < size; i++) {
        if(arr[i] == arr[i-1]) {
            return false;
        }
    }
    return true;
}