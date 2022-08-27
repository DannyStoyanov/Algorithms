#include <iostream>
#include "mergeSort.h"

// You are given an array of integers of size N. 
// Your task is to find the dominant number in the array.
// A dominant number in an array is an integer that occurs
// more than N/2 times in the array, where N is the array’s length.

int predominantElement(int arr[], std::size_t size) {
    mergeSort(arr, size);
    return arr[size/2];
}