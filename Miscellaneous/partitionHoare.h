#include <iostream>

template <typename T>
int partitionHoare(T arr[], std::size_t low, std::size_t high) {
    T pivot = arr[low];
    int i = low-1;
    int j = high+1;
    while(true) {
        do {
            --j;
        }while(arr[j] > pivot);
        do {
            ++i;
        }while(arr[i] < pivot);
        if(i >= j) {
            return j;
        }
        std::swap(arr[i], arr[j]);
    }
}