#include <iostream>
#include "mergeSort.h"

// Given array of integers

// Find min{ |a_i - a_j| : 0 <= i < j < n }

std::pair<int, int> closestPair(int arr[], std::size_t size) {
    if(size == 0) {
        return std::make_pair(INT_MIN, INT_MAX);
    }
    if(size == 1) {
        return std::make_pair(arr[0], INT_MAX);
    }
    if(size == 2) {
        return std::make_pair(arr[0], arr[1]);
    }
    mergeSort<int>(arr, size);
    int closest = INT_MAX;
    int first = arr[0];
    int second = arr[1];
    for (size_t i = 0; i < size-1; i++) {
        if(arr[i+1] - arr[i] < closest) {
            closest = arr[i+1] - arr[i];
            first = arr[i];
            second = arr[i+1];
        }
    }
    return std::make_pair(first, second);
}