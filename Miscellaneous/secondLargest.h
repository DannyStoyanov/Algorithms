#include <iostream>

// Find Second largest element in an array

// Given an array of integers, our task is to write a program that
// efficiently finds the second largest element present in the array.

int secondLargest(int arr[], std::size_t size)
{
    if (size <= 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    if (size == 2)
    {
        return std::min(arr[0], arr[1]);
    }
    int p = std::max(arr[0], arr[1]);
    int q = std::min(arr[0], arr[1]);
    for (size_t i = 2; i < size; i++) {
        if (arr[i] > p) {
            q = p;
            p = arr[i];
        }
        else {
            if(arr[i] > q) {
                q=arr[i];
            }
        }
    }
    return q;
}