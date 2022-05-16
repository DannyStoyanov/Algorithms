#include <iostream>
#include "mergeSort.h"

// Mode

// Given array of integers. Find mode of the array.

int mode(int arr[], std::size_t size)
{
    mergeSort<int>(arr, size);
    int mode = arr[0];
    int m = 1;
    int s = 1;
    for (size_t i = 1; i < size; i++) {
        if (arr[i - 1] == arr[i]) {
            if (arr[i - 1] == mode) {
                m++;
            }
            else {
                s++;
                if (s > m) {
                    mode = arr[i];
                    m = s;
                }
            }
        }
        else {
            s = 1;
        }
    }
    return mode;
}