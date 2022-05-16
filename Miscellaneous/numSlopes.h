#include <iostream>

// Count Strictly Increasing Subarrays

// Given an array of integers, count number of subarrays (of size more than one) that are strictly increasing. 
// Expected Time Complexity : O(n) 
// Expected Extra Space: O(1)

template <typename T>
unsigned numSlopes(T* arr, std::size_t size) {
    unsigned res = 0;
    for (size_t i = 1; i < size; i++) {
        if(arr[i] > arr[i-1]) {
            res++;
        }
    }
    return res;
}